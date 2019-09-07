#include "pch.h"
#include "Simulation.h"


Simulation::Simulation()
{
	// Allocate memory for 2D array
	critters = new Critter**[ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		critters[i] = new Critter*[COLS];
	}

	// Initialize the entire array with Critter objects (not sure if this is correct, but it just works)
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			critters[i][j] = new Critter; // I tried nullptr, but it prevented me from calling Critter functions.
		}
	}
}
 

Simulation::~Simulation()
{
}

void Simulation::initSim()
{
	while (choice < 2)
	{
		cout << "Enter a choice" << endl
			<< "1. Enter steps" << endl
			<< "2. Exit" << endl;
		choice = getValidInt(min, max_menu);
		switch (choice)
		{
		case 1:
		{
			int steps = 0;
			cout << "Enter steps" << endl;
			steps = getValidInt(min, max_steps);
			cout << "beginning sim" << endl;
			beginSim(steps);
		}
		break;
		case 2:
		{
			cout << "Exiting program" << endl;
			break;
		}
		default:
			break;
		}
	}
}
void Simulation::displayGrid()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << critters[i][j]->getCellSymbol();
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Simulation::beginSim(int steps)
{
	// Initialize the board with the critters
	for (int i = 0; i < numAnts; i++)
	{
		placeAnt();
	}
	for (int i = 0; i < numDoodlebugs; i++)
	{
		placeDB();
	}
	displayGrid(); // for testing purposes, not needed.
	
	
	int step_counter = 0;
	while (step_counter < steps)
	{
		// This is where all the magic happens.

		/*** HOW EACH STEP WILL GO ***/

		/* 1. MOVE DOODLEBUGS */
			// Margaret you write your functions here
			// If ant, eat the ant

		//starve();
		/* 2. CHECK IF DOODLEBUG STARVED */
			// If it reaches 8 time steps without eating, it dies.
			// delete DB at position
			// assign it a new Critter object
			// critters[row][column] = new critter // This will delete the doodlebug
			// Because the "movement" will be determined on whether there is an ant nearby to eat.
			// From website: For every time step, the doodlebug will firstly try to move to an adjacent cell containing an ant and eat the ant


		/* 3. CHECK IF DOODLEBUG CAN SPAWN ANOTHER DB */
			// Spawns after 8 time steps
			// 
		
		/* 4. MOVE ANTS */
		
		
		
		/* 5. CHECK AGE FOR BREEDING */
			// if ant old enough, it breeds if there is space

		// That's basically it.

		//displayGrid(); // after every step
		step_counter++;
	}
}

// Places a doodlebug in an empty space
void Simulation::placeAnt()
{
	srand(time(NULL));

	int critterRow = rand() % 19;
	int critterColumn = rand() % 19;
	char symbol;
	symbol = critters[critterRow][critterColumn]->getCellSymbol();	// Get the symbol of the randomized object
	
	// If the symbol is already there, call the function again
	if (symbol == 'O' || symbol == 'X')
	{
		placeAnt();
	}
	else // Add ant object
	{
		critters[critterRow][critterColumn] = new Ant;
	}
}

// Places a doodlebug in an empty space
void Simulation::placeDB()
{
	srand(time(NULL));
	int critterRow = rand() % 19;
	int critterColumn = rand() % 19;
	char symbol;
	symbol = critters[critterRow][critterColumn]->getCellSymbol();	// Get the symbol for whatever object is there.
	
	// If the symbol is already there, call the function again
	if (symbol == 'O' || symbol == 'X')
	{
		placeDB();
	}
	else // Add DB object
	{
		critters[critterRow][critterColumn] = new Doodlebug;
	}
}

void Simulation::starve(Critter db)
{

}


