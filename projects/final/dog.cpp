#include "dog.hpp"

Dog::Dog()
{
    armor = 10;
    strength_points = 50;
    name = "Ghoul Dog";
}

int Dog::attack_func()
{
    die1 = dice_12();
    die2 = dice_12();

    attack = die1 + die2;
    return attack;
}

void Dog::defense_func(int attack_recieved)
{
    die1 = dice_10();
    die2 = dice_10(); 

    defense = die1 + die2;
    damage = attack_recieved - defense - armor;
    strength_points = strength_points - abs(damage);    //damage is positive to subtract from health
}

bool Dog::persuaded()
{

}