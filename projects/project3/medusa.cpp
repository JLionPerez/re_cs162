/* 
* File name: medusa.cpp
* Purpose: Holds definitions for medusa.hpp
*/

#include "medusa.hpp"

/*
* Function name: Medusa()
* Purpose: Default constructor for class, initializes members
* Arguments: none
* Returns: none
*/
Medusa::Medusa()
{
    armor = 3;
    strength_points = 8;
    name = "Medusa";
}

/*
* Function name: attack_func()
* Purpose: Rolls dice for character's attack
* Arguments: none
* Returns: integer
*/
int Medusa::attack_func()
{
    die1 = dice_6();
    die2 = dice_6();

    attack = die1 + die2;
    glare();    //special trait

    return attack;
}

/*
* Function name: defense_func()
* Purpose: Rolls dice for character's defense
* Arguments: integer
* Returns: none
*/
void Medusa::defense_func(int attack_recieved)
{
    die1 = dice_6();

    defense = die1;
    damage = attack_recieved - defense - armor;
    strength_points = strength_points - abs(damage);    //damage is positive to subtract from health    
}

/*
* Function name: glare()
* Purpose: Special ability, activates when specific requirement is met
* Arguments: none
* Returns: none
*/
void Medusa::glare()
{
    if(attack == 12)
    {
        attack = 9999;
        cout << "\t\tMedusa turned their opponent to stone, Fatality!" << endl;
    }
}