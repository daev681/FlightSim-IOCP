#pragma once

class Player
{
public:

	uint64					playerId = 0;
	string					name;
	Protocol::PlayerType	type = Protocol::PLAYER_TYPE_NONE;
	GameSessionRef			ownerSession; // Cycle
	float                  px = 0;
	float                  py = 0;
	float                  pz = 0;
	float                  rx = 0;
	float                  ry = 0;
	float                  rz = 0;
};

