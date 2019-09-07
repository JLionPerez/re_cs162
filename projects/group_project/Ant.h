#pragma once
#include "Critter.h"
class Ant : public Critter
{
public:
	Ant();
	~Ant();

	char getCellSymbol() override;
};

