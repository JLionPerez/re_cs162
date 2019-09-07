#include "pch.h"
#include "Ant.h"


Ant::Ant()
{
	cell_symbol = 'O';
}


Ant::~Ant()
{
}

char Ant::getCellSymbol()
{
	return cell_symbol;
}