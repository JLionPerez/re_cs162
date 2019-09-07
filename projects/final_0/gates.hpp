/*
* File name: gates.hpp
* Purpose: Holds prototypes for gates.cpp
*/

#ifndef GATES_HPP
#define GATES_HPP

#include "spaces.hpp"

class Gates : public Space  //subclass of Space
{
    private:
        int pull;
        
    public:
        Gates();

        void special(Player& knight);
        void validation();
};

#endif