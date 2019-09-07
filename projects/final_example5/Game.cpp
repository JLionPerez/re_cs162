/*******************************************************************************
**	Program Name:	Game.cpp
**	Author:			Will Clayton
**	Date:			2017-12-05
**	Description:	'Game' class implementation file
*******************************************************************************/

#include "Game.hpp"
#include "Item.hpp"

#include <iostream>
using std::cout;

Game::Game()
// Constructor
{
	// Initialize all variables;
	lib = new wcLibrary;
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			location[x][y] = NULL;
		}
	}
	exit = new NormalSpace("LONG, HAPPY LIFE","As you pass through the security doors for the last time, Jerry comes breathlessly running out to bum a ride.  You drop the security card in the night deliveries box and hop into your 1981 Honda Civic.  What an adventure it's been!\nYOU WIN!");
	currentLocation = NULL;
	demogorgonLocation = NULL;
	demogorgonSleeping = true;
	result = "";
	for (int i = 0; i < 5; i++)
	{
		inventory[i] = NULL;
	}
	for (int d = 0; d < 2; d++)
	{
		used[d] = NULL;
		hand[d] = NULL;
	}
	for (int a = 0; a < 7; a++)
	{
		accomplishment[a] = false;
	}
	health	= 100;
	score	= 0;

	// Populate the map, including a duplicative section of "Upside-Down" and some blank spaces
	// Row 0
	location[1][0] = new LightSpace ("Northwest Hallway Lounge", "You are in the informal hallway seating area where you and Jerry often hang out for breaks and such.  The sofa and\nchairs are here but everything is green and overgrown with nasty vines, including that ugly painting you love to make\nfun of.  There's an upright reading lamp sticking out of the vines, glowing very faintly.  The air is filled with\nfloating ash.  From this corner the hallway continues east and south.");
	location[1][0]->setUpsideDown(true);
	location[1][0]->setMessage("  Faintly, as if from another world, you can hear Jerry singing 'Islands in the Stream' (both parts)\n  Of everything in this nightmare, this lamp seems the most touchable.");
	location[2][0] = new NormalSpace ("North Hallway", "You are in the hallway north of the break room.  Nasty green vines cover everything, including your supervisor Jeanine's\nfavorite motivational poster, and the air is filled with floating ash.  The hallway continues to the east and to the\nwest; the break room is to the south.");
	location[2][0]->setWest(location[1][0]);	// This Space
	location[1][0]->setEast(location[2][0]);	// Other Space that needed this one
	location[2][0]->setUpsideDown(true);

	location[3][0] = new NormalSpace ("Northeast Hallway", "You are in the hallway near the break room.  Nasty green vines cover everything, and the air is filled with floating\nash.  The hallway continues to the west and to the south.");
	location[3][0]->setWest(location[2][0]);	// This Space
	location[2][0]->setEast(location[3][0]);	// Other Space that needed this one
	location[3][0]->setUpsideDown(true);

	location[4][0] = new PortalSpace("Intern Restroom", "Normally this is a safe place (mostly for Jerry), but it feels downright hostile now, what with the nasty vine cover\nand the floating ash.  Upside: the stall appears unoccupied!  Normally the only exit is to the south, but right now\nthere is a glowing green portal where the east wall should be, writhing with nasty vines, but you could probably leap\ninto the darkness beyond if you wanted to.  Fresh air appears to be entering through the hole in the east wall.");
	location[4][0]->stringer(0, "  The stall door is closed.");
	location[4][0]->stringer(1, "  The stall door is open, revealing a slimy green 'portal' to somewhere else.  Through the portal you can see Jerry's Feet,\nand his keycard clipped to his trousers.  Eww.  You can faintly hear him humming something by Chuck Mangione.");
	location[4][0]->setUpsideDown(true);
	location[4][0]->action(0);

	// ROW 1 ===================================================
	
	location[1][1] = new NormalSpace ("West Hallway", "You are in the hallway west of the break room.  The security doors that normally fill the west wall are (along with\neverything else) completely obscured by writhing green vines, and the air is filled with floating ash.  The hallway\ncontinues to the north and to the south; the break room is to your east.");
	location[1][1]->setNorth(location[1][0]);	// This Space
	location[1][0]->setSouth(location[1][1]);	// Other Space that needed this one
	location[1][1]->setUpsideDown(true);

	location[2][1] = new PortalSpace ("Break Room", "You are in the Computer Science area break room, which used to be your favorite part of the office.  But now it's got\nnasty green vines covering all the tables, chairs and counters, and there is no edible food to be seen.  The\nrefrigerator is completely covered except for the freezer barely sticking out on top.  This sucks!  The air is filled\nwith floating ash.  There are exits on all four walls of the break room.");
	location[2][1]->stringer(0, "  The freezer door is closed.");
	location[2][1]->stringer(1, "  The freezer door is open, revealing a slimy green 'portal' to somewhere else.  Through the portal you can see an Eggo\nWaffle ('Eggo').");	
	location[2][1]->setNorth(location[2][0]);	// This Space
	location[2][0]->setSouth(location[2][1]);	// Other Space that needed this one
	location[2][1]->setWest(location[1][1]);	// This Space
	location[1][1]->setEast(location[2][1]);	// Other Space that needed this one
	location[2][0]->setUpsideDown(true);
	location[2][1]->action(0);

	location[3][1]= new DoorSpace ("East Hallway", "You are in the east hallway, which continues to your north and to your south.  To your west is the break room, and to\nyour east are the heavy security doors that lead to the 'Intern Farm' where you and Jerry have spent the summer working.\nNasty green vines cover everything, and the air is filled with floating ash.");
	location[3][1]->setNorth(location[3][0]);	// This Space
	location[3][0]->setSouth(location[3][1]);	// Other Space that needed this one
	location[3][1]->setWest(location[2][1]);	// This Space
	location[2][1]->setEast(location[3][1]);	// Other Space that needed this one
	location[3][1]->setUpsideDown(true);

	location[4][1] = new DoorSpace ("Intern Farm", "You and Jerry have spent the summer and early fall in these cubicles, except that they're completely covered in nasty\ngreen vines.  The air is filled with ash.  Where your terminal would normally be there is a congealed mass of what\nappears to be dried blood.  Your chair is a writhing mass of jagged talons.  Does this mean your whole summer's worth of\ncode is unsubmitted and gone?  The intern restroom is to your north and the heavy security doors are to your west.");
	location[4][1]->setNorth(location[4][0]);	// This Space
	location[4][0]->setSouth(location[4][1]);	// Other Space that needed this one
	location[4][1]->setWest(location[3][1]);	// This Space
	location[3][1]->setEast(location[4][1]);	// Other Space that needed this one
	location[3][1]->spacer(1,location[4][1]);	// Set 3,1 east door lockable to 4,1
	location[3][1]->action(0);					// Lock 3,1 east door
	location[4][1]->spacer(0, location[3][1]);	// Set 4,1 west door locable to 3,1
	location[4][1]->action(0);					// Lock 4,1 west door
	location[4][0]->setUpsideDown(true);

	// ROW 2 ===================================================
	location[1][2] = new NormalSpace ("Southwest Hallway", "You are in the hallway near the break room.  Nasty green vines cover everything, and the air is filled with floating\nash.  The hallway continues to the north and to the east.");
	location[1][2]->setNorth(location[1][1]);	// This Space
	location[1][1]->setSouth(location[1][2]);	// Other Space that needed this one
	location[1][2]->setUpsideDown(true);

	location[2][2] = new PortalSpace ("South Hall and Watercooler", "You are in the hallway south of the break room, where you and Jerry have spent many hours discussing the final episode\nof 'M*A*S*H'.  Everything is choked with writhing green vines, and the air is filled with floating ash.  The cooler is\nmostly obscured by the vines and appears to be filled with black bile, and the mini fridge is barely poking out on one\nside.  The hallway continues to your east and west, and the break room is to your north.");
	location[2][2]->stringer(0, "  The mini fridge door is closed.");
	location[2][2]->stringer(1, "  The mini fridge door is open, revealing a slimy green 'portal' to somewhere else.  Through the portal you can see a can\nof Coca-Cola ('Coke').");	
	location[2][2]->setNorth(location[2][1]);	// This Space
	location[2][1]->setSouth(location[2][2]);	// Other Space that needed this one
	location[2][2]->setWest(location[1][2]);	// This Space
	location[1][2]->setEast(location[2][2]);	// Other Space that needed this one
	location[2][2]->setUpsideDown(true);
	location[2][2]->action(0);

	location[3][2] = new NormalSpace ("Southeast Hallway", "You are in the hallway near the break room.  Nasty green vines cover everything, and the air is filled with floating\nash.  The hallway continues to the west and to the north.");
	location[3][2]->setNorth(location[3][1]);	// This Space
	location[3][1]->setSouth(location[3][2]);	// Other Space that needed this one
	location[3][2]->setWest(location[2][2]);	// This Space
	location[2][2]->setEast(location[3][2]);	// Other Space that needed this one
	location[3][0]->setUpsideDown(true);
	// END OF 'UPSIDE-DOWN' ROWS

	// ROW 3 ===================================================

	location[0][3] = new NormalSpace ("Unknown Hallway", "It is pitch black. You are likely to be eaten by something unpleasant.");

	location[1][3] = new NormalSpace ("Unknown Hallway", "It is pitch black. You are likely to be eaten by something unpleasant.");
	location[1][3]->setWest(location[0][3]);	// This Space
	location[0][3]->setEast(location[1][3]);	// Other Space that needed this one

	location[2][3] = new NormalSpace ("Unknown Hallway", "It is pitch black. You are likely to be eaten by something unpleasant.");
	location[2][3]->setWest(location[1][3]);	// This Space
	location[1][3]->setEast(location[2][3]);	// Other Space that needed this one

	location[3][3] = new NormalSpace ("Unknown Hallway", "It is pitch black. You are likely to be eaten by something unpleasant.");
	location[3][3]->setWest(location[2][3]);	// This Space
	location[2][3]->setEast(location[3][3]);	// Other Space that needed this one

	location[4][3] = new NormalSpace ("Unknown Hallway", "It is pitch black. You are likely to be eaten by something unpleasant.");
	location[4][3]->setWest(location[3][3]);	// This Space
	location[3][3]->setEast(location[4][3]);	// Other Space that needed this one

	location[5][3] = new NormalSpace ("Unknown Hallway", "It is pitch black. You are likely to be eaten by something unpleasant.  There is a faint red glow to the south.");
	location[5][3]->setWest(location[4][3]);	// This Space
	location[4][3]->setEast(location[5][3]);	// Other Space that needed this one

	// ROW 4 ===================================================

	location[0][4] = new NormalSpace ("Applied Psychiatrics Lab", "Oh man -- you are not supposed to be in here.  Signs on each wall warn that this is 'APPLIED PSYCHIATRICS LAB: OMEGA\nCLEARANCE RESTRICTED'.  That is disconcerting, but not as much as the blood and shreds of lab coat that cover all the\nwalls, tables and equipment.  This looks like just the sort of thing they'd want an intern to clean up!  A hallway\nproceeds to the north, and you can see what's left of the Applied Psych lobby through the decontamination system to\nthe south.");
	location[0][4]->setNorth(location[0][3]);	// This Space
	location[0][3]->setSouth(location[0][4]);	// Other Space that needed this one
	
	location[1][4] = new NormalSpace ("Northwest Hallway Lounge", "You are in the informal hallway seating area where you and Jerry often hang out for breaks and such.  The sofa and\nchairs are how you remember them - comfy and inviting, without all those nasty vines!  On the north wall is bolted a\npainting of an elderly man in a toga, wrestling a donkey, captioned 'The Triumph of Reason'.  There's an upright reading lamp sticking out of the vines, glowing brightly.  From this corner the\nhallway continues east and south.");

	location[2][4] = new NormalSpace ("North Hallway", "You are in the hallway north of the break room.  To the north wall is bolted a framed poster of rowers in a Roman\ngalley, captioned 'Get to work.  Visualize your dreams on your own time!'.  The hallway continues to the east and to the\nwest; the break room is to the south.");
	location[2][4]->setWest(location[1][4]);	// This Space
	location[1][4]->setEast(location[2][4]);	// Other Space that needed this one

	location[3][4] = new NormalSpace ("Northeast Hallway", "You are in the hallway near the break room.  The hallway continues to the west and to the south.");
	location[3][4]->setWest(location[2][4]);	// This Space
	location[2][4]->setEast(location[3][4]);	// Other Space that needed this one

	location[4][4] = new NormalSpace ("Intern Restroom", "This is a safe place (except right after Jerry uses it!).  The door to the single stall is permanently bent around it's\nsupport column as if someone large left the stall in a panicked hurry.  The east wall is back to its normal drab tan\nwallpaper.  The only exit is to the south.");

	location[5][4] = new NormalSpace ("Utility Corridor", "You are in a non-descript concrete corridor, faintly illuminated by a red emergency lamp that is dripping something\ngooey.  A patch of slime adorns the west wall, but the passage proceeds only north and south.");
	location[4][0]->setEast(location[5][4]);	// One-Way Portal from Upside-Down Bathroom
	location[5][4]->setNorth(location[5][3]);	// This Space
	location[5][3]->setSouth(location[5][4]);	// Other Space that needed this one

	// ROW 5 ===================================================
	location[0][5] = new DoorSpace ("Lobby", "You are in the lobby for your IT team and for the Applied Psychiatrics team (who\nare jerks -- they once put jalepenos in Jerry's lunch, which was pretty funny, but still not cool).  The Applied\nPsychiatrics decontamination system is hissing but empty to the north, The IT security doors that east to your\nworkspace, and to the south is the building entryway.");
	location[0][5]->setNorth(location[0][4]);	// This Space
	location[0][4]->setSouth(location[0][5]);	// Other Space that needed this one

	location[1][5] = new DoorSpace ("West Hallway", "You are in the hallway west of the break room.  The security doors to the lobby are open to your west.  This bland,\nnon-descript hallway continues to the north and to the south; the break room is to your east.");
	location[1][5]->setNorth(location[1][4]);	// This Space
	location[1][4]->setSouth(location[1][5]);	// Other Space that needed this one
	location[1][5]->setWest(location[0][5]);	// This Space
	location[0][5]->setEast(location[1][5]);	// Other Space that needed this one
	location[0][5]->spacer(1,location[1][5]);	// Set 0,5 east door lockable to 1,5
	location[0][5]->action(0);					// Lock 0,5 east door
//	location[1][5]->spacer(0, location[0][5]);	// Set 1,5 west door locable to 0,5
//	location[1][5]->action(0);					// Lock 1,5 west door

	location[2][5] = new NormalSpace ("Break Room", "You are in the Computer Science area break room, which is your favorite part of the office.  A cheap fridge/freezer and\nnon-descript table and chairs make this a classic corporate break room.  If only they had a microwave oven!  There are\nexits on all four walls of the break room.");
	location[2][5]->setNorth(location[2][4]);	// This Space
	location[2][4]->setSouth(location[2][5]);	// Other Space that needed this one
	location[2][5]->setWest(location[1][5]);	// This Space
	location[1][5]->setEast(location[2][5]);	// Other Space that needed this one

	location[3][5] = new DoorSpace ("East Hallway", "You are in the east hallway, which continues to your north and to your south.  To your west is the break room, and to\nyour east are the heavy security doors that lead to the 'Intern Farm' where you and Jerry have spent the summer working.");
	location[3][5]->setNorth(location[3][4]);	// This Space
	location[3][4]->setSouth(location[3][5]);	// Other Space that needed this one
	location[3][5]->setWest(location[2][5]);	// This Space
	location[2][5]->setEast(location[3][5]);	// Other Space that needed this one

	location[4][5] = new DoorSpace ("Intern Farm", "You and Jerry have spent the summer and early fall in these cubicles, but you took most of your stuff home yesterday\nsince today is your last day.  Your terminal is online and - miraculously - still ready to submit your final code\npackage.  The intern restroom is to your north and the heavy security doors are to your west.");
	location[4][5]->setMessage("  Your work terminal is on - you could use it if you want.");
	location[4][5]->setNorth(location[4][4]);	// This Space
	location[4][4]->setSouth(location[4][5]);	// Other Space that needed this one
	location[4][5]->setWest(location[3][5]);	// This Space
	location[3][5]->setEast(location[4][5]);	// Other Space that needed this one
//	location[3][5]->spacer(1,location[4][5]);	// Set 3,5 east door lockable to 4,5
//	location[3][5]->action(0);					// Lock 3,5 east door
//	location[4][5]->spacer(0, location[3][5]);	// Set 1,5 west door locable to 0,5
//	location[4][5]->action(0);					// Lock 1,5 west door

	location[5][5] = new NormalSpace ("Utility Corridor", "It is pitch black. You are likely to be eaten by something unpleasant.  There is a faint red glow to the north.");
	location[5][5]->setNorth(location[5][4]);	// This Space
	location[5][4]->setSouth(location[5][5]);	// Other Space that needed this one

	// ROW 6 ===================================================
	location[0][6] = new DoorSpace ("Security Entryway", "You are in a bland security checkpoint with a formica countertop and no other furnishings.  You have come through here\nevery work day all summer, and you've never seen the armed guard station empty like it is now.  You can head north to\nthe lobby or leave the building through the massive bulletproof doors to the west.");
	location[0][6]->setNorth(location[0][5]);	// This Space
	location[0][5]->setSouth(location[0][6]);	// Other Space that needed this one
	location[0][6]->setWest(exit);				// This Space - one-way traverse
	location[0][6]->spacer(0, exit);			// Set 0,6 west door locable to 0,5
	location[0][6]->action(0);					// Lock 0,6 west door

	location[1][6] = new NormalSpace ("Southwest Hallway", "You are in the hallway near the break room.  The hallway continues to the north and to the east.");
	location[1][6]->setNorth(location[1][5]);	// This Space
	location[1][5]->setSouth(location[1][6]);	// Other Space that needed this one

	location[2][6] = new NormalSpace ("South Hall and Watercooler", "You are in the hallway south of the break room, where you and Jerry have spent many hours discussing the final episode\nof 'M*A*S*H'.  The generic water cooler lets loose a large bubb;e that is a little unnerving at this point.  There is a\nsmall mini fridge where you can normally score a cold soda.  The hallway continues to your east and west, and the break\nroom is to your north.");
	location[2][6]->setNorth(location[2][5]);	// This Space
	location[2][5]->setSouth(location[2][6]);	// Other Space that needed this one
	location[2][6]->setWest(location[1][6]);	// This Space
	location[1][6]->setEast(location[2][6]);	// Other Space that needed this one

	location[3][6] = new NormalSpace ("Southeast Hallway", "You are in the hallway near the break room.  The hallway continues to the west and to the north.");
	location[3][6]->setNorth(location[3][5]);	// This Space
	location[3][5]->setSouth(location[3][6]);	// Other Space that needed this one
	location[3][6]->setWest(location[2][6]);	// This Space
	location[2][6]->setEast(location[3][6]);	// Other Space that needed this one

	location[4][6] = new NormalSpace ("Breaker Room", "You are in a bare concrete dead end, where a number of electrical conduits converge.  By the faint glow of an orange\nemergency light you see a massive circuit breaker adorning the west wall.  The hallway continues to the east.");
	location[4][6]->setMessage("  There is a breaker reset button - you could use it if you want.");

	location[5][6] = new NormalSpace ("Utility Corridor", "It is pitch black. You are likely to be eaten by something unpleasant.  There is a faint orange glow to the west.");
	location[5][6]->setNorth(location[5][5]);	// This Space
	location[5][5]->setSouth(location[5][6]);	// Other Space that needed this one
	location[5][6]->setWest(location[4][6]);	// This Space
	location[4][6]->setEast(location[5][6]);	// Other Space that needed this one

	// Demogorgon nearby in the dark
	location[5][4]->setMessage("There is an ominous slavering growl coming from the darkness nearby.");
	location[5][3]->setMessage("There is an ominous slavering growl coming from the darkness nearby.");
	location[4][3]->setMessage("There is an ominous slavering growl coming from the darkness nearby.");
	location[3][3]->setMessage("There is an ominous slavering growl coming from the darkness nearby.");

	// Populate Items - No more sophisticated structure than this is needed...
	inventory[0] = new Item ("Eggo Waffle ('Eggo')", "eggo");
	inventory[0]->setLocation(location[2][5]);
	inventory[0]->setPortalLocation(location[2][1]);
	inventory[1] = new Item ("Coca-Cola ('Coke')", "coke");
	inventory[1]->setLocation(location[2][6]);
	inventory[1]->setPortalLocation(location[2][2]);
	inventory[2] = new Item ("Hawkins Lab Key Card ('Key')", "key");
	inventory[2]->setLocation(location[4][4]);
	inventory[2]->setPortalLocation(location[4][0]);
	inventory[3] = new Item ("Severed Human Thumb ('Thumb')", "thumb");
	inventory[3]->setLocation(location[3][0]);
	inventory[4] = new Item ("Badminton Racket ('Racket')", "racket");
	inventory[4]->setLocation(location[1][1]);

	currentLocation = location[2][1];

	return;
}

void Game::play()
// Let's Play!
{
	// Welcome Splash Screen
	cout << ".....................................................................................................................   \n";
	cout << "  ....,,.............................. .     .................. ...... .............  .... ..........................   \n";
	cout << " .$$$$$$$$$$$$.$$$$$$$$$$$$Z$$$$$$$$$$$$..   .Z$$$$$~. .Z$$$$$$$..$$$$ ..$$$$$$$$$$.  Z$$$$$$$$$$$.$$$$$$$$$$$$$$$$..   \n";
	cout << ",$$$$$=...$ZZ$Z$I.?$$$$.~$$.~$$$$Z.,$$$$$..  .=$$$$$.. ..$$$$$$$...$$ .$$$$$,...Z$$.  .$$$$$...=$$..$$$$$$$Z7$$$$$$$$   \n";
	cout << "Z$$$$,.    .$?$.  +$$$$.  $..$$$$   ,$$$$.   .$$$$$$7..  $Z7$$$$$..$$.$$$$Z.     .$.  .$$$$O.....$=.Z$$$$$..  +$$$$$$   \n";
	cout << "$$$$$Z.    ....   +$$$$.  ...$$$$  .Z$$$...  =Z,Z$$$$..  $$..$$$Z$.$$.$$$$..     ..,  .$$$$Z...$..$.Z$$$$$..  .$$$$$,   \n";
	cout << "Z$$$$$$O....      +$$$$.    .$$$$..$$$7.   ..$$..$$$$$.  $$...$$$$$$$.$$$$.    ........$$$$$$$$$....Z$$$$$. ..Z$$$$:    \n";
	cout << "$$$$$$$$$$$$....  +$$$$.    .$$$$$$$$$Z.   .,$~..$$$$$.  $$.  .7$$$$$.$$$$..   .$$$$Z..$$$$Z...$,.  Z$$$$$...$$$$$.     \n";
	cout << ".$$$$$$$$$$$$$O.  +$$$$.    .$$$$.O$$$$$   .$$$$$$$$$$.  $$.  ..$$$$$.$$$$..    $$$$=..$$$$Z......  Z$$$$$$$$$$$Z..     \n";
	cout << "..,$$$$$$$$$$$ZZ  +$$$$.    .$$$$..Z$$$$=. O$Z..I$$$$$$..$$.  ...$$$$.$$$$..   .$$$$= .$$$$Z.      $Z$$$$$$$$$$$$$...   \n";
 	cout << ".   ..Z$$$$$$$$$. +$$$$.    .$$$$  .$$$$$..$$...  $$$$$..$$.     .$$$.$$$$$. . .$$$$=..$$$$Z.   ..?=Z$$$$$..$$$$$$$..   \n";
	cout << "=.  ......$$$$$$..?$$$$.    .$$$$  ..$$$$$Z$$...  .$$$$Z.$$.    ...$$..O$$$$.. .$$$$=..$$$$$.  ..Z$.Z$$$$$. .$$$$$$Z.   \n";
	cout << "$~..     .$$$$$$..Z$$$$.....O$$$$....$$$$$$$Z .....$$$$$.$$..   ...$$....Z$$$$$$$$$$Z..$$$$$$$$$$$O.Z$$$$$. ..$$$$$$?   \n";
	cout << "$$........$$$$$O.,,,,,,,, ........  ............ .............   .....  .  .........................Z$$$$$..  7$$$$$$.. \n";
	cout << "$$$$....Z$$$$$Z    ....                                                                          ...O$$$$$    .$$$$$$Z..\n";
	cout << "$$$$$$$$$$$$$...   .. .. .. .. ...  . .....  .  .. .  ....  .  ....  ... ....... ...    ...... .....$$$$$$+....$$$$$$$..\n";
	cout << "..........  .     .$$$$$$$$Z$$$IZ$$$$$+..Z$$$$$,.$$$$$$..$$$$$$$,.:$$$...Z$$$$$$$$$.  ..,$$$$$$$$$..........  ..........\n";
	cout << " ...............   $O..$$$$O..Z$.$$$$O....$$$$~...$$$$,...$$$$$$,..O$..=$$$$Z...7Z$.  .O$$$Z...$ZO......................\n";
	cout << "$$$$$$$$$$$$$$$$$......$$$$O   $.$$$$Z ...$$$$,.  $$$$.  .$I$$$$$I.O$.Z$$$$.     .$$...$$$$..  ..$.$$$$$$$$$$$$$$$$$$$$$\n";
	cout << ". ................ ....$$$$O   ..$$$$$$$$$Z$$$,.  $$$$.  .$I.$$$$$ZZ$.$$$$Z.     ..Z..,$$$$$:. ....                     \n";
	cout << "                     ..$$$$O     $$$$Z....$$$$,.  $$$$.  .$I..$$$$$$$.$$$$..   ........Z$$$$$$$$:.                      \n";
	cout << "                     ..$$$$O     $$$$Z  ..$$$$,.  $$$$.  .$I  .$$$$$$.$$$$..   .Z$$$$...$$$$$$$$$$,.                    \n";
	cout << "                     ..$$$$O     $$$$Z  ..$$$$,.  $$$$.  .$I  ..Z$$$$.$$$$.    .=$$$$. ...=$$$$$$$$.                    \n";
	cout << "                     ..$$$$O     $$$$Z  ..$$$$,.  $$$$.  .$I    .~$$$.$$$$O.   .=$$$$.Z.    ..Z$$$$:                    \n";
	cout << "                      .$$$$O     $$$$Z  ..$$$$,.  $$$$.  .$I     .:$$.+$$$$..  .=$$$$.Z....  ..$$$$.                    \n";
	cout << "                      .$$$$Z     $$$$Z   .$$$$:.  $$$$.  .$7    ...$$..:$$$$....Z$$$$.Z$$..  .$$$$Z                     \n";
	cout << "                     ..$$$$$.....$$$$$....$$$$Z..,$$$$Z..O$$..  ...$$= ..Z$$$$$$$$$$$.7$$$$$$$$$$,..                    \n";
	cout << "                     .........  ....... ........ ....... ....     .....     ..,.......:....?$+..                        \n\n";
	cout << "THE UNAUTHORIZED TEXT ADVENTURE GAME by WILL CLAYTON for his CS162 FINAL PROJECT. MORE FUN THAN YOU CAN FIT ON A FLOPPY!\n\n";
	cout << "************************************************************************************************************************\n";
	cout << "** Seriously, though.  Intellectual property is a big deal.  This game is not authorized by '21 Laps Entertainment'   **\n";
	cout << "** or by 'Monkey Massacre' or 'Netflix', so don't go trying to make money off it or anything.  This game constitutes  **\n";
	cout << "** fair use as a parody under US copyright law, and is presented as such.            - Will Clayton -                 **\n";
	cout << "************************************************************************************************************************\n\n";
	lib->pause("to continue...");
	cout << "\nWow!  What a summer it's been.  In preparation for completion of your Computer Science degree at Oregon State University\n";
	cout << "you were selected for a very perstigious internship at the Hawkins National Laboratory in Indiana.  As 1983 draws to a\n";
	cout << "close, you're proud of your accomplishments:\n";
	cout << " * You've completely converted their BASIC code to C++\n";
 	cout << " * You've secretly trained Jerry - the other intern - to use the bathroom every time you flash your desk lamp\n";
 	cout << " * The Department of Energy was nice enough to extend the internship through November, and promised not to kill your\n   advisors if they allow it!\n";
	cout << "\nToday's the day!  Get that code submitted and head back to Corvallis.  But wouldn't you know it -- right as you hit the\n";
	cout << "break room for lunch, the whole facility was rocked by some mysterious event that knocked you unconscious, and now you've\n";
	cout << "awoken to a terrifying Hell-scape that used to be the office.  But you can do this!  You'll survive and graduate,\n";
	cout << "if only you can:\n 1. Grab some lunch\n 2. Submit your code\n 3. Escape this nightmare\n";
	cout << "This air feels like poison or death or something: You'd better get moving!\n\n";

	bool keepGoing = true;

	while (keepGoing)
	{
		cout << "________________________________________________________________________________________________________________________\n";
		cout << currentLocation->getName();
		int padding = 102 - currentLocation->getName().length();
		if (score == 100)
		{
			padding -= 3;
		}
		else if (score > 9)
		{
			padding -= 2;
		}
		else
		{
			padding -= 1;
		}
		if (health == 100)
		{
			padding -= 3;
		}
		else if (health > 9)
		{
			padding -= 2;
		}
		else
		{
			padding -= 1;
		}
		for (int p = 0; p < padding; p++)
		{
			cout << " ";
		}
		cout << "Score: " << score << " | Health: " << health << "\n";

		if (currentLocation->doShowDescription() )
		{
			currentLocation->setShowDescription(false);
			cout << currentLocation->getDescription() << "\n";
		}
		if (currentLocation->hasMessage() )
		{
			cout << currentLocation->getMessage() << "\n";
		}
		for (int i = 0; i < 5; i++)
		{
			if (inventory[i])
			{
				if (inventory[i]->getLocation() == currentLocation)
				{
					cout << "  There is an item here!  " << inventory[i]->getName() << "\n";
				}
			}
		}
		result = parseInput(lib->getStringMinPrompt("> ", 40) );
		if (result == "Good Bye!")	// Quit
		{
			keepGoing = false;
		}
		if (currentLocation == exit)
		{
			if (!accomplishment[5])	// Code not submitted
			{
				result += "\nAs you leave the building, A creature about the size of a person grabs you.  It's face opens like a leather flower to reveal rows and rows of razor sharp teeth, which proceed to eat you.  As you die, you're pretty sure you heard the creature whisper 'You should have submitted your code!'\nYOU HAVE DIED!  And what's worse, you have FAILED YOUR INTERNSHIP!";
			}
			else if (!accomplishment[0] && !accomplishment[1])	// No lunch
			{
				result += "\nAs you leave the building a creature about the size of a person, whose face opens like a leather flower to reveal rows and rows of razor sharp teeth, grabs you.  You try to run but you didn't have any lunch and you just don't have the strength.  The creature bites your face off and eats you.  If only you'd had some lunch!\nYOU HAVE DIED!";
			}
			else
			{
				result = "You did it!  You hop in your 1981 Honda Civic and head back home.  What an adventure it's been!\nYOU WIN!";
				cout << "________________________________________________________________________________________________________________________\n";
				cout << currentLocation->getName();
				int padding = 102 - currentLocation->getName().length();
				if (score == 100)
				{
					padding -= 3;
				}
				else if (score > 9)
				{
					padding -= 2;
				}
				else
				{
					padding -= 1;
				}
				if (health == 100)
				{
					padding -= 3;
				}
				else if (health > 9)
				{
					padding -= 2;
				}
				else
				{
					padding -= 1;
				}
				for (int p = 0; p < padding; p++)
				{
					cout << " ";
				}
				cout << "Score: " << score << " | Health: " << health << "\n";
				if (currentLocation->doShowDescription() )
				{
					currentLocation->setShowDescription(false);
					cout << currentLocation->getDescription() << "\n";
				}
				keepGoing = false;
				return;
			}
		}
		if (health < 1)
		{
			result = "Your exposure to all that green mess has gone and killed you.  Perhaps if you've eaten some lunch or gotten out faster!\nYOU HAVE DIED.";
			keepGoing = false;
		}
		if (result != "")
		{
			cout << result << "\n";
		}
		if (currentLocation->isUpsideDown() )
		{
			health -=4;
			cout << "**This place is killing you!**\n";
		}
		else
		{
			health -=1;
			cout << "All that green stuff hass still got you feeling down.  You need some fresh air\n";
		}
	}
	cout << "\n\n";

	return;
}

string Game::parseInput(string command)
// See if the input contains or infers a valid noun and/or verb
{
	string response = "";
	string verb = "";
	string noun = "?";

	while (command.length() )
	{
		char temp = command[0];
		if (temp>64 && temp<91)		// lower-case everything
		{
			temp += 32;
		}
		if (temp == '?')									// Go straight to help
		{
			verb = "help";
			command = "";
		}
		else if (temp == 32 && verb == "");					// Trim Leading Spaces
		else if (temp>96 && temp<123 && noun == "?")	// Parse verb
		{
			verb += temp;
		}
		else if (temp == 32 && verb != "" && noun == "?")	// Verb finished - Start on Noun
		{
			noun = "";
		}
		else if (temp>96 && temp<123 && noun != "?")	// Parse noun
		{
			noun += temp;
		}
		else if (temp == 32 && verb != "" && noun != "?")	// Spaces after noun!
		{
			for (int x = 0; x < command.length(); x++)	// See if there is non-space input (fail if so)
			{
				if (command[x] != ' ');	// Should Not be here!
				{
					verb = "bad";		// FAIL
					x = command.length();	// Terminate this for loop
					command = "";	// Terminate parent while loop
				}
			}
		}
		// This automatically ignores non-alpha characters except for '?'
		if (command.length() )	// Remove character just processed from front of command
		{
			command = command.substr(1);
		}
	}
	if (verb == "n" || verb == "e" || verb == "s" || verb == "w")	// Rejigger movements
	{
		noun = verb;
		verb = "go";
	}
	else if (verb == "go" || verb == "run")	// Whole-word directions can just be first letters
	{
		noun = noun[0];
	}
	if (verb == "i")	// Synonym
	{
		verb = "inventory";
	}
	if (verb == "q")	// Synonym
	{
		verb = "quit";
	}

	// RESPOND TO COMMANDS - Switch doesn't work on strings and there is no good reason to convert user commands to int's...
	if (verb == "help")
	{
		response = "Solve the adventure using the following commands: {Help / ?, (Go) N, S, E, W, Look, Map, Inventory / I, Get [Item],\n  Use [Item], Drop [Item], Run [N/S/E/W], Touch [Object], Open [Container], Quit / Q}\n  There's also a 'Hint' if you really need one.";
	}
	else if (verb == "go")
	{
		Space* temp = currentLocation;
		currentLocation = currentLocation->go(currentLocation, noun);
		if (temp == currentLocation)
		{
			response = "You can't go that direction.";
		}
	}
	else if (verb == "cheat")
	{
		health = 100;
		response = "Your health just jumped to 100%, but you somehow feel worse about it.";
	}
	else if (verb == "inventory")
	{
		if (hand[0] || hand[1])
		{
			response = "You are holding: {";
			if (hand[0])
			{
				response += hand[0]->getName();
			}
			if (hand[0] && hand[1])
			{
				response += ", ";
			}
			if (hand[1])
			{
				response += hand[1]->getName();
			}
			response += "}";
		}
		else
		{
			response = "You are not holding anything right now.";
		}
	}
	else if (verb == "hint")
	{
		if (lib->doOrNot("Figure it out by yourself", "Get a Hint (This could wreck the fun!)") )
		{
			response = "In the TV show, a person trapped in the 'Upside-Down' dark mirror of our world (where you are now trapped) can fiddle\n  around with electric lights, causing their counterparts in the real world to flash.  As a clever intern, you have\n  trained your colleague to have to use the bathroom (which is in the locked area of the facility) any time a light\n  flashes.  Work that angle.  There are also things you can grab through portals to the real world, but they're inside\n  things you'll need to open.  Good Luck!";
		}
		else
		{
			response = "  Good call -- you'll figure it out!";
		}
	}
	else if (verb == "xyzzy" || verb == "plugh" || verb == "plover")
	{
		response = "  A hollow voice says 'Nice Try...'";
	}
	else if (verb == "quit")
	{
		response = "Good Bye!";
	}
	else if (verb == "get")
	{
		response = "There is nothing here by that name.  Hint: Items must be called by their one-word ('Name') values.";
		for (int i = 0; i < 5; i++)	// Instead of hard-coded 5 this should really be a dynamic indicator of item count...
		{
			if (inventory[i])	// Item exists
			{
				if (inventory[i]->getWord() == noun)	// Item is what you want to get
				{
					bool itemHere = false;
					if (inventory[i]->getLocation() == currentLocation)	// Item is here
					{
						itemHere = true;
					}
					if (currentLocation->getType() == "portal")	// There is a portal here
					{
					if (currentLocation->action(2) == "open")	// The portal is open
						{
							if (inventory[i]->getPortalLocation() == currentLocation)	// Item is in the portal
							{
								itemHere = true;
							}
						}
					}
					if (itemHere)	// Item is here or in open portal here
					{
						if (hand[0] && hand[1])	// Hands are full
						{
							response = "Your hands are full.  You'll need to drop something to pick it up.";
						}
						else	// Get it
						{
							// Update portal descriptions when items are moved
							if (inventory[i]->getWord() == "eggo")
							{
								location[2][1]->stringer(1, "  The freezer door is open, revealing some green slime, but no food.");	
							}
							else if (inventory[i]->getWord() == "coke")
							{
								location[2][2]->stringer(1, "  The mini fridge door is open; it contains only sadness.");	
							}
							else if (inventory[i]->getWord() == "key")
							{
								location[4][0]->stringer(1, "  The stall door is open.  There is nothing interesting inside.");
							}
							for (int h = 0; h < 2; h++)	// Find a free hand...
							{
								if (hand[h] == NULL)
								{
									inventory[i]->setLocation(NULL);
									inventory[i]->setPortalLocation(NULL);
									hand[h] = inventory[i];
									if (inventory[i]->getWord() == "key")
									{
										score += 10;
									}
									inventory[i] = NULL;
									h = 2;	// Stop looking
									response = "Got it!";
								}
							}
						}
					}
				}
			}
		}
	}
	else if (verb == "open")
	{
		response = "I don't know what you would open here.";
		if (currentLocation->getType() == "portal")
		{
			response = currentLocation->action(1);
		}
	}
	else if (verb == "close")
	{
		response = "I don't know what you would close here.";
		if (currentLocation->getType() == "portal")
		{
			response = currentLocation->action(0);
		}
	}
	else if (verb == "use")
	{
		response = "You don't have anything by that name.  Hint: Items must be called by their one-word ('Name') values.";
		for (int h = 0; h < 2; h++)
		{
			if (hand[h])	// Something in the hand
			{
				if (hand[h]->getWord() == noun)	// It's what you want to use
				{
					if (noun == "eggo" || noun == "coke")
					{
						health += 30;	// Bump 30 health or to full
						if (health > 100)
						{
							health = 100;
						}
						if (used[0])
						{
							used[1] = hand[h];
						}
						else
						{
							used[0] = hand[h];
						}
						if (accomplishment[0])
						{
							accomplishment[1] = true;
						}
						else
						{
							accomplishment[0] = true;
						}
						score += 10;
						hand[h] = NULL;
						response = "Oh, man, that hit the spot.  You can feel the life coursing through your veins!";
					}
					if (noun == "thumb")
					{
						response = "Aaaaaaaay!  Way to go, there, Fonzie!";
					}
					if (noun == "racket")
					{
						response = "Whiffff!  Anybody got a shuttlecock?";
					}
					if (noun == "key")
					{
						// I had something more elegant in mind for this part...
						if (currentLocation == location[0][5])	// Intern Door
						{
							response = currentLocation->action(1);
						//	location[0][5]->action(1);
						}
						else if (currentLocation == location[0][6])	// Main door
						{
							response = currentLocation->action(1);
							response += "\nThe blue sky and freedom becon just outside!";
							if (!accomplishment[0] && !accomplishment[1])
							{
								response += "\nYou'd better get something to eat before you go.";
							}
							if (!accomplishment[5])
							{
								response += "\nIf you leave this internship without submitting your code you will suffer a fate worse than death!";
							}
						}
						else
						{
							response = "There's nowhere to use it here.";
						}
					}
				}
			}
		}
		if (noun == "button")
		{
			response = "I don't see it here.";
			if (currentLocation == location[4][6])	// At the breaker button
			{
				if (accomplishment[4])	// Already pushed
				{
					response = "Ka-chunk";
				}
				else
				{
					accomplishment[4] = true;
					score += 10;
					response = "With a loud clunk glaring flourescent lights come on.";
					location[4][6]->setMessage("");
					location[4][6]->updateDescription("You are in a bare concrete dead end, where a number of electrical conduits converge.  Industrial flourescent lights\nglare overhead.  A massive circuit breaker adorns the west wall.  The hallway continues to the east.");
					location[4][6]->setShowDescription(true);

					location[5][6]->updateDescription("This is an empty concrete corridor, lit by industrial flourescent lights.  It continues to the west and to the north.");
					location[5][6]->setShowDescription(true);

					location[5][5]->updateDescription("This is an empty concrete corridor, lit by industrial flourescent lights.  It continues to the north and to the south.");
					location[5][5]->setShowDescription(true);

					location[5][4]->updateDescription("This is an empty concrete corridor, lit by industrial\nflourescent lights.  A patch of slime adorns the west wall, and the red emergency lamp is dripping something gooey.\nThe corridor continues to the north and to the south.");
					location[5][4]->setShowDescription(true);
					location[5][4]->setMessage("");

					location[5][3]->updateDescription("This is an empty concrete corridor, lit by industrial flourescent lights.  It continues to the west and to the south.");
					location[5][3]->setShowDescription(true);
					location[5][3]->setMessage("");

					location[4][3]->updateDescription("This is an empty concrete corridor, lit by industrial flourescent lights.  It continues to the west and to the east.");
					location[4][3]->setShowDescription(true);
					location[4][3]->setMessage("");

					location[3][3]->updateDescription("This is an empty concrete corridor, lit by industrial flourescent lights.  It continues to the west and to the east.");
					location[3][3]->setShowDescription(true);
					location[3][3]->setMessage("");

					location[2][3]->updateDescription("This is an empty concrete corridor, lit by industrial flourescent lights.  It continues to the west and to the east.");
					location[2][3]->setShowDescription(true);

					location[1][3]->updateDescription("This is an empty concrete corridor, lit by industrial flourescent lights.  It continues to the west and to the east.");
					location[1][3]->setShowDescription(true);

					location[0][3]->updateDescription("This is an empty concrete corridor, lit by industrial flourescent lights.\nIt continues to the east, and to the south you see what appears to be a laboratory space.");
					location[0][3]->setShowDescription(true);
				}
			}
		}
		if (noun == "terminal")
		{
			response = "I don't see any terminal here.";
			if (currentLocation == location[4][5])	// At the terminal
			{
				if (accomplishment[5])	// Already submitted
				{
					response = "You try to play some 'Star Trek', but whoever programmed it thought it was smart to have you manually seed the pseudorandom\nnumber generator instead of just using the system clock and it's not really very fun...";
				}
				else
				{
					accomplishment[5] = true;
					score += 25;
					location[4][5]->updateDescription("You and Jerry spent the summer and early fall in these cubicles, but your stuff is all out, you are done with your trusty terminal, and it's time to head back home.  The intern restroom is to your north and the heavy security doors are to your west.");
					response = "Huzzah!  You have successfully submitted the package of code you've worked on all summer.\nYou should probably get out of here before you're killed, though!";
					location[4][5]->setMessage("");
				}
			}
		}
	}
	else if (verb == "drop")
	{
		response = "You don't have anything by that name.  Hint: Items must be called by their one-word ('Name') values.";
		for (int h = 0; h < 2; h++)	// OK to hard-code since I've limited to two hands
		{
			if (hand[h])	// Something in the hand to check
			{
				if (hand[h]->getWord() == noun)	// It's what you want to drop
				{
					for (int i = 0; i < 5; i++)	// Find an on-board item 'spot'
					{
						if (inventory[i] == NULL)
						{
							inventory[i] = hand[h];	// Put it in a free spot
							inventory[i]->setLocation(currentLocation);	// Let it know were it is
							hand[h] = NULL;	// Empty the hand
							response = ("So long, " + inventory[i]->getWord() + "!");
							i = 5;	// Stop looking for a spot
							h = 2;	// Stop looking for a hand with the thing
						}
					}
				}
			}
		}
	}
	else if (verb == "map")
	{
		response = "        ##### MAP OF THE KNOWN (INTERN) WORLD #####\n        +---------+-------+-------+-------+-------+\n        | Applied |  NW   |       |       | Intern|\n        |  Psych  | Hall    North |   NE  |  Rest |\n        | (OFF-   |   &      Hall |  Hall |  Room |\n        | LIMITS) |Lounge |       |       |       |\n        +---------+--   --+--   --+--   --+--   --+\n        |         |       | ***** |       | Intern|\n        |  Lobby  # West    Break   East  #  Cube |\n        |         # Hall     Room   Hall  #  Farm |\n        |         |       | ***** |       |       |\n        +---###---+--   --+--   --+--   --+-------+\n        |         |       | South |       |\nPARKING # Security|  SW   | Hall/ |  SE   | # = Security\n  AREA  # Entryway| Hall  | Water | Hall  |      Doors\n        |         |       | Cooler|       |\n        +---------+-------+-------+-------+";
	}
	else if (verb == "run")
	{
		if (noun == "n" || noun == "e" || noun == "s" || noun == "w")
		{
			Space* temp = currentLocation;
			currentLocation = currentLocation->go(currentLocation, noun);
			temp = currentLocation;
			currentLocation = currentLocation->go(currentLocation, noun);
			if (temp == currentLocation)
			{
				health -= 5;
				response = "You ran into a wall and really hurt yourself!";
			}
		}
		else	// Run needs direction
		{
			response = "You ran a nice tight circle and almost pulled a hammy (supply a direction to actually go anywhere).";
		}
	}
	else if (verb == "touch")
	{
		if (currentLocation->getType() == "light")	// You're at a light
		{
			if (accomplishment[2])
			{
				response = "You fiddle around with the lamp, which sparkles curiously.  But you should probably see where Jerry's gotten off to.";
			}
			else
			{
				response = currentLocation->action(1);
				location[3][1]->action(1);	// Open the doors now
				location[4][1]->action(1);	// Open the other side, too
				accomplishment[2] = true;
				score += 10;
				location[1][0]->setMessage("  Faintly, as if from another world, you can hear Jerry to your east urgently singing the 'Alka-Seltzer' jingle from TV.");
				location[2][0]->setMessage("  Faintly, as if from another world, you can hear Jerry to your south and east urgently singing the 'Alka-Seltzer'\njingle from TV.");
				location[3][0]->setMessage("  Faintly, as if from another world, you can hear Jerry to your south urgently singing the 'Alka-Seltzer' jingle\nfrom TV.");
				location[2][1]->setMessage("  Faintly, as if from another world, you can hear Jerry to your east urgently singing the 'Alka-Seltzer' jingle from TV.");
				location[3][1]->setMessage("  The security doors to the intern area to your east are open - when is that going to happen again?\n  Faintly, as if from another world, you can hear Jerry to your east urgently singing the 'Alka-Seltzer' jingle from TV.");
				location[3][2]->setMessage("  Faintly, as if from another world, you can hear Jerry to your north urgently singing the 'Alka-Seltzer' jingle\nfrom TV.");
			}
		}
		else
		{
			response = "I'm not sure I even know what you're trying to touch.  Let's just say nothing happened.";
		}
	}
	else if (verb == "look")
	{
		cout << currentLocation->getDescription() << "\n";
	}
	else
	{
		response = "Sorry - I don't know how to do that.  Try 'help' to see what I can do.";
	}
	return response;
}

Game::~Game()
// Destructor - CLEAN UP!
{
	// Cleanup Items
	for (int x = 0; x < 5; x++)
	{
		if (inventory[x])
		{
			delete inventory[x];
			inventory[x] = NULL;
		}
	}
	for (int x = 0; x < 2; x++)
	{
		if (used[x])
		{
			delete used[x];
			used[x] = NULL;
		}
	}
	for (int x = 0; x < 2; x++)
	{
		if (hand[x])
		{
			delete hand[x];
			hand[x] = NULL;
		}
	}
	// Cleanup Spaces
	currentLocation = NULL;
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			if (location[x][y])
			{
				//cout << "...Deleting[" << x << "][" << y << "]";
				delete location[x][y];
				location[x][y] = NULL;
			}
		}
	}
	cout << "\n";
	delete exit;
	exit = NULL;
	delete lib;
	lib = NULL;
	return;
}
