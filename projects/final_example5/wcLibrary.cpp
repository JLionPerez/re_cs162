/*******************************************************************************
**	Program Name:	wcLibrary.cpp
**	Author:			Will Clayton
**	Date:			2017-12-05 - VERSION 1.07
**	Description:	'wcLibrary' class implementation file
**			Will's reusable component library.
*******************************************************************************/

#include "wcLibrary.hpp"

#include <iostream>
using std::cout;
using std::cin;
#include <cstdlib>	// Header file needed to use srand and rand
#include <ctime>	// Header file needed to use time
#include <sstream>	// Prepackage some functions here since I'll be adding my tool set anyway...


// CONTRUCTOR - Create new wcLibrary
wcLibrary::wcLibrary ()
{
	unsigned seed = time(0);
	srand(seed);
}

int wcLibrary::validInteger(int lowVal, int highVal)
// Loop until the user enters an integer between the two values
{
	int 	keepTrying = 1,
			response = 0;
	double	tempResponse = 0;
	string	theInput = "";
	int		multiplier = 1;

	while (keepTrying)
	{
		keepTrying = 1;	// Un-set error condition for next try
		multiplier = 1;
		response = 0;

		cout << "Enter an integer between " << lowVal << " and " << highVal << ": ";
		getline(cin, theInput);	// This is much better at handling strange inputs

		if (theInput.length() )	// Only parse non-empty inputs
		{
			int processLength = theInput.length()-1;
			if (processLength > 10)	// Don't process strings that can't be valid integers
			{
				processLength = -1;
				keepTrying = 2;	// Signify bad input
				cout << "** That is not a valid number **\n";
			}
			for (int i=processLength; i>=0; i--)	// Parse each character in turn
			{
				char temp = theInput[i];
				if (temp == 45 && i==0)	// Negative Sign
				{
					multiplier = -1;
				}
				else if (temp < 48 || temp > 57)	// Non-numeric characters were supplied
				{
					keepTrying = 2;	// Signify bad input
					i = -1;	// Stop parsing
					cout << "** That is not a valid number **\n";
				}
				else	// Add numeric character value to response
				{
					int digitHolder = theInput[i]-48;
					for (int e=0; e < (theInput.length()-i)-1; e++)
					{
						digitHolder *= 10;
					}
					tempResponse += digitHolder;
				}
			}
		}
		else	// Empty response
		{
			keepTrying = 2;	// Set error flag
		}
		if (tempResponse > 2147483647)	// Numeric input bigger than int
		{
			keepTrying = 2;	// Set error flag
			cout << "** That is not a valid number **\n";
		}
		if (keepTrying == 1 && tempResponse < lowVal)
		{
			cout << "** That number is too low **\n";
		}
		else if (keepTrying == 1 && tempResponse > highVal)
		{
			cout << "** That number is too high **\n";
		}
		else if (keepTrying == 1)	// No error was encountered
		{
			keepTrying = 0;
		}
		response = tempResponse;
		tempResponse = 0;
	}
	response *= multiplier;
	return response;
}

float wcLibrary::validFloat(float lowVal, float highVal)
// Loop until user enters float between two values (no negative number support in this version)
{
	bool keepTrying = true;	// Sentinal for valid input received
	float response;
	while (keepTrying)	// Repeat until valid input is received
	{
		response = 0.0;
		string input;
		cout << "Enter a number (float) between " << lowVal << " and " << highVal << ": ";
		getline(cin, input);

		if (input.length() &&  input.length() < 10)	// Only parse non-empty inputs less than 10 characters
		{
			keepTrying = false;	// Stop prompting for input unless an error is encountered
			int offset = 1;		// Compensate for off-by-one and/or numbers after decimal
			double tempResponse = 0.0;
			bool foundDecimalPoint = false;
			for (int i=input.length()-1; i>=0; i--)	// Parse the string from right to left
			{
				char temp = input[i];
				if (temp > 47 && temp < 58)	// Valid Number
				{
					float placeValue = temp - 48;	// Convert character to numerical digit
					for (int z = offset; z < (input.length()-i); z++)	// Multiple it by its 'places' to get the actual value
					{
						placeValue *= 10;
					}
					response += placeValue;	// Add the character's value to the response
				}
				else if (!foundDecimalPoint && temp == 46)	// Decimal Point (only one so far)
				{
					for (int z = 1; z < (input.length()-i); z++)
					{
						response /= 10;
						offset++;
					}
					offset++;	// One more to account for the decimal point character
				}
				else if (temp == 46)	// Decimal Point (REPEAT)
				{
					cout << "** Valid numbers contain a maximum of one decimal point **\n";
					keepTrying = true;
					i = 0;
				}
				else	// Invalid Character
				{
					cout << "** Input contains invalid character(s) **\n";
					keepTrying = true;
					i = 0;
				}
			}
		}
		else if (input.length() > 10)	// Input too long
		{
			cout << "** Let's stick to 10 characters or less, please **\n";
		}
		if (!keepTrying && response > highVal)	// Valid float but higher than maximum
		{
			cout << "** Input is too high **\n";
			keepTrying = true;
		}
		else if (!keepTrying && response < lowVal)	// Valid float but lower than minimum
		{
			cout << "** Input is too low **\n";
			keepTrying = true;
		}
	}
	return response;
}

// Function	'marquee' - print the string, wrapped in stars
void wcLibrary::marquee (string toDisplay)
{
	string border = "\n";
	for (int i = 0; i < (toDisplay.length() + 6); i++)
	{
		border += "*";
	}
	cout << border << "\n** " << toDisplay << " **" << border << "\n\n";
	return;
}

// Function 'doOrNot' - present the user with a default and an action and return their selection
bool wcLibrary::doOrNot (string doNotLabel, string doLabel)
{
	cout << "How would you like to proceed?\n   1) " << doLabel;
	cout << "\n   2) " << doNotLabel << "\n";
	
	if (validInteger(1,2) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Function 'getInteger' - show the user the prompt and return a supplied integer between 2 values
int wcLibrary::getInteger(string message, int lowerBound, int upperBound)
{
	cout << message << "\n";
	return validInteger(lowerBound,upperBound);
}

// Function 'getFloat' - show the user the prompt and return a supplied float between 2 values
float wcLibrary::getFloat(string message, float lowerBound, float upperBound)
{
	cout << message << "\n";
	return validFloat(lowerBound,upperBound);
}

// Function 'randomInt' - return a randomly-selected integer between the supplied values, per Chapter 3
int wcLibrary::randomInt(int lowerBound, int upperBound, int multiplier)
{
	unsigned seed = time(0);
	srand(seed*multiplier);	// I think I am calling this function so quickly it is getting the same seed; I could probably fix this by finding a more precise unit of time, but I'll just brute-force it like this for now
	return (rand() % upperBound) + lowerBound;
}

// Function 'getString' - prompt, then limit the length of the returned string
string wcLibrary::getString(string message, int maxLength)
{
	bool keepTrying = true;	// Sentinal for valid input received
	string response = "";

	while (keepTrying)	// Repeat until valid input is received
	{
		string input;
		cout << message << " (Max " << maxLength << " chars): ";
		getline(cin, input);

		// Trim leading spaces
		while (input[0] == ' ')
		{
			input = input.substr(1);
		}
		// Trim trailing spaces
		while (input[(input.length()-1)] == ' ')
		{
			input = input.substr(0,(input.length()-1) );
		}
		// Convert strange characters to underscore (_)
		for (int x = 0; x < input.length(); x++)
		{
			char temp = input[x];
			if (temp < 32 || temp > 126)
			{
				input[x] = '_';
			}
		}
		keepTrying = false;
		if (input.length() > maxLength)
		{
			cout << "  Please limit your response to " << maxLength << " characters or less.\n";
			keepTrying = true;
		}
		else if (input.length() == 0)	// Blank: Just repeat prompt
		{
			keepTrying = true;
		}
		response = input;
	}
	return response;
}

// Function 'getStringMinPrompt' - prompt, then limit the length of the returned string, but don't output limit
string wcLibrary::getStringMinPrompt(string message, int maxLength)
{
	bool keepTrying = true;	// Sentinal for valid input received
	string response = "";

	while (keepTrying)	// Repeat until valid input is received
	{
		string input;
		cout << message;
		getline(cin, input);

		// Trim leading spaces
		while (input[0] == ' ')
		{
			input = input.substr(1);
		}
		// Trim trailing spaces
		while (input[(input.length()-1)] == ' ')
		{
			input = input.substr(0,(input.length()-1) );
		}
		// Convert strange characters to underscore (_)
		for (int x = 0; x < input.length(); x++)
		{
			char temp = input[x];
			if (temp < 32 || temp > 126)
			{
				input[x] = '_';
			}
		}
		keepTrying = false;
		if (input.length() > maxLength)
		{
			cout << "  Please limit your response to " << maxLength << " characters or less.\n";
			keepTrying = true;
		}
		else if (input.length() == 0)	// Blank: Just repeat prompt
		{
			cout << "I beg your pardon?\n\n";
			keepTrying = true;
		}
		response = input;
	}
	return response;
}

// Get a single character from a string, return the int of its position in the string
int wcLibrary::getChar(string choices)
{
	int response = -1;
	bool keepTrying = true;	// Sentinal for valid input received
	while (keepTrying)	// Repeat until valid input is received
	{
		string input;

		cout << "Enter the character corresponding to your choice (" << choices[0];
		for (int x = 1; x < choices.length(); x++)
		{
			cout << "/" << choices[x];
		}
		cout << "): ";

		getline(cin, input);

		if (input.length() == 1)	// Valid character
		{
			keepTrying = false;
			for (int x = 0; x < choices.length(); x++)
			{
				if (tolower(input[0]) == tolower(choices[x]) )
				{
					response = x;
					x = choices.length();
				}
			}
			if (response == -1)
			{
				cout << "Hey, just what you see, pal. (Invalid character)\n";
				keepTrying = true;
			}
		}
		else if (input.length() > 1)	// Too many characters!
		{
			cout << "  One character only, please.\n";
		}
	}
	return response;
}

int wcLibrary::newRandomInt(int lowerBound, int upperBound)
// A better way to get a randoim integer
{
	int range = upperBound - lowerBound + 1;
	float mid = range + 0.0;
	float fraction = mid * rand() / 2147483647.0;
	int response = fraction;
	response += lowerBound;
	if (response > upperBound)	// Just in case fraction works out to exactly 1.0
	{
		response = upperBound;
	}
	return response;
}

string wcLibrary::appendFileName(string fileName, string appendValue)
// Return the file name with appendValue between the base and the suffix
{
	bool lookingForDot = true;
	string response;
	for (int i = 0; i < fileName.length(); i++)
	{
		if (lookingForDot && fileName[i]=='.')	// Found the dot!
		{
			lookingForDot = false;		// Stop looking
			response += appendValue;	// Append the value before the suffix
			response += fileName[i];
		}
		else if (fileName[i] > 44 && fileName[i] < 123)
		{
			response += fileName[i];
		}
	}
	if (lookingForDot)	// There was no dot -- append value to end of fileName
	{
		response += appendValue;
	}
	return response;
}

string wcLibrary::stringOrDefault(string message, int maxLength, string defaultValue)
// Function 'stringOrDefault' - prompt, then limit the length of the returned string, return default if blank
{
	bool keepTrying = true;	// Sentinal for valid input received
	string response = "";

	while (keepTrying)	// Repeat until valid input is received
	{
		string input;
		cout << message << " (Max " << maxLength << " chars), or ENTER to use '" << defaultValue << "': ";
		getline(cin, input);

		// Trim leading spaces
		while (input[0] == ' ')
		{
			input = input.substr(1);
		}
		// Trim trailing spaces
		while (input[(input.length()-1)] == ' ')
		{
			input = input.substr(0,(input.length()-1) );
		}
		// Convert strange characters to underscore (_)
		for (int x = 0; x < input.length(); x++)
		{
			char temp = input[x];
			if (temp < 32 || temp > 126)
			{
				input[x] = '_';
			}
		}
		keepTrying = false;
		if (input.length() > maxLength)
		{
			cout << "  Please limit your response to " << maxLength << " characters or less.\n";
			keepTrying = true;
		}
		else if (input.length() == 0)	// Blank: Just repeat prompt
		{
			keepTrying = false;
			input = defaultValue;
			cout << "      Using default value '" << defaultValue << "'\n";
		}
		response = input;
	}
	return response;
}

string wcLibrary::intAsString(int source)
// Packaged way to convert ints to strings
{
	std::stringstream processor;
	processor << source;
	return processor.str();
}

void wcLibrary::pause(string message)
// Prompt for ENTER with message, proceed afterward
{
	cout << "Press ENTER " << message;
	string nothing;
	getline(cin, nothing);
}
