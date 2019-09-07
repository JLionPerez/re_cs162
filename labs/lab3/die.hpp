/*
* File name: die.hpp
* Purpose: Holds prototypes for definitions in die.cpp.
*/
#ifndef DIE_H
#define DIE_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>
#include <ctime>

class Die
{
    protected:
        int sides;
        int score;

    public:
        int get_sides();
        void set_sides(int sides);

        int get_score();
        void set_score(int score);
        
        int roll();

        Die();
};

#endif