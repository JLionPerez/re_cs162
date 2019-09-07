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
    turn = 1;
    play_again = 0;
    team_a_points = 0;
    team_b_points = 0;
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
        cout << "\nWARNING: NO SPACES OR DECIMALS!" << endl;
        cout << "\nDo you want to play again?" << endl;
        cout << "\t1) Yes" << "\t2) No" << endl;
        cout << "Enter: ";
        cin >> buffer;
        enter = atoi(buffer);

        if(enter < 1 || enter > 2) { cout << "\nPlease enter a valid number." << endl; }

        else if(enter == 1)     //play again
        {
            delete player1;     //delete previous data
            delete player2;

            delete team_a;
            delete team_b;
            delete loser_pile;

            round = 1;          //resets rounds for new game

            beginning();
        }

        else if(enter == 2)     //quit
        {
            delete player1;
            delete player2;

            delete team_a;
            delete team_b;
            delete loser_pile;

            cout << "\nBye bye!" << endl;
            return;
        }

    } while(enter < 1 || enter > 2);
}

/*
* Function name: beginning()
* Purpose: Beginning menu, asks player if they want to play
* Arguments: none
* Returns: none
*/
void Menu::beginning()
{
    do
    {
        cout << "Welcome to the Fantasy Combat Tournament!" << endl;
        cout << "\nWARNING: NO SPACES OR DECIMALS!" << endl;
        cout << "\nDo you want to play?" << endl;
        cout << "\t1) Play" << "\t\t2) Exit" << endl;
        cout << "Enter (No spaces, or decimals): ";
        cin >> buffer;

        enter = atoi(buffer);

        if (enter < 1 || enter > 2) { cout << "\nPlease try again." << endl; }

        else if (enter == 2) { cout << "\nBye bye!" << endl; return; }

    } while(enter < 1 || enter > 2);

    //ask each team how many teammates, and what characters
    teams_chose();

    //play game
    tournament();

    //play again?
    end();
}

/*
* Function name: teams_chose()
* Purpose: Lets the players choose teams
* Arguments: none
* Returns: none
*/
void Menu::teams_chose()
{
    cout << endl;
    team_a_chooses();
    cout << endl;
    team_b_chooses();
}

/*
* Function name: team_a_chooses()
* Purpose: Asks the player to choose teammates
* Arguments: none
* Returns: none
*/
void Menu::team_a_chooses()
{
    do
    {
        cout << "\nWARNING: NO SPACES OR DECIMALS!" << endl;
        cout << "Team A, how many players will you have in your team? ";
        cin >> buffer;

        team_a_mates = atoi(buffer);

        if (team_a_mates <= 0) { cout << "\nPlease try again." << endl; }

    } while (team_a_mates <= 0);

    team_a = new Queue;
    
    cout << "\nWARNING: NO SPACES OR DECIMALS!" << endl;

    cout << "\nHere is a list of characters: " << endl;
    cout << "\t1) Barbarian" << endl;
    cout << "\t2) Blue Men" << endl;
    cout << "\t3) Harry Potter" << endl;
    cout << "\t4) Medusa" << endl;
    cout << "\t5) Vampire" << endl;

    charas = 0;
    for (int i = 0; i < team_a_mates; i++)
    {
        charas++;

        do
        {
            cout << "\nOption for teammate #" << charas << ": ";
            cin >> buffer;

            option_player1 = atoi(buffer);

            if(validation(option_player1 == false)) { cout << "\nPlease try again." << endl; }

        } while(validation(option_player1 == false));

        cin.ignore();

        player1_choices();

        cout << "What is the name of this character? ";
        getline(cin, player_name);

        player1->set_name(player_name);

        team_a->addBack(player1);
    }

    cout << "\n\tTeam A lineup: ";
    team_a->print_queue();
}

/*
* Function name: team_b_chooses()
* Purpose: Asks the player to choose teammates
* Arguments: none
* Returns: none
*/
void Menu::team_b_chooses()
{
    do
    {
        cout << "\nWARNING: NO SPACES OR DECIMALS!" << endl;
        cout << "Team B, how many players will you have in your team? ";
        cin >> buffer;

        team_b_mates = atoi(buffer);

        if (team_b_mates <= 0) { cout << "\nPlease try again." << endl; }

    } while (team_b_mates <= 0);

    team_b = new Queue;

    cout << "\nWARNING: NO SPACES OR DECIMALS!" << endl;

    cout << "\nHere is a list of characters: " << endl;
    cout << "\t1) Barbarian" << endl;
    cout << "\t2) Blue Men" << endl;
    cout << "\t3) Harry Potter" << endl;
    cout << "\t4) Medusa" << endl;
    cout << "\t5) Vampire" << endl;

    charas = 0;
    for (int i = 0; i < team_b_mates; i++)
    {
        charas++;

        do
        {
            cout << "\nOption for teammate #" << charas << ": ";
            cin >> buffer;

            option_player2 = atoi(buffer);

            if(validation(option_player2) == false) { cout << "\nPlease try again." << endl; }

        } while(validation(option_player2) == false);

        cin.ignore();

        player2_choices();

        cout << "What is the name of this character? ";
        getline(cin, player_name);

        player2->set_name(player_name);

        team_b->addBack(player2);
    }

    cout << "\n\tTeam B lineup: ";
    team_b->print_queue();
}

/*
* Function name: tournament()
* Purpose: Goes through lists pairing each other to battle
* Arguments: none
* Returns: none
*/
void Menu::tournament()
{

    double percentage = 0;
    int temp = 0, health = 0;
    loser_pile = new Queue;

    while(team_a->isEmpty() == false && team_b->isEmpty() == false)
    {
        player1 = team_a->get_head()->teammate; //gets the next teammate in line
        player2 = team_b->get_head()->teammate; //

        cout << "\n* * * TURN " << turn << ": Team A " << player1->get_type() << " " << player1->get_name() << " vs. Team B " << player2->get_type() << " " << player2->get_name() << " * * *" << endl;

        gameplay();
        round = 1;  //resets round for the next battle

        if(player1->get_strength_points() > 0 && player2->get_strength_points() <= 0)    //player 1 won
        {
            //recovery
            percentage = player1->recovery();
            health = player1->get_strength_points();
            temp = player1->get_strength_points() * percentage;
            health += temp;
            player1->set_strength_points(health);

            cout << "\n" << player1->get_name() << " regained " << temp << " health points." << endl;
            cout << "Next turn's starting health will be " << player1->get_strength_points() << "." << endl;

            team_a->addBack(player1);   //add to the back of team a
            team_a->remove_front();     //removes player from front, gets new head
        }

        else if(player1->get_strength_points() <= 0 && player2->get_strength_points() > 0)    //player 1 lost
        {
            loser_pile->addBack(player1);   //adds loser to loser_pile
            team_a->remove_front();         //removes loser from team a
        }

        if(player2->get_strength_points() > 0 && player1->get_strength_points() <= 0)   //player 2 won
        {
            //recovery
            percentage = player2->recovery();
            health = player2->get_strength_points();
            temp = player2->get_strength_points() * percentage;
            health += temp;
            player2->set_strength_points(health);

            cout << "\n" << player2->get_name() << " regained " << temp << " health points." << endl;
            cout << "Next turns starting health will be " << player2->get_strength_points() << "." << endl;

            team_b->addBack(player2);   //add to the back of team b
            team_b->remove_front();     //removes player from front, gets new head
        }

        else if(player2->get_strength_points() <=0 && player1->get_strength_points() > 0)  //player 2 lost
        {
            loser_pile->addBack(player2);   //adds loser to loser_pile
            team_b->remove_front();         //removes loser from team b
        }

        turn++;

        cout << "\n~ ~ ~ Next Lineups ~ ~ ~" << endl;
        cout << "\tTeam A: ";
        team_a->print_queue();

        cout << "\tTeam B: ";
        team_b->print_queue();

        cout << endl;
    }

    winner();
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
* Function name: player1_attack()
* Purpose: player 1 attacks first
* Arguments: none
* Returns: none
*/
void Menu::player1_attack()
{
    cout << "\n\tPlayer 1:" << endl;
    cout << "\t\t" << player1->get_name() << " attacks!" << endl;        
    player1->attack_func();     //player 1 attacks
    cout << "\n\t\tRolled " << player1->get_attack() << " attack points." << endl;    
}

/*
* Function name: player1_defend()
* Purpose: player 1 defends
* Arguments: none
* Returns: none
*/
void Menu::player1_defend()
{
    //Display Player 1
    cout << "\n\tPlayer 1:" << endl;
    cout << "\t\t" << player1->get_name() << " defends." << endl;  
    cout << "\n\t\tStarting with " << player1->get_strength_points() << " strength points." << endl;    //starting health
    cout << "\t\t" << player1->get_armor() << " armor points." << endl;      
    player1->defense_func(player2->get_attack());   //player 1 defends
    cout << "\t\tRolled " << player1->get_defense() << " defense points." << endl;
    cout << "\t\tInflicted " << abs(player1->get_damage()) << " damage." << endl;
    cout << "\t\tRemaining " << player1->get_strength_points() << " strength points." << endl;    //updated health    
}

/*
* Function name: player2_attack()
* Purpose: player 2 attacks first
* Arguments: none
* Returns: none
*/
void Menu::player2_attack()
{
    cout << "\n\tPlayer 2:" << endl;
    cout << "\t\t" << player2->get_name() << " attacks!" << endl;        
    player2->attack_func();     //player 2 attacks
    cout << "\n\t\tRolled " << player2->get_attack() << " attack points." << endl;
}

/*
* Function name: player2_defend()
* Purpose: player 2 defends
* Arguments: none
* Returns: none
*/
void Menu::player2_defend()
{
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
        if(player1->get_strength_points() > 0)
        {
            //Display Player 1
            cout << "\n\nPlayer 1's turn." << endl;
            player1_attack();
            player2_defend();
        }
        
        else if (player1->get_strength_points() <= 0) { break; }

        //Player 2 turn
        if(player2->get_strength_points() > 0)
        {
            //Display Player 2
            cout << "\n\nPlayer 2's turn." << endl;
            player2_attack();
            player1_defend();
        }

        else if (player2->get_strength_points() <= 0) { break; }

        round++;
    }

    gameover();
}

/*
* Function name: gameover();
* Purpose: Ends the turn displaying winner and loser
* Arguments: none
* Returns: none
*/
void Menu::gameover()
{
    if(player1->get_strength_points() <= 0)     //player 1 lost, and player 2 won
    {
        cout << "\n\n" << player2->get_type() << " " << player2->get_name() << " Won!" << endl;
        cout << "\tTEAM B GAINED 2 POINTS" << endl;

        //add 2 points to team b
        team_b_points += 2;

        cout << "\n" << player1->get_type() << " " << player1->get_name() << " Lost." << endl;
        cout << "\tTEAM A LOST 1 POINT" << endl;
        
        //subtract 1 point from team a
        team_a_points--;

        cout << "\n\tTEAM B WON THIS TURN!" << endl;
    }

    else if (player2->get_strength_points() <= 0)   //player 2 lost, and player 1 won
    {
        cout << "\n" << player1->get_type() << " " << player1->get_name() << " Won!" << endl;
        cout << "\tTEAM A GAINED 2 POINTS" << endl;

        //add 2 points to team a 
        team_a_points += 2;

        cout << "\n" << player2->get_type() << " " << player2->get_name() << " Lost." << endl;
        cout << "\tTEAM B LOST 1 POINT" << endl;

        //subtract 1 point from team b
        team_b_points--;

        cout << "\n\tTEAM A WON THIS TURN!" << endl;
    }

    cout << "\n- - - Current Scores - - -" << endl;
    cout << "\tTeam A: " << team_a_points << endl;
    cout << "\tTeam B: " << team_b_points << endl;

    return; 
}

/*
* Function name: winner()
* Purpose: Determines the winning team, or tie
* Arguments: none
* Returns: none
*/
void Menu::winner()
{
    cout << "\n* * * * * * SCORES * * * * * *" << endl;

    if(team_a_points > team_b_points)   //team a had more points than team b
    {
        cout << "\n\tTEAM A TOTAL POINTS: " << team_a_points << endl;
        cout << "\tTEAM B TOTAL POINTS: " << team_b_points << endl;
        cout << "\n\tWINNER IS TEAM A!" << endl;

        team_a->clear();    //deletes list
    }

    else if(team_a_points < team_b_points)  //team a had less points than team b
    {
        cout << "\n\tTEAM A TOTAL POINTS: " << team_a_points << endl;
        cout << "\tTEAM B TOTAL POINTS: " << team_b_points << endl;
        cout << "\n\tWINNER IS TEAM B!" << endl;

        team_b->clear();    //deletes list
    }

    else if (team_a_points == team_b_points)  //tie
    {
        cout << "\n\tTEAM A TOTAL POINTS: " << team_a_points << endl;
        cout << "\tTEAM B TOTAL POINTS: " << team_b_points << endl;
        cout << "\n\tBOTH TEAMS ARE A TIE!" << endl;
    }

    print_loser_pile();
}

/*
* Function name: print_loser_pile()
* Purpose: Prints the names of those who fell
* Arguments: none
* Returns: none
*/
void Menu::print_loser_pile()
{
    do
    {
        cout << "\nWARNING: NO SPACES OR DECIMALS!" << endl;

        cout << "\nDo you want to print out the loser pile?" << endl;
        cout << "\t1) Yes" << "\t\t2) No" << endl;
        cout << "Enter: ";
        cin >> buffer;

        enter = atoi(buffer);

        if(enter < 1 || enter > 2) { cout << "\nPlease try again." << endl; }

        else if (enter == 1)
        {
            cout << "\nLoser pile: ";
            loser_pile->print_queue();
        }

    } while (enter < 1 || enter > 2);
}