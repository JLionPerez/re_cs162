#include "snake.hpp"

Snake::Snake()
{
    armor = 0;
    strength_points = 20;
    name = "White Snake";
}

int Snake::attack_func()
{
    die1 = dice_6();
    die2 = dice_6();

    attack = die1 + die2;
    return attack;
}

void Snake::defense_func(int attack_recieved)
{
    die1 = dice_6();
    die2 = dice_6();

    defense = die1 + die2;
    damage = attack_recieved - defense - armor;
    strength_points = strength_points - abs(damage);    //damage is positive to subtract from health
}

bool Snake::persuaded()
{
    
}