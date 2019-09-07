/*
* File name: menu.hpp
* Description: Holds prototypes for menu.cpp
*/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstring>
#include <string>
using std::string;

#include <cstdlib>

class Menu
{
    private:
        int option;

    public:
        void start_up();
        void rev_str_menu();
        void sum_menu();
        void tri_menu();
};

#endif