/*
* Program name: Project 3 - Fantasy Combat Game
* Description: This program is a game where 2 players battle each other using the picked characters they chose.
* Author: Joelle Perez
* Date: 19 February 2018 (2 Bonus Days)
*/

#include "characters.hpp"
#include "barbarian.hpp"
#include "vampires.hpp"
#include "blue_men.hpp"
#include "harry_potter.hpp"
#include "medusa.hpp"
#include "menu.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    srand(time(NULL));

    Menu menu;
    menu.startup();

    return 0;
}