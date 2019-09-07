/***********************************************
**Author: Dylan Markovic
**Date:  12.2.2016
**Description:  Final "Rattle Room Header"
************************************************/
#ifndef RATTLEROOM_HPP
#define RATTLEROOM_HPP
#include "room.hpp"

class rattleRoom : public room
{
private:
	pawn *bon;
	pawn *enemy[15];
public:
	rattleRoom(player *user);
	~rattleRoom();
	virtual void printMessage() const;
	virtual bool traverseLeft();
	virtual void setRogueRight();
	virtual void moveCharacters();
};
#endif