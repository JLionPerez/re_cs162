/* 
* File name: barbarian.hpp
* Purpose: Holds prototypes for barbarian.cpp
*/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "characters.hpp"

class Barbarian : public Characters
{
    public:
        Barbarian();

        int attack_func();
        void defense_func(int attack_recieved); 
};

#endif