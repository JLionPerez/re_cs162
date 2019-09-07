/*
* File name: building.cpp
* Purpose: Holds definitions for building.hpp
*/

#include "building.hpp"

/*
* Function name: get_name()
* Purpose: Returns the private member of the building class
* Argument: none
* Returns: string
*/
string Building::get_name()
{
    return name;
}

/*
* Function name: set_name()
* Purpose: Sets value for a private member of the building class
* Argument: string
* Returns: none
*/
void Building::set_name(string name)
{
    this->name = name;
}

/*
* Function name: get_size()
* Purpose: Returns the private member of the building class
* Argument: none
* Returns: integer
*/
int Building::get_size()
{
    return size;
}

/*
* Function name: set_size()
* Purpose: Sets value for a private member of the building class
* Argument: integer
* Returns: none
*/
void Building::set_size(int size)
{
    this->size = size;
}

/*
* Function name: get_address()
* Purpose: Returns the private member of the building class
* Argument: none
* Returns: string
*/
string Building::get_address()
{
    return address;
}

/*
* Function name: set_address()
* Purpose: Sets value for a private member of the building class
* Argument: string
* Returns: none
*/
void Building::set_address(string address)
{
    this->address = address;
}