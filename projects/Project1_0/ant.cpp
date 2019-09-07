/*
* File name: ant.cpp
* Purpose: Holds definitions for prototypes in ant.hpp.
*/
#include "ant.hpp"
#include "menu.hpp"

/*
* Function Name: get_x()
* Purpose: Accesses member function in class Ant.
* Arguments: none
* Returns: Ant member
*/
int Ant::get_x()
{
    return ant_x;
}

/*
* Function Name: set_x()
* Purpose: Mutate member variable by passed value.
* Arguments: integer
* Returns: none
*/
void Ant::set_x(int ant_x)
{
    this->ant_x = ant_x;
}

/*
* Function Name: get_y()
* Purpose: Accesses member function in class Ant.
* Arguments: none
* Returns: Ant member
*/
int Ant::get_y()
{
    return ant_y;
}

/*
* Function Name: set_y()
* Purpose: Mutate member variable by passed value.
* Arguments: integer
* Returns: none
*/
void Ant::set_y(int ant_y)  //mutator
{
    this->ant_y = ant_y;
}

/*
* Function Name: get_steps()
* Purpose: Accesses member function in class Ant.
* Arguments: none
* Returns: Ant member
*/
int Ant::get_steps()
{
    return steps;
}

/*
* Function Name: set_steps()
* Purpose: Mutate member variable by passed value.
* Arguments: integer
* Returns: none
*/
void Ant::set_steps(int steps)  //mutator
{
    this->steps = steps;
}

/*
* Function Name: get_direction()
* Purpose: Accesses member function in class Ant.
* Arguments: none
* Returns: Ant member
*/
int Ant::get_direction()
{
    return direction;
}

/*
* Function Name: set_direction()
* Purpose: Mutate member variable by passed value.
* Arguments: integer
* Returns: none
*/
void Ant::set_direction(int direction)
{
    this->direction = direction;
}

/*
* Function Name: get_color_temp()
* Purpose: Accesses member function in class Ant.
* Arguments: none
* Returns: Ant member
*/
int Ant::get_color_temp()
{
    return color_temp;
}

/*
* Function Name: set_color_temp()
* Purpose: Mutate member variable by passed value.
* Arguments: integer
* Returns: none
*/
void Ant::set_color_temp(int color_temp)
{
    this->color_temp = color_temp;
}

/*
* Function Name: turn_left()
* Purpose: Set's the direction of the ant 90 degrees to the left.
* Arguments: none
* Returns: none
*/
void Ant::turn_left()
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

/*
* Function Name: turn_right()
* Purpose: Set's the direction of the ant 90 degrees to the right.
* Arguments: none
* Returns: none
*/
void Ant::turn_right()
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

/*
* Function Name: ant_turn()
* Purpose: Turns the ant either left or right depending on the color of the square the ant is on.
* Arguments: integer double array board
* Returns: none
*/
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

/*
* Function Name: out_of_bound()
* Purpose: Wraps the board and prevents the ant from going out of bounds.
* Arguments: integer double array board, and integers width and length
* Returns: none
*/
void Ant::out_of_bound(int** &board, int width, int length)
{
    int min_bound = 0;

    if(ant_x >= width)
    {
        ant_x = (ant_x) % width;
    }

    else if(ant_x <= 0)
    {
        ant_x = width-1;    //warp on the left or rigth side of board
    }

    if(ant_y >= length)
    {
        ant_y = (ant_y) % length;
    }

    else if(ant_y <= 0)
    {
        ant_y = length-1;   //warp on the bottom or top side of board
    }
}

/*
* Function Name: ant_move()
* Purpose: To move the ant, turn, and change the color of the board.
* Arguments: integer double array board, and integers width and length
* Returns: none
*/
void Ant::ant_move(int** &board, int width, int length)
{
    board[ant_x][ant_y] ^= 1;   //xor switches color of board
    out_of_bound(board, width, length);
    get_future_pos(board, ant_x, ant_y);
    out_of_bound(board, width, length);
    ant_turn(board);
}

/*
* Function Name: get_future_pos()
* Purpose: Move's the ant's position forward depending the direction it is facing.
* Arguments: integer double array board and integers of the x and y coordinates of ant
* Returns: none
*/
void Ant::get_future_pos(int** &board, int &future_x, int &future_y)
{
    const int NORTH = 1, EAST = 2, SOUTH = 3, WEST = 4;

    switch (get_direction()) {
        case NORTH:
            if (future_y <= 0) {    //if y is 0 or less skip this step
                return;
            }
            future_y--;
            return;
        case WEST:
            if (future_x <= 0) {    //if x is 0 or greater skip this step
                return;
            }
            future_x--;
            return;
        case EAST:
            future_x++;
            return;
        case SOUTH:
            future_y++;
            return;
        default:
            return;
    }
}

/*
* Function Name: Ant()
* Purpose: Sets default settings in the beginning of the program.
* Arguments: none
* Returns: none
*/
Ant::Ant()
{
    set_steps(0);
    set_x(0);
    set_y(0);
    set_direction(2);   //ant faces east (fixed)
    set_color_temp(0);  //white is the first color ant sits on
}