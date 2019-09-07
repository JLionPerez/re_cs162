/*
* File name: player.cpp
* Purpose: Holds definitions for player.hpp
*/

#include "player.hpp"

/*
* Function name: Player()
* Purpose: Constructor for class, initializes members
* Arguments: none
* Returns: none
*/
Player::Player()
{
    health = 100;
    num_gems = 0;
}

/*
* Function name: set_health()
* Purpose: Sets the member variable to a value
* Arguments: integer
* Returns: none
*/
void Player::set_health(int health) { this->health = health; }

/*
* Function name: get_health()
* Purpose: Returns the member
* Arguments: none
* Returns: integer
*/
int Player::get_health() { return health; }

/*
* Function name: set_num_gems()
* Purpose: Sets the member variable to a value
* Arguments: integer
* Returns: none
*/
void Player::set_num_gems(int num_gems) { this->num_gems = num_gems; }

/*
* Function name: get_num_gems()
* Purpose: Returns the member
* Arguments: none
* Returns: integer
*/
int Player::get_num_gems() { return num_gems; }

/*
* Function name: dealt_damage()
* Purpose: When damage is dealth, health is subtracted
* Arguments: integer
* Returns: none
*/
void Player::dealt_damage(int damage) { health -= damage; }

/*
* Function name: add_gem()
* Purpose: Add's a gem to the queue and increments the amount of Gems
* Arguments: none
* Returns: none
*/
void Player::add_gem()
{
    gems.push("Gem");
    num_gems++;
}

/*
* Function name: print_gems()
* Purpose: Prints the items within the pouch
* Arguments: none
* Returns: none
*/
void Player::print_gems()
{
    cout << "\nPouch: ";

    for(int i = 0; i < num_gems; i++)
    {
        cout << "Gem ";
    }

    cout << endl;
}

/*
* Function name: print_total_gems()
* Purpose: Deletes the queue
* Arguments: none
* Returns: none
*/
void Player::print_total_gems()
{
    while(!gems.empty())
    {
        cout << gems.front() << " ";
        gems.pop();
    }

    cout << endl;
}