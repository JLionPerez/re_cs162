/*******************************************************************************
**	Program Name:	DoorSpace.cpp
**	Author:			Will Clayton
**	Date:			2017-10-29
**	Description:	Class Definition
*******************************************************************************/

#include "DoorSpace.hpp"

DoorSpace::DoorSpace(string newName, string newDescription)
// Constructor - set name & description
{
	type				=	"door";
	name 				=	newName;
	description			=	newDescription;
	holdLock			=	false;
	lockEastLocation	=	NULL;
	lockWestLocation	=	NULL;
	return;
}

string DoorSpace::action(int code)
// Player interacts with the door - 0:Lock; 1:Unlock; 2:HoldOpen; 3:GetState("0"/"1"); 4:GetDirection ("0"/"1")
{
	switch (code)
	{
		case 0:		if (lockEastLocation)
					{
						right = NULL;
					}
					else if (lockWestLocation)
					{
						left = NULL;
					}
					return "The doors are now closed";
		case 1:		if (lockEastLocation)
					{
						right = lockEastLocation;
					}
					else if (lockWestLocation)
					{
						left = lockWestLocation;
					}
					return "The doors open with a mechanical whirring";
		case 2:		holdLock = true;
					return "HOLDLOCK";
		case 3:		if (lockEastLocation)
					{
						if (right)
						{
							return "1";
						}
						else
						{
							return "0";
						}
					}
					else if (lockWestLocation)
					{
						if (left)
						{
							return "1";
						}
						else
						{
							return "0";
						}
					}
					else
					{
						return "2";
					}
		case 4:		if (lockWestLocation)
					{
						return "0";
					}
					if (lockEastLocation)
					{
						return "1";
					}
					return "";
		default:	return "";
	}
}

string DoorSpace::spacer(int code, Space* newSpace)	// code - 0:west; 1:east;
{
	switch (code)
	{
		case 0:		lockWestLocation = left;
					return "West door lockable";
		case 1:		lockEastLocation = right;
					return "East door lockable";
		default:	return "Door Spacer Default";
	}
	return "DoorSpace Spacer";
}
