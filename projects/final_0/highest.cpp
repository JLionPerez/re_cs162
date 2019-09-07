/*
* File name: highest.cpp
* Purpose: Holds defintiions for highest.hpp
*/

#include "highest.hpp"

/*
* Function name: Highest()
* Purpose: Constructor for class, initializes members
* Arguments: none
* Returns: none
*/
Highest::Highest()
{
    place = 0;
}

/*
* Function name: validation()
* Purpose: validates user's inputs
* Arguments: none
* Returns: none
*/
void Highest::validation()
{
    do
    {
        cout << "\nWould you like to place your gems in the door? " << endl;
        cout << "\t1) Yes \t2) No" << endl;
        cout << "Enter: ";
        cin >> place;

        if (place < 1 || place > 2 || cin.fail())
        {
            cout << "\nPlease try again." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }

    } while (place < 1 || place > 2 || cin.fail());
}

/*
* Function name: special()
* Purpose: Special action for floor
* Arguments: referenced Player
* Returns: none
*/
void Highest::special(Player& knight)
{
    cout << "\nYou came across an enchanted door leading to where the princess/prince is being held in." << endl;
    cout << "The door is encrusted in gold gildings and had mysterious engravings on it." << endl;
    cout << "\nIn the middle of the door are 4 circle slots arranged in a diamond like alignment." << endl;
    cout << "It seems like the gems might fit into these slots." << endl;

    validation();

    if (place == 2)
    {
        cout << "\nYou decided not to place the gems in the door." << endl;
        went_back = true;
    }

    else if (place == 1)
    {
        cout << "\nYou decided to place the gems in the door." << endl;

        if (knight.get_num_gems() < 4)
        {
            cout << "\nHowever, you didn't have enough gems." << endl;
            cout << "The door can not be opened." << endl;
            went_back = true;
        }

        else if (knight.get_num_gems() == 4)
        {
            cout << "\nThe gems fitted perfectly into the slots." << endl;
            cout << "Door : ";
            knight.print_total_gems();
            cout << "\nThe 4 gems started glowing along with the door." << endl;
            cout << "In a bright flash the door suddenly disappeared!" << endl;
            passed = true;
            went_back = false;
        }
    }
}
