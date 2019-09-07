/*
* File name: node.cpp
* Purpose: Holds definitions for prototypes in node.hpp
*/

#include "node.hpp"

void Node::menu()
{
    int option, again = 1;  //repeats program
    char buffer[100];

    do
    {
        cout << "\nSelect an option. (No spaces, please)" << endl;
        cout << "\t1) Add a new node to the head." << endl;
        cout << "\t2) Add a new node to the tail." << endl;
        cout << "\t3) Delete the first node in the list." << endl;
        cout << "\t4) Delete the last node in the list." << endl;
        cout << "\t5) Traverse the list reversly." << endl;
        cout << "\t6) Traverse the list." << endl;
        cout << "\t7) Quit." << endl;
        cout << "Enter: ";
        cin >> buffer;
        option = atoi(buffer);  //turns letters into 0

        if(option < 1 || option > 7) { cout << "Please enter a valid input." << endl; }

        else if(option == 1) { add_node_head(); }

        else if(option == 2) { add_node_tail(); }

        else if(option == 3) { delete_node_first(); }

        else if(option == 4) { delete_node_last(); }

        else if(option == 5) { print_rev_list(); }

        else if(option == 6) { print_list(); }

        else if (option == 7)
        {
            cout << "\nBye bye!" << endl;
            again = 0;  //stops program from repeating
            return;
        }

    } while(option < 1 || option > 7 || again == 1);
}

void Node::add_node_head()
{
    cout << "Unfinished" << endl;
}

void Node::add_node_tail()
{
    cout << "Unfinished" << endl;
}

void Node::delete_node_first()
{
    cout << "Unfinished" << endl;
}

void Node::delete_node_last()
{
    cout << "Unfinished" << endl;
}

void Node::print_rev_list()
{
    cout << "Unfinished" << endl;
}

void Node::print_list()
{
    cout << "Unfinished" << endl;
}