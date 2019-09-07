/*
* File name: instructor.cpp
* Purpose: Holds definitions for instructor.hpp
*/

#include "instructor.hpp"

/*
* Function name: Instructor()
* Purpose: Default constructor to initialize members
* Argument: none
* Returns: none
*/
Instructor::Instructor()
{
    set_rating(random_foat(5.0));
    set_name("Salph Maed");
}

/*
* Function name: get_rating()
* Purpose: Returns private member in instructor class
* Argument: none
* Returns: float
*/
float Instructor::get_rating()
{
    return rating;
}

/*
* Function name: set_rating()
* Purpose: Sets value to private member
* Argument: float
* Returns: none
*/
void Instructor::set_rating(float rating)
{
    this->rating = rating;
}

/*
* Function name: do_work()
* Purpose: Prints out the hours this person worked
* Argument: none
* Returns: none
*/
float Instructor::do_work()
{
    srand(time(NULL));
    int x = rand() % (10 - 3 + 1) + 3;

    cout << get_name() << " graded papers for " << x << " hours." << endl;
}