/*
* File name: spaces.hpp
* Purpose: Holds prototypes for spaces.cpp
*/

#ifndef SPACES_HPP
#define SPACES_HPP

#include "player.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>
#include <ctime>

#include <cstring>
#include <string>
using std::string;

#include <thread>
using std::this_thread::sleep_for;

#include <chrono>
using std::chrono::milliseconds;
using std::chrono::seconds;

class Space
{
    protected:
        Space* top;
        Space* bottom;
        Space* left;
        Space* right;

        string name;
        bool passed;
        bool went_back;

    public:
        Space();
        ~Space();

        void set_top(Space* top);
        Space* get_top();

        void set_bottom(Space* bottom);
        Space* get_bottom();

        void set_left(Space* left);
        Space* get_left();

        void set_right(Space* right);
        Space* get_right();

        void set_name(string name);
        string get_name();

        void set_passed(bool passed);
        bool get_passed();

        void set_went_back(bool went_back);
        bool get_went_back();

        virtual void special(Player& knight) = 0;  //returns damage recieved
        virtual void validation() = 0;
};

#endif