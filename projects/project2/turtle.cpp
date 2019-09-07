/*
* File name: turtle.cpp
* Purpose: Holds defintions for turtle.hpp
*/

#include "turtle.hpp"

/*
* Function name: Turtle()
* Purpose: Default constructor to initialize private members
* Arguments: none
* Returns: none
*/
Turtle::Turtle()
{
    age = 0;
    cost = 100;
    num_babies = 10;
    base_food_cost = 5;
    payoff = 5;
}