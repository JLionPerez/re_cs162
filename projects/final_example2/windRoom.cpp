//#include "stdafx.h"
/*****************************************************************
**Author: Dylan Markovic
**Date: 12.6.2016
**Description: Final "Wind Room Imp File"
******************************************************************/
#include "windRoom.hpp"
#include "pawn.hpp"
#include "wind.hpp"
#include <iostream>
#include "wall.hpp"
/********************************************************************
**Function:constuctor
**Description:creates instance of windroom
**Parameters:player*
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
windRoom::windRoom(player *user) : room(user)
{
	//walls to indicate doors
	map[1][20] = &wall1;
	map[1][22] = &wall1;
	map[2][20] = &wall1;
	map[2][22] = &wall1;

	map[18][20] = &wall1;
	map[18][22] = &wall1;
	map[19][20] = &wall1;
	map[19][22] = &wall1;

	//wind arrays
	for (int i = 0; i < 15; i++)
	{

		//create columns of wind to block rogue
		//until he has finished other rooms
		enemy1[i] = new wind;
		map[3 + i][20] = enemy1[i];

		enemy2[i] = new wind;
		map[3 + i][21] = enemy2[i];
	}
}

/********************************************************************
**Function:destructor
**Description:destroys instance of windroom
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
windRoom::~windRoom()
{
	pawn *temp;
	for(int i = 0; i <15; i++)
	{
		temp = enemy1[i];
		enemy1[i] = NULL;
		delete temp;

		temp = enemy2[i];
		enemy2[i] = NULL;
		delete temp;
	}
}

/********************************************************************
**Function:printMessage
**Description:prints room's message
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void windRoom::printMessage() const
{
	bool hasEyes = false;
	for (int i = 0; i < 6; i++)
		if (rogue->checkInventory("Ruby Eye") == true
			&& rogue->checkInventory("Emerald Eye") == true)
		{
			hasEyes = true;
		}

	if (hasEyes == false)
	{
		std::cout << "\nMighty winds (~) block you from going any farther"
				  << "\n           You Hear a voice say:"
				  << "\n    Only Those with Snake Eyes may enter!!!\n";
	}
	else
	{
		for (int i = 0; i < 15; i++)
		{

			//move column of wind to unblock rogue
			map[3 + i][22] = enemy2[i];
			if (map[3 + i][21] != NULL && map[3 + i][21]->getBody() != '@')
			map[3 + i][21] = NULL;
		}
		std::cout << "\n  The Winds (~) have parted"
				  << "\n    You Hear a voice say:"
				  << "\nI See Your Eyes, Please Enter\n";
	}
}

/********************************************************************
**Function:traverseTop()
**Description: checks if the room should move to Top Room
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool
*******************************************************************/
bool windRoom::traverseTop()
{
	/*
	*if the room *top is not Null
	*and if the rogue's position is correct
	* switch to the room "above" the windRoom
	*/
	
	bool moveToTop = false;
	if (this->top != NULL == true)
		if ((map[1][21] != NULL) && (map[1][21]->getBody() == '@'))
		{
			map[1][21] = NULL;
			moveToTop = true;
		}
	return moveToTop;
}

/********************************************************************
**Function:setRogueBottom
**Description: positions rogue apropriately when traveling back into windRoom
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return:none
*******************************************************************/
void windRoom::setRogueBottom()
{
	//bossRoom is the top pointer of the windRoom,
	//place the rogue near the top entrance
	rogue->setX(2);
	rogue->setY(21);
	map[2][21] = rogue;
}
/********************************************************************
**Function:setRogueTop
**Description: positions rogue apropriately when traveling back into windRoom
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void windRoom::setRogueTop()
{
	//snake room is the bottom pointer of the entryRoom,
	//place the rogue near the bottom entrance
	rogue->setX(18);
	rogue->setY(21);
	map[18][21] = rogue;
}
/********************************************************************
**Function:traverseBottom
**Description: checks if room should switch to bottom pointer
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool
*******************************************************************/
bool windRoom::traverseBottom()
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
