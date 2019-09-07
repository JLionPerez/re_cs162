/*
* File name: spaces.cpp
* Purpose: Holds definitions for spaces.hpp
*/

#include "spaces.hpp"

/*
* Function name: Space()
* Purpose: Constructor for class, initializes members
* Arguments: none
* Returns: none
*/
Space::Space()
{
    top = NULL;
    bottom = NULL;
    left = NULL;
    right = NULL;
    went_back = false;
    name = "";
    passed = false;
}

/*
* Function name: ~Space()
* Purpose: Deletes members
* Arguments: none
* Returns: none
*/
Space::~Space()
{
    delete top;
    delete bottom;
    delete left;
    delete right;
}

/*
* Function name: set_went_back()
* Purpose: Sets the member to a value
* Arguments: boolean
* Returns: none
*/
void Space::set_went_back(bool went_back) { this->went_back = went_back; }

/*
* Function name: get_went_back()
* Purpose: Returns member
* Arguments: none
* Returns: boolean
*/
bool Space::get_went_back() { return went_back; }

/*
* Function name: set_top()
* Purpose: Sets the member to a value
* Arguments: Space pointer
* Returns: none
*/
void Space::set_top(Space* top) { this->top = top; }

/*
* Function name: get_top()
* Purpose: Returns member
* Arguments: none
* Returns: Space pointer
*/
Space* Space::get_top() { return top; }

/*
* Function name: set_bottom()
* Purpose: Sets the member to a value
* Arguments: Space pointer
* Returns: none
*/
void Space::set_bottom(Space* bottom) { this->bottom = bottom; }

/*
* Function name: get_bottom()
* Purpose: Returns member
* Arguments: none
* Returns: Space pointer
*/
Space* Space::get_bottom() { return bottom; }

/*
* Function name: set_left()
* Purpose: Sets the member to a value
* Arguments: Space pointer
* Returns: none
*/
void Space::set_left(Space* left) { this->left = left; }

/*
* Function name: get_left()
* Purpose: Returns member
* Arguments: none
* Returns: Space pointer
*/
Space* Space::get_left() { return left; }

/*
* Function name: set_right()
* Purpose: Sets the member to a value
* Arguments: Space pointer
* Returns: none
*/
void Space::set_right(Space* right) { this->right = right; }

/*
* Function name: get_right()
* Purpose: Returns member
* Arguments: none
* Returns: Space pointer
*/
Space* Space::get_right() { return right; }

/*
* Function name: set_name()
* Purpose: Sets the member to a value
* Arguments: string 
* Returns: none
*/
void Space::set_name(string name) { this->name = name; }

/*
* Function name: get_name()
* Purpose: Returns member
* Arguments: none
* Returns: string
*/
string Space::get_name() { return name; }

/*
* Function name: get_name()
* Purpose: Sets the member to a value
* Arguments: none
* Returns: string
*/
void Space::set_passed(bool passed) { this->passed = passed; }

/*
* Function name: set_passed()
* Purpose: Returns member
* Arguments: none
* Returns: boolean
*/
bool Space::get_passed() { return passed; }