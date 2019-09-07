//#include "stdafx.h"
/*********************************************
**Author: Dylan Markovic
**Date: 11.30.16
**Description: Final "Snake Room Imp."
**********************************************/
#include "snakeRoom.hpp"
#include <iostream>
#include "snake.hpp"
#include "cobra.hpp"
#include "firePit.hpp"
#include "wall.hpp"


/********************************************************************
**Function:constructor
**Description: creates instance of snakeRoom
**Parameters: player*
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
snakeRoom::snakeRoom(player *user) : room(user)
{

	/*
	enemy = new snake;
	map[5][5] = enemy;
	this->enemy->setX(5);
	this->enemy->setY(5);
	*/

	//fill and place enemy array
	for (int i = 0; i < 15; i++)
	{
		enemy[i] = new snake;
		map[2 + i][5 + (2 * i)] = enemy[i];
		this->enemy[i]->setX(2 + i);
		this->enemy[i]->setY(5 + (2 * i));
	}

	//fill and place pit array
	for (int i = 0; i < 4; i++)
		pit[i] = new firePit;

		map[1][1] = pit[0];
		this->pit[0]->setX(1);
		this->pit[0]->setY(1);

		map[19][1] = pit[1];
		this->pit[1]->setX(19);
		this->pit[1]->setY(1);
	
		map[1][43] = pit[2];
		this->pit[2]->setX(1);
		this->pit[2]->setY(43);

		map[19][43] = pit[3];
		this->pit[3]->setX(19);
		this->pit[3]->setY(43);

		//place walls to indicate door openings
		map[9][1] = &wall1;
		map[11][1] = &wall1;
		map[9][2] = &wall1;
		map[11][2] = &wall1;

		map[9][42] = &wall1;
		map[11][42] = &wall1;
		map[9][43] = &wall1;
		map[11][43] = &wall1;

		map[1][20] = &wall1;
		map[1][22] = &wall1;
		map[2][20] = &wall1;
		map[2][22] = &wall1;
	
		map[18][20] = &wall1;
		map[18][22] = &wall1;
		map[19][20] = &wall1;
		map[19][22] = &wall1;
}

/********************************************************************
**Function:destructor
**Description: destroys instance of snakeRoom
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
snakeRoom::~snakeRoom()
{
	pawn *temp;
	for(int i = 0; i < 15; i++)
	{
		temp = enemy[i];
		enemy[i] = NULL;
		delete temp;
	}

	for(int i = 0; i < 4; i++)
	{
		temp = pit[i];
		pit[i] = NULL;
		delete temp;
	}
}
/********************************************************************
**Function:moveCharacters()
**Description: changes postions of characters in map array
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void snakeRoom::moveCharacters()
{
	controlPlayer();
	for(int i = 0; i < 15; i++)
		moveEnemy(enemy[i]);

}

/********************************************************************
**Function:setRogueTop()
**Description: places rogue at apropriate location after room switch
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void snakeRoom::setRogueTop()
{
	//snake room is the top pointer of the entryRoom,
	//place the rogue near the bottom entrance
	rogue->setX(18);
	rogue->setY(21);
	map[18][21] = rogue;
}

/********************************************************************
**Function:setRogueBottom()
**Description: places rogue at apropriate location after room switch
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void snakeRoom::setRogueBottom()
{
	//windRoom is the top pointer of the entryRoom,
	//place the rogue near the bottom entrance
	rogue->setX(2);
	rogue->setY(21);
	map[2][21] = rogue;
}
/********************************************************************
**Function:printMessage
**Description:prints room's message
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void snakeRoom::printMessage() const
{
	bool onFire = true;
	for (int i = 0; i < 4; i++)
	{
		if (pit[i]->getBody() == 'O')
			onFire = false;
	}
	if(onFire == false)
	std::cout << "\n               OH NO, SNAKES (S) !!!!"
			  <<"\nUsing your torch, Ligt the Oil Pits (O) on fire (*)\n";

	else
	{

		if (this->rogue->checkInventory("Flute") == true
			|| this->rogue->checkInventory("Bongo"))
			std::cout 
				<< "\nThe Snakes a scared and pacing about the fire!"
				<< "\n        Continue on your journey!\n";
		else
		std::cout 
			<< "\n              The Snakes hate fire!"
			<< "\nThey magically open the North, East, and West Doors"
			<< "\n  So you can leave before you start more fire!!!\n";
	}
}
/********************************************************************
**Function:traverse Bottom
**Description:checks if room should switch to its bottom pointer
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool
*******************************************************************/
bool snakeRoom::traverseBottom()
{
	/*
	*if the room *bottom is not Null
	*if rogue is in right location
	*move rogue to "bottom" room
	*/
	bool moveToBottom = false;
	if (this->bottom != NULL)
		if ((map[19][21] != NULL) && (map[19][21]->getBody() == '@'))
		{
			map[19][21] = NULL;
			moveToBottom = true;
		}
	return moveToBottom;
}
/********************************************************************
**Function:traverseTop
**Description:checks if room should switch to its top pointer
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool
*******************************************************************/
bool snakeRoom::traverseTop()
{
	/*
	*if the room *bottom is not Null
	*if rogue is in right location
	*move rogue to "bottom" room
	*/
	bool onFire = true;
	for (int i = 0; i < 4; i++)
	{
		if (pit[i]->getBody() == 'O')
			onFire = false;
	}
	bool moveToTop = false;
	if (this->top != NULL && onFire == true)
		if ((map[1][21] != NULL) && (map[1][21]->getBody() == '@'))
		{
			map[1][21] = NULL;
			moveToTop = true;
		}
	return moveToTop;
}


/********************************************************************
**Function:traverseLeft
**Description:checks if room should switch to its left pointer
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool
*******************************************************************/
bool snakeRoom::traverseLeft()
{
	/*
	*if the room *left is not Null
	*if rogue is in right location
	*move rogue to "bottom" room
	*if the fire pits are '*'
	*/
	bool onFire = true;
	for (int i = 0; i < 4; i++)
	{
		if (pit[i]->getBody() == 'O')
			onFire = false;
	}
	bool moveToLeft = false;
	if (this->left != NULL && onFire == true)
		if ((map[10][1] != NULL) && (map[10][1]->getBody() == '@'))
		{
			map[10][1] = NULL;
			moveToLeft = true;
		}
	return moveToLeft;
}
/********************************************************************
**Function:traverseRight
**Description:checks if room should switch to its right pointer
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool
*******************************************************************/
bool snakeRoom::traverseRight()
{
	/*
	*if the room *right is not Null
	*if rogue is in right location
	*move rogue to "right" room
	*if the fire pits are '*'
	*/
	bool onFire = true;
	for (int i = 0; i < 4; i++)
	{
		if (pit[i]->getBody() == 'O')
			onFire = false;
	}
	bool moveToRight = false;
	if (this->right != NULL && onFire == true)
		if ((map[10][43] != NULL) && (map[10][43]->getBody() == '@'))
		{
			map[10][43] = NULL;
			moveToRight = true;
		}
	return moveToRight;
}

/********************************************************************
**Function:setRogueRight()
**Description: places rogue at apropriate location after room switch
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void snakeRoom::setRogueRight()
{
	//snake room is the top pointer of the entryRoom,
	//place the rogue near the bottom entrance
	rogue->setX(10);
	rogue->setY(2);
	map[10][2] = rogue;
}

/********************************************************************
**Function:setRogueLeft()
**Description: places rogue at apropriate location after room switch
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void snakeRoom::setRogueLeft()
{
	//snake room is the left pointer of the rattleRoom,
	//place the rogue near the right entrance
	rogue->setX(10);
	rogue->setY(42);
	map[10][42] = rogue;
}


