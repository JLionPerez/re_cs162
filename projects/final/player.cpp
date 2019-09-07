#include "player.hpp"

Player::Player()
{
    armor = 0;
    strength_points = 50;
    name = "";
}

int Player::attack_func()
{
    die1 = dice_6();
    die2 = dice_6();
    die3 = dice_6();

    attack = die1 + die2 + die3;
    return attack;
}

void Player::defense_func(int attack_recieved)
{
    die1 = dice_10();
    die2 = dice_10(); 

    defense = die1 + die2;
    damage = attack_recieved - defense - armor;
    strength_points = strength_points - abs(damage);    //damage is positive to subtract from health
}