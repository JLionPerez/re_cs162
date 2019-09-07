/*
* File name: gates.cpp
* Purpose: Holds definitions for gates.hpp
*/

#include "gates.hpp"

/*
* Function name: Gates()
* Purpose: Constructor for class, initializes members
* Arguments: none
* Returns: none
*/
Gates::Gates()
{
    pull = 0;
}

/*
* Function name: validation()
* Purpose: Validates the user's input
* Arguments: none
* Returns: none
*/
void Gates::validation()
{
    do
    {
        cout << "\nWill you pull the lever? " << endl;
        cout << "\t1) Yes \t2) No" << endl;
        cout << "Enter: ";
        cin >> pull;

        if(pull < 1 || pull > 2 || cin.fail())
        {
            cout << "\nPlease try again." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }

    } while (pull < 1 || pull > 2 || cin.fail());
}

/*
* Function name: special()
* Purpose: Special action for this floor
* Arguments: referenced Player
* Returns: none
*/
void Gates::special(Player& knight)
{
    if(passed == false)
    {
        cout << "\nIn front of you is a gate to enter the tower." << endl;
        cout << "There is a lever on the right side of the gate." << endl;
        cout << "It seems like the lever is connected to the gate somehow." << endl;

        validation();

        if(pull == 2)      //means you left
        {
            cout << "\nYou didn't pull lever and since there's no way else in\nyou turn around and gave up on rescuing the princess/prince." << endl;
            went_back = true;
        }

        else if (pull == 1)     //entered tower
        {
            cout << "\nYou pulled the lever and the gate opened. You enter the tower." << endl;
            cout << "Suddenly the gate closed behind you, seems like there's no turning back now." << endl;
            passed = true;
            went_back = false;
        }
    }

    else if (passed) { cout << "\nThe gate is locked, you can't leave the tower through here." << endl; }
}