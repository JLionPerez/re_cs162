#pragma once
#include "namespaces.h"
class Critter
{
protected:
	char cell_symbol;
public:
	Critter();
	~Critter();

	virtual char getCellSymbol();
};

