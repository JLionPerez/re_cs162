/* 
* File name: menu.hpp
* Purpose: Holds prototypes for menu.cpp
*/

#ifndef MENU_HPP
#define MENU_HPP

#include "containers.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Menu
{
    private:
        int option_player1;
        int option_player2;
        char buffer[100];

        int team_a_mates;
        int team_b_mates;

        int team_a_points;
        int team_b_points;

        int charas;
        int round;
        int turn;
        int play_again;
        int enter;

        enum c {BARBARIAN = 1, BLUEMEN, HARRY, MEDUSA, VAMPIRE};    //types

        //players
        Characters* player1;
        Characters* player2;

        string player_name;

        //queues
        Queue* team_a;
        Queue* team_b;
        Queue* loser_pile;

    public:
        Menu();

        bool validation(int option);
        void beginning();
        void end();

        void teams_chose();
        void team_a_chooses();
        void team_b_chooses();

        void tournament();  //tournament goes through each node and places 
        void gameplay();    //one on one battle
        void gameover();    //determines loser and winner of each battle, and adds points
        void winner();      //determines winning team
        void print_loser_pile();

        void player1_choices();
        void player2_choices();

        void player1_attack();
        void player1_defend();
        
        void player2_attack();
        void player2_defend();

};

#endif