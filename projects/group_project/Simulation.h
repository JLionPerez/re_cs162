#pragma once
#include "Critter.h"
#include "namespaces.h"
#include "validation.h"
#include "Ant.h"
#include "Doodlebug.h"

#include <ctime>
#include <cstdlib>

class Simulation
{
private:
	const int ROWS = 20;	// define grid size
	const int COLS = 20;	
	int max_steps = 15;		// Max number of iterations
	int min = 1;		
	int max_menu = 2;
	int choice = 0;
	int numAnts = 100;
	int numDoodlebugs = 5;
	Critter ***critters;		// initialize 400 pointers to critters
 
public:
	Simulation();
	~Simulation();

	void initSim();
	void displayGrid();
	void beginSim(int);
	void placeAnt();
	void placeDB();

	void starve(Critter bd);	//deletes doodlebug
};

