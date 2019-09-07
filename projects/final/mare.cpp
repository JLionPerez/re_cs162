#include "mare.hpp"

Mare::Mare()
{
    armor = 50;
    strength_points = 100;
    name = "White Mare";
}

int Mare::attack_func()
{
    die1 = dice_12();
    die2 = dice_12();
    die3 = dice_12();

    attack = die1 + die2 + die3;
    return attack;
}

void Mare::defense_func(int attack_recieved)
{
    die1 = dice_10();
    die2 = dice_10();
    die3 = dice_10();

    defense = die1 + die2 + die3;
    damage = attack_recieved - defense - armor;
    strength_points = strength_points - abs(damage);    //damage is positive to subtract from health
}

bool Mare::persuaded()
{

}