#pragma once
#include "Critter.h"
class Doodlebug : public Critter
{
public:
	Doodlebug();
	~Doodlebug();

	char getCellSymbol() override;
};

