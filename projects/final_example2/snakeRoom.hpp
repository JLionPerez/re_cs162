/*********************************************
**Author: Dylan Markovic
**Date: 11.30.16
**Description: Final "Snake Room Header"
**********************************************/
#ifndef SNAKEROOM_HPP
#define SNAKEROOM_HPP
#include "room.hpp"
#include "player.hpp"
#include "pawn.hpp"
class snakeRoom : public room
{
private:
	pawn *enemy[15];
	pawn *pit[4];
public:
	snakeRoom(player *user);
	~snakeRoom();
	virtual void moveCharacters();
	virtual void setRogueTop();
	virtual void setRogueLeft();
	virtual void setRogueRight();
	virtual void setRogueBottom();
	virtual void printMessage() const;
	virtual bool traverseTop();
	virtual bool traverseBottom();
	virtual bool traverseLeft();
	virtual bool traverseRight();
};
#endif
