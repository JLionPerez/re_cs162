//#include "stdafx.h"
/*****************************************************************
**Author: Dylan Markovic
**Date: 12.6.2016
**Description: Final "Cobra Room Imp File"
******************************************************************/
#include "pawn.hpp"
#include "flute.hpp"
#include <iostream>
#include "wall.hpp"
#include "cobra.hpp"
#include "cobraRoom.hpp"

/********************************************************************
**Function:constructor
**Description: creates instance of cobraRoom
**Parameters:player*
**Pre-Conditions: none
**Post-Conditions: none
***Return: none
*******************************************************************/
cobraRoom::cobraRoom(player *user) : room(user)
{
	flu = new flute;
	map[10][2] = flu;
	
	//place cobras
	
	
	for (int i = 0; i < 15; i++)
	{
		enemy[i] = new cobra;
		map[19-i][1 + (3*i)] = enemy[i];
		this->enemy[i]->setX(19-i);
		this->enemy[i]->setY(1 + (3*i));
	}

	//place walls to indicate door
	map[9][42] = &wall1;
	map[11][42] = &wall1;
	map[9][43] = &wall1;
	map[11][43] = &wall1;


}

/********************************************************************
**Function:destructor
**Description: destroys instance of cobraRoom
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
cobraRoom::~cobraRoom()
{
//flute is deleted when rogue collects it, which is necessary to complete game
if(rogue->checkInventory("Flute") == false)
	{
		map[10][2] = NULL;
		delete flu;
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
**Description: Prints rooms message
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void cobraRoom::printMessage() const
{
	bool hasFlute = false;
	for (int i = 0; i < 6; i++)
		if (rogue->checkInventory("Flute") == true)
		{
			hasFlute = true;
		}

	if (hasFlute == false)
	{
		std::cout 
			<< "\n                OH NO COBRAS (6) !!!!!"
			<< "\n     You better grab and play the flute(f)\n";
	}
	else
	{
		std::cout 
			<< "\n           The Cobras dig your music"
			<< "\n      They bring you the Emerald Snake Eye\n";
		if(this->rogue->checkInventory("Emerald Eye") == false)
			this->rogue->addToInventory("Emerald Eye");

	}
}

/********************************************************************
**Function:TraverseRight
**Description: checks if the cobraRoom should move to right Room
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool
*******************************************************************/
bool cobraRoom::traverseRight()
{
	/*
	*if the room *right is not Null
	*and if the rogue's position is correct
	* switch to the room "next" to the entryRoom
	*/
	bool moveToRight = false;
	if (this->right != NULL)
		if ((map[10][43] != NULL) && (map[10][43]->getBody() == '@'))
		{
			map[10][43] = NULL;
			moveToRight = true;
		}
	return moveToRight;
}

/********************************************************************
**Function:setRogueleft
**Description: positions rogue apropriately when traveling back into cobraRoom
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void cobraRoom::setRogueLeft()
{
	//entryRoom is the bottom pointer of the snakeRoom,
	//place the rogue near the entrance
	rogue->setX(10);
	rogue->setY(42);
	map[10][42] = rogue;
}

/********************************************************************
**Function:moveCharacters()
**Description: changes postions of characters in map array
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void cobraRoom::moveCharacters()
{
	controlPlayer();
	for (int i = 0; i < 15; i++)
		moveEnemy(enemy[i]);

}
