/*
* File name:animal.cpp
* Purpose: Holds definitions for animal.hpp
*/

#include "animal.hpp"

/*
* Function name: get_age()
* Purpose: Returns private member to be available outside of class
* Arguments: none
* Returns: integer
*/
int Animal::get_age()
{
    return age;
}

/*
* Function name: set_age()
* Purpose: Sets private member to passed value
* Arguments: integer
* Returns: none
*/
void Animal::set_age(int age)
{
    this->age = age;
}

/*
* Function name: get_cost()
* Purpose: Returns private member to be available outside of class
* Arguments: none
* Returns: double
*/
double Animal::get_cost()
{
    return cost;
}

/*
* Function name: set_cost()
* Purpose: Sets private member to passed value
* Arguments: double
* Returns: none
*/
void Animal::set_cost(double cost)
{
    this->cost = cost;
}

/*
* Function name: get_num_babies()
* Purpose: Returns private member to be available outside of class
* Arguments: none
* Returns: integer
*/
int Animal::get_num_babies()
{
    return num_babies;
}

/*
* Function name: set_num_babies()
* Purpose: Sets private member to passed value
* Arguments: integer
* Returns: none
*/
void Animal::set_num_babies(int num_babies)
{
    this->num_babies = num_babies;
}

/*
* Function name: get_base_food_cost()
* Purpose: Returns private member to be available outside of class
* Arguments: none
* Returns: double
*/
double Animal::get_base_food_cost()
{
    return base_food_cost;
}

/*
* Function name: set_base_food()
* Purpose: Sets private member to passed value
* Arguments: double
* Returns: none
*/
void Animal::set_base_food_cost(double base_food_cost)
{
    this->base_food_cost = base_food_cost;
}

/*
* Function name: get_payoff()
* Purpose: Returns private member to be available outside of class
* Arguments: none
* Returns: double
*/
double Animal::get_payoff()
{
    return payoff;
}

/*
* Function name: set_payoff()
* Purpose: Sets private member to passed value
* Arguments: double
* Returns: none
*/
void Animal::set_payoff(double payoff)
{
    this->payoff = payoff;
}