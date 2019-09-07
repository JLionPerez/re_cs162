/*******************************************************************************
**	Program Name:	Item.cpp
**	Author:			Will Clayton
**	Date:			2017-12-05
**	Description:	'Item' class implementation file
*******************************************************************************/

#include "Item.hpp"


Item::Item(string theName, string theWord)
// Constructor
{
	name = theName;
	word = theWord;
	location = NULL;
	portalLocation = NULL;
}

string Item::getName()
// Return the name
{
	return name;
}

string Item::getWord()
// Return the single word representing the object
{
	return word;
}

void Item::setLocation(Space* theLocation)
// Set the item's primary location
{
	location = theLocation;
}

Space* Item::getLocation()
// Return the item's primary location
{
	return location;
}

void Item::setPortalLocation(Space* theLocation)
// Set the location from which the itme can be recovered by portal
{
	portalLocation = theLocation;
}

Space* Item::getPortalLocation()
// Get the location from which the item can be recovered by portal
{
	return portalLocation;
}
