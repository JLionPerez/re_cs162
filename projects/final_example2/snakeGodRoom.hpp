/*********************************************
**Author: Dylan Markovic
**Date: 11.30.16
**Description: Final "Snake God Room Header"
**********************************************/
#ifndef SNAKEGODROOM_HPP
#define SNAKEGODROOM_HPP
#include "room.hpp"
#include "player.hpp"
#include "pawn.hpp"
class snakeGodRoom : public room
{
private:
public:
	snakeGodRoom(player *user);
	~snakeGodRoom();
	virtual void setRogueTop();
	virtual void printMessage() const;
	virtual bool traverseBottom();
	virtual void printRoom() const;
};
#endif
