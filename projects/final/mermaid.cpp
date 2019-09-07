#include "mermaid.hpp"

Mermaid::Mermaid()
{
    armor = 20;
    strength_points = 35;
    name = "Mermaid";
}

int Mermaid::attack_func()
{
    die1 = dice_10();
    die2 = dice_10();

    attack = die1 + die2;
    return attack;
}

void Mermaid::defense_func(int attack_recieved)
{
    die1 = dice_10();
    die2 = dice_10();
    die3 = dice_10();

    defense = die1 + die2 + die3;
    damage = attack_recieved - defense - armor;
    strength_points = strength_points - abs(damage);    //damage is positive to subtract from health
}

bool Mermaid::persuaded()
{

}