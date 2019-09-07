/*
* File name: game.hpp
* Purpose: Holds prototypes for game.cpp
*/

#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "gates.hpp"
#include "jester.hpp"
#include "magician.hpp"
#include "highest.hpp"

class Game
{
    private:
        int choice;
        int again;
        Player knight;

        Space* current_floor;
        Space* floor1;
        Space* floor2;
        Space* floor3;
        Space* floor4;
        Space* floor5;
        Space* floor6;

        bool completed;
        bool quit;

        bool done;

    public:
        Game();

        void validate_input(int min, int max);

        void beginning();
        void floor1_menu();
        void floors_menus();
        void floor6_menu();
        void play();
        void end();
        void game_over();

        void set_floors();
        void display_floor();
        bool is_done();
};

#endif