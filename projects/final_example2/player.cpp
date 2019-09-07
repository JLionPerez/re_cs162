//#include "stdafx.h"
/*********************************************
**Author: Dylan Markovic
**Date: 11.30.16
**Description: Final "player Implementation"
**********************************************/
#include "player.hpp"
#include <string>
#include <iostream>

/********************************************************************
**Function:constructor
**Description: creates instance of player
**Parameters: int x and int y
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
player::player() : pawn()
{
	this->body = '@';
	this->health = 800;
	for (int i = 0; i < 6; i++)
		this->inventory[i] = "";
}

/********************************************************************
**Function:destructor
**Description: destroys instance of player
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
player::~player()
{
}
/********************************************************************
**Function:addToInventory
**Description: adds string to inventory
**Parameters: string
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void player::addToInventory(std::string s)
{
	bool isPlaced = false;
	int index = 0;
		while (isPlaced == false)
		{
			if (inventory[index] == "")
			{
				inventory[index] = s;
				isPlaced = true;
			}
			index++;
		}
		//std::cout << "\na "<< s <<" has been placed in the rogue's inventory\n";
}
/********************************************************************
**Function:checkInventory
**Description: checks if string exists in inventory
**Parameters: string
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool
*******************************************************************/
bool player::checkInventory(std::string s)
{
	bool isFound = false;
	for (int i = 0; i < 6; i++)
	{
		if (inventory[i] == s)
			isFound = true;
	}

	return isFound;
}

/********************************************************************
**Function:printInventory
**Description: prints iventory
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void player::printInventory() const
{
	std::cout << "\nInventory:";
	for (int i = 0; i < 6; i++)
	{
		std::cout << " ";
		std::cout << inventory[i];
	}
		
}
/********************************************************************
**Function:decreaseHealth
**Description: decreases health by 1;
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void player::decreaseHealth()
{
	health--;
}

/********************************************************************
**Function:getHealth
**Description: return health
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: integer
*******************************************************************/
int player::getHealth()
{
	return health;
}

/********************************************************************
**Function:kill
**Description: sets player health to 0
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void player::kill()
{
	health = 0;
}
