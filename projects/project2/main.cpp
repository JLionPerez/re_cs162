/*
* Program name: Project 2 - Zoo Tycoon
* Author: Joelle Perez
* Description: This program is a game where the user owns a zoo with three species of animals, they must maintain profit in order for the zoo to keep running.
* Date: 3 February 2019
* Cited work: How to Generate Random Numbers Betwee Two Variables
*            //https://stackoverflow.com/questions/12657962/how-do-i-generate-a-random-number-between-two-variables-that-i-have-stored
*/

#include "zoo.hpp"
#include "animal.hpp"
#include "penguin.hpp"
#include "tiger.hpp"
#include "turtle.hpp"

int main()
{
    Zoo z;
    Animal a;
    Penguin p;
    Tiger t;
    Turtle tt;

    char buffer[100];   //for input validation
    int remaining_money = 0, num_animals = 0, option = 0, bonus_payoff = 0;

    cout << "\nWelcome to Zoo Tycoon!" << endl;
    cout << "First, you have to buy a penguin, a tiger, and a turtle to start." << endl;

    while(z.get_bankruptcy() != true)   //keep going if there's still money in the bank
    {
        cout << "\nDay: " << z.get_days() << endl;
        cout << "Money in the Bank: $" << z.get_bank() << endl;

        do  //buy penguins
        {
            cout << "\nHow many penguins will you buy? Between 1 and 2." << endl;
            cout << "Or press 3 to not buy penguins." << endl;
            cout << "\nEach penguin costs $" << p.get_cost() << endl;
            cout << "Number: ";
            cin >> buffer;

            num_animals = atoi(buffer);

            if(num_animals < 1 || num_animals > 3) { cout << "\nSorry, please enter only 1 or 2." << endl; }

            else if(num_animals == 3) { cout << "Okay, no penguins today." << endl; break; }

            else
            {
                z.set_bank(z.get_bank() - (p.get_cost() * num_animals));    //subtracts cost from bank money
                z.set_num_penguins(num_animals);
                z.add_penguin();
            }

        } while(num_animals < 1 || num_animals > 3);

        do  //buy tigers
        {
            cout << "\nHow many tigers will you buy? Between 1 or 2." << endl;
            cout << "Or press 3 to not buy tigers." << endl;
            cout << "\nEach tiger costs $" << t.get_cost() << endl;
            cout << "Number: ";
            cin >> buffer;

            num_animals = atoi(buffer);

            if(num_animals < 1 || num_animals > 3) { cout << "\nSorry, please enter only 1 or 2." << endl; }

            else if(num_animals == 3) { cout << "Okay, no tigers today." << endl; break; }

            else 
            {   
                z.set_bank(z.get_bank() - (t.get_cost() * num_animals));    //subtracts cost from bank money
                z.set_num_tigers(num_animals);
                z.add_tiger();
            }

        } while(num_animals < 1 || num_animals > 3);

        do  //buy turtles
        {   cout << "\nHow many turtles will you buy? Between 1 or 2." << endl;
            cout << "Each turtle costs $" << tt.get_cost() << endl;
            cout << "\nOr press 3 to not buy turtles." << endl;
            cout << "Number: ";
            cin >> buffer;

            num_animals = atoi(buffer);

            if(num_animals < 1 || num_animals > 3) { cout << "\nSorry, please enter only 1 or 2." << endl; }

            else if(num_animals == 3) { cout << "Okay, no turtles today." << endl; break; }

            else
            {
                z.set_bank(z.get_bank() - (tt.get_cost() * num_animals));   //subtracts cost from bank money
                z.set_num_turtles(num_animals);
                z.add_turtle();
            }

        } while(num_animals < 1 || num_animals > 3);

        z.set_days(1);  //increases day by 1

        if(z.get_num_penguins() > 0) { z.increase_peng_age(); }     //if there are any animals increase their age

        if(z.get_num_tigers() > 0) { z.increase_tiger_age(); }      //

        if(z.get_num_turtles() > 0) { z.increase_turtle_age(); }    //

        z.random_events(bonus_payoff);

        cout << "\nNumber of penguins: " << z.get_num_penguins() << endl;   
        z.print_peng_info();

        cout << "\nNumber of tigers: " << z.get_num_tigers() << endl;
        z.print_tiger_info();

        cout << "\nNumber of turtles: " << z.get_num_turtles() << endl;
        z.print_turtle_info();

        z.total_cost(p, t, tt);     //added costs of bought animals
        z.total_payoff(p, t, tt, bonus_payoff);
        z.total_feeding_cost(p, t, tt);

        cout << "\nRemaing balance at the end of day: $" << z.get_bank() << endl;

        if(z.get_bank() <= 0)   //exits game when money = 0 or less
        {
            cout << "\nGame over!" << endl;
            z.set_bankruptcy(true);
            return 0;
        }

        do  //ask user to keep playing or quit  
        {
            cout << "\nWill you play again or quit?" << endl;
            cout << "1) Play again" << endl;
            cout << "2) Quit" << endl;
            cout << "Option: ";
            cin >> buffer;

            option = atoi(buffer);

            if(option != 1 && option != 2) { cout << "\nSorry, please enter only 1 or 2." << endl; }

            else if(option == 2) { return 0; }

        } while (option != 1 && option != 2);
    }

    return 0;
}