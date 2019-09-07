/*
* Program Name: Project 1 - Langton's Ant Simulation
* Author: Joelle Perez
* Date: 20 January 2019
* Description: This program simulates an ant on a board which switches the blocks the ant is on to black or white, and recieves coordinates from the user.
* Cited Works:
*       How do I Make a Game Board: https://www.dreamincode.net/forums/topic/375555-how-do-i-make-a-game-board/
*       Validating Input: Credits to T.A. Khuong Cam Luu
*/

#include "menu.hpp"
#include "ant.hpp"

int main() {
    
    int** board, option, width, length, num = 1;
    Ant a;  //ant object

    do
    {
        start_menu(option);
        if(option != 2)
        {
            menu(board, width, length);
            ant_info(board, a, width, length);
            for(int i = 0; i < a.get_steps(); i++)
            {
                cout << " Slide " << num << endl;
                num++;

                cover_board(board, width, length, a);
                a.ant_move(board, width, length);
            }

            delete_board(board, width, length);
            num = 1;
            end_menu(board, option);    //asks user if they want to play again or not
        }

        else
        {
            return 0;
        }
    } while(option == 1);
}