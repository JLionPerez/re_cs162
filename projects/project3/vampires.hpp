/* 
* File name: vampires.hpp
* Purpose: Holds prototypes for vampires.cpp
*/

#ifndef VAMPIRES_HPP
#define VAMPIRES_HPP

#include "characters.hpp"

class Vampires : public Characters
{
    private:
        int no_damage;

    public:
        Vampires();

        int attack_func();
        void defense_func(int attack_recieved);

        void charm(int attack_recieved);   //special trait
};

#endif