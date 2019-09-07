#ifndef MENU_HPP
#define MENU_HPP

#include "typewriter.hpp"
#include "game.hpp"

class Menu
{
    private:
        int again;
        int option;
        char buffer[100];
        string str;

    public:
        void beginning();
        void end();

        void story();
        void layout();
};

#endif