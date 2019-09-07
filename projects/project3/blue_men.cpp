/* 
* File name: blue_men.cpp
* Purpose: Holds defintions for blue_men.hpp
*/

#include "blue_men.hpp"

/*
* Function name: BlueMen()
* Purpose: Default constructor for this class, initializes members
* Arguments: none
* Returns: none
*/
BlueMen::BlueMen()
{
    armor = 3;
    strength_points = 12;
    name = "Blue Men";
}

/*
* Function name: attack_func()
* Purpose: Rolls dice for character's attack
* Arguments: none
* Returns: integer
*/
int BlueMen::attack_func()
{
    die1 = dice_10();
    die2 = dice_10();

    attack = die1 + die2;

    return attack;
}

/*
* Function name: defense_func()
* Purpose: Rolls dice for character's defense
* Arguments: integer
* Returns: none
*/
void BlueMen::defense_func(int attack_recieved) 
{
    damage = attack_recieved - mob() - armor;   //special trait
    strength_points = strength_points - abs(damage);    //damage is positive to subtract from health    
}

/*
* Function name: mob()
* Purpose: Special trait, activates when requirements met
* Arguments: none
* Returns: integer
*/
int BlueMen::mob()
{
    if(strength_points <= 4)   //1d6, takes away a die
    {
        cout << "\t\tOh no! The Blue Men lost another dice!" << endl;
        die1 = dice_6();
        defense = die1;
    }

    else if(strength_points <= 8)    //2d6, takes away a die
    {
        cout << "\t\tOh no! The Blue Men lost a dice!" << endl;
        die1 = dice_6();
        die2 = dice_6();
        defense = die1 + die2;
    }

    else if(strength_points <= 12)   //3d6. starts with all dice
    {
        die1 = dice_6();
        die2 = dice_6(); 
        die3 = dice_6();
        defense = die1 + die2 + die3;
    }
    return defense;
}