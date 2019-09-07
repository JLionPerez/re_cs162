#pragma once
#include "room.hpp"
#include "player.hpp"
class testRoom :
	public room
{
public:
	testRoom(player*);
	~testRoom();
};

