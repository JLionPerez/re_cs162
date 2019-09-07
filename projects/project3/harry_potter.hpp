/* 
* File name: harry_potter.hpp
* Purpose: Holds prototypes for harry_potter.cpp
*/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "characters.hpp"

class HarryPotter : public Characters
{
    private:
        bool first_life;
        
    public:
        HarryPotter();

        int attack_func();
        void defense_func(int attack_recieved);

        void hogwarts();    //special trait
};

#endif