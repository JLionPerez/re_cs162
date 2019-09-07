/*
* File name: menu.cpp
* Purpose: Holds definitions for prototypes in menu.hpp.
*/
#include "menu.hpp"

/*
* Function Name: start_menu()
* Purpose: Recieves input for starting options and validates those options from user.
* Arguments: takes an integer
* Returns: integer
*/
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

/*
* Function Name: menu()
* Purpose: Second menu, recieves dimensions for board and validates them.
* Arguments: takes in a double 2D array, and integers for width and length of board
* Returns: none
*/
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

        if (validation(width, length))
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

/*
* Function Name: end_menu()
* Purpose: Last menu, asks the user if they want to play again or wuit.
* Arguments: takes in a double 2D array, and integer option
* Returns: integer
*/
int end_menu(int** &board, int &option)
{
    char buffer[100];
    do
    {    
        cout << "\nWould you like to:" << endl;   
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

/*
* Function Name: validation()
* Purpose: Validates dimensions for board.
* Arguments: integers width and length
* Returns: bool true or false
*/
bool validation(int width, int length)
{
    if (width > 0 && length > 0)
    {
        if(width < 101 && length < 101)
            return true;    //is valid
        else
        {
            cout << "\nThose dimensions are too high, the max is 100." << endl;
        }
    }

    else
    {
        cout << "\nThose dimensions are too low, the minimum is 0." << endl;
    }

    return false;   //not valid
}

/*
* Function Name: validate_int()
* Purpose: To validate integers until user types in right input.
* Arguments: constant char string, and integers for minimum and maximum values
* Returns: integer input
*   Credits to: T.A. Khuong Cam Luu
*/
int validate_int(const char* str, int min, int max)
{
    int input;
    cout << str;
    cin >> input;
    while(cin.fail() || input < min || input > max-1 )
    {
        cout << "Please enter integers greater than " << min << " and less than " <<  max-1 << " only." << endl;
        cout << str;
        cin >> input;
        cin.clear();    //clears input
        cin.ignore(9999, '\n');
    }
    return input;
}

/*
* Function Name: ant_info()
* Purpose: Takes input for ant's coordinates and steps and set's them in the class.
* Arguments: takes in a double 2D array, and integers width and length
* Returns: none
*/
void ant_info(int** board, Ant &a, int width, int length) 
{
    int steps, x, y, max_steps = width*length, min = 0;
    const char* steps_str = "Steps: ";
    const char* row_str = "Row: ";
    const char* col_str = "Column: ";

    cout << "\nCoordinates start at (0,0)." << endl;
    cout << "Now please enter the ant's total steps and coordinates." << endl;
    steps = validate_int(steps_str, min, max_steps);
    x = validate_int(row_str, min, width);
    y = validate_int(col_str, min, length);

    a.set_steps(steps);
    a.set_x(x);
    a.set_y(y);
}

/*
* Function Name: allocate_board()
* Purpose: Allocates memory on the heap for 2D array.
* Arguments: takes in a double 2D array, and integers width and length
* Returns: none
*/
void allocate_board(int** &board, int width, int length)
{
    //allocate memory space for board
    board = new int*[width];
    for(int i = 0; i < width; i++)
    {
        board[i] = new int[length];     //allocate mem space
    }
}

/*
* Function Name: initial_board()
* Purpose: Fills board with 0s.
* Arguments: takes in a double 2D array, and integers width and length
* Returns: none
*/
void initial_board(int** &board, int width, int length)
{
    //initialize with zeroes
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < length; y++)
        {
            board[x][y] = 0;    //fill with 0s
        }
    }
}

/*
* Function Name: cover_board()
* Purpose: Replaces integers on board with characters.
* Arguments: takes in a double 2D array, and integers width and length, and class Ant object
* Returns: none
*/
void cover_board(int** board, int width, int length, Ant a)
{
    int white = 0, black = 1;

    cout << " ";
    for(int x = 0; x < width; x++)      //top border
    {
        cout << "-";
    }
    cout << "\n";

    for(int y = 0; y < length; y++)     //insides of board
    {
        cout << "|";                    //plus right wall
        for(int x = 0; x < width; x++)
        {
            if(y == a.get_y() && x == a.get_x())    //for ant sprite
            {
                cout << '*';
            }

            else
            {
                if(board[x][y] == white)            //sprite for white block
                {
                    cout << ' ';
                }
                else if(board[x][y] == black)       //sprite for black block
                {
                    cout << '#';
                }
            }
        }
        cout << "|";                    //left border
        cout << endl;
    }

    cout << " ";
    for(int x = 0; x < width; x++)      //bottom border
    {
        cout << "-";
    }
    cout << "\n";
}

/*
* Function Name: delete_board()
* Purpose: Deletes memory on heap.
* Arguments: takes in a double 2D array, and integers width and length
* Returns: none
*/
void delete_board(int** board, int width, int length)
{

    for(int i = 0; i < width; i++)
    {
        delete [] board[i];
    }
    delete [] board;
}