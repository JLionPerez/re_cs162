/*
* File name: ant.hpp
* Purpose: Holds the prototypes of definitions in ant.cpp.
*/
#ifndef ANT_HPP
#define ANT_HPP

class Ant 
{
    private:
        int ant_x;     
        int ant_y;     
        int steps;
        int direction;  //north = 1, east = 2, south = 3, west = 4
        int color_temp;

    public:
        int get_x(); 
        void set_x(int ant_x); 

        int get_y();
        void set_y(int ant_y);

        int get_steps();
        void set_steps(int steps);

        int get_direction();
        void set_direction(int direction);

        int get_color_temp();
        void set_color_temp(int color);

        void ant_move(int** &board, int width, int length);
        void get_future_pos(int** & board, int &future_x, int &future_y);
        
        void ant_turn(int** &board);
        void turn_left();
        void turn_right();

        void out_of_bound(int** &board, int width, int length);

        Ant();  //default constructor
};

#endif