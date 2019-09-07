#ifndef ANT_HPP
#define ANT_HPP

#include <cmath>
using std::abs;

class Ant 
{
    private:
        int ant_x;      //location
        int ant_y;      //coordinates
        int steps;
        int direction;  //north = 1, east = 2, south = 3, west = 4

        int color_temp;     //saves initial and previous colors under ant
        int past_ant_x;     //saves previous spot of ant
        int past_ant_y;     //

    public:
        int get_x();    //accessor
        void set_x(int ant_x);   //mutator

        int get_y();
        void set_y(int ant_y);

        int get_steps();
        void set_steps(int steps);

        int get_direction();
        void set_direction(int direction);

        int get_color_temp();
        void set_color_temp(int color_temp);

        int get_past_x();
        void set_past_x(int past_ant_x);

        int get_past_y();
        void set_past_y(int past_ant_y);
 
        void ant_turn(int** &board);
        void ant_move(int** &board, int width, int length);
        void out_of_bound(int** &board, int width, int length);

        int turn_left();
        int turn_right();

        int get_future_pos(int** & board, int &future_x, int &future_y);
        //void color_switch(int** &board);
        
        Ant();  //default constructor
};

#endif