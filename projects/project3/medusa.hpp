/* 
* File name: medusa.hpp
* Purpose: Holds prototypes for medusa.cpp
*/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "characters.hpp"

class Medusa : public Characters
{
    public:
        Medusa();
        
        int attack_func();
        void defense_func(int attack_recieved);

        void glare();   //special trait
};

#endif