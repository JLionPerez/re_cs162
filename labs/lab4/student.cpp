/*
* File name: student.cpp
* Purpose: Holds definitions for student.hpp
*/

#include "student.hpp"

/*
* Function name: Student()
* Purpose: Default constructor intializes private members
* Argument: none
* Returns: none
*/
Student::Student()
{
    set_gpa(random_foat(4.0));
    set_name("Avery Joe");
}

/*
* Function name: get_gpa()
* Purpose: Returns private member from Student class
* Argument: none
* Returns: float
*/
float Student::get_gpa()
{
    return GPA;
}

/*
* Function name: set_gpa()
* Purpose: Sets private member to value
* Argument: float 
* Returns: none
*/
void Student::set_gpa(float gpa)
{
    GPA = gpa;
}

/*
* Function name: do_work()
* Purpose: Prints hours of work of the person
* Argument: none
* Returns: none
*/
float Student::do_work()
{
    srand(time(NULL));
    int x = rand() % (5 - 1 + 1) + 1;

    cout << get_name() << " did " << x  << " hours of homework." << endl;
}