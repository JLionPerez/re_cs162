//#include "stdafx.h"
/*****************************************************************
**Author: Dylan Markovic
**Date: 12.6.2016
**Description: Final "Rattle Room Imp File"
******************************************************************/
#include "pawn.hpp"
#include "bongo.hpp"
#include <iostream>
#include "wall.hpp"
#include "rattleSnake.hpp"
#include "rattleRoom.hpp"

/********************************************************************
**Function:constructor
**Description: creates instance of rattleRoom
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
rattleRoom::rattleRoom(player *user) : room(user)
{
	bon = new bongo;
	map[18][42] = bon;

	//place cobras
	for (int i = 0; i < 15; i++)
	{
		enemy[i] = new rattleSnake;
		map[4 + i][1 + (3 * i)] = enemy[i];
		this->enemy[i]->setX(4 + i);
		this->enemy[i]->setY(1 + (3 * i));
	}

	//place walls to indicate door
	map[9][1] = &wall1;
	map[11][1] = &wall1;
	map[9][2] = &wall1;
	map[11][2] = &wall1;


}

/********************************************************************
**Function:destructor
**Description: destroys instance of rattleRoom
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
rattleRoom::~rattleRoom()
{
	if(rogue->checkInventory("Bongo") == false)
		{
		map[18][42] = NULL;
		delete bon;
		}

	pawn *temp;
	for(int i = 0; i < 15; i++)
	{
		temp = enemy[i];
		enemy[i] = NULL;
		delete temp;
	}
}
/********************************************************************
**Function:printMessage
**Description: prints Message to screen
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void rattleRoom::printMessage() const
{
	bool hasBongo = false;
	for (int i = 0; i < 6; i++)
		if (rogue->checkInventory("Bongo") == true)
		{
			hasBongo = true;
		}

	if (hasBongo == false)
	{
		std::cout 
			<< "\n             OH NO RATTLE SNAKES (&) !!!!!"
			<< "\n         Maybe the Rattle Snakes will be nice"
			<<"\n          If you grab and play the Bongos(w)!\n";
	}
	else
	{
		std::cout 
			<< "\n         The Rattle Snakes Hate Bongos"
			<< "\n       They bring you the Ruby Snake Eye"
			<< "\n         To make you stop playing!\n";

		if (this->rogue->checkInventory("Ruby Eye") == false)
			this->rogue->addToInventory("Ruby Eye");

	}
}

/********************************************************************
**Function:TraverseLeft
**Description: checks if the player should move to Top Room
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool
*******************************************************************/
bool rattleRoom::traverseLeft()
{
	/*
	*if the room *left is not Null
	*and if the rogue's position is correct
	* switch to the room "next" to the entryRoom
	*/
	bool moveToLeft = false;
	if (this->left != NULL)
		if ((map[10][1] != NULL) && (map[10][1]->getBody() == '@'))
		{
			map[10][1] = NULL;
			moveToLeft = true;
		}
	return moveToLeft;
}

/********************************************************************
**Function:setRogueRight
**Description: positions rogue apropriately when traveling back into room
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void rattleRoom::setRogueRight()
{
	//snakeRoom is the right pointer of the rattleRoom,
	//place the rogue near the entrance
	rogue->setX(10);
	rogue->setY(2);
	map[10][2] = rogue;
}

/********************************************************************
**Function:moveCharacters()
**Description: changes postions of characters in map array
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void rattleRoom::moveCharacters()
{
	controlPlayer();
	for (int i = 0; i < 15; i++)
		moveEnemy(enemy[i]);

}
