/*
* File name: penguin.cpp
* Purpose: Holds defintiions for penguin.hpp
*/

#include "penguin.hpp"

/*
* Function name: Penguin()
* Purpose: Default constructor to initialize private members
* Arguments: none
* Returns: none
*/
Penguin::Penguin()
{
    age = 0;
    cost = 1000;
    num_babies = 5;
    base_food_cost = 10;
    payoff = 100;
}