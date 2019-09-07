/*
* File name: highest.hpp
* Purpose: Holds prototypes for highest.cpp
*/

#ifndef HIGHEST_HPP
#define HIGHEST_HPP

#include "spaces.hpp"

class Highest : public Space //subclass of Space
{
    private:
        int place;

    public:
        Highest();

        void special(Player& knight);
        void validation();
};

#endif