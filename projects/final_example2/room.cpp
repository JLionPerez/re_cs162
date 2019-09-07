//#include "stdafx.h"
/*********************************************
**Author: Dylan Markovic
**Date: 11.30.16
**Description: Final "Room implementation"
**********************************************/
#include "room.hpp"
#include "pawn.hpp"
#include "wall.hpp"
#include <iostream>
#include "player.hpp"
#include <cmath>
#include "utlty.hpp"



/********************************************************************
**Function:room constructor
**Description: creates instance of room
**Parameters: 4 room*, int rows and int cols
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
room::room(player *user)
{
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
	rows = 21;
	cols = 45;
	rogue = user;
	

	//create empty map
	map = new pawn**[rows];
	for (int i = 0; i < rows; i++)
		map[i] = new pawn*[cols];

	//set all map elements to NULL
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			map[i][j] = NULL;

	//make edges of map wall1
	for (int i = 0; i < rows; i++)
	{
		map[i][0] = &wall1;
		map[i][cols - 1] = &wall1;
	}
	for (int j = 1; j < cols-1; j++)
	{
		map[0][j] = &wall1;
		map[rows - 1][j] = &wall1;
	}

}

/********************************************************************
**Function:destructor
**Description: destroys instance of room
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return:none
*******************************************************************/
room::~room()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = NULL;
			delete map[i][j]; // delete stored pointer
		}
		delete[] map[i]; // delete sub array
	}
	delete[] map; //delete outer array
	//std::cout << "\nthe map has been destroyed\n";
	map = NULL;

}

/********************************************************************
**Function:printRoom()
**Description: prints body values of map pawns
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void room::printRoom() const
{
	printMessage();

	this->rogue->printInventory();//print player inventory
	std::cout << "\nCurrent Health: " << this->rogue->getHealth() << "\n";//print health
	//for (int j = 0; j < cols; j++)		//use for coordinates
		//std::cout << j%10;
	std::cout << "\n";
	for (int i = 0; i < rows; i++)
	{
		//std::cout << i%10;				//use for coordinates
		for (int j = 0; j < cols; j++)
		{
			if (map[i][j] == NULL)
				std::cout << '.';
			else
				std::cout << map[i][j]->getBody();
		}
		std::cout << "\n";
	}
	std::cout << "\n      3 = up    4 = right     Press 5 to"
		<< "\n      2 = down  1 = left       interact";

}
/********************************************************************
**Function:moveCharacters()
**Description: changes postions of characters in map array
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void room::moveCharacters()
{
	controlPlayer();
}

/********************************************************************
**Function:moveplayer()
**Description: changes postions of player in map array
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void room::controlPlayer()
{
	int control = -1;
	
	while (control < 1 || control >5)
	{
		std::cout << "\nEnter Single Input(1, 2, 3, 4, or 5): ";
		control = intCheck();
	}
		
	
		switch (control)
		{
			//move right
		case 4: if (rogue->getY() < cols - 1)
		{
			if (map[rogue->getX()][rogue->getY() + 1] == NULL)
			{
				map[rogue->getX()][rogue->getY() + 1] = rogue;
				map[rogue->getX()][rogue->getY()] = NULL;
				rogue->setY(rogue->getY() + 1);
			}
		}
				  break;

				  //move down
		case 2: if (rogue->getX() < rows - 1)
		{
			if (map[rogue->getX() + 1][rogue->getY()] == NULL)
			{
				map[rogue->getX() + 1][rogue->getY()] = rogue;
				map[rogue->getX()][rogue->getY()] = NULL;
				rogue->setX(rogue->getX() + 1);
			}
		}
				  break;

				  //move left
		case 1: if (rogue->getY() > 0)
		{
			if (map[rogue->getX()][rogue->getY() - 1] == NULL)
			{
				map[rogue->getX()][rogue->getY() - 1] = rogue;
				map[rogue->getX()][rogue->getY()] = NULL;
				rogue->setY(rogue->getY() - 1);
			}
		}
				  break;

				  //move up
		case 3: if (rogue->getX() < rows - 1)
		{
			if (map[rogue->getX() - 1][rogue->getY()] == NULL)
			{
				map[rogue->getX() - 1][rogue->getY()] = rogue;
				map[rogue->getX()][rogue->getY()] = NULL;
				rogue->setX(rogue->getX() - 1);
			}
		}
				  break;
		
		
		case 5:
			//torch interaction
			if (map[rogue->getX() + 1][rogue->getY()] != NULL
				&& map[rogue->getX() + 1][rogue->getY()]->getBody() == 'i')
			{
				rogue->addToInventory(map[rogue->getX() + 1][rogue->getY()]->getName());
				pawn *temp = map[rogue->getX() + 1][rogue->getY()];
				map[rogue->getX() + 1][rogue->getY()] = NULL;
				delete temp;
			}


			else if (map[rogue->getX() - 1][rogue->getY()] != NULL
					&& map[rogue->getX() - 1][rogue->getY()]->getBody() == 'i')
			{
				rogue->addToInventory(map[rogue->getX() - 1][rogue->getY()]->getName());
				pawn *temp = map[rogue->getX() - 1][rogue->getY()];
				map[rogue->getX() - 1][rogue->getY()] = NULL;
				delete temp;
			}


			else if (map[rogue->getX()][rogue->getY() +1] != NULL
					&& map[rogue->getX()][rogue->getY() + 1]->getBody() == 'i')
			{
				rogue->addToInventory(map[rogue->getX()][rogue->getY() + 1]->getName());
				pawn *temp = map[rogue->getX()][rogue->getY() +1];
				map[rogue->getX()][rogue->getY() +1] = NULL;
				delete temp;
			}


			else if (map[rogue->getX()][rogue->getY() - 1] != NULL
					&& map[rogue->getX()][rogue->getY() - 1]->getBody() == 'i')
			{
				rogue->addToInventory(map[rogue->getX()][rogue->getY() - 1]->getName());
				pawn *temp = map[rogue->getX()][rogue->getY() - 1];
				map[rogue->getX()][rogue->getY() - 1] = NULL;
				delete temp;
			}




			////////flute interaction
			if (map[rogue->getX() + 1][rogue->getY()] != NULL
				&& map[rogue->getX() + 1][rogue->getY()]->getBody() == 'f')
			{
				rogue->addToInventory(map[rogue->getX() + 1][rogue->getY()]->getName());
				pawn *temp = map[rogue->getX() + 1][rogue->getY()];
				map[rogue->getX() + 1][rogue->getY()] = NULL;
				delete temp;
			}


			else if (map[rogue->getX() - 1][rogue->getY()] != NULL
				&& map[rogue->getX() - 1][rogue->getY()]->getBody() == 'f')
			{
				rogue->addToInventory(map[rogue->getX() - 1][rogue->getY()]->getName());
				pawn *temp = map[rogue->getX() - 1][rogue->getY()];
				map[rogue->getX() - 1][rogue->getY()] = NULL;
				delete temp;
			}


			else if (map[rogue->getX()][rogue->getY() + 1] != NULL
				&& map[rogue->getX()][rogue->getY() + 1]->getBody() == 'f')
			{
				rogue->addToInventory(map[rogue->getX()][rogue->getY() + 1]->getName());
				pawn *temp = map[rogue->getX()][rogue->getY() + 1];
				map[rogue->getX()][rogue->getY() + 1] = NULL;
				delete temp;
			}


			else if (map[rogue->getX()][rogue->getY() - 1] != NULL
				&& map[rogue->getX()][rogue->getY() - 1]->getBody() == 'f')
			{
				rogue->addToInventory(map[rogue->getX()][rogue->getY() - 1]->getName());
				pawn *temp = map[rogue->getX()][rogue->getY() - 1];
				map[rogue->getX()][rogue->getY() - 1] = NULL;
				delete temp;
			}





			//////Bongo interaction

			if (map[rogue->getX() + 1][rogue->getY()] != NULL
				&& map[rogue->getX() + 1][rogue->getY()]->getBody() == 'w')
			{
				rogue->addToInventory(map[rogue->getX() + 1][rogue->getY()]->getName());
				pawn *temp = map[rogue->getX() + 1][rogue->getY()];
				map[rogue->getX() + 1][rogue->getY()] = NULL;
				delete temp;
			}


			else if (map[rogue->getX() - 1][rogue->getY()] != NULL
				&& map[rogue->getX() - 1][rogue->getY()]->getBody() == 'w')
			{
				rogue->addToInventory(map[rogue->getX() - 1][rogue->getY()]->getName());
				pawn *temp = map[rogue->getX() - 1][rogue->getY()];
				map[rogue->getX() - 1][rogue->getY()] = NULL;
				delete temp;
			}


			else if (map[rogue->getX()][rogue->getY() + 1] != NULL
				&& map[rogue->getX()][rogue->getY() + 1]->getBody() == 'w')
			{
				rogue->addToInventory(map[rogue->getX()][rogue->getY() + 1]->getName());
				pawn *temp = map[rogue->getX()][rogue->getY() + 1];
				map[rogue->getX()][rogue->getY() + 1] = NULL;
				delete temp;
			}


			else if (map[rogue->getX()][rogue->getY() - 1] != NULL
				&& map[rogue->getX()][rogue->getY() - 1]->getBody() == 'w')
			{
				rogue->addToInventory(map[rogue->getX()][rogue->getY() - 1]->getName());
				pawn *temp = map[rogue->getX()][rogue->getY() - 1];
				map[rogue->getX()][rogue->getY() - 1] = NULL;
				delete temp;
			}







			/////firePit interaction


			if (map[rogue->getX() + 1][rogue->getY()] != NULL
				&& map[rogue->getX() + 1][rogue->getY()]->getBody() == 'O')
			{
				map[rogue->getX() + 1][rogue->getY()]->setBody('*');
			}


			else if (map[rogue->getX() - 1][rogue->getY()] != NULL
				&& map[rogue->getX() - 1][rogue->getY()]->getBody() == 'O')
			{
				map[rogue->getX() - 1][rogue->getY()]->setBody('*');
			}


			else if (map[rogue->getX()][rogue->getY() + 1] != NULL
				&& map[rogue->getX()][rogue->getY() + 1]->getBody() == 'O')
			{
				map[rogue->getX()][rogue->getY() + 1]->setBody('*');
			}


			else if (map[rogue->getX()][rogue->getY() - 1] != NULL
				&& map[rogue->getX()][rogue->getY() - 1]->getBody() == 'O')
			{
				map[rogue->getX()][rogue->getY() - 1]->setBody('*');
			}
			break;
		}
	
}

/********************************************************************
**Function:moveEnemy()
**Description: changes postions of enemy in map array
**Parameters: character*
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void room::moveEnemy(pawn *enemy)
{
	if (enemy != NULL)			//make sure enemy is still alive
	{
		switch (enemy->getBody())			//different enemies move differently
		{
		case 'S': //snakes move left and right
			if ((enemy->getY() < cols - 1) && enemy->getDirection() == true)
			{
				if (map[enemy->getX()][enemy->getY() + 1] == NULL)
				{
					map[enemy->getX()][enemy->getY() + 1] = enemy;
					map[enemy->getX()][enemy->getY()] = NULL;
					enemy->setY(enemy->getY() + 1);
				}
				else
				{
					enemy->setDirection(false);	//something blocking snake, start leftward motion
				}
			}
			else
			{
				if (enemy->getY() > 0)
				{
					if (map[enemy->getX()][enemy->getY() - 1] == NULL)
					{
						map[enemy->getX()][enemy->getY() - 1] = enemy;
						map[enemy->getX()][enemy->getY()] = NULL;
						enemy->setY(enemy->getY() - 1);
					}
					else
					{
						enemy->setDirection(true);	//something blocking snake, start rightward motion
					}
				}
			}
			break;


		case '6':		//cobras move up and down
			if ((enemy->getX() < rows - 1) && enemy->getDirection() == true)
			{
				if (map[enemy->getX() - 1][enemy->getY()] == NULL)
				{
					map[enemy->getX() - 1][enemy->getY()] = enemy;
					map[enemy->getX()][enemy->getY()] = NULL;
					enemy->setX(enemy->getX() - 1);
				}
				else
				{
					enemy->setDirection(false);	//something blocking cobra, start leftward motion
				}
			}
			else
			{
				if (enemy->getX() > 0)
				{
					if (map[enemy->getX() + 1][enemy->getY()] == NULL)
					{
						map[enemy->getX() + 1][enemy->getY()] = enemy;
						map[enemy->getX()][enemy->getY()] = NULL;
						enemy->setX(enemy->getX() + 1);
					}
					else
					{
						enemy->setDirection(true);	//something blocking snake, start rightward motion
					}
				}
			}
			break;
		case '&':		//rattleSnakes move up and down
			if ((enemy->getX() < rows - 1) && enemy->getDirection() == true)
			{
				if (map[enemy->getX() - 1][enemy->getY()] == NULL)
				{
					map[enemy->getX() - 1][enemy->getY()] = enemy;
					map[enemy->getX()][enemy->getY()] = NULL;
					enemy->setX(enemy->getX() - 1);
				}
				else
				{
					enemy->setDirection(false);	//something blocking cobra, start leftward motion
				}
			}
			else
			{
				if (enemy->getX() > 0)
				{
					if (map[enemy->getX() + 1][enemy->getY()] == NULL)
					{
						map[enemy->getX() + 1][enemy->getY()] = enemy;
						map[enemy->getX()][enemy->getY()] = NULL;
						enemy->setX(enemy->getX() + 1);
					}
					else
					{
						enemy->setDirection(true);	//something blocking snake, start rightward motion
					}
				}
			}
			break;
		}
	}
}
/********************************************************************
**Function:traverseTop
**Description: changes the currentroom for the user
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool(false)
*******************************************************************/
bool room::traverseTop() 
{
	//parent function returns false only
	//derived classes use this function
	//to check if the current room should change
	return false;
}
/********************************************************************
**Function:traverseBottom
**Description: changes the currentroom for the user
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool(false)
*******************************************************************/
bool room::traverseBottom()
{
	//parent function returns false only
	//derived classes use this function
	//to check if the current room should change
	return false;
}
/********************************************************************
**Function:traverseRight()
**Description: changes the currentroom for the user
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool(false)
*******************************************************************/
bool room::traverseRight()
{
	//parent function returns false only
	//derived classes use this function
	//to check if the current room should change
	return false;
}
/********************************************************************
**Function:traverseLeft
**Description: changes the currentroom for the user
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool(false)
*******************************************************************/
bool room::traverseLeft()
{
	//parent function returns false only
	//derived classes use this function
	//to check if the current room should change
	return false;
}

/********************************************************************
**Function:setRogueTop()
**Description: places rogue at apropriate location after room switch
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void room::setRogueTop()
{
	//parent does nothing
}
/********************************************************************
**Function:setRogueBottom()
**Description: places rogue at apropriate location after room switch
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void room::setRogueBottom()
{
	//parent does nothing
}
/********************************************************************
**Function:setRogueRight()
**Description: places rogue at apropriate location after room switch
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void room::setRogueRight()
{
	//parent does nothing
}
/********************************************************************
**Function:setRogueleft()
**Description: places rogue at apropriate location after room switch
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: void
*******************************************************************/
void room::setRogueLeft()
{
	//parent does nothing
}

/********************************************************************
**Function:getRight
**Description: returns right pointer
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: room*
*******************************************************************/
room* room::getRight() const
{
	return this->right;
}

/********************************************************************
**Function:getLeft
**Description: returns left pointer
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: room*
*******************************************************************/
room* room::getLeft() const
{
	return this->left;
}

/********************************************************************
**Function:getTop
**Description: creturns top pointer
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: room*
*******************************************************************/
room* room::getTop() const
{
	return this->top;
}

/********************************************************************
**Function:getBottom
**Description: returns bottom pointer
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: room*
*******************************************************************/
room* room::getBottom() const
{
	return this->bottom;
}

/********************************************************************
**Function:setRight
**Description: sets right pointer
**Parameters:room*
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void room::setRight(room* r)
{
	this->right = r;
}

/********************************************************************
**Function:setLeft
**Description: sets left pointer
**Parameters:room*
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void room::setLeft(room* l)
{
	this->left = l;
}

/********************************************************************
**Function:setTop
**Description: sets top pointer
**Parameters:room*
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void room::setTop(room* t)
{
	this->top = t;
}

/********************************************************************
**Function:setBottom
**Description: sets bottom pointer
**Parameters:room*
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void room::setBottom(room* b)
{
	this->bottom = b;
}

/********************************************************************
**Function:printMessage
**Description: prints room message
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void room::printMessage() const
{
	std::cout << "\nthis is the parent class message\n";
}

