#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "characters.hpp"

class Player : Characters
{
    public:
        Player();

        int attack_func();
        void defense_func(int attack_recieved);
};

#endif