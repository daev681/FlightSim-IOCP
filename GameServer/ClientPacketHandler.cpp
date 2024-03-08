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

	// TODO: Validation check

	Protocol::S_LOGIN loginPkt;
	loginPkt.set_success(true);

	// Generate ID (not from DB but for in-game use)
	static Atomic<uint64> idGenerator = 0;
	static Atomic<float> px = 0.0;
	auto player = loginPkt.add_players();
	player->set_name(u8"AIrPlane" + to_string(idGenerator));
	player->set_id(idGenerator);
	player->set_playertype(Protocol::PLAYER_TYPE_MAGE);
	player->set_px(px);
	player->set_py(450.0);
	player->set_pz(-2500.0);
	player->set_rx(0.0); // Initial rotation values
	player->set_ry(0.0);
	player->set_rz(0.0);
	px = px + 20;

	PlayerRef playerRef = MakeShared<Player>();
	playerRef->playerId = idGenerator++;
	playerRef->name = player->name();
	playerRef->type = player->playertype();
	playerRef->ownerSession = gameSession;
	playerRef->px = player->px();
	playerRef->py = player->py();
	playerRef->pz = player->pz();
	playerRef->rx = player->rx();
	playerRef->ry = player->ry();
	playerRef->rz = player->rz();

	if (!IsPlayerIDExists(playerRef->playerId)) {
		currentPlayersMap[playerRef->playerId] = playerRef;
	}

	gameSession->_players.push_back(playerRef);

	auto sendBuffer = ClientPacketHandler::MakeSendBuffer(loginPkt);
	session->Send(sendBuffer);

	return true;
}

bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt)
{
	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

	uint64 index = pkt.playerindex();
	// TODO: Validation

	PlayerRef player = gameSession->_players[index]; // READ_ONLY?
	GRoom.Enter(player); // WRITE_LOCK

	Protocol::S_ENTER_GAME enterGamePkt;
	enterGamePkt.set_success(true);

	for (const auto& currentPlayer : currentPlayersMap) {
		Protocol::Player* playerMsg = enterGamePkt.add_currentallplayers();
		playerMsg->set_id(currentPlayer.second->playerId);
		playerMsg->set_name(currentPlayer.second->name);
		playerMsg->set_px(currentPlayer.second->px);
		playerMsg->set_py(currentPlayer.second->py);
		playerMsg->set_pz(currentPlayer.second->pz);
		playerMsg->set_rx(currentPlayer.second->rx);
		playerMsg->set_ry(currentPlayer.second->ry);
		playerMsg->set_rz(currentPlayer.second->rz);
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

	cout << "Position Sync - ID: " << player->playerId
		<< ", PX: " << pkt.px()
		<< ", PY: " << pkt.py()
		<< ", PZ: " << pkt.pz()
		<< ", RX: " << pkt.rx()
		<< ", RY: " << pkt.ry()
		<< ", RZ: " << pkt.rz() << endl;

	PlayerRef currentSession = currentPlayersMap[player->playerId];
	currentSession->px = pkt.px();
	currentSession->py = pkt.py();
	currentSession->pz = pkt.pz();
	currentSession->rx = pkt.rx();
	currentSession->ry = pkt.ry();
	currentSession->rz = pkt.rz();
	currentPlayersMap[player->playerId] = currentSession;

	Protocol::S_POSITION positionPkt;
	for (const auto& currentPlayer : currentPlayersMap) {
		Protocol::Player* playerMsg = positionPkt.add_currentallplayers();
		playerMsg->set_id(currentPlayer.second->playerId);
		playerMsg->set_name(currentPlayer.second->name);
		playerMsg->set_px(currentPlayer.second->px);
		playerMsg->set_py(currentPlayer.second->py);
		playerMsg->set_pz(currentPlayer.second->pz);
		playerMsg->set_rx(currentPlayer.second->rx);
		playerMsg->set_ry(currentPlayer.second->ry);
		playerMsg->set_rz(currentPlayer.second->rz);
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
	missilePkt.set_targetid(pkt.targetid());
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

