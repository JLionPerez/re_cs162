/***********************************************
**Author: Dylan Markovic
**Date:  12.2.2016
**Description:  Final "Entry Room Header"
************************************************/
#ifndef ENTRYROOM_HPP
#define ENTRYROOM_HPP
#include "room.hpp"
#include "torch.hpp"
class entryRoom : public room
{
private:
	pawn *enemy;
public:
	entryRoom(player *user);
	~entryRoom();
	virtual void printMessage() const;
	virtual bool traverseTop();
	virtual void setRogueBottom();
};
#endif
