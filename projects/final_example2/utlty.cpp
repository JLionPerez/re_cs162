//#include "stdafx.h"
/**************************************************
* **Author: Dylan Markovic
* **Date: 10.9.2016
* **Description: "UTLTY Implementation File"
*************************************************/
#include <limits>
#include "utlty.hpp"
#include <iostream>
#include <cmath>
#include "entryRoom.hpp"
#include "snakeRoom.hpp"


/*********************************************************
* Function: print2DCharArr
* Description: prints 2d char array
* Parameters: char**, int for rows, and int for columns
* PreConditions: none
* PostConditions: none
* Return: void
*******************************************************/
void print2DCharArr(char** matrix, int row, int col)
{
	for (int j = 0; j < col; j++)
	{
		for (int i = 0; i < row; i++)
		{
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}
}


//checks to make sure the user enters an integer
/*******************************************************
* Function: intCheck
* Descriptoin: makes sure user input is int
* Parameters: none
* Preconditions: none
* PostConditions: none
* Return: int
* ****************************************************/
int intCheck()

{
	int x = 0;
	while (!(std::cin >> x))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Value must be an integer\n"
			<<"Decimals will be ignored\n";
	}
	return x;
}


/*******************************************************
* Function:getRand
* Descriptoin: returns random number from rand()
it seems that rand() does not always act random without this
* Parameters: none
* Preconditions: none
* PostConditions: none
* Return: int
* ****************************************************/
int getRand()
{
	return rand();
}
