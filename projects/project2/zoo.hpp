/*
* File name: zoo.hpp
* Purpose: This holds the prototypes for zoo.cpp
*/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "penguin.hpp"
#include "tiger.hpp"
#include "turtle.hpp"

#include <iostream>
using namespace std;

#include <ctime>
#include <cstdlib>

class Zoo
{
    private:
        double bank;    //holds money, starts with $100,000
        int days;
        bool bankruptcy;    //true if bank == 0, false if bank > 0

        int starting_capacity;   //10, will later be doubled if needed

        Penguin* penguin_list;  //starts of 10
        int num_penguins;   

        Tiger* tiger_list;      //starts of 10
        int num_tigers;     

        Turtle* turtle_list;    //starts of 10
        int num_turtles;    

    public:
        Zoo();
        ~Zoo();

        int get_starting_capacity();
        void set_starting_capacity(int starting_capacity);  //will be used to increase size

        double get_bank();
        void set_bank(double bank);     //sets available money of player

        int get_days();
        void set_days(int days);        //will be used to increment by 1 day each turn

        bool get_bankruptcy();
        void set_bankruptcy(bool bankruptcy);          //will be used to for when bank hits 0 or less

        int get_num_penguins();
        void set_num_penguins(int num_penguins);

        int get_num_tigers();
        void set_num_tigers(int num_tigers);

        int get_num_turtles();
        void set_num_turtles(int num_turtles);

        //Penguin, add and remove penquins
        void remove_penguin(int animal_place);
        void add_penguin();
        void penguin_temp(int animal_place, Penguin *temp_list);
        void assign_penguin_data(Penguin* temp_list);
        void print_peng_info();
        void increase_peng_age();
        void add_peng_baby();
        Penguin chosen_penguin(int chosen);

        //Tiger, add and remove tigers
        void remove_tiger(int animal_place);
        void add_tiger();
        void tiger_temp(int animal_place, Tiger *temp_list);
        void assign_tiger_data(Tiger* temp_list);
        void print_tiger_info();
        void increase_tiger_age();
        void add_tiger_baby();
        Tiger chosen_tiger(int chosen);

        //Turtle, add and remove turtles
        void remove_turtle(int animal_place);
        void add_turtle();
        void turtle_temp(int animal_place, Turtle *temp_list);
        void assign_turtle_data(Turtle* temp_list);
        void print_turtle_info();
        void increase_turtle_age();
        void add_turtle_baby();
        Turtle chosen_turtle(int chosen);

        //random functions
        void random_events(int &bonus_payoff);   //1) sickness in zoo, 2) boom in attendance, 3) baby is born
        void sickness();
        void boom(int &bonus_payoff);
        void baby_born();

        //overall functions
        void total_cost(Penguin &p, Tiger &t, Turtle &tt);
        void total_feeding_cost(Penguin &p, Tiger &t, Turtle &tt);
        void total_payoff(Penguin &p, Tiger &t, Turtle &tt, int &bonus_payoff);
};
#endif