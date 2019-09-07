//#include "stdafx.h"
/***************************************
**Author: Dylan Markovic
**Date: 11.30.2016
**Description:  Final Project "Main"
****************************************/
#include "room.hpp"
#include "snakeRoom.hpp"
#include "player.hpp"
#include <iostream>
#include "entryRoom.hpp"
#include "utlty.hpp"
#include "cobraRoom.hpp"
#include "rattleRoom.hpp"
#include "windRoom.hpp"
#include "snakeGodRoom.hpp"
//#include "menu.hpp"
#include "m3nu.hpp"
//#include "testRoom.hpp"

int main()
{
	outputM3nu();
	//player *rogue = new player;
	//room *test = new testRoom(rogue);
	//test->printRoom();
	//delete test;
	//delete rogue;
	return 0;
}
/*
int main()
{
	std::cout
		<< "\n             Welcome to the Serpent Temple!!"
		<< "\n"
		<< "\nA villager has stolen eggs from the Sacred Snake Temple!!!"
		<< "\n     A Curse has been placed on you and your people!!!"
		<< "\n             You must go into the temple."
		<< "\n   YOU MUST FIND THE CURE, AND RETURN TO YOUR PEOPLE\n"
		<< "\n\n"
		<< "\n                  Enter any number to begin";
	intCheck();


	player *rogue = new player;
	room *currentRoom;
	room *entRoom = new entryRoom(rogue);
	room *snkRoom = new snakeRoom(rogue);
	room *cobRoom = new cobraRoom(rogue);
	room *ratRoom = new rattleRoom(rogue);
	room *wnRoom = new windRoom(rogue);
	room *bossRoom = new snakeGodRoom(rogue);
	entRoom->setTop(snkRoom);
	snkRoom->setBottom(entRoom);
	cobRoom->setRight(snkRoom);
	snkRoom->setLeft(cobRoom);
	ratRoom->setLeft(snkRoom);
	snkRoom->setRight(ratRoom);
	wnRoom->setBottom(snkRoom);
	snkRoom->setTop(wnRoom);
	bossRoom->setBottom(wnRoom);
	wnRoom->setTop(bossRoom);
	
	
	currentRoom = entRoom;
	//outputMenu();
	while (rogue->getHealth() > 0)
	{
		if ((rogue->checkInventory("\n		Snake God's Cure") == true)  && (currentRoom == entRoom))
		{
			for (int i = 0; i < 100; i++)
				std::cout << "\n";
			std::cout
				<< "\nYou Have Saved Your People from the Curse"
				<< "\n\n\n"
				<< "\n           Thanks for Playing!\n";
			rogue->kill();

		}
		else
		{
			for (int j = 0; j < 500; j++)
				std::cout << "\n";

			currentRoom->printRoom();
			currentRoom->moveCharacters();

			if (currentRoom->traverseTop() == true)
			{
				currentRoom = currentRoom->getTop();
				currentRoom->setRogueTop();
			}
			else if (currentRoom->traverseBottom() == true)
			{
				currentRoom = currentRoom->getBottom();
				currentRoom->setRogueBottom();
			}
			else if (currentRoom->traverseRight() == true)
			{
				currentRoom = currentRoom->getRight();
				currentRoom->setRogueRight();
			}
			else if (currentRoom->traverseLeft() == true)
			{
				currentRoom = currentRoom->getLeft();
				currentRoom->setRogueLeft();
			}
			rogue->decreaseHealth();

			if (rogue->getHealth() <= 0)
			{
				for (int i = 0; i < 100; i++)
					std::cout << "\n";
				std::cout
					<< "\n            OH NO!!!!"
					<< "\n  The Curse has taken your life"
					<< "\nBefore you could save your people!\n";
			}
		}


	}
	/*for (int i = 0; i < 800; i++)
	{
		for (int j = 0; j < 500; j++)
			std::cout << "\n";

		currentRoom->printRoom();
		currentRoom->moveCharacters();
		if (currentRoom->traverseTop() == true)
		{
			currentRoom = currentRoom->getTop();
			currentRoom->setRogueTop();
		}
		else if (currentRoom->traverseBottom() == true)
		{
			currentRoom = currentRoom->getBottom();
			currentRoom->setRogueBottom();
		}
		else if (currentRoom->traverseRight() == true)
		{
			currentRoom = currentRoom->getRight();
			currentRoom->setRogueRight();
		}
		else if (currentRoom->traverseLeft() == true)
		{
			currentRoom = currentRoom->getLeft();
			currentRoom->setRogueLeft();
		}
		//traverse(currentRoom);
	
	}	*/
	/*
	delete entRoom;
	delete snkRoom;
	delete cobRoom;
	delete ratRoom;
	delete wnRoom;
	delete bossRoom;
	delete rogue;

	return 0;
}
*/
