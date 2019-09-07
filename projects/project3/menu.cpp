/* 
* File name: menu.cpp
* Purpose: Holds defintions for menu.hpp
*/

#include "menu.hpp"

/*
* Function name: Menu()
* Purpose: Default constructor of this class, initializes members
* Arguments: none
* Returns: none
*/
Menu::Menu() 
{
    round = 1;
    play_again = 0;
}

/*
* Function name: 
* Purpose: Deconstructor, deletes objects of class off heap
* Arguments: none
* Returns: none
*/
Menu::~Menu()
{
    delete player1;
    delete player2;
}

/*
* Function name: validation()
* Purpose: Validates options if within bounds
* Arguments: integer
* Returns: boolean
*/
bool Menu::validation(int option)
{
    if(option < 1 || option > 5)
    {
        return false;
    }
    return true;
}

/*
* Function name: end()
* Purpose: End menu, asks player if they want to play again
* Arguments: none
* Returns: none
*/
void Menu::end()
{
    do
    {
        cout << "\nDo you want to play again? (No spaces, please)" << endl;
        cout << "\t1) Yes" << "\t2) No" << endl;
        cout << "Enter: ";
        cin >> buffer;
        enter = atoi(buffer);

        if(enter < 1 || enter > 2) { cout << "\nPlease enter a valid number." << endl; }

        else if(enter == 1)     //play again
        {
            delete player1;     //delete previous data
            delete player2;

            round = 1;          //resets rounds for new game

            startup();
        }

        else if(enter == 2)     //quit
        {
            cout << "\nBye bye!" << endl;
            return;
        }

    } while(enter < 1 || enter > 2);
}

/*
* Function name: startup()
* Purpose: Starting menu lets players choose their option
* Arguments: none
* Returns: none
*/
void Menu::startup()
{
    cout << "\nWelcome to the Fantasy Combat Game!" << endl;

    cout << "\nHere is a list of characters: " << endl;
    cout << "\t1) Barbarian" << endl;
    cout << "\t2) Blue Men" << endl;
    cout << "\t3) Harry Potter" << endl;
    cout << "\t4) Medusa" << endl;
    cout << "\t5) Vampire" << endl;

    cout << "\nNote: Player 1 attacks first." << endl;

    do  //player 1 picks a character
    {
        cout << "\nPlease pick Player 1 (No spaces, please): ";
        cin >> buffer;
        option_player1 = atoi(buffer);

        if(validation(option_player1) == false) { cout << "Please enter a valid option." << endl; }

    } while(validation(option_player1) == false);

    do  //player 2 picks a character
    {
        cout << "\nPlease pick Player 2 (No spaces, please): ";
        cin >> buffer;
        option_player2 = atoi(buffer);

        if(validation(option_player2) == false) { cout << "Please enter a valid option." << endl; }

    } while(validation(option_player2) == false);

    player1_choices();  //player 1 chooses a character to be as
    player2_choices();  //player 2 chooses a character to be as

    gameplay(); //starts battle
    end();  //end menu
}

/*
* Function name: player1_choices()
* Purpose: Player 1 chooses a character to play as
* Arguments: none
* Returns: none
*/
void Menu::player1_choices()
{
    switch (option_player1)
    {
        case BARBARIAN:
            player1 = new Barbarian();  //Character* = new Barbarian(), etc.
            break;

        case BLUEMEN:
            player1 = new BlueMen();
            break;

        case HARRY:
            player1 = new HarryPotter();
            break;

        case MEDUSA:
            player1 = new Medusa();
            break;

        case VAMPIRE:
            player1 = new Vampires();
            break;

        default:
            break;
    }
}

/*
* Function name: player2_choices()
* Purpose: Player 2 chooses a character to play as
* Arguments: none
* Returns: none
*/
void Menu::player2_choices()
{
    switch (option_player2)
    {
        case BARBARIAN:
            player2 = new Barbarian();  //Character* = new Barbarian(), etc.
            break;

        case BLUEMEN:
            player2 = new BlueMen();
            break;

        case HARRY:
            player2 = new HarryPotter();
            break;

        case MEDUSA:
            player2 = new Medusa();
            break;

        case VAMPIRE:
            player2 = new Vampires();
            break;

        default:
            break;
    }    
}

/*
* Function name: player1_turn()
* Purpose: Starts with player 1, player 1 attacks first
* Arguments: none
* Returns: none
*/
void Menu::player1_turn()
{
    //Display Player 1
    cout << "\n\nPlayer 1's turn." << endl;

    cout << "\n\tPlayer 1:" << endl;
    cout << "\t\t" << player1->get_name() << " attacks!" << endl;        
    player1->attack_func();     //player 1 attacks
    cout << "\n\t\tRolled " << player1->get_attack() << " attack points." << endl;

    //Display player 2
    cout << "\n\tPlayer 2:" << endl;
    cout << "\t\t" << player2->get_name() << " defends." << endl; 
    cout << "\n\t\tStarting with " << player2->get_strength_points() << " strength points." << endl;    //starting health
    cout << "\t\t" << player2->get_armor() << " armor points." << endl;
    player2->defense_func(player1->get_attack());   //player 2 defends
    cout << "\t\tRolled " << player2->get_defense() << " defense points." << endl;
    cout << "\t\tInflicted " << abs(player2->get_damage()) << " damage." << endl;
    cout << "\t\tRemaining " << player2->get_strength_points() << " strength points." << endl;    //updated health
}

/*
* Function name: player2_turn()
* Purpose: Starts with player 2, player 2 attacks first
* Arguments: none
* Returns: none
*/
void Menu::player2_turn()
{
    //Display Player 2
    cout << "\n\nPlayer 2's turn." << endl;

    cout << "\n\tPlayer 2:" << endl;
    cout << "\t\t" << player2->get_name() << " attacks!" << endl;        
    player2->attack_func();     //player 2 attacks
    cout << "\n\t\tRolled " << player1->get_attack() << " attack points." << endl;

    //Display Player 1
    cout << "\n\tPlayer 1:" << endl;
    cout << "\t\t" << player1->get_name() << " defends." << endl;  
    cout << "\n\t\tStarting with " << player1->get_strength_points() << " strength points." << endl;    //starting health
    cout << "\t\t" << player1->get_armor() << " armor points." << endl;      
    player1->defense_func(player1->get_attack());   //player 1 defends
    cout << "\t\tRolled " << player1->get_defense() << " defense points." << endl;
    cout << "\t\tInflicted " << abs(player1->get_damage()) << " damage." << endl;
    cout << "\t\tRemaining " << player1->get_strength_points() << " strength points." << endl;    //updated health
}

/*
* Function name: gameplay()
* Purpose: Plays through rounds until one player loses
* Arguments: none
* Returns: none
*/
void Menu::gameplay()
{
    cout << "\n\t\tBATTLE START!" << endl;

    while (player1->get_strength_points() > 0 && player2->get_strength_points() > 0)
    {
        cout << "\n\n\t----------ROUND " << round << "----------"<< endl;

        //Player 1 turn
        if(player1->get_strength_points() > 0) { player1_turn(); }
        
        else if (player1->get_strength_points() <= 0) { break; }

        //Player 2 turn
        if(player2->get_strength_points() > 0) { player2_turn(); }

        else if (player2->get_strength_points() <= 0) { break; }

        round++;
    }

    gameover();
}

/*
* Function name: gameover();
* Purpose: Ends the game displaying winner and loser
* Arguments: none
* Returns: none
*/
void Menu::gameover()
{
    if(player1->get_strength_points() <= 0)     //player 1 lost, and player 2 won
    {
        cout << "\n\n" << player2->get_name() << " stands undeafeted!" << endl;
        cout << "\tPlayer 2 WON!" << endl;

        cout << "\n" << player1->get_name() << " perished!" << endl;
        cout << "\tPlayer 1 LOST." << endl;
    }

    else if (player2->get_strength_points() <= 0)   //player 2 lost, and player 1 won
    {
        cout << "\n" << player1->get_name() << " stands undeafeted!" << endl;
        cout << "\tPlayer 1 WON!" << endl;

        cout << "\n" << player2->get_name() << " perished!" << endl;
        cout << "\tPlayer 2 LOST." << endl;
    }

    cout << "\n\tGAME OVER!" << endl;
    return; 
}