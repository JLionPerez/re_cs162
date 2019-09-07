/*
* File name: jester.cpp
* Purpose: Holds definitions for jester.hpp
*/

#include "jester.hpp"

/*
* Function name: Jester()
* Purpose: Constructor for class, initializes members
* Arguments: none
* Returns: none
*/
Jester::Jester()
{
    damage = 5;
    enemy_points = 0;
    player_points = 0;
    rounds = 3; //3 rounds of rock, paper, scissors
}

/*
* Function name: validation()
* Purpose: validates user's input
* Arguments: none
* Returns: none
*/
void Jester::validation()
{
    do
    {
        cout << "\nYou get your hands ready." << endl;
        cout << "\t1) Rock \t2) Paper \t3) Scissors" << endl;
        cout << "\nWhat do you pick? ";
        cin >> option;

        if (option < 1 || option > 3 || cin.fail())
        {
            cout << "\nPlease try again." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }

        else if (option == 1) { player_pick = ROCK; }
        else if (option == 2) { player_pick = PAPER; }
        else if (option == 3) { player_pick = SCISSORS; }

    } while(option < 1 || option > 3 || cin.fail());
}

/*
* Function name: options()
* Purpose: Lets user pick an option
* Arguments: Pick (enum)
* Returns: none
*/
void Jester::options(Pick pick)
{
    switch (pick)
    {
        case ROCK:
            cout << "Rock." << endl;
            break;
        case PAPER:
            cout << "Paper." << endl;
            break;
        case SCISSORS:
            cout << "Scissors." << endl;
            break;
        default:
            break;
    }
}

/*
* Function name: player_winnings()
* Purpose: When player wins a round
* Arguments: none
* Returns: none
*/
void Jester::player_winnings()
{
    if (player_pick == PAPER && jester_pick == ROCK)
    {
        cout << "\nYou won this round!" << endl;
        player_points++;    //gained point
    }

    else if (player_pick == SCISSORS && jester_pick == PAPER)
    {
        cout << "\nYou won this round!" << endl;
        player_points++;    //gained point
    }

    else if (player_pick == ROCK && jester_pick == SCISSORS)
    {
        cout << "\nYou won this round!" << endl;
        player_points++;    //gained point
    }
}

/*
* Function name: enemy_winnings()
* Purpose: when enemy wins
* Arguments: none
* Returns: none
*/
void Jester::enemy_winnings()
{
    if (jester_pick == PAPER && player_pick == ROCK)
    {
        cout << "\nThe jester won this round!" << endl;
        enemy_points++;    //gained point
    }

    else if (jester_pick == SCISSORS && player_pick == PAPER)
    {
        cout << "\nThe jester won this round!" << endl;
        enemy_points++;    //gained point
    }

    else if (jester_pick == ROCK && player_pick == SCISSORS)
    {
        cout << "\nThe jester won this round!" << endl;
        enemy_points++;    //gained point
    }
}

/*
* Function name: special()
* Purpose: Special action for floor
* Arguments: referencd Player
* Returns: none
*/
void Jester::special(Player& knight)
{
    if(passed == false)     //first time entering
    {
        int temp;
        cout << "\nA jester appeared, he challenges you to a game of Rock, Paper, Scissors!" << endl;

        do
        {
            cout << "There will be 3 rounds." << endl;

            for(int i = 0; i < rounds; i++)
            {
                temp = i;

                //get user input
                validation(); 

                //play round
                cout << "\n* * * * * * ROUND "<< temp + 1 << " * * * * * *" << endl;

                jester_pick = static_cast<Pick>(rand() % SCISSORS + ROCK);

                cout << "\n\t1, 2, 3..." << endl;
                sleep_for(milliseconds(500));

                cout << "\n\tYou threw ";
                options(player_pick);

                cout << "\tJester threw ";
                options(jester_pick);

                //tie no one gets points
                if (jester_pick == player_pick) { cout << "\nIt was a draw! No one won or lost this round." << endl; }
                
                //if player won gets a point
                player_winnings();

                //if jester won gets a point
                enemy_winnings();
            }
            //display points
            cout << "\n\t- SCORES -" << endl;
            cout << "\n\tYou won " << player_points << " rounds." << endl;
            cout << "\tThe jester won " << enemy_points << " rounds." << endl;

            if (player_points == enemy_points)
            {
                cout << "\nOverall both sides are tied in rounds, so there will be a repeat." << endl;
                player_points = 0;
                enemy_points = 0;
                temp = 0;   //restarts counting
            }

        }while (player_points == enemy_points);     //if points on both sides are equal play again

        //if player had more points they pass
        if (player_points > enemy_points)
        {
            cout << "\nYou've defeated the jester!\nIn shame the jester pulled a lever which opened a door beneath him, exiting the scene." << endl;
            cout << "You recieved a Gem!" << endl;
            passed = true;
            went_back = false;
            knight.add_gem();
        }

        //else return damage
        else if (enemy_points > player_points)
        {
            cout << "\nThe jester spins towards you.\nHitting you with the bells on his cap dealing 5 points of damage." << endl;
            knight.dealt_damage(damage);
            cout << "Then the jester pulled a lever which opened a door beneath you.\nYou fell down to the previous floor you were in." << endl;
            went_back = true;
        }

        player_points = 0;
        enemy_points = 0;
        temp = 0;   //restarts counting
    }

    else if (passed) { cout << "\nYou already went through here and defeated the jester." << endl; } //already went through here
}