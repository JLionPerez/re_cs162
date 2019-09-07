#include "menu.hpp"
#include "ant.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

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
            cout << "Beginning coordinates x: " << a.get_x() << " y: " << a.get_y() << endl;
            //print_board(board, width, length);    //save for after the ant is placed
            //here lies the for loop for the steps to go through, animation time
            for(int i = 0; i < a.get_steps(); i++)
            {
                cout << " Slide " << num << endl;
                num++;

                cover_board(board, width, length, a);
                //print_board(board, width, length, a);    //save for after the ant is placed
                cout << "Past coordinates x: " << a.get_past_x() << " y: " << a.get_past_y() << endl;
                cout << "Ant facing " << a.get_direction() << endl;
                cout << "Past color " << a.get_color_temp() << endl;
                
                cout << "Future color " << a.get_color_temp() << endl;
                cout << "\n" << "Ant x: " << a.get_x() << " Ant y: " << a.get_y() << endl;
                a.ant_move(board, width, length);
                cout << "width: " << width << " length: " << length;
                //cout << "\n" << a.get_x() << " " << a.get_y();
                //a.color_switch(board);  //swtich color of board
                cout << "Current coordinates x: " << a.get_x() << " y: " << a.get_y() << endl;
                //cout << a.get_color_temp() << endl; //color of piece under ant
                cout << endl;
            }

            delete_board(board, width, length);
            end_menu(board, option);    //asks user if they want to play again or not
        }

        else
        {
            return 0;
        }
    } while(option == 1);
}