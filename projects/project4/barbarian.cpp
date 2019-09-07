/* 
* File name: barbarian.cpp
* Purpose: Holds definitions for barbarian.hpp
*/

#include "barbarian.hpp"

/*
* Function name: Barbarian()
* Purpose: Default constructor for this class, initializes members
* Arguments: none
* Returns: none
*/
Barbarian::Barbarian()
{
    armor = 0;
    strength_points = 12;
    name = " ";
    type = "Barbarian";
}

/*
* Function name: attack_func()
* Purpose: Rolls dice for character's attac
* Arguments: none
* Returns: integer
*/
int Barbarian::attack_func()
{
    die1 = dice_6();
    die2 = dice_6();

    attack = die1 + die2;

    return attack;
}

/*
* Function name: defense_func()
* Purpose: Rolls dice for characters defense
* Arguments: integer
* Returns: none
*/
void Barbarian::defense_func(int attack_recieved)
{
    die1 = dice_6();
    die2 = dice_6(); 

    defense = die1 + die2;
    damage = attack_recieved - defense - armor;
    strength_points = strength_points - abs(damage);    //damage is positive to subtract from health
}