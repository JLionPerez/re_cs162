/*
* File name: menu.cpp
* Purpose: Holds the prototypes for menu.hpp
*/

#include "menu.hpp"

/*
* Funtion name: beginning()
* Purpose: Menu for the user to choose an option
* Arguemnts: none
* Returns: none
*/
void Menu::beginning()
{
    do
    {
        cout << endl;
        cout << "Welcome to Stack and Queue STL Containers!" << endl;
        cout << "\t1) Buffer" << endl;
        cout << "\t2) Palindrome" << endl;
        cout << "\t3) Quit" << endl;
        cout << "Enter: ";
        cin >> hold;

        option = atoi(hold);

        switch(option)
        {
            case 1:
                buffer_menu();
                break;

            case 2:
                palindrome_menu();
                break;

            case 3:
                cout << "\nBye bye!" << endl;
                return;

            default:
                cout << "\nPlease try again." << endl;
                break;
        }

    } while(option < 1 || option > 3);

    end();
}

/*
* Funtion name: random_1000()
* Purpose: Generates a random number for N
* Arguemnts: none
* Returns: integer
*/
int Menu::random_1000() //N gets appended
{
    N = rand() % 1000 + 1;
    return N;
}

/*
* Funtion name: random_100()
* Purpose: Generates a percentage for N to append or front to be removed
* Arguemnts: none
* Returns: integer
*/
int Menu::random_100() //decides if a number is removed or added, the percentage
{
    int percentage = rand() % 100 + 1;
    return percentage;
}

/*
* Funtion name: print_queue()
* Purpose: Prints and deletes queue
* Arguemnts: none
* Returns: none
* Cited source: How to use library of Queue: https://www.geeksforgeeks.org/queue-cpp-stl/
*/
void Menu::print_queue()
{
    while(!q.empty())
    {
        cout << " " << q.front();
        q.pop();
    }

    cout << endl;
}

/*
* Funtion name: avaerage_length()
* Purpose: Calculates the average length of queue
* Arguemnts: integer
* Returns: double
*/
double Menu::average_length(int i)
{
    int inner = i - 1;
    double a_length = prev_al * inner;

    a_length += al;
    a_length = static_cast<double>(a_length) / static_cast<double>(i);    //makes it a decimal

    return a_length;
}

/*
* Funtion name: buffer_menu()
* Purpose: Asks the user for inputs for the buffer
* Arguemnts: none
* Returns: none
*/
void Menu::buffer_menu()
{
    do
    { 
        cin.clear();
        cin.ignore(9999, '\n');

        cout << endl;

        cout << "How many rounds? ";
        cin >> rounds;

        if(rounds < 0 || cin.fail()) { cout << "\nPlease try again, and have rounds greater than 0." << endl; }

    } while(rounds < 0 || cin.fail());

    do
    {
        cin.clear();
        cin.ignore(9999, '\n');

        cout << "Percentage to append random number? ";
        cin >> append_percentage;

        if(cin.fail()) { cout << "\nPlease try again." << endl; }

    } while(cin.fail());

    do
    {
        cin.clear();
        cin.ignore(9999, '\n');

        cout << "Percentage to remove front number? ";
        cin >> remove_percentage;

        if(cin.fail()) { cout << "\nPlease try again." << endl; }

    } while(cin.fail());

    buffer();
}

/*
* Funtion name: buffer()
* Purpose: Goes through each round and displays the queue values
* Arguemnts: none
* Returns: none
* Cited source: How to use library of Queue: https://www.geeksforgeeks.org/queue-cpp-stl/
*/
void Menu::buffer()
{
    for (int i = 0; i < rounds; i++)
    {
        prev_al = q.size();     //previous length

        cout << endl;
        cout << "\n\t- - - Round " << i + 1 << " - - -" << endl;

        if (random_100() <= append_percentage)   //append N
        {
            q.push(random_1000());
            cout << "\nValue for this round is " << q.back() << endl;
        }

        if(random_100() <= remove_percentage && !q.empty())      //remove front
        {
            cout << "\n" << q.front() << " was removed." << endl;
            q.pop();
        }
        
        //current length
        al = q.size();

        cout << "\nLength is " << al << "." << endl;

        //average length
        cout << "Average length is " << average_length(i) << "." << endl;
    }

        //print values in buffer
        cout << "\nQueue list";

        if (!q.empty()) 
        {
            cout << ":";
            print_queue(); 
        }

        else if (q.empty()) { cout << " is empty." << endl; }
}

/*
* Funtion name: print_stack()
* Purpose: Prints and deletes stack
* Arguemnts: none
* Returns: none
* Cited sources: How to use library of Stack: https://www.geeksforgeeks.org/stack-in-cpp-stl/
*/
void Menu::print_stack()
{
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    cout << endl;
}

/*
* Funtion name: palindrome_menu()
* Purpose: Asks the user for string
* Arguemnts: none
* Returns: none
*/
void Menu::palindrome_menu()
{
    cout << endl;
    cin.ignore();

    cout << "What is your palindrome? ";
    getline(cin, str);

    palindrome();
}

/*
* Funtion name: palindrome()
* Purpose: Creates palindrome from string of user
* Arguemnts: none
* Returns: none
* Cited sources: How to use library of Stack: https://www.geeksforgeeks.org/stack-in-cpp-stl/
*/
void Menu::palindrome()
{
    for(int i = 0; i < str.length(); i++)
    {
        char c = str.at(i);

        temp.push(c);   //both have reversed str
        s.push(c);      //
    }

    while(!temp.empty())
    {
        s.push(temp.top());     //puts the top character in temp to s
        temp.pop();             //then deletes top
    }

    cout << "\nYour palindrome is ";
    print_stack();
}

/*
* Funtion name: end()
* Purpose: Asks the user if they want to play again
* Arguemnts: none
* Returns: none
*/
void Menu::end()
{
    do
    {
        cout << endl;

        cout << "Do you want to play again?" << endl;
        cout << "\t1) Yes" << endl;
        cout << "\t2) No" << endl;
        cout << "Enter: ";
        cin >> hold;

        again = atoi(hold);

        if (again < 1 || again > 2) { cout << "\nPlease try again." << endl; }

        else if (again == 1) { beginning(); }

        else if (again == 2) { cout << "\nBye bye!" << endl; return; }

    } while (again < 1 || again > 2);
}