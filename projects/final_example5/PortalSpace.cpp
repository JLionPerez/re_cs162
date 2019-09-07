/*******************************************************************************
**	Program Name:	PortalSpace.cpp
**	Author:			Will Clayton
**	Date:			2017-10-29
**	Description:	Class Definition
*******************************************************************************/

#include "PortalSpace.hpp"


PortalSpace::PortalSpace(string newName, string newDescription)
// Constructor - set name & description
{
	type = "portal";
	name = newName;
	description = newDescription;
	portalOpen = false;
	closedState = "closed";
	openState = "open";
	return;
}

string PortalSpace::action(int code)
// Player interacts with the portal - 0:Close; 1:Open; 2:getState
{
	switch (code)
	{
		case 0:		portalOpen = false;
					specialMessage = closedState;
					return "You closed it.";
		case 1:		portalOpen = true;
					specialMessage = openState;
					return "You opened it.";
		case 2:		if (portalOpen)
					{
						return "open";
					}
					else
					{
						return "closed";
					}
		default:	return "Portal Default";
	}
}

string PortalSpace::stringer(int code, string value)
// Update portal description text - 0:Close; 1:Open
{
	switch (code)
	{
		case 0:		closedState = value;
					return "Closed State Updated";
		case 1:		openState = value;
					if (portalOpen)
					{
						specialMessage = value;
					}
					return "Open State Updated";
		default:	return "Portal Default";
	}
}

PortalSpace::~PortalSpace()
// Destructor
{
	return;
}