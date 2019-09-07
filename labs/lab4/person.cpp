/*
* File name: person.cpp
* Purpose: Holds definitions for person.hpp
*/

#include "person.hpp"

/*
* Function name: get_name()
* Purpose: Returns private member from Person class
* Argument: none
* Returns: string
*/
string Person::get_name()
{
    return name;
}

/*
* Function name: set_name()
* Purpose: Sets value to private member
* Argument: string
* Returns: none
*/
void Person::set_name(string name)
{
    this->name = name;
}

/*
* Function name: get_age()
* Purpose: Returns private member from Person class
* Argument: none
* Returns: integer
*/
int Person::get_age()
{
    return age;
}

/*
* Function name: set_age()
* Purpose: Sets value to private member
* Argument: integer
* Returns: none
*/
void Person::set_age(int age)
{
    this->age = age;
}

/*
* Function name: random_float()
* Purpose: Randomly generates a float for GPA and Rating of Student and Instructor classes
* Argument: float
* Returns: float
*/
float Person::random_foat(float max)
{
    srand(time(NULL));
    float random = static_cast<float>(rand() / static_cast<float>(RAND_MAX/max));
    return random;
}

/*
* Function name: do_work()
* Purpose: Prints default statement
* Argument: none
* Returns: none
*/
float Person::do_work()
{
    cout << "Person did this many hours of work." << endl;
}