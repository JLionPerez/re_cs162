/*********************************************
**Author: Dylan Markovic
**Date: 11.30.16
**Description: Final "player Header"
**********************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "pawn.hpp"
#include <string>
class player : public pawn
{
private:
	std::string inventory[6];
public:
	player();
	~player();
	void addToInventory(std::string);
	bool checkInventory(std::string);
	void printInventory() const;
	void decreaseHealth();
	int getHealth();
	void kill();
};
#endif

