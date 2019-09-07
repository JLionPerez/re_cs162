/*******************************************************************************
**	Program Name:	NormalSpace.cpp
**	Author:			Will Clayton
**	Date:			2017-10-29
**	Description:	Class Definition
*******************************************************************************/

#include "NormalSpace.hpp"

NormalSpace::NormalSpace(string newName, string newDescription)
// Constructor - set name & description
{
	type = "normal";
	name = newName;
	description = newDescription;
	return;
}