//#include "stdafx.h"
/*****************************************************************
**Author: Dylan Markovic
**Date: 12.6.2016
**Description: Final "Entry Room Imp File"
******************************************************************/
#include "entryRoom.hpp"
#include "pawn.hpp"
#include "torch.hpp"
#include <iostream>
#include "wall.hpp"
/********************************************************************
**Function:constructor
**Description: creates instance of entryRoom
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
entryRoom::entryRoom(player *user) : room(user)
{
	map[2][3] = user;
	this->rogue->setX(2);
	this->rogue->setY(3);

	enemy = new torch;
	map[15][30] = enemy;

	map[10][22] = &wall1;
	map[9][22] = &wall1;
	map[11][22] = &wall1;
	map[10][23] = &wall1;
	map[9][23] = &wall1;
	map[11][23] = &wall1;

	map[10][20] = &wall1;
	map[9][20] = &wall1;
	map[11][20] = &wall1;
	map[10][19] = &wall1;
	map[9][19] = &wall1;
	map[11][19] = &wall1;

	map[9][21] = &wall1;
}

/********************************************************************
**Function:destructor
**Description: destroys instance of entryRoom
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
entryRoom::~entryRoom()
{
	if(rogue->checkInventory("Torch") == false)
	{
		map[15][30] = NULL;
		delete enemy;
	}
}

/********************************************************************
**Function:printMessage
**Description: prints room's message
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void entryRoom::printMessage() const
{
	bool hasTorch = false;
	for(int i = 0; i < 6; i++)
		if (rogue->checkInventory("Torch") == true)
		{
			hasTorch = true;
		}

	if(hasTorch == false)
		{
			std::cout 
				<< "\n               The Serpent Temple is dark"
				<< "\n             You better grab the torch(i)\n";
		}
	else
		{
			std::cout 
				<< "\n            The Torch will light"
				<< "\n             The Serpent Temple\n";
		}
}

/********************************************************************
**Function:traverseTop()
**Description: checks if the entryRoom should move to Top Room
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool
*******************************************************************/
bool entryRoom::traverseTop() 
{
	/*
	*if the room *top is not Null
	*if the rogue's inventory has a torch
	*and if the rogue's position is correct
	* switch to the room "above" the entryRoom
	*/
	bool moveToTop = false;
	if((this->top != NULL) && (this->rogue->checkInventory("Torch") == true))
		if ((map[10][21] != NULL) && (map[10][21]->getBody() == '@'))
		{
			map[10][21] = NULL;
			moveToTop = true;
		}
	return moveToTop;
}

/********************************************************************
**Function:setRogueBottom
**Description: positions rogue apropriately when traveling back into entryRoom
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void entryRoom::setRogueBottom()
{
	//entryRoom is the bottom pointer of the snakeRoom,
	//place the rogue near the entrance
	rogue->setX(11);
	rogue->setY(21);
	map[11][21] = rogue;
}
