/* 
* File name: characters.hpp
* Purpose: Holds prototypes for characters.cpp
*/

#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <cstdlib>
#include <ctime>

#include <cmath>

#include <cstring>
#include <string>
using std::string;

class Characters
{
    protected:
        //attributes
        int attack;
        int defense;
        int armor;
        int strength_points;

        int damage;
        int rolled;

        string name;

        //dice
        int die1;
        int die2;
        int die3;

    public:
        Characters();

        int get_attack();
        void set_attack(int attack);

        int get_defense();
        void set_defense(int defense);

        int get_armor();
        void set_armor(int armor);

        int get_strength_points();
        void set_strength_points(int strength_points);

        int get_damage();
        void set_damage(int damage);

        //rolls dice
        int dice_12();
        int dice_6();
        int dice_10();

        string get_name();
         
        //virtual functions
        virtual int attack_func();
        virtual void defense_func(int attack_recieved);
};
#endif