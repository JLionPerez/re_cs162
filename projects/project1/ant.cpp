#include "ant.hpp"
#include "menu.hpp"

int Ant::get_x()    //accessor
{
    return ant_x;
}

void Ant::set_x(int ant_x)   //mutator
{
    this->ant_x = ant_x;
}

int Ant::get_y()    //accessor
{
    return ant_y;
}

void Ant::set_y(int ant_y)  //mutator
{
    this->ant_y = ant_y;
}

int Ant::get_steps()    //accessor
{
    return steps;
}

void Ant::set_steps(int steps)  //mutator
{
    this->steps = steps;
}

int Ant::get_direction()
{
    return direction;
}

void Ant::set_direction(int direction)
{
    this->direction = direction;
}

int Ant::get_color_temp()
{
    return color_temp;
}

void Ant::set_color_temp(int color_temp)
{
    this->color_temp = color_temp;
}

int Ant::get_past_x()
{
    return past_ant_x;
}

void Ant::set_past_x(int past_ant_x)
{
    this->past_ant_x = past_ant_x;
}

int Ant::get_past_y()
{
    return past_ant_y;
}

void Ant::set_past_y(int past_ant_y)
{
    this->past_ant_y = past_ant_y;
}


int Ant::turn_left()
{
    int north = 1, east = 2 , south = 3, west = 4;

    if(get_direction() == north)
    {
        set_direction(west);
    }

    else if(get_direction() == east)
    {
        set_direction(north);
    }

    else if(get_direction() == south)
    {
        set_direction(east);
    }

    else if(get_direction() == west)
    {
        set_direction(south);
    }
}

int Ant::turn_right()
{
    int north = 1, east = 2 , south = 3, west = 4;

    if(get_direction() == north)
    {
        set_direction(east);
    }

    else if(get_direction() == east)
    {
        set_direction(south);
    }

    else if(get_direction() == south)
    {
        set_direction(west);
    }

    else if(get_direction() == west)
    {
        set_direction(north);
    }
}

void Ant::ant_turn(int** &board)
{
    int black = 1;

    if(board[ant_x][ant_y] == black)
    {
        turn_left();
    }

    else
    {
        turn_right();
    }
}

void Ant::ant_move(int** &board, int width, int length)
{
    //int north = 1, east = 2, south = 3, west = 4, x = get_x(), y = get_y(), ant = 2;
    //get_future_pos(board, ant_x, ant_y);    //makes ant move
    //out_of_bound(board); // here
    //board[ant_x][ant_y] ^= 1;   //xor switches color of board
    //get_future_pos(board, ant_x, ant_y);    //makes ant move

    board[ant_x][ant_y] ^= 1;   //xor switches color of board
    get_future_pos(board, ant_x, ant_y);    //makes ant move
    out_of_bound(board, width, length);
    ant_turn(board);

    /*if(ant_x < 0 || ant_y < 0)
    {
        ant_turn(board);
    }
    else
    {
        board[ant_x][ant_y] ^= 1;   //xor switches color of board
        out_of_bound(board, width, length);
        get_future_pos(board, ant_x, ant_y);    //makes ant move
    }*/
    //ant_turn(board);
        //new_x = (ant_x++) % 
        //set_x(new_x);
    
    //ant_turn(board);
    //ant_turn(board);

}

int Ant::get_future_pos(int** &board, int &future_x, int &future_y)
{
    int north = 1, east = 2, south = 3, west = 4;

    if(get_direction() == north)
    {
        future_y -= 1;      //decrease x so it's on the block in front of ant
    }

    if(get_direction() == east)
    {
        future_x += 1;      //increase y so it's on the block in front of ant
    }

    if(get_direction() == south)
    {
        future_y += 1;      //increase x so it's on the block in front of ant
    }

    if(get_direction() == west)
    {
        future_x -= 1;      //decrease y so it's on the block in front of ant
    }
}

void Ant::out_of_bound(int** &board, int width, int length)
{

    if(ant_x == width)
    {
        ant_x = (ant_x) % width;  //new x coordinate
    }

    else if(ant_x == -1)
    {
        ant_x = abs(((ant_x + 2) % length) - 1);
    }

    else if(ant_y == length)
    {
        ant_y = (ant_y) % length; //new y coordinated
    }

    else if(ant_y == -1)
    {
        ant_y = abs(((ant_y + 2) % length) - 1);
    }
}

/*void Ant::color_switch(int** &board)
{
    int white = 0, black = 1, ant = 2, past_x = get_past_x(), past_y = get_past_y();

    if(get_color_temp() == white)
    {
        board[past_x][past_y] = black;
    }

    if(get_color_temp() == black)
    {
        board[past_x][past_y] = black;
    }

    //if()get_color

}*/

Ant::Ant()  //default constructor
{
    set_steps(0);
    set_x(0);
    set_y(0);
    set_direction(2);   //ant faces east (fixed)
    set_color_temp(0);  //white is the first color ant sits on
}