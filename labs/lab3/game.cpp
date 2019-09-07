/*
* File name: game.cpp
* Purpose: Holds definitions for prototypes in game.hpp.
*/
#include "game.hpp"

/*
* Function Name: start_menu()
* Purpose: To ask the player if they would want to play or exit
* Arguments: none
* Returns: none
*/
int Game::start_menu()
{
    char buffer[100];
    int hold;
    do
    {
        cout << "\nDo you want to play or exit the game?" << endl;
        cout << "1) Play game" << endl;
        cout << "2) Exit game" << endl;
        cout << "\nEnter: ";
        cin >> buffer;

        hold = atoi(buffer);
        set_option(hold);

        if(option == 2)
        {
            cout << "\nGoodbye!" << endl;
            return 0;
        }

        else if(option != 1)
        {
            cout << "\nPlease enter an integer." << endl;
        }

    } while (option != 1);
    
}

/*
* Function Name: main_menu()
* Purpose: To ask the player how many rounds and gather input
* Arguments: none
* Returns: none
*/
void Game::main_menu()
{
    char buffer[100];
    //int num;
    if(option == 1)
    { 
        do
        {
            cout << "\nHow many rounds will be played? ";
            cin >> buffer;
            rounds = atoi(buffer);

            //cout << rounds << endl;

            if(rounds == 0)
            {
                cout << "\nPlease enter integers." << endl;
            }

            else
            {
                player_num = 1;
                cout << "\nPlayer 1, ";
                type_die(player1);

                player_num = 2;
                cout << "\nPlayer 2,";
                type_die(player2);
            }

        }while(rounds == 0);
    }
}

/*
* Function Name: type_die()
* Purpose: To ask the user what kind of die they would want
* Arguments: Die player
* Returns: none
*/
void Game::type_die(Die *player)
{
    char buffer[100];
    int temp;

    do
    {
        cout << "what type of die would you like?" << endl;
        cout << "1) Normal" << endl;
        cout << "2) Loaded" << endl;
        cin >> buffer;

        temp = atoi(buffer);
        
        //cout << temp << endl;

        if(temp != 1 && temp != 2)
        {
            cout << "\nPlease enter an integer." << endl;
        }

    }while(temp != 1 && temp != 2);

    if(player_num == 1)
    {
        create_die(temp, player1);

        if(temp == 1)
        {
            player1_norm_load = temp; //normal
        }

        else if (temp == 2)
        {
            player1_norm_load = temp; //loaded
        }
    }

    else if(player_num == 2)
    {
        create_die(temp, player2);

        if(temp == 1)
        {
            player2_norm_load = temp; //normal
        }

        else if (temp == 2)
        {
            player2_norm_load = temp; //loaded
        }
    }   
}

/*
* Function Name: total_sides()
* Purpose: Gets the total sides from the user
* Arguments: Die player
* Returns: none
*/
void Game::total_sides(Die* player)
{
    char buffer[100];
    Die d;
    int sides;

    cout << "\nEnter the number of sides: ";
    cin >> buffer;
    sides = atoi(buffer);
    d.set_sides(sides);
}

/*
* Function Name: create_die()
* Purpose: To create new dies for the player
* Arguments: integer and Die player
* Returns: none
*/
void Game::create_die(int hold, Die *player)
{
    if(hold == 1)
    {
        player = new Die();     //player gets normal die    
    }

    else if(hold == 2)
    {
        player = new LoadedDie();    //player gets loaded die
    }
}

/*
* Function Name: compare_rolls()
* Purpose: To compare both players to see which had the highest values
* Arguments: Die pointers
* Returns: none
*/
int Game::compare_rolls(Die *player1, Die *player2)
{
    if(player1_norm_load == 1 && player2_norm_load == 1)
    {
        if(player1->roll() > player2->roll())
        {
            //player 1 gets 1 point
        }
    }
}

/*
* Function Name: delete_objs()
* Purpose: To delete objects from the heap
* Arguments: none
* Returns: none
*/
void Game::delete_objs()
{
    delete player1;
    delete player2;
}