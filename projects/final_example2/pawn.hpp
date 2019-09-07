/*********************************************
**Author: Dylan Markovic
**Date: 11.30.16
**Description: Final "Pawn Header"
**********************************************/
#ifndef PAWN_HPP
#define PAWN_HPP
#include <string>
/*
*pawn class entails all elements that can exist in a room
*such as keys, doors and characters
*no movement capabilities with standard pawn rules
*/
class pawn
{
protected:
	char body;				//screen output character
	int xPos;				//room x coordinate
	int yPos;				//room y coordinate
	int health;
	bool direction;
	std::string name;

public:
	pawn();
	virtual ~pawn() = 0; //pure virtual function
	void setX(int);
	void setY(int);
	int getX() const;
	int getY() const;
	char getBody() const;
	void setHealth(int);
	int getHealth() const;
	bool getDirection() const;
	void setDirection(bool);
	std::string getName() const;
	void setBody(char);
	
};
#endif

