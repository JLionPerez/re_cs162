/*
* File name: zoo.cpp
* Purpose: Holds the definitions for zoo.hpp
*/

#include "zoo.hpp"

/*
* Function name: Zoo()
* Purpose: Default constructor to initialize members
* Arguments: none
* Returns: none
*/
Zoo::Zoo()
{
    bank = 100000;
    days = 0;
    bankruptcy = false;

    starting_capacity = 10;

    num_penguins = 0;
    penguin_list = new Penguin[starting_capacity];
    
    num_tigers = 0;
    tiger_list = new Tiger[starting_capacity];

    num_turtles = 0;
    turtle_list = new Turtle[starting_capacity];
}

/*
* Function name: ~Zoo()
* Purpose: Deletes allocated memory on the heap
* Arguments: none
* Returns: none
*/
Zoo::~Zoo()
{
    delete [] penguin_list;
    delete [] tiger_list;
    delete [] turtle_list;
}

/*
* Function name: get_starting_capacity()
* Purpose: Returns private member to be available outside of class
* Arguments: none
* Returns: integer
*/
int Zoo::get_starting_capacity()
{
    return starting_capacity;
}

/*
* Function name: set_starting_capacity()
* Purpose: Sets private member to passed value
* Arguments: integer
* Returns: none
*/
void Zoo::set_starting_capacity(int starting_capacity)
{
    this->starting_capacity = starting_capacity;
}

/*
* Function name: get_bank()
* Purpose: Returns private member to be available outside of class
* Arguments: none
* Returns: double
*/
double Zoo::get_bank()
{
    return bank;
}

/*
* Function name: set_bank()
* Purpose: Sets private member to passed value
* Arguments: double
* Returns: none
*/
void Zoo::set_bank(double bank)
{
    this->bank = bank;
}

/*
* Function name: get_days()
* Purpose: Returns private member to be available outside of class
* Arguments: none
* Returns: integer
*/
int Zoo::get_days()
{
    return days;
}

/*
* Function name: set_days()
* Purpose: Sets private member to passed value
* Arguments: integer
* Returns: none
*/
void Zoo::set_days(int days)
{
    this->days += days;
}

/*
* Function name: get_bankruptcy()
* Purpose: Returns private member to be available outside of class
* Arguments: none
* Returns: boolean
*/
bool Zoo::get_bankruptcy()
{
    return bankruptcy;
}

/*
* Function name: set_bankruptcy()
* Purpose: Sets private member to passed value
* Arguments: boolean
* Returns: none
*/
void Zoo::set_bankruptcy(bool bankruptcy)
{
    this->bankruptcy = bankruptcy;

}

/*
* Function name: get_num_penguins()
* Purpose: Returns private member to be available outside of class
* Arguments: none
* Returns: integer
*/
int Zoo::get_num_penguins()
{
    return num_penguins;
}

/*
* Function name: set_num_penguins()
* Purpose: Sets private member to passed value
* Arguments: integer
* Returns: none
*/
void Zoo::set_num_penguins(int num_penguins)
{
    this->num_penguins += num_penguins;
}

/*
* Function name: get_num_tigers()
* Purpose: Returns private member to be available outside of class
* Arguments: none
* Returns: integer
*/
int Zoo::get_num_tigers()
{
    return num_tigers;
}

/*
* Function name: set_num_tigers()
* Purpose: Sets private member to passed value
* Arguments: integer
* Returns: none
*/
void Zoo::set_num_tigers(int num_tigers)
{
    this->num_tigers += num_tigers;
}

/*
* Function name: get_num_turtles()
* Purpose: Returns private member to be available outside of class
* Arguments: none
* Returns: integer
*/
int Zoo::get_num_turtles()
{
    return num_turtles;
}

/*
* Function name: set_num_turtles()
* Purpose: Sets private member to passed value
* Arguments: integer
* Returns: none
*/
void Zoo::set_num_turtles(int num_turtles)
{
    this->num_turtles += num_turtles;
}

/*
* Function name: remove_penguin()
* Purpose: Removes a certain animal from their list
* Arguments: integer
* Returns: none
*/
void Zoo::remove_penguin(int animal_place)  //animal_place is where the animal that will be removed is placed
{
    Penguin *temp_list = new Penguin[num_penguins];  //dynamic temp array
    penguin_temp(animal_place, temp_list);

    for(int i = animal_place + 1; i < num_penguins; i++)  //assigns penguins, after removed penguin, from old to temp array
    {
        temp_list[i-1] = penguin_list[i];  //temp_array continues from the skipped index of the original array
    }

    num_penguins--;
    delete [] penguin_list; //deletes array to delete the removed penguin
    penguin_list = new Penguin[num_penguins];   //make new array with less penguins

    assign_penguin_data(temp_list);

    delete [] temp_list;   //deletes temp array since it's not needed anymore
}

/*
* Function name: add_penguin()
* Purpose: Adds an animal to their species' list
* Arguments: none
* Returns: none
*/
void Zoo::add_penguin()
{
    Penguin* temp_list = new Penguin[num_penguins];
    penguin_temp(num_penguins, temp_list);

    delete [] penguin_list; //deletes array to add new penguin

    penguin_list = new Penguin[num_penguins];

    for(int i = 0; i < num_penguins - 2; i++)   //reloads old data, except for removed, back into original array
    {
        penguin_list[i].set_age(temp_list[i].get_age());
        penguin_list[i].set_base_food_cost(temp_list[i].get_base_food_cost());
        penguin_list[i].set_cost(temp_list[i].get_cost());
        penguin_list[i].set_num_babies(temp_list[i].get_num_babies());
        penguin_list[i].set_payoff(temp_list[i].get_payoff());
    }
    delete [] temp_list;
}

/*
* Function name: add_peng_baby()
* Purpose: Add baby animals to their list increasing the array
* Arguments: none
* Returns: none
*/
void Zoo::add_peng_baby()
{
    num_penguins = num_penguins + penguin_list[0].get_num_babies(); //add in the babies, new value
    Penguin* temp_list = new Penguin[num_penguins];
    penguin_temp(num_penguins, temp_list);

    delete [] penguin_list; //deletes array to add new penguins

    penguin_list = new Penguin[num_penguins];   //makes a new list with added babies

    for(int i = 0; i < num_penguins - 3; i++)   //reloads old data, except for removed, back into original array
    {
        penguin_list[i].set_age(temp_list[i].get_age());
        penguin_list[i].set_base_food_cost(temp_list[i].get_base_food_cost());
        penguin_list[i].set_cost(temp_list[i].get_cost());
        penguin_list[i].set_num_babies(temp_list[i].get_num_babies());
        penguin_list[i].set_payoff(temp_list[i].get_payoff());
    }
    delete [] temp_list;    
}

/*
* Function name: increase_peng_age()
* Purpose: Increase each animal's age by 1
* Arguments: none
* Returns: none
*/
void Zoo::increase_peng_age()
{
    int j = 0;
    for(int i = 0; i < num_penguins; i++)
    {
        j++;
        penguin_list[i].set_age(j);
    }
}

/*
* Function name: chosen_penguin()
* Purpose: Chooses an animal in the list to be returned
* Arguments: integer
* Returns: Penguin
*/
Penguin Zoo::chosen_penguin(int chosen)
{
    return penguin_list[chosen];
}

/*
* Function name: print_peng_info()
* Purpose: Prints information of each animal in the list
* Arguments: none
* Returns: none
*/
void Zoo::print_peng_info()
{
    int j = 1;
    for(int i = 0; i < num_penguins; i++)
    {
        cout << "\nPenguin " << j++ << endl;
        cout << "\tage: " << penguin_list[i].get_age() << endl;
        cout << "\tfood cost: $" << penguin_list[i].get_base_food_cost() << endl;
        cout << "\tcost: $" << penguin_list[i].get_cost() << endl;
        cout << "\tpotential babies: " << penguin_list[i].get_num_babies() << endl;
        cout << "\tpayoff: $" << penguin_list[i].get_payoff() << endl;
    }
}

/*
* Function name: penguin_temp()
* Purpose: Makes temporary list for that certain animal type
* Arguments: integer, and Penguin object
* Returns: none
*/
void Zoo::penguin_temp(int animal_place, Penguin *temp_list)
{
    for(int i = 0; i < animal_place; i++)   //assigns animals from old into temp array
    {
        temp_list[i] = penguin_list[i];
    }
}

/*
* Function name: assign_penguin_data()
* Purpose: Assigns data to each animal in their list
* Arguments: Penguin array
* Returns: none
*/
void Zoo::assign_penguin_data(Penguin* temp_list)
{
    for(int i = 0; i < num_penguins; i++)   //reloads old data, except for removed, back into original array
    {
        penguin_list[i].set_age(temp_list[i].get_age());
        penguin_list[i].set_base_food_cost(temp_list[i].get_base_food_cost());
        penguin_list[i].set_cost(temp_list[i].get_cost());
        penguin_list[i].set_num_babies(temp_list[i].get_num_babies());
        penguin_list[i].set_payoff(temp_list[i].get_payoff());
    }
}

/*
* Function name: increase_tiger_age()
* Purpose: Increase each animal's age by 1
* Arguments: none
* Returns: none
*/
void Zoo::increase_tiger_age()
{
    int j = 0;
    for(int i = 0; i < num_tigers; i++)
    {
        j++;
        tiger_list[i].set_age(j);
    }
}

/*
* Function name: chosen_tiger()
* Purpose: Chooses an animal in the list to be returned
* Arguments: integer
* Returns: Tiger object
*/
Tiger Zoo::chosen_tiger(int chosen)
{
    return tiger_list[chosen];
}

/*
* Function name: remove_tiger
* Purpose: Removes a certain animal from their list
* Arguments: integer
* Returns: none
*/
void Zoo::remove_tiger(int animal_place)
{
    Tiger *temp_list = new Tiger[num_tigers];  //dynamic temp array
    tiger_temp(animal_place, temp_list);

    for(int i = animal_place + 1; i < num_tigers; i++)  //assigns tigers, after removed tiger, from old to temp array
    {
        temp_list[i-1] = tiger_list[i];  //temp_array continues from the skipped index of the original array
    }

    num_tigers--;
    
    delete [] tiger_list; //deletes array to delete the removed tiger
    tiger_list = new Tiger[num_tigers];   //make new array with less tigers

    assign_tiger_data(temp_list);

    delete [] temp_list;   //deletes temp array since it's not needed anymore
}

/*
* Function name: add_tiger()
* Purpose: Adds an animal to their species' list
* Arguments: none
* Returns: none
*/
void Zoo::add_tiger()
{
    Tiger* temp_list = new Tiger[num_tigers];
    tiger_temp(num_tigers, temp_list);

    delete [] tiger_list; //deletes array to add new tiger

    tiger_list = new Tiger[num_tigers];

    for(int i = 0; i < num_tigers - 2; i++)   //reloads old data, except for removed, back into original array
    {
        tiger_list[i].set_age(temp_list[i].get_age());
        tiger_list[i].set_base_food_cost(temp_list[i].get_base_food_cost());
        tiger_list[i].set_cost(temp_list[i].get_cost());
        tiger_list[i].set_num_babies(temp_list[i].get_num_babies());
        tiger_list[i].set_payoff(temp_list[i].get_payoff());
    }
    delete [] temp_list;
}

/*
* Function name: add_tiger_baby()
* Purpose: Add baby animals to their list increasing the array
* Arguments: none
* Returns: none
*/
void Zoo::add_tiger_baby()
{
    num_tigers = num_tigers + tiger_list[0].get_num_babies();
    Tiger* temp_list = new Tiger[num_tigers];
    tiger_temp(num_tigers, temp_list);

    delete [] tiger_list; //deletes array to add new tiger
    tiger_list = new Tiger[num_tigers];

    for(int i = 0; i < num_tigers - 3; i++)   //reloads old data, except for removed, back into original array
    {
        tiger_list[i].set_age(temp_list[i].get_age());
        tiger_list[i].set_base_food_cost(temp_list[i].get_base_food_cost());
        tiger_list[i].set_cost(temp_list[i].get_cost());
        tiger_list[i].set_num_babies(temp_list[i].get_num_babies());
        tiger_list[i].set_payoff(temp_list[i].get_payoff());
    }
    delete [] temp_list;
}

/*
* Function name: print_tiger_info()
* Purpose: Prints information of each animal in the list
* Arguments: none
* Returns: none
*/
void Zoo::print_tiger_info()
{
    int j = 1;
    for(int i = 0; i < num_tigers; i++)
    {
        cout << "\nTiger " << j++ << endl;
        cout << "\tage: " << tiger_list[i].get_age() << endl;
        cout << "\tfood cost: $" << tiger_list[i].get_base_food_cost() << endl;
        cout << "\tcost: $" << tiger_list[i].get_cost() << endl;
        cout << "\tpotential babies: " << tiger_list[i].get_num_babies() << endl;
        cout << "\tpayoff: $" << tiger_list[i].get_payoff() << endl;
    }  
}

/*
* Function name: tiger_temp()
* Purpose: Makes temporary list for that certain animal type
* Arguments: integer, Tiger object
* Returns: none
*/
void Zoo::tiger_temp(int animal_place, Tiger *temp_list)
{
    for(int i = 0; i < animal_place; i++)   //assigns animals from old into temp array
    {
        temp_list[i] = tiger_list[i];
    }
}

/*
* Function name: assign_tiger_data()
* Purpose: Assigns data to each animal in their list
* Arguments: Tiger array
* Returns: none
*/
void Zoo::assign_tiger_data(Tiger* temp_list)
{
    for(int i = 0; i < num_tigers; i++)   //reloads old data, except for removed, back into original array
    {
        tiger_list[i].set_age(temp_list[i].get_age());
        tiger_list[i].set_base_food_cost(temp_list[i].get_base_food_cost());
        tiger_list[i].set_cost(temp_list[i].get_cost());
        tiger_list[i].set_num_babies(temp_list[i].get_num_babies());
        tiger_list[i].set_payoff(temp_list[i].get_payoff());
    }
}

/*
* Function name: increase_turtle_age()
* Purpose: Increase each animal's age by 1
* Arguments: none
* Returns: none
*/
void Zoo::increase_turtle_age()
{
    int j = 0;
    for(int i = 0; i < num_turtles; i++)
    {
        j++;
        turtle_list[i].set_age(j);
    }
}

/*
* Function name: chosen_turtle()
* Purpose: Chooses an animal in the list to be returned
* Arguments: inreger
* Returns: Turtle object
*/
Turtle Zoo::chosen_turtle(int chosen)
{
    return turtle_list[chosen];
}

/*
* Function name: remove_turtle()
* Purpose: Removes a certain animal from their list
* Arguments: integer
* Returns: none
*/
void Zoo::remove_turtle(int animal_place)
{
    Turtle *temp_list = new Turtle[num_turtles];  //dynamic temp array
    turtle_temp(animal_place, temp_list);

    for(int i = animal_place + 1; i < num_turtles; i++)  //assigns turtle, after removed turtle, from old to temp array
    {
        temp_list[i-1] = turtle_list[i];  //temp_array continues from the skipped index of the original array
    }

    num_turtles--;

    delete [] turtle_list; //deletes array to delete the removed turtle
    turtle_list = new Turtle[num_turtles];   //make new array with less turtles

    assign_turtle_data(temp_list);

    delete [] temp_list;   //deletes temp array since it's not needed anymore
}

/*
* Function name: add_turtle()
* Purpose: Adds an animal to their species' list
* Arguments: none
* Returns: none
*/
void Zoo::add_turtle()
{
    Turtle* temp_list = new Turtle[num_turtles];
    turtle_temp(num_turtles, temp_list);

    delete [] turtle_list; //deletes array to add new turtle

    turtle_list = new Turtle[num_turtles];

    for(int i = 0; i < num_turtles - 2; i++)   //reloads old data, except for removed, back into original array
    {
        turtle_list[i].set_age(temp_list[i].get_age());
        turtle_list[i].set_base_food_cost(temp_list[i].get_base_food_cost());
        turtle_list[i].set_cost(temp_list[i].get_cost());
        turtle_list[i].set_num_babies(temp_list[i].get_num_babies());
        turtle_list[i].set_payoff(temp_list[i].get_payoff());
    }
    delete [] temp_list;
}

/*
* Function name: add_turtle_baby()
* Purpose: Add baby animals to their list increasing the array
* Arguments: none
* Returns: none
*/
void Zoo::add_turtle_baby()
{
    num_turtles = num_turtles + turtle_list[0].get_num_babies();
    Turtle* temp_list = new Turtle[num_turtles];
    turtle_temp(num_turtles, temp_list);

    delete [] turtle_list; //deletes array to add new turtle
    turtle_list = new Turtle[num_turtles];

    for(int i = 0; i < num_turtles - 3; i++)   //reloads old data, except for removed, back into original array
    {
        turtle_list[i].set_age(temp_list[i].get_age());
        turtle_list[i].set_base_food_cost(temp_list[i].get_base_food_cost());
        turtle_list[i].set_cost(temp_list[i].get_cost());
        turtle_list[i].set_num_babies(temp_list[i].get_num_babies());
        turtle_list[i].set_payoff(temp_list[i].get_payoff());
    }
    delete [] temp_list;    
}

/*
* Function name: print_turtle_info()
* Purpose: Prints information of each animal in the list
* Arguments: none
* Returns: none
*/
void Zoo::print_turtle_info()
{
    int j = 1;
    for(int i = 0; i < num_turtles; i++)
    {
        cout << "\nTurtle " << j++ << endl;
        cout << "\tage: " << turtle_list[i].get_age() << endl;
        cout << "\tfood cost: $" << turtle_list[i].get_base_food_cost() << endl;
        cout << "\tcost: $" << turtle_list[i].get_cost() << endl;
        cout << "\tpotential babies: " << turtle_list[i].get_num_babies() << endl;
        cout << "\tpayoff: $" << turtle_list[i].get_payoff() << endl;
    }
}

/*
* Function name: turtle_temp()
* Purpose: Makes temporary list for that certain animal type
* Arguments: integer, turtle object
* Returns: none
*/
void Zoo::turtle_temp(int animal_place, Turtle *temp_list)
{
    for(int i = 0; i < animal_place; i++)   //assigns animals from old into temp array
    {
        temp_list[i] = turtle_list[i];
    }
}

/*
* Function name: assign_turtle_data()
* Purpose: Assigns data to each animal in their list
* Arguments: Turtle array
* Returns: none
*/
void Zoo::assign_turtle_data(Turtle* temp_list)
{
    for(int i = 0; i < num_turtles; i++)   //reloads old data, except for removed, back into original array
    {
        turtle_list[i].set_age(temp_list[i].get_age());
        turtle_list[i].set_base_food_cost(temp_list[i].get_base_food_cost());
        turtle_list[i].set_cost(temp_list[i].get_cost());
        turtle_list[i].set_num_babies(temp_list[i].get_num_babies());
        turtle_list[i].set_payoff(temp_list[i].get_payoff());
    }
}

/*
* Function name: random_events()
* Purpose: To randomly select an event
* Arguments: referenced integer
* Returns: none
*/
void Zoo::random_events(int &bonus_payoff)   //1) sickness in zoo, 2) boom in attendance, 3) baby is born, 4) nothing happens
{
    srand(time(NULL));

    enum Event {SICKNESS = 1, BOOM, BABY, NOTHING};
    Event e = static_cast<Event>(rand() % NOTHING + SICKNESS);

    switch(e)
    {
        case SICKNESS:
            sickness();
            break;

        case BOOM:
            boom(bonus_payoff);
            break;

        case BABY:
            baby_born();
            break;

        case NOTHING:
            cout << "\nNothing happened today." << endl;
            break;

        default:
            break;
    }
}

/*
* Function name: sickness()
* Purpose: An event that removes a specific animal from their list
* Arguments: none
* Returns: none
*/
void Zoo::sickness()
{
    srand(time(NULL));

    int animal_place = 0;
    enum Type {PENGUIN = 1, TIGER, TURTLE}; //indicates which type of animal is being used: 1, 2, 3
    Type t = static_cast<Type>(rand() % TURTLE + PENGUIN);

    cout << "\nOh no! A sickness infested the zoo, and killed one of your animals!" << endl;
    
    if(t == PENGUIN && num_penguins > 0)
    {
        cout << "A penguin was lost." << endl;
        animal_place = rand() % get_num_penguins();
        remove_penguin(animal_place);
    }

    else if(t ==  TIGER && num_tigers > 0)
    {
        cout << "A tiger was lost." << endl;
        animal_place = rand() % get_num_tigers();
        remove_tiger(animal_place);
    }

    else if (t == TURTLE && num_turtles > 0)
    {   cout << "A turtle was lost." << endl;
        animal_place = rand() % get_num_turtles();
        remove_turtle(animal_place);
    }

    else
    {
        cout << "Everyone survived." << endl;
    }
    
}

/*
* Function name: boom()
* Purpose: Increases payoff of tigers to a randomly generated number
* Arguments: referenced integer
* Returns: none
* Based on: How to Generate Random Number Between Two Variables
*           //https://stackoverflow.com/questions/12657962/how-do-i-generate-a-random-number-between-two-variables-that-i-have-stored
*/
void Zoo::boom(int &bonus_payoff)
{
    srand(time(NULL));
    int bonus = 0;

    cout << "\nWow! Today's attendance skyrocketed!" << endl;

    for(int i = 0; i < num_tigers; i++)
    {
        bonus = rand() % (500 - 250 + 1) + 250; //generates between $250 - $500
        tiger_list[i].set_payoff(tiger_list[i].get_payoff() + bonus);

        bonus_payoff += tiger_list[i].get_payoff();
    }

    cout << "Tigers' total payoff with bonus is $" << bonus_payoff << endl;
}

/*
* Function name: baby_born()
* Purpose: Adds more animals into their list, amount depends on the species of animal
* Arguments: none
* Returns: none
*/
void Zoo::baby_born()
{
    srand(time(NULL));

    int chosen = 0;
    enum Type {PENGUIN = 1, TIGER, TURTLE}; //indicates which type of animal is being used: 1, 2, 3
    Type t = static_cast<Type>(rand() % TURTLE + PENGUIN);

    if(t == PENGUIN)
    {
        chosen = rand() % num_penguins;
        if(chosen_penguin(chosen).get_age() >= 3)
        {
            add_peng_baby();
            cout << "\nA penguin gave birth!" << endl;
        }

        else
        {
            t = static_cast<Type>(rand() % TURTLE + PENGUIN);   //generates different outcome
            cout << "\nThe penguins were too young to give birth." << endl;
        }
        
    }

    else if(t == TIGER)
    {
        chosen = rand() % num_tigers;
        if(chosen_tiger(chosen).get_age() >= 3)
        {
            add_tiger_baby();
            cout << "\nA tiger gave birth!" << endl;
        }

        else
        {
            t = static_cast<Type>(rand() % TURTLE + PENGUIN);
            cout << "\nThe tigers were too young to give birth." << endl;
        }
        
    }

    else if(t == TURTLE)
    {
        chosen = rand() % num_turtles;
        if(chosen_turtle(chosen).get_age() >= 3)
        {
            add_turtle_baby();
            cout << "\nA turtle gave birth!" << endl;
        }

        else
        {
            t = static_cast<Type>(rand() % TURTLE + PENGUIN);
            cout << "\nThe turtles were too young to give birth." << endl;
        }
    }

    else if (chosen_penguin(num_penguins - 1).get_age() < 3 && chosen_tiger(num_tigers - 1).get_age() < 3 && chosen_turtle(num_turtles - 1).get_age() < 3)
    {
        cout << "\nAll the animals were too young to give birth." << endl;
        return;
    }
}

/*
* Function name: total_cost()
* Purpose: Calculates and prints total cost for all animals
* Arguments: referenced Penguin object, Tiger object, and Turtle object
* Returns: none
*/
void Zoo::total_cost(Penguin &p, Tiger &t, Turtle &tt)
{
    double total_penguins_cost = p.get_cost() * num_penguins;
    double total_tigers_cost = t.get_cost() * num_tigers;
    double total_turtles_cost = tt.get_cost() * num_turtles;

    double total_cost = total_penguins_cost + total_tigers_cost + total_turtles_cost;

    cout << "\nTotal costs of bought animals: $" << total_cost << endl;
}

/*
* Function name: total_feeding_cost()
* Purpose: Calculates and prints out total feeding cost of each animal
* Arguments: referenced Penguin object, Tiger object, and Turtle object
* Returns: none
*/
void Zoo::total_feeding_cost(Penguin &p, Tiger &t, Turtle &tt)
{
    cout << "\nFeed Cost for All Animals" << endl;

    double total_penguin_feeding_cost = num_penguins * p.get_base_food_cost();
    cout << "\tPenguins' total feeding cost: $" << total_penguin_feeding_cost << endl;

    double total_tiger_feeding_cost = num_tigers * t.get_base_food_cost();
    cout << "\tTigers' total feeding cost: $" << total_tiger_feeding_cost << endl;

    double total_turtle_feeding_cost = num_turtles * tt.get_base_food_cost();
    cout << "\tTurtles' total feeding cost: $" << total_turtle_feeding_cost << endl;

    double total_cost = total_penguin_feeding_cost + total_tiger_feeding_cost + total_turtle_feeding_cost;
    cout << "\n\tTotal feeding cost overall: $" << total_cost << endl;

    bank -= total_cost; //subtracts cost from bank
}

/*
* Function name: total_payoff()
* Purpose: Calculates and prints the total payoff of each animal
* Arguments: referenced Penguin object, Tiger object, Turtle object, and integer
* Returns: none
*/
void Zoo::total_payoff(Penguin &p, Tiger &t, Turtle &tt, int &bonus_payoff)
{
    cout << "\nPayoff for All Animals" << endl;

    double total_payoff = 0;

    double total_penguin_payoff = p.get_payoff() * num_penguins;
    cout << "\tPenguins' total payoff: $" << total_penguin_payoff << endl;
    total_payoff += total_penguin_payoff;
    
    double total_turtle_payoff = tt.get_payoff() * num_turtles;
    cout << "\tTurtles' total payoff: $" << total_turtle_payoff << endl;
    total_payoff += total_turtle_payoff;

    if(bonus_payoff > 0)    //special case for tigers
    {
        total_payoff += bonus_payoff;
        cout << "\tTigers' total payoff with bonus: $" << bonus_payoff << endl;
    }   

    else 
    {
        double total_tiger_payoff = t.get_payoff() * num_tigers;
        cout << "\tTigers' total payoff: $" << total_tiger_payoff << endl;
        total_payoff += total_tiger_payoff;
    }

    bank += total_payoff;
    cout << "\n\tAnimals total payoff: $" << total_payoff << endl;
}