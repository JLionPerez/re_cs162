/*
* File name: player.hpp
* Purpose: Holds definitions for player.cpp
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <queue>
using std::queue;

#include <cstring>
#include <string>
using std::string;

class Player
{
    private:
        int health;
        int num_gems;

        queue <string> gems;

    public:
        Player();

        void set_health(int health);
        int get_health();

        void set_num_gems(int num_gems);
        int get_num_gems();

        void dealt_damage(int damage);
        void add_gem();
        void print_gems();
        void print_total_gems();
};

#endif