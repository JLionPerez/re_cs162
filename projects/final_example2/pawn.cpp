//#include "stdafx.h"
/*********************************************
**Author: Dylan Markovic
**Date: 11.30.16
**Description: Final "Pawn Implementation"
**********************************************/
#include "pawn.hpp"

/********************************************************************
**Function:pawn constructor
**Description: creates instance of pawn
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
pawn::pawn()
{
	this->body = '?';		//'?' used only for debugging
	direction = true;
	setHealth(1);
	name = "notImportant";
}

/********************************************************************
**Function:setX
**Description: sets pawn's x coordinate (xPos)
**Parameters: int x
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void pawn::setX(int x)
{
	xPos = x;
}

/********************************************************************
**Function:setY
**Description: sets pawn's Y coordinate (yPos)
**Parameters: int y
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void pawn::setY(int y)
{
	yPos = y;
}

/********************************************************************
**Function:getX
**Description: gets pawn's x coordinate (xPos)
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: int
*******************************************************************/
int pawn::getX() const
{
	return xPos;
}

/********************************************************************
**Function:getX
**Description: gets pawn's y coordinate (xPos)
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: int
*******************************************************************/
int pawn::getY() const
{
	return yPos;
}

/********************************************************************
**Function:getBody
**Description: gets pawn's body
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: char
*******************************************************************/
char pawn::getBody() const
{
	return this->body;
}

/********************************************************************
**Function:pawn destructor
**Description: destroys instance of pawn
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
pawn::~pawn()
{

}
/********************************************************************
**Function:setHealth
**Description: sets health of character
**Parameters: int x
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void pawn::setHealth(int x)
{
	this->health -= x;
}

/********************************************************************
**Function:getHealth
**Description: returns health
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: int
*******************************************************************/
int pawn::getHealth() const
{
	return this->health;
}

/********************************************************************
**Function:getDirection
**Description: returns direction
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: none
**Return: bool
*******************************************************************/
bool pawn::getDirection() const
{
	return this->direction;
}

/********************************************************************
**Function:setDirection
**Description: sets direction
**Parameters: bool
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void pawn::setDirection(bool d)
{
	this->direction = d;
}
/********************************************************************
**Function:getName()
**Description:returns name of pawn
**Parameters: bool
**Pre-Conditions: none
**Post-Conditions: none
**Return: string
*******************************************************************/
std::string pawn::getName() const
{
	return name;
}

/********************************************************************
**Function:setBody
**Description: sets body of character
**Parameters:char b
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
void pawn::setBody(char b)
{
	this->body = b;
}



