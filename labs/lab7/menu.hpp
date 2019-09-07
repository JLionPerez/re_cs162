#ifndef MENU_HPP
#define MENU_HPP

#include "queue.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

class Menu
{
    private:
        int option;
        int again;
        char buffer[100];

    public:
        void startup(Queue q, Queue* list);
};
#endif