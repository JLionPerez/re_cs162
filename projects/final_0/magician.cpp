/*
* File name: magician.cpp
* Purpose: Holds defintions for magician.hpp
*/

#include "magician.hpp"

/*
* Function name: Magician()
* Purpose: Constructor for class, initializes members
* Arguments: none
* Returns: none
*/
Magician::Magician()
{
    death = 100;
    damage = 10;
    card = 0;
}

/*
* Function name: validation()
* Purpose: Validates the user's inputs
* Arguments: none
* Returns: none
*/
void Magician::validation()
{
    do
    {
        cout << "Which card will you pick? ";
        cin >> card;

        if(card < 1 || card > 3 || cin.fail())
        {
            cout << "\nPlease try again." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }

        else if(card == 1) { picked = card1; }  //picked 1st card
        else if(card == 2) { picked = card2; }  //picked 2nd card
        else if(card == 3) { picked = card3; }  //picked 3rd card

    } while(card < 1 || card > 3 || cin.fail());
}

/*
* Function name: special()
* Purpose: Special action for this floor
* Arguments: referenced Player
* Returns: none
*/
void Magician::special(Player& knight)
{
    if(passed == false)
    {
        cout << "\nA magician faded in the room from thin air." << endl;
        cout << "\nThey summoned out a table from underneath their cape,\nand placed it directly in front of you." << endl;
        cout << "The magician places 3 tarot cards facing down on the table." << endl;
        cout << "\nHe explains that there are 3 types of cards on the table:\n\tThe Chariot, The Devil, and Death." << endl;
        cout << "\nThe Chariot will let you pass,\nThe Devil will inflict damage,\nand Death will kill you instantly." << endl;
        cout << "\nYou will have to pick out a card, and deal with the consequences." << endl;
        cout << "Make it count." << endl;

        //randomize cards
        card1 = static_cast<Tarot>(rand() % DEATH + CHARIOT);
        card2 = static_cast<Tarot>(rand() % DEATH + CHARIOT);
        card3 = static_cast<Tarot>(rand() % DEATH + CHARIOT);

        cout << "\nHere are the cards on the table: " << endl;
        cout << "     _____     _____     _____ " << endl;
        cout << "    |     |   |     |   |     |" << endl;
        cout << "    |  1  |   |  2  |   |  3  |" << endl;
        cout << "    |  @  |   |  @  |   |  @  |" << endl;
        cout << "    |     |   |     |   |     |" << endl;
        cout << "     -----     -----     ----- " << endl;

        validation();

        if(picked == CHARIOT) //got gem
        {
            cout << "\nYou've bested the magician at their own game!" << endl;
            cout << "The magician scowls and disappears into thin air, exiting the scene." << endl;
            passed = true;
            went_back = false;
            cout << "\nYou recieved a gem!" << endl;
            knight.add_gem();
        }

        else if(picked == DEVIL) //knight hurt
        {
            cout << "\nThe card started shaking and glowing red." << endl;
            cout << "Suddenly a horned red-skinned creature started climbing out of the card." << endl;
            sleep_for(milliseconds(500));
            cout << "Their size growing the more they climb out of the card." << endl;
            sleep_for(milliseconds(500));
            cout << "\nNow leaning over you is the Devil himself!" << endl;
            cout << "He roared then spout fire towards you. \nGaining 10 damage points from the impact." << endl;
            cout << "The flames made you fall backwards down to the previous floor you were in." << endl;
            knight.dealt_damage(damage);
            went_back = true;
        }

        else if(picked == DEATH) //knight hurt/killed
        {
            cout << "\nThe card started to feel cold to the touch." << endl;
            cout << "Suddenly black fog started eminating from the card." << endl;
            cout << "Filling the room with darkness." << endl;
            cout << "\nSuddenly a hooded figure appeared before you." << endl;
            sleep_for(milliseconds(500));
            cout << "They slowly looked up staring directly into your eyes." << endl;
            cout << "You are now face to face with Death himself!" << endl;
            cout << "You're paralyzed and can't move from the feeling of dread." << endl;
            cout << "Death held up his scythe..." << endl;
            sleep_for(milliseconds(500));
            cout << "And reaped your soul..." << endl;
            knight.dealt_damage(death);
            went_back = true;
        }
    }

    else if (passed) { cout << "\nYou already went through here and defeated the magician." << endl; }
}