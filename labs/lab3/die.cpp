/*
* File name: die.cpp
* Purpose: Holds definitions for prototypes in die.hpp.
*/
#include "die.hpp"

/*
* Function Name: get_sides()
* Purpose: Returns private member
* Arguments: none
* Returns: integer
*/
int Die::get_sides()
{
    return sides;
}

/*
* Function Name: set_sides()
* Purpose: Sets the private member to an integer
* Arguments: integer
* Returns: none
*/
void Die::set_sides(int sides)
{
    this->sides = sides;
}

/*
* Function Name: get_score()
* Purpose: To return a private member
* Arguments: none
* Returns: integer
*/
int Die::get_score()
{
    return score;
}

/*
* Function Name: set_score()
* Purpose: To a member variable to an integer
* Arguments: integer
* Returns: none
*/
void Die::set_score(int score)
{
    this->score = score;
}

/*
* Function Name: roll()
* Purpose: To roll a randomly generated number from 1 to number of sides
* Arguments: none
* Returns: integer
*/
int Die::roll() 
{
    srand(time(NULL));
    int rolled = rand() % sides + 1;
    return rolled;
}

/*
* Function Name: Die()
* Purpose: Default constructor sets members to 0
* Arguments: none
* Returns: none
*/
Die::Die()
{
    score = 0;
}