#include "menu.hpp"
//#include "ant.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

/*#include <algorithm>
using std::copy;
using std::boolalpha;
using std::equal;*/

int start_menu(int &option)
{
    char buffer[100];
    do      //for invalid input
    {
        cout << "\nWelcome to Langton's Ant Simulation!" << endl;
        cout << "1. Start Langton's Ant Simulation" << endl;
        cout << "2. Quit" << endl;
        cout << "\nPlease select an option: ";
        cin >> buffer;

        option = atoi(buffer);

        if(option == 2)
        {
            cout << "Okay, goodbye." << endl;
            return 0;
        }

        else if(option == 0)
        {
            cout << "\nPlease enter a valid value." << endl;
        }
    } while(option != 1);
}

void menu(int** &board, int &width, int &length)
{
    char width_buffer[100], length_buffer[100];

    do
    {
        cout << "\nPlease enter the size of board below." << endl;
        cout << "Width: ";
        cin >> width_buffer;
        cout << "Length: ";
        cin >> length_buffer;

        width = atoi(width_buffer);     //how many rows
        length = atoi(length_buffer);   //how many columns

        if (validation(width, length) == true)
        {
            allocate_board(board, width, length);
            initial_board(board, width, length);
        }

        else
        {
            cout << "\nSorry I can not accept those integers. Please try again." << endl;
        }

    }while(width <= 0 || length <= 0 || width >= 101 || length >= 101);
}

int end_menu(int** &board, int &option)
{
    char buffer[100];
    do
    {    
        cout << "\nWould you like to:" << endl;   //end of program
        cout << "1) Play Again" << endl;
        cout << "2) Quit" << endl;
        cout << "\nPlease enter an option: ";
        cin >> buffer;

        option = atoi(buffer);

        if(option == 2)
        {
            cout << "Okay, goodbye." << endl;
            return 0;
        }

        else if(option != 1)
        {
            cout << "\nPlease enter a valid value." << endl;
        }

    } while (option != 1);
}

bool validation(int width, int length)
{
    if (width > 0 && length > 0)
    {
        if(width < 101 && length < 101)
            return true;    //is valid
    }

    return false;   //not valid
}

int validate_int(const char* str, int min, int max) //credits to TA
{
    int input;
    cout << str;
    cin >> input;   //user input
    while(cin.fail() || input < min || input > max )
    {
        cout << "Please enter integers greater than 0 and less than 1000 only." << endl;
        cout << str;
        cin >> input;
        cin.clear();
        cin.ignore(9999, '\n');
    }
    return input;
}

void ant_info(int** board, Ant &a, int width, int length)   //gets ant position (and steps needs validation)
{
    int steps, x, y, max = 1000, min = 0;
    const char* steps_str = "Steps: ";
    const char* row_str = "Row: ";
    const char* col_str = "Column: ";

    cout << "\nCoordinates start at (0,0)." << endl;
    cout << "Now please enter the ant's total steps and coordinates." << endl;
    steps = validate_int(steps_str, min, max);
    x = validate_int(row_str, min, max);
    y = validate_int(col_str, min, max);

    a.set_steps(steps);
    a.set_x(x);
    a.set_y(y);

    //board[x][y] = 2;

    a.set_past_x(x);    //saves initial coords as past coords
    a.set_past_y(y);    //
}

void allocate_board(int** &board, int width, int length)
{
    //allocate memory space for board
    board = new int*[width];
    for(int i = 0; i < width; i++)
    {
        board[i] = new int[length];
    }
}

void initial_board(int** &board, int width, int length)
{
    //initialize with zeroes
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < length; y++)
        {
            board[x][y] = 0;
        }
    }
}

/*void borders_board(int** board, int width, int length)  //https://stackoverflow.com/questions/20667960/how-do-i-make-a-square-in-c
{
    for(int y = 0; y < length; y++) //top wall
    {
        cout << "-";
    }
    cout << "\n";

    for(int x = 0; x < width; x++)  //left wall
    {
        cout << "|";

        for(int y = 0; y < length; y++)
        {
            cout << " ";    //empty spaces within boundaries
        }
        cout << "|\n";  //right wall
    }

    for(int y = 0; y < length; y++) //bottom wall
    {
        cout << "-";
    }
    cout << "\n";
}*/

void cover_board(int** board, int width, int length, Ant a)
{
    int white = 0, black = 1;

    cout << " ";
    for(int x = 0; x < width; x++)
    {
        cout << "-";
    }
    cout << "\n";

    for(int y = 0; y < length; y++)
    {
        cout << "|";
        for(int x = 0; x < width; x++)
        {
            if(y == a.get_y() && x == a.get_x())
            {
                cout << '*';
            }

            else
            {
                if(board[x][y] == white)
                {
                    cout << ' ';
                }
                else if(board[x][y] == black)
                {
                    cout << '#';
                }
            }

            //cout << "|" << e
        }
        cout << "|";
        cout << endl;
    }

    cout << " ";
    for(int x = 0; x < width; x++)
    {
        cout << "-";
    }
    cout << "\n";
}

void print_board(int** board, int width, int length, Ant a)
{
    //prints board
    for(int y = 0; y < length; y++)
    {
        for(int x = 0; x < width; x++)
        {
            cout << board[x][y] << " ";
        }
        cout << endl;
    }
}

void delete_board(int** board, int width, int length)
{
    //free allocated memory
    for(int i = 0; i < width; i++)
    {
        delete [] board[i];
    }
    delete [] board;
}