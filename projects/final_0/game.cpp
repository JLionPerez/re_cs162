/*
* File name: game.hpp
* Purpose: Holds the prototypes for game.cpp
*/

#include "game.hpp"

/*
* Function name: Game()
* Purpose: Constructor for class, initializes members
* Arguments: none
* Returns: none
*/
Game::Game()
{
    floor1 = NULL;
    floor2 = NULL;
    floor3 = NULL;
    floor4 = NULL;
    floor5 = NULL;
    floor6 = NULL;
    current_floor = NULL;

    completed = false;
    quit = false;

    done = false;
}

/*
* Function name: beginning()
* Purpose: Welcomes player and begins the game
* Arguments: none
* Returns: none
*/
void Game::beginning()
{
    cout << "\nWelcome to Tower Rescue!" << endl;

    cout << "\nYou're a Knight from a far away kingdom." << endl;
    cout << "You came to a tower where a princess/prince is kept hostage in the top floor." << endl;
    cout << "\nYour task is to save this princess/prince by going up through each floor." << endl;
    cout << "Challenging each opponent you face in order to save them." << endl;
    cout << "\nYou will face jesters and magicians.\nYou must win their games in order to move on and get Gems." << endl;
    cout << "There will be 4 Gems to open the door leading to the top floor of the tower." << endl;
    cout << "\nYou will have a total of 100 points of health.\nEach time you lose to an opponent your health is reduced." << endl;
    cout << "Once your health reaches 0 you'll lose and the game will end.\nHowever, if you reach the top and save the princess/prince then you will win the game!" << endl;

    cout << "\nHere is the layout of the tower:" << endl; 
    cout << endl;
    cout << "                _||_ " << endl;
    cout << "              _|    |_" << endl;
    cout << "            _|________|_" << endl;
    cout << "           |__|  __  |__| " <<endl;
    cout << "              | |__| |" <<endl;
    cout << "              |______|" << endl;
    cout << "              |      |" << endl;
    cout << "              |  5F  |" << endl;
    cout << "              |______|" << endl;
    cout << "              |      |" << endl;
    cout << "              |  4F  |" << endl;
    cout << "              |______|" << endl;
    cout << "              |      |" << endl;
    cout << "              |  3F  |" << endl;
    cout << "              |______|" << endl;
    cout << "              |      |" << endl;
    cout << "              |  2F  |" << endl;
    cout << "              |______|" << endl;
    cout << "              | ____ |" << endl;
    cout << "              | |||| |" << endl;
    cout << "_-_-_-_-_-_-_-|_||||_|_-_-_-_-_-_-_-" << endl;

    set_floors();

    //at the gates of the tower
    current_floor = floor1;
    play();
}

/*
* Function name: validate_input()
* Purpose: Validates the inputs within ranges
* Arguments: none
* Returns: none
*/
void Game::validate_input(int min, int max)
{
    do
    {
        cout << "Choice: ";
        cin >> choice;
        
        if(cin.fail() || choice < min || choice > max)
        {
            cout << "\nPlease try again." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }

    } while (cin.fail() || choice < min || choice > max);
}

/*
* Function name: floor1_menu()
* Purpose: The menu for first floor
* Arguments: none
* Returns: none
*/
void Game::floor1_menu()
{
    if(current_floor->get_went_back())   //quitted at the beginning of game
    {
        cout << "\nFrom developer: 'Wow, you didn't even try.' (-_-)" << endl;
        quit = true;
    }

    else if(current_floor->get_went_back() == false)
    {
        display_floor();
        cout << "\nHealth: " << knight.get_health() << endl;
        knight.print_gems();

        cout << "\n1) Go up the stairs to " << current_floor->get_top()->get_name() << "." << endl;
        validate_input(1, 1);

        if(choice == 1) //goes up to the top floor
        {
            current_floor = current_floor->get_top();
            choice = 0; //resets choice
        }
    }
}

/*
* Function name: floor6_menu()
* Purpose: The menu for floor 6
* Arguments: none
* Returns: none
*/
void Game::floor6_menu()
{
    if(current_floor->get_went_back())
    {
        cout << "\n1) Go down the stairs to " << current_floor->get_bottom()->get_name() << "." << endl;
        validate_input(1, 1);

        if(choice == 1) //goes down to the bottom floor
        {
            current_floor = current_floor->get_bottom();
            choice = 0; //resets choice
        }
    }

    else if(current_floor->get_went_back() == false)
    {
        sleep_for(milliseconds(50));
        cout << "\nStanding there is the princess/prince, you found them!" << endl;
        cout << "You won the game, Congratulations!" << endl;
        completed = true;
    }
}

/*
* Function name: floors_menus()
* Purpose: The menus for floors between 1 and 6
* Arguments: none
* Returns: none
*/
void Game::floors_menus()
{
    if(current_floor->get_went_back()) //if knight got hurt
    {
        current_floor = current_floor->get_bottom();    //goes back down
    }

    else if(current_floor->get_passed() && current_floor->get_went_back() == false)    //moves to the next
    {
        cout << "\n1) Go up the stairs to " << current_floor->get_top()->get_name() << "." << endl;
        cout << "\n2) Go down the stairs to " << current_floor->get_bottom()->get_name() << "." << endl;
        validate_input(1, 2);

        if(choice == 1) //goes up to top floor
        {
            current_floor = current_floor->get_top();
            choice = 0; //resets choice
        }

        else if(choice == 2)
        {
            current_floor = current_floor->get_bottom();
            choice = 0; //resets choice
        }                
    }  
}

/*
* Function name: play()
* Purpose: The main function to keep the game going
* Arguments: none
* Returns: none
*/
void Game::play()
{
    while(knight.get_health() > 0 && completed == false && quit == false)
    {
        current_floor->special(knight);
        
        if (current_floor->get_name() == "1st Floor")
        {
            floor1_menu();
        }

        else if (current_floor->get_name() == "6th Floor")
        {
            floor6_menu();
        }

        else if (current_floor->get_top() != NULL && current_floor->get_bottom() != NULL)
        {
            floors_menus();
        }

        if(quit == false)
        {
            display_floor();
            cout << "\nHealth: " << knight.get_health() << endl;
            knight.print_gems();
        }

        game_over();
    }
    end();
}

/*
* Function name: game_over()
* Purpose: To exit game when player dies
* Arguments: none
* Returns: none
*/
void Game::game_over()
{
    //knight dies
    if(knight.get_health() <= 0)
    {
        cout << "\nSadly, you died fighting valantly." << endl;
        cout << "Game Over!" << endl;
        quit = true;
    }    
}

/*
* Function name: set_floors()
* Purpose: Links and initializes floors
* Arguments: none
* Returns: none
*/
void Game::set_floors()
{
    //floor 6 initialize and links
    floor6 = new Highest();
    floor6->set_name("6th Floor");
    floor6->set_top(NULL);
    floor6->set_left(NULL);
    floor6->set_right(NULL);

    //floor 5 initialize and links
    floor5 = new Magician();
    floor5->set_name("5th Floor");
    floor5->set_top(floor6);
    floor5->set_left(NULL);
    floor5->set_right(NULL);

    //floor 4 initialize and links
    floor4 = new Jester();
    floor4->set_name("4th Floor");
    floor4->set_top(floor5);
    floor4->set_left(NULL);
    floor4->set_right(NULL);

    //floor 3 initialize and links
    floor3 = new Magician();
    floor3->set_name("3rd Floor");
    floor3->set_top(floor4);
    floor3->set_left(NULL);
    floor3->set_right(NULL);

    //floor 2 initialize and links
    floor2 = new Jester();
    floor2->set_name("2nd Floor");
    floor2->set_top(floor3);
    floor2->set_left(NULL);
    floor2->set_right(NULL);

    //floor 1 initialize and links
    floor1 = new Gates();
    floor1->set_name("1st Floor");
    floor1->set_top(floor2);
    floor1->set_bottom(NULL);
    floor1->set_left(NULL);
    floor1->set_right(NULL);

    //set bottoms
    floor2->set_bottom(floor1);
    floor3->set_bottom(floor2);
    floor4->set_bottom(floor3);
    floor5->set_bottom(floor4);
    floor6->set_bottom(floor5);
}

/*
* Function name: display_floor()
* Purpose: Displays the floor the player is in
* Arguments: none
* Returns: none
*/
void Game::display_floor()
{
    cout << "\nYou are on the " << current_floor->get_name() << "." << endl;

    if(current_floor->get_name() == "1st Floor")
    {
        cout << endl;
        cout << "                _||_ " << endl;
        cout << "              _|    |_" << endl;
        cout << "            _|________|_" << endl;
        cout << "           |__|  __  |__| " <<endl;
        cout << "              | |__| |" <<endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  5F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  4F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  3F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  2F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              | (-_-)|" << endl;
        cout << "_-_-_-_-_-_-_-|______|_-_-_-_-_-_-_-" << endl;
    }

    else if(current_floor->get_name() == "2nd Floor")
    {
        cout << "\nHere is the layout of the tower:" << endl; 
        cout << endl;
        cout << "                _||_ " << endl;
        cout << "              _|    |_" << endl;
        cout << "            _|________|_" << endl;
        cout << "           |__|  __  |__| " <<endl;
        cout << "              | |__| |" <<endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  5F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  4F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  3F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              | (-_-)|" << endl;
        cout << "              |______|" << endl;
        cout << "              | ____ |" << endl;
        cout << "              | |||| |" << endl;
        cout << "_-_-_-_-_-_-_-|_||||_|_-_-_-_-_-_-_-" << endl;
    }

    else if(current_floor->get_name() == "3rd Floor")
    {
        cout << "\nHere is the layout of the tower:" << endl; 
        cout << endl;
        cout << "                _||_ " << endl;
        cout << "              _|    |_" << endl;
        cout << "            _|________|_" << endl;
        cout << "           |__|  __  |__| " <<endl;
        cout << "              | |__| |" <<endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  5F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  4F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              | (-_-)|" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  2F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              | ____ |" << endl;
        cout << "              | |||| |" << endl;
        cout << "_-_-_-_-_-_-_-|_||||_|_-_-_-_-_-_-_-" << endl;
    }

    else if(current_floor->get_name() == "4th Floor")
    {
        cout << "\nHere is the layout of the tower:" << endl; 
        cout << endl;
        cout << "                _||_ " << endl;
        cout << "              _|    |_" << endl;
        cout << "            _|________|_" << endl;
        cout << "           |__|  __  |__| " <<endl;
        cout << "              | |__| |" <<endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  5F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              | (-_-)|" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  3F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  2F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              | ____ |" << endl;
        cout << "              | |||| |" << endl;
        cout << "_-_-_-_-_-_-_-|_||||_|_-_-_-_-_-_-_-" << endl;
    }

    else if(current_floor->get_name() == "5th Floor")
    {
        cout << "\nHere is the layout of the tower:" << endl; 
        cout << endl;
        cout << "                _||_ " << endl;
        cout << "              _|    |_" << endl;
        cout << "            _|________|_" << endl;
        cout << "           |__|  __  |__| " <<endl;
        cout << "              | |__| |" <<endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              | (-_-)|" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  4F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  3F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  2F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              | ____ |" << endl;
        cout << "              | |||| |" << endl;
        cout << "_-_-_-_-_-_-_-|_||||_|_-_-_-_-_-_-_-" << endl;
    }

    else if(current_floor->get_name() == "6th Floor")
    {
        cout << "\nHere is the layout of the tower:" << endl; 
        cout << endl;
        cout << "                _||_ " << endl;
        cout << "              _|    |_" << endl;
        cout << "            _|________|_" << endl;
        cout << "           |__|      |__| " <<endl;
        cout << "              | (-_-)|" <<endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  5F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  4F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  3F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              |      |" << endl;
        cout << "              |  2F  |" << endl;
        cout << "              |______|" << endl;
        cout << "              | ____ |" << endl;
        cout << "              | |||| |" << endl;
        cout << "_-_-_-_-_-_-_-|_||||_|_-_-_-_-_-_-_-" << endl;
    }
}

/*
* Function name: end()
* Purpose: Indicates when the game ends
* Arguments: none
* Returns: none
*/
void Game::end() { done = true; }

/*
* Function name: is_done()
* Purpose: Returns status on the game
* Arguments: none
* Returns: boolean
*/
bool Game::is_done() { return done; }