#include "pch.h"
#include "Doodlebug.h"


Doodlebug::Doodlebug()
{
	cell_symbol = 'X';
}


Doodlebug::~Doodlebug()
{
}

char Doodlebug::getCellSymbol()
{
	return cell_symbol;
}