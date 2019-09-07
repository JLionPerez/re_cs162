/*
* File name: animal.hpp
* Purpose: Holds prototypes for animal.cpp
*/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
    protected:
        int age;    //adult if >= 3 days, baby if < 3 days
        double cost;    //different costs for different animals
        int num_babies;     //each animal gives brith to different amount of babies
        double base_food_cost;   //each animal have different costs when feeding
        double payoff;  //profit of the animal

    public:
        int get_age();
        void set_age(int age);

        double get_cost();
        void set_cost(double cost);

        int get_num_babies();
        void set_num_babies(int num_babies);

        double get_base_food_cost();
        void set_base_food_cost(double base_food_cost);

        double get_payoff();
        void set_payoff(double payoff);
};

#endif
