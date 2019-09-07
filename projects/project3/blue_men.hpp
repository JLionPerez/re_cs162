/* 
* File name: blue_men.hpp
* Purpose: Holds prototypes for blue_men.cpp
*/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "characters.hpp"

class BlueMen : public Characters
{
    public:
        BlueMen();

        int attack_func();
        void defense_func(int attack_recieved);

        int mob();      //special trait
};

#endif