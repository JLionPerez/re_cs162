//#include "stdafx.h"
/*********************************************
**Author: Dylan Markovic
**Date: 11.30.16
**Description: Final "Snake God Room Imp."
**********************************************/
#include "snakeGodRoom.hpp"
#include <iostream>
#include "wall.hpp"
#include <iostream>


/********************************************************************
**Function:constructor
**Description: creates instance of snakeGodRoom
**Parameters:player*
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
snakeGodRoom::snakeGodRoom(player *user) : room(user)
{

	/*
	enemy = new snake;
	map[5][5] = enemy;
	this->enemy->setX(5);
	this->enemy->setY(5);
	*/

	//place walls to indicate door openings

	map[18][20] = &wall1;
	map[18][22] = &wall1;
	map[19][20] = &wall1;
	map[19][22] = &wall1;

	//place walls to create small subroom
	map[18][19] = &wall1;
	map[18][17] = &wall1;
	map[18][18] = &wall1;
	map[17][17] = &wall1;
	map[16][17] = &wall1;
	map[15][17] = &wall1;
	map[15][18] = &wall1;
	map[15][19] = &wall1;
	map[15][20] = &wall1;
	map[15][21] = &wall1;
	map[15][22] = &wall1;
	map[15][23] = &wall1;
	map[15][24] = &wall1;
	map[16][24] = &wall1;
	map[17][24] = &wall1;
	map[18][24] = &wall1;
	map[18][23] = &wall1;
}

/********************************************************************
**Function:destructor
**Description: destroys instance ofsnakeGodRoom
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
snakeGodRoom::~snakeGodRoom()
{
}


/********************************************************************
**Function:setRogueTop()
**Description: places rogue at apropriate location after room switch
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void snakeGodRoom::setRogueTop()
{
	//snake room is the top pointer of the entryRoom,
	//place the rogue near the bottom entrance
	rogue->setX(18);
	rogue->setY(21);
	map[18][21] = rogue;
}

/********************************************************************
**Function:printMessage
**Description:prints room's message
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void snakeGodRoom::printMessage() const
{
	if(this->rogue->checkInventory("\n		Snake God's Cure") == false)
		this->rogue->addToInventory("\n		Snake God's Cure");

	std::cout 
		<< "\n        The Snake God See's you've attained"
		<< "\n               The Eyes of the Snake "
		<< "\n        Without Harming his serpent children"
		<< "\n          For this, he gives you the cure"
		<< "\n   Go back to your village, and save your people\n";
	
}
/********************************************************************
**Function:traverseBottoms
**Description:checks if room should switch to its bottom pointer
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool
*******************************************************************/
bool snakeGodRoom::traverseBottom()
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
**Function:printRoom
**Description:prints image of Snake God and usable portion of map
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void snakeGodRoom::printRoom() const
{
	printMessage();

	this->rogue->printInventory();//print player inventory
	std::cout << "\n";
	std::cout
		<< "\n             ______"
		<< "\n            / _____>}}}}}}"
		<< "\n            | |___________"
		<< "\n            \\____________ \\ "
		<< "\n             _____________| | "
		<< "\n            /  ___________ / "
		<< "\n            | |___________ "
		<< "\n            \\____________ \\ "
		<< "\n              ____________| | "
		<< "\n             / ___________ / "
		<< "\n             | | _____ "
		<< "\n             \\_____   \\ "
		<< "\n                    \\   \\ "
		<< "\n                    |   | "
		<< "\n                   /     \\ "
		<< "\n                  | _   _ | "
		<< "\n                  \\ \\\\ // / "
		<< "\n                   \\_____/ "
		<< "\n                     V V \n";
	std::cout << " ";
	//for (int j = 0; j < cols; j++)		//use for coordinates
		//std::cout << j % 10;
	std::cout << "\n";
	for (int i = 15; i < rows; i++)
	{
		//std::cout << i % 10;				//use for coordinates
		for (int j = 0; j < cols; j++)
		{
			if (map[i][j] == NULL)
				std::cout << '.';
			else
				std::cout << map[i][j]->getBody();
		}
		std::cout << "\n";
	}
	std::cout << "\n      w = up    d = right     Press e to"
		<< "\n      s = down  a = left       interact";
}








