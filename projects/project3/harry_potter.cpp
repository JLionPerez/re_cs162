/* 
* File name: harry_potter.cpp
* Purpose: Holds definitions for harry_potter.hpp
*/

#include "harry_potter.hpp"

/*
* Function name: HarryPotter()
* Purpose: Default constructor for class, initializes members
* Arguments: none
* Returns: none
*/
HarryPotter::HarryPotter()
{
    armor = 0;
    strength_points = 10;   //starting health
    first_life = true;      //starts with first life
    name = "Harry Potter";
}

/*
* Function name: attack_func()
* Purpose: Rolls for character's attack
* Arguments: none
* Returns: integer
*/
int HarryPotter::attack_func()
{
    die1 = dice_6();
    die2 = dice_6();

    attack = die1 + die2;

    return attack;
}

/*
* Function name: defense_func()
* Purpose: Rolls for character's defense
* Arguments: integer
* Returns: none
*/
void HarryPotter::defense_func(int attack_recieved)
{
    die1 = dice_6();
    die2 = dice_6(); 

    defense = die1 + die2;
    damage = attack_recieved - defense - armor;
    strength_points = strength_points - abs(damage);    //damage is positive to subtract from health
    
    hogwarts();     //special trait
}

/*
* Function name: hogwarts()
* Purpose: Special trait, activates when specific requirement is met
* Arguments: none
* Returns: none
*/
void HarryPotter::hogwarts()
{
    if(first_life && strength_points <= 0)    //replenishes harry with 20 health points
    {
        strength_points = 20;
        first_life = false;     //this is NOT his first life anymore
        cout << "\t\tHarry lives once more!" << endl;
    }
}