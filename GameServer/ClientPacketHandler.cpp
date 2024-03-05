#include "pch.h"
#include "ClientPacketHandler.h"
#include "Player.h"
#include "Room.h"
#include "GameSession.h"
static std::unordered_map<int, PlayerRef> currentPlayersMap;
PacketHandlerFunc GPacketHandler[UINT16_MAX];

// 이미 처리한 패킷의 식별자를 저장하는 HashSet
std::unordered_set<int> processedPacketIds;


// IsPlayerIDExists 함수 수정
bool IsPlayerIDExists(int playerId) {
	// unordered_map의 find 함수를 사용하여 playerId를 탐색
	return currentPlayersMap.find(playerId) != currentPlayersMap.end();
}

void removePlayer(int playerId) {
	auto it = currentPlayersMap.find(playerId);
	if (it != currentPlayersMap.end()) {
		currentPlayersMap.erase(it);
	
	}
	else {
	}
		
}

// 직접 컨텐츠 작업자

bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
{
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
	// TODO : Log
	cout << "Handle_INVALID: " << buffer << endl;
	return false;
}

bool Handle_C_LOGIN(PacketSessionRef& session, Protocol::C_LOGIN& pkt)
{
	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

	// TODO : Validation 체크

	Protocol::S_LOGIN loginPkt;
	loginPkt.set_success(true);

	// DB에서 플레이 정보를 긁어온다
	// GameSession에 플레이 정보를 저장 (메모리)

	// ID 발급 (DB 아이디가 아니고, 인게임 아이디)
	static Atomic<uint64> idGenerator = 0;

	//{
	//	auto player = loginPkt.add_players();
	//	player->set_name(u8"DB에서긁어온이름1");
	//	player->set_playertype(Protocol::PLAYER_TYPE_KNIGHT);

	//	PlayerRef playerRef = MakeShared<Player>();
	//	playerRef->playerId = idGenerator++;
	//	playerRef->name = player->name();
	//	playerRef->type = player->playertype();
	//	playerRef->ownerSession = gameSession;
	//	
	//	gameSession->_players.push_back(playerRef);
	//}

	{
		auto player = loginPkt.add_players();
		player->set_name(u8"AIrPlane" + to_string(idGenerator));
		player->set_id(idGenerator);
		player->set_playertype(Protocol::PLAYER_TYPE_MAGE);
		player->set_x(-1.0);
		player->set_y(450.0);
		player->set_z(-2500.0);
		PlayerRef playerRef = MakeShared<Player>();
		playerRef->playerId = idGenerator++;
		playerRef->name = player->name();
		playerRef->type = player->playertype();
		playerRef->ownerSession = gameSession;
		playerRef->x = player->x();
		playerRef->y = player->y();
		playerRef->z = player->z();
		if (!IsPlayerIDExists(playerRef->playerId)) {
			currentPlayersMap[playerRef->playerId] = playerRef;
		}

		gameSession->_players.push_back(playerRef);
	
		
	}

	auto sendBuffer = ClientPacketHandler::MakeSendBuffer(loginPkt);
	session->Send(sendBuffer);

	return true;
}



bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt)
{

	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

	uint64 index = pkt.playerindex();
	// TODO : Validation

	PlayerRef player = gameSession->_players[index]; // READ_ONLY?
	GRoom.Enter(player); // WRITE_LOCK
	Protocol::S_ENTER_GAME enterGamePkt;
	enterGamePkt.set_success(true);
	for (const auto& currentPlayer : currentPlayersMap) {
		Protocol::Player* playerMsg = enterGamePkt.add_currentallplayers();
		playerMsg->set_id(currentPlayer.second->playerId);
		playerMsg->set_name(currentPlayer.second->name);
		playerMsg->set_x(currentPlayer.second->x);
		playerMsg->set_y(currentPlayer.second->y);
		playerMsg->set_z(currentPlayer.second->z);
	}

	std::cout << "환영합니다. " << player->playerId << " 님이 입장 하였습니다." << std::endl;
	auto sendBuffer = ClientPacketHandler::MakeSendBuffer(enterGamePkt);
	player->ownerSession->Send(sendBuffer);
	GRoom.Broadcast(sendBuffer); // WRITE_LOCK
	return true;
}

bool Handle_C_CHAT(PacketSessionRef& session, Protocol::C_CHAT& pkt)
{
	std::cout << pkt.msg() << endl;

	Protocol::S_CHAT chatPkt;
	chatPkt.set_msg(pkt.msg());
	auto sendBuffer = ClientPacketHandler::MakeSendBuffer(chatPkt);

	GRoom.Broadcast(sendBuffer); // WRITE_LOCK

	return true;
}

bool Handle_C_POSITION(PacketSessionRef& session, Protocol::C_POSITION& pkt)
{

	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);
	PlayerRef player = gameSession->_players[0]; // READ_ONLY?


	
	int packetId = PKT_C_POSITION;

	
		cout << "Position Sync - ID: " << player->playerId
		<< ", X: " << pkt.x()
		<< ", Y: " << pkt.y()
		<< ", Z: " << pkt.z() << endl;
		
			PlayerRef currentSession = currentPlayersMap[player->playerId];
			currentSession->x = pkt.x();
			currentSession->y = pkt.y();
			currentSession->z = pkt.z();
			currentPlayersMap[player->playerId] = currentSession;
			Protocol::S_POSITION positionPkt;
			for (const auto& currentPlayer : currentPlayersMap) {
			Protocol::Player* playerMsg = positionPkt.add_currentallplayers();
			playerMsg->set_id(currentPlayer.second->playerId);
			playerMsg->set_name(currentPlayer.second->name);
			playerMsg->set_x(currentPlayer.second->x);
			playerMsg->set_y(currentPlayer.second->y);
			playerMsg->set_z(currentPlayer.second->z);
			}
			auto sendBuffer = ClientPacketHandler::MakeSendBuffer(positionPkt);
			GRoom.Broadcast(sendBuffer); // WRITE_LOCK
	


	return true;
}

bool Handle_C_MISSILE(PacketSessionRef& session, Protocol::C_MISSILE& pkt)
{

	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);
	PlayerRef player = gameSession->_players[0]; // READ_ONLY?
	Protocol::S_MISSILE missilePkt;
	cout << "MISSILE LAUNCH !!!! ID: " << player->playerId << endl;
	missilePkt.set_px(pkt.px());
	missilePkt.set_py(pkt.py());
	missilePkt.set_pz(pkt.pz());
	missilePkt.set_rx(pkt.rx());
	missilePkt.set_ry(pkt.ry());
	missilePkt.set_rz(pkt.rz());
	missilePkt.set_playerid(player->playerId);

	auto sendBuffer = ClientPacketHandler::MakeSendBuffer(missilePkt);
	GRoom.Broadcast(sendBuffer); // WRITE_LOCK

	return true;
}

bool Handle_C_DESTORY(PacketSessionRef& session, Protocol::C_DESTROY& pkt)
{
	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);
	PlayerRef player = gameSession->_players[0]; // READ_ONLY?
	removePlayer(player->playerId);
	Protocol::S_DESTROY destoryPkt;
	destoryPkt.set_success(1);
	destoryPkt.set_playerid(player->playerId);
	auto sendBuffer = ClientPacketHandler::MakeSendBuffer(destoryPkt);
	GRoom.Broadcast(sendBuffer); // WRITE_LOCK
	return false;
}

bool Handle_C_TEST(PacketSessionRef& session, Protocol::C_CHAT& pkt)
{
	std::cout << pkt.msg() << endl;

	Protocol::S_CHAT chatPkt;
	chatPkt.set_msg(pkt.msg());
	auto sendBuffer = ClientPacketHandler::MakeSendBuffer(chatPkt);

	GRoom.Broadcast(sendBuffer); // WRITE_LOCK

	return true;
}

