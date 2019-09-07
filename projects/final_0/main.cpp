/*
* Program name: Final Project - Tower Rescue, A Test-Based Game
* Author: Joelle Perez
* Description: This is a game where the player is a knight going in a tower facing enemies to rescue the princess/prince.
* Date: 18 March 2019
*/

#include "game.hpp"

//prototype
bool try_game_again();

int main()
{
    srand(time(NULL));

    Game *g = NULL;

    do
    {
        g = new Game();
        g->beginning();

        delete g;

    } while (g->is_done() && try_game_again());

    return 0;
}

/*
* Function name: try_game_again()
* Purpose: To ask the player if they want to play again
* Arguments: none
* Returns: boolean
*/
bool try_game_again() {

    int again;
    do 
    {
        cout << "\nDo you want to play again?" << endl;
        cout << "\t1) Yes" << endl;
        cout << "\t2) No" << endl;
        cout << "Enter: ";
        cin >> again;

        if (cin.fail() || again < 1 || again > 2)
        {
            cout << "\nPlease try again." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }
        
        else if (again == 2) { cout << "\nBye bye!" << endl; return false; }
        
        else if (again == 1) { return true; }

    } while (cin.fail() || again < 1 || again > 2);
}