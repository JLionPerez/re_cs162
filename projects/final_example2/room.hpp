/*********************************************
**Author: Dylan Markovic
**Date: 11.30.16
**Description: Final "Room Header"
**********************************************/
#include "pawn.hpp"
#include "player.hpp"
#include "snake.hpp"
#include "cobra.hpp"
#include "wall.hpp"

#ifndef ROOM_HPP
#define ROOM_HPP
class room
{
protected:
	 room *top;				//room above current instance
	 room *bottom;			//room below current instance
	 room *left;				//room left of current instance
	 room *right;			//room right of current instance
	int rows;
	int cols;
	pawn ***map;
	player *rogue;
	wall wall1;
	
	

public:
	room(player *user);
	virtual ~room() = 0;
	virtual void printRoom() const;
	virtual void moveCharacters();
	void controlPlayer();
	void moveEnemy(pawn*);
	virtual room* getRight() const;
	virtual room* getLeft() const;
	virtual room* getTop() const;
	virtual room* getBottom() const;
	virtual void setRight(room*);
	virtual void setLeft(room*);
	virtual void setTop(room*);
	virtual void setBottom(room*);
	virtual void printMessage() const;
	virtual bool traverseTop();
	virtual bool traverseBottom();
	virtual bool traverseRight();
	virtual bool traverseLeft();
	virtual void setRogueTop();
	virtual void setRogueBottom();
	virtual void setRogueLeft();
	virtual void setRogueRight();
	

};
#endif
