#include "pch.h"
#include "Critter.h"


Critter::Critter()
{
	cell_symbol = ' ';
}

Critter::~Critter()
{
}

char Critter::getCellSymbol()
{
	return cell_symbol;
}
