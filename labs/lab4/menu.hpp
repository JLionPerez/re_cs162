/*
* File name: menu.hpp
* Purpose: Holds prototypes for menu.cpp
*/

#ifndef MENU_HPP
#define MENU_HPP

#include "university.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

void menu(int &option);
void nested_menu(University &school);

#endif 