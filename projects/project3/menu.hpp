/* 
* File name: menu.hpp
* Purpose: Holds prototypes for menu.cpp
*/

#ifndef MENU_HPP
#define MENU_HPP

#include "characters.hpp"
#include "barbarian.hpp"
#include "vampires.hpp"
#include "blue_men.hpp"
#include "harry_potter.hpp"
#include "medusa.hpp"

class Menu
{
    private:
        int option_player1;
        int option_player2;
        char buffer[100];

        int round;
        int play_again;
        int enter;

        enum c {BARBARIAN = 1, BLUEMEN, HARRY, MEDUSA, VAMPIRE};    //types

        //players
        Characters* player1;
        Characters* player2;

    public:
        Menu();
        ~Menu();

        bool validation(int option);
        void startup();
        void end();

        void gameplay();
        void gameover();

        void player1_choices();
        void player2_choices();

        void player1_turn();
        void player2_turn();

};

#endif