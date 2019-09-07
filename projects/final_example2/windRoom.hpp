/***********************************************
**Author: Dylan Markovic
**Date:  12.2.2016
**Description:  Final "Wind Room Header"
************************************************/
#ifndef WINDROOM_HPP
#define WINDROOM_HPP
#include "room.hpp"
#include "wind.hpp"
class windRoom : public room
{
private:
	pawn *enemy1[15];
	pawn *enemy2[15];
public:
	windRoom(player *user);
	~windRoom();
	virtual void printMessage() const;
	virtual bool traverseTop();
	virtual bool traverseBottom();
	virtual void setRogueBottom();
	virtual void setRogueTop();
};
#endif
