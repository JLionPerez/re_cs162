/*******************************************************************************
**	Program Name:	LightSpace.cpp
**	Author:			Will Clayton
**	Date:			2017-10-29
**	Description:	Class Definition
*******************************************************************************/

#include "LightSpace.hpp"


LightSpace::LightSpace(string newName, string newDescription)
// Constructor - set name & description
{
	type = "light";
	name = newName;
	description = newDescription;
	return;
}

string LightSpace::action(int code)
// Player interacts with the light
{
	switch (code)
	{
		case 1:		return "You fiddle around with the lamp, which sparkles curiously.  Faintly - as if from another world - you hear Jerry abruptly\nstop singing and exclaim 'Shazbot!'";
		default:	return "";
	}
}
