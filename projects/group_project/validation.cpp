#include "pch.h"
#include "validation.h"


int getValidInt(int &min, int &max)
{
	int out;
	std::string in;

	while (true)
	{
		std::cout << "Enter an integer between " << min << " and " << max << ": ";
		//gets user input as a string
		std::getline(std::cin, in);
		//converts user input into a stream to convert to int
		std::stringstream ss(in);

		//checks for valid conversion to int, rejects unconverted input
		//makes sure number is in range
		if ((ss >> out) && (!(ss >> in)) && (out >= min) && (out <= max))
		{
			return out;
		}
		//clears any std::cin error
		std::cin.clear();
		//error with stream
		std::cerr << "\nInvalid input. Please try again.\n";
	}
}
