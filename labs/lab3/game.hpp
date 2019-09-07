/*
* File name: game.hpp
* Purpose: Holds prototypes for definitions in game.cpp.
*/
#ifndef GAME_HPP
#define GAME_HPP
#include "die.hpp"
#include "loaded_die.hpp"

class Game
{
    private:
        int option;
        int rounds;
        int norm_sides;     //for normal die
        int load_sides;     //for loaded die
        int add_score;      //increments by one
        Die *player1;
        int player1_norm_load;  //1 means normal 2 means loaded
        Die *player2;
        int player2_norm_load;  //1 means normal 2 means loaded
        int player_num;
    
    public:
        int start_menu();
        void main_menu();

        void type_die(Die* player);
        void total_sides(Die* player);
        void create_die(int hold, Die *player);
        int compare_rolls(Die *player1, Die *player2);

        void delete_objs();
};

#endif