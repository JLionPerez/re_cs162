/*******************************************************************************
**	Program Name:	Game.hpp
**	Author:			Will Clayton
**	Date:			2017-10-22
**	Description:	'Game' class declaration file
*******************************************************************************/

#ifndef Game_H
#define Game_H

#include <string>
using std::string;

#include "wcLibrary.hpp"

#include "Space.hpp"
#include "NormalSpace.hpp"
#include "DoorSpace.hpp"
#include "LightSpace.hpp"
#include "PortalSpace.hpp"
#include "Item.hpp"

class Game
{
	private:
		wcLibrary*	lib;
		// Space objects form a fully free-standing two-dimensional linked-space, and they'll provide their own navigation.  This 'location' array grid exists only to 1) Help me visualize and systematically create it, 2) Control the behavior of my monster, and 3) Systematically free its memory.  This array is NOT storing the map for this game -- the Space objects do that.
		Space*	location[6][7];
		Space*	exit;
		Space*	currentLocation;
		Space*	demogorgonLocation;
		bool	demogorgonSleeping;
		string	result;
		Item*	inventory[5];
		Item*	used[2];
		Item*	hand[2];
		bool	accomplishment[7];	// Eggo, Coke, Door, Key, Breaker, Terminal, Escape [10,10,10,10,10,25,25]
		int		health;
		int		score;
	public:
				Game();
		string	parseInput(string);
		void	play();
				~Game();
};

#endif
