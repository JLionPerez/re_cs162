/* 
* File name: vampires.cpp
* Purpose: Holds definitions for vampires.hpp
*/

#include "vampires.hpp"

/*
* Function name: Vampires()
* Purpose: Default constructor for class, initializes members
* Arguments: none
* Returns: none
*/
Vampires::Vampires()
{
    armor = 1;
    strength_points = 18;
    no_damage = strength_points;
    name = " ";
    type = "Vampire";
}

/*
* Function name: attack_func()
* Purpose: Rolls dice for attack
* Arguments: none
* Returns: integer
*/
int Vampires::attack_func()
{
    die1 = dice_12();

    attack = die1;

    return attack;
}

/*
* Function name: defense_func()
* Purpose: Rolls for defense and damage recieved
* Arguments: integer
* Returns: none
*/
void Vampires::defense_func(int attack_recieved)
{
    die1 = dice_6();

    defense = die1;
    damage = attack_recieved - defense - armor;
    strength_points = strength_points - abs(damage);    //damage is positive to subtract from health  

    charm(attack_recieved);  //special trait
}

/*
* Function name: charm()
* Purpose: Special ability of character, activates when special requirement is met
* Arguments: integer
* Returns: none
*/
void Vampires::charm(int attack_recieved)
{
    if(attack_recieved % 2 == 0)
    {
        strength_points = no_damage;
        cout << "\t\tThe vampire was too beautiful to hit. Vampire dealt no damage." << endl;
    }
    
    else { no_damage = strength_points; }    //updates to current health
}