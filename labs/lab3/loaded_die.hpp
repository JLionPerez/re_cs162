/*
* File name: loaded_die.hpp
* Purpose: Holds prototypes for definitions in loaded_die.cpp.
*/
#ifndef LOADED_DIE
#define LOADED_DIE
#include "die.hpp"

class LoadedDie : public Die
{
    public:
    int cheat();
};

#endif