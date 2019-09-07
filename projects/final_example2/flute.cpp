//#include "stdafx.h"
/*****************************************************************
**Author: Dylan Markovic
**Date: 12.6.2016
**Description: Final "flute Imp File"
******************************************************************/
#include "flute.hpp"

/********************************************************************
**Function:constructor
**Description: creates instance of flute
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
flute::flute()
{
	this->setBody('f');
	this->name = "Flute";
}

/********************************************************************
**Function:destructor
**Description: destroys instance of flute
**Parameters:none
**Pre-Conditions: none
**Post-Conditions: none
**Return: none
*******************************************************************/
flute::~flute()
{
}
