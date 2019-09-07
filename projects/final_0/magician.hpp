/*
* File name: magician.hpp
* Purpose: Holds protoypes for magician.cpp
*/

#ifndef MAGICIAN_HPP
#define MAGICIAN_HPP

#include "spaces.hpp"

class Magician : public Space   //subclass of Space
{
    private:
        enum Tarot {CHARIOT = 1, DEVIL, DEATH};    //1, 2, 3

        int death;
        int damage;
        int card;
        Tarot picked;

        Tarot card1;
        Tarot card2;
        Tarot card3;

    public:
        Magician();

        void special(Player& knight);
        void validation();
};

#endif