/***********************************************
**Author: Dylan Markovic
**Date:  12.2.2016
**Description:  Final "Cobra Room Header"
************************************************/
#ifndef COBRAROOM_HPP
#define COBRAROOM_HPP
#include "room.hpp"
#include "torch.hpp"
#include "cobra.hpp"
class cobraRoom : public room
{
private:
	pawn *flu;
	pawn *enemy[15];
public:
	cobraRoom(player *user);
	~cobraRoom();
	virtual void printMessage() const;
	virtual bool traverseRight();
	virtual void setRogueLeft();
	virtual void moveCharacters();
};
#endif
