/*
* File name: menu.cpp
* Description: Holds definitions for menu.cpp
*/

#include "menu.hpp"
#include "recursive.hpp"

/*
* Function name: start_up()
* Purpose: Start up menu for the user to pick an option
* Arguments: none
* Returns: none
*/
void Menu::start_up()
{
    char buffer[100];
    int answer = 0;

    do
    {
        cout << "\nSelect a function to run. (No spaces, please)" << endl;
        cout << "\t1) Reverse String" << endl;
        cout << "\t2) Calculate Sum of List" << endl;
        cout << "\t3) Calculate The Triangular of a Number" << endl;
        cout << "\t4) Quit" << endl;
        cout << "Option: ";
        cin >> buffer;
        option = atoi(buffer);

        if(option < 1 || option > 4)
        {
            cout << "Enter a valid option." << endl;
        }

        else if(option == 1)
        {
            cin.ignore();   //ignores previous newline
            rev_str_menu();
        }

        else if(option == 2)
        {
            cin.ignore();
            sum_menu();
        }

        else if(option == 3)
        {
            cin.ignore();
            tri_menu();
        }

        else if(option == 4)
        {
            cout << "Bye bye!" << endl;
            return;
        }

        do  //end menu, asks user to play again or no
        {
            cout << "\nDo you want to play again? (No spaces, please)" << endl;
            cout << "1) Yes\t2) No" << endl;
            cout << "Answer: ";
            cin >> buffer;

            answer = atoi(buffer);

            if (answer == 0) {
               cout << "\nPlease enter a valid answer." << endl;
            }

            else if (answer == 2)
            {
                cout << "Okay, bye!" << endl;
                return;
            }
            
        } while (answer < 1 || answer > 2);
        
    } while (option < 1 || option > 4 || answer == 1);
}

/*
* Function name: rev_str_menu()
* Purpose: To ask the user for input
* Arguments: none
* Returns: none
*/
void Menu::rev_str_menu()
{
    string str;

    cout << "\nPlease enter a string: ";
    getline(cin, str);

    cout << "Reversed string: " << reverse_str(str) << endl;
}

/*
* Function name: sum_menu()
* Purpose: To ask the user for input
* Arguments: none
* Returns: none
*/
void Menu::sum_menu()
{
    int* list, size, num;

    cout << "\nHow many numbers will there be? ";
    cin >> size;
    
    list = new int[size];

    cout << "Please list your numbers below. (Only integers, please)" << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> num;
        list[i] = num;
    }

    cout << "Sum of numbers: " << sum(list, size) << endl;

    delete [] list;
}

/*
* Function name: tri_menu()
* Purpose: To ask the user for input
* Arguments: none
* Returns: none
*/
void Menu::tri_menu()
{
    int num;

    cout << "\nCalculate the triangular number of: ";
    cin >> num;
    
    cout << "Triangular sum: " << triangulate(num) << endl;
}