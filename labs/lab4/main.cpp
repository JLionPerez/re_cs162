/*
* Program name: Lab 4 - OSU Information System
* Author: Joelle Perez
* Description: This program let's the user see information about people and buildings, and also assign people to work for certain hours.
* Date: 3 February 2019
*/

#include "menu.hpp"
#include "university.hpp"
#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"

int main()
{
    char buffer[100];
    int option;
    University *OSU;

    cout << "\nWelcome to OSU's Information System." << endl;
    cout << "\n1. Prints information about all the buildings" << endl;
    cout << "2. Prints information about everybody at the university" << endl;
    cout << "3. Choose a person to do work" << endl;
    cout << "4. Exit the program" << endl;
    cout << "Option: ";
    cin >> buffer;
    
    option = atoi(buffer);  //alphabets turn 0

    menu(option);
    
    return 0;
}