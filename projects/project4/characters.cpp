/* 
* File name: character.cpp
* Purpose: Holds defintions for characters.hpp
*/

#include "characters.hpp"

/*
* Function name: Characters()
* Purpose: Default constructor of this class, initializes members
* Arguments: none
* Returns: none
*/
Characters::Characters() {}

/*
* Function name: get_attack()
* Purpose: returns integer member
* Arguments: none
* Returns: integer
*/
int Characters::get_attack() { return attack; }

/*
* Function name: set_attack()
* Purpose: sets member to value
* Arguments: integer
* Returns: none
*/
void Characters::set_attack(int attack) { this->attack = attack; }

/*
* Function name: get_defense()
* Purpose: returns integer member
* Arguments: none
* Returns: integer
*/
int Characters::get_defense() { return defense; }

/*
* Function name: set_defense()
* Purpose: set member to value
* Arguments: integer
* Returns: none
*/
void Characters::set_defense(int defense) { this->defense = defense; }

/*
* Function name: get_armor()
* Purpose: returns integer member
* Arguments: none
* Returns: integer
*/
int Characters::get_armor() { return armor; }

/*
* Function name: set_armor()
* Purpose: sets member to value
* Arguments: integer
* Returns: none
*/
void Characters::set_armor(int armor) { this->armor = armor; }

/*
* Function name: get_strength_points()
* Purpose: returns integer member
* Arguments: none
* Returns: integer
*/
int Characters::get_strength_points() { return strength_points; }

/*
* Function name: set_strength_points()
* Purpose: sets member to value
* Arguments: integer
* Returns: none
*/
void Characters::set_strength_points(int strength_points) { this->strength_points = strength_points; }

/*
* Function name: get_damage()
* Purpose: returns integer member
* Arguments: none
* Returns: integer
*/
int Characters::get_damage() { return damage; }

/*
* Function name: set_damage()
* Purpose: sets member to value
* Arguments: integer
* Returns: none
*/
void Characters::set_damage(int damage) { this->damage = damage; }

/*
* Function name: get_name()
* Purpose: returns string member
* Arguments: none
* Returns: string
*/
string Characters::get_name() { return name; }

/*
* Function name: set_name()
* Purpose: sets memeber to value
* Arguments: string
* Returns: none
*/
void Characters::set_name(string name) { this->name = name; }

/*
* Function name: get_type()
* Purpose: returns string member
* Arguments: none
* Returns: string
*/
string Characters::get_type() { return type; }

/*
* Function name: set_type()
* Purpose: sets memeber to value
* Arguments: string
* Returns: none
*/
void Characters::set_type(string type) { this->type = type; }

/*
* Function name: attack_func()
* Purpose: Prints attack
* Arguments: none
* Returns: none
*/
int Characters::attack_func() { cout << "Attack!" << endl; }

/*
* Function name: defense_func()
* Purpose: Prints defend
* Arguments: integer
* Returns: none
*/
void Characters::defense_func(int attack_recieved) { cout << "Defend." << endl; }

/*
* Function name: dice_12()
* Purpose: Rolls values 1 to 12
* Arguments: none
* Returns: integer
*/
int Characters::dice_12()
{
    rolled = rand()% 12 + 1;
    return rolled;
}

/*
* Function name: dice_6()
* Purpose: Rolls values 1 to 6
* Arguments: none
* Returns: integer
*/
int Characters::dice_6()
{
    rolled = rand()% 6 + 1;
    return rolled;
}

/*
* Function name: dice_10()
* Purpose: Rolls values 1 to 10
* Arguments: none
* Returns: integer
*/
int Characters::dice_10()
{
    rolled = rand()% 10 + 1;
    return rolled;
}

/*
* Function name: recovery()
* Purpose: Returns a percentage of a character's health
* Arguments: none
* Returns: double
*/
double Characters::recovery()
{
    int percentage = rand()% 5 + 1;  //can recover from 10% to 90% of health back

    if(percentage == 1) { recovered = 0.1; }            //10% of health
    
    else if (percentage == 2) { recovered = 0.2; }      //20% of health

    else if (percentage == 3) { recovered = 0.3; }      //30% of health

    else if (percentage == 4) { recovered = 0.4; }      //40% of health

    else if (percentage == 5) { recovered = 0.5; }      //50% of health

    return recovered;
}