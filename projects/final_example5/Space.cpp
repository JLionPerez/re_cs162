/*******************************************************************************
**	Program Name:	Space.hpp
**	Author:			Will Clayton
**	Date:			2017-12-05
**	Description:	Class declaration
*******************************************************************************/

#include "Space.hpp"

Space::Space()
// Constructor
{
	top				= NULL;
	right			= NULL;
	left			= NULL;
	bottom			= NULL;
	upsideDown		= false;
	showDescription	= true;
	specialMessage	= "";
}

void Space::updateDescription(string newDescription)
// Set the description to a new value
{
	description = newDescription;
}

string Space::getType()
// Return the 'type' string of the Space
{
	return type;
}

string Space::getName()
// Return the assigned name
{
	return name;
}

string Space::getDescription()
// Return the assigned description
{
	return description;
}

void Space::setMessage(string message)
// Assign a special Message
{
	specialMessage = message;
}

bool Space::hasMessage()
// Tell whether the Place has a special message
{
	if (specialMessage.length() )
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Space::getMessage()
// Get the special message
{
	return specialMessage;
}

Space* Space::go(Space* currentLocation, string direction)
// Attempt to move in the specified direction; return new location (or old location if fail)
{
	if (direction == "n" && top)
	{
		return top;
	}
	else if (direction == "e" && right)
	{
		return right;
	}
	else if (direction == "s" && bottom)
	{
		return bottom;
	}
	else if (direction == "w" && left)
	{
		return left;
	}
	else
	{
		return currentLocation;
	}
}

void Space::setNorth(Space* newLocation)
// Assign the neighboring space to the north (top)
{
	top = newLocation;
}

void Space::setEast(Space* newLocation)
// Assign the neighboring space to the east (right)
{
	right = newLocation;
}

void Space::setSouth(Space* newLocation)
// Assign the neighboring space to the south (bottom)
{
	bottom = newLocation;
}

void Space::setWest(Space* newLocation)
// Assign the neighboring space to the west (left)
{
	left = newLocation;
}

void Space::setUpsideDown(bool newValue)
//
{
	upsideDown = newValue;
}

bool Space::isUpsideDown()
//
{
	return upsideDown;
}
void Space::setShowDescription(bool newValue)
//
{
	showDescription = newValue;
}

bool Space::doShowDescription()
// Return 
{
	return showDescription;
}

string Space::action(int)
// Perform class-specific action(s)
{
	return "ACTION: BASE CLASS";
}

string Space::spacer(int code, Space* newSpace)
// Perform class-specific place manipulations
{
	return "PLACER: BASE CLASS";
}

string Space::stringer(int code, string value)
// Perform class-specific place manipulations
{
	return "STRINGER: BASE CLASS";
}

Space::~Space()
// Destructor
{
	return;
}