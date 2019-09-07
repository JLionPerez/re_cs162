/*
* File name: jester.hpp
* Purpose: Holds prototypes for jester.cpp
*/

#ifndef JESTER_HPP
#define JESTER_HPP

#include "spaces.hpp"

class Jester : public Space //subclass of Space
{
    private:
        enum Pick {ROCK = 1, PAPER, SCISSORS};  //1, 2, 3
        Pick jester_pick;
        Pick player_pick;

        int damage;
        int option;
        int enemy_points;
        int player_points;
        int rounds;

    public:
        Jester();

        void special(Player& knight);
        void validation();

        void options(Pick pick);
        void player_winnings();
        void enemy_winnings();
};

#endif
