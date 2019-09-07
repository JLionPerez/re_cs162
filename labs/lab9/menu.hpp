/*
* File name: menu.hpp
* Purpose: Holds the prototypes for menu.cpp
*/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>
#include <ctime>

#include <cstring>
#include <string>
using std::string;

#include <queue>
using std::queue;

#include <stack>
using std::stack;

class Menu
{
    private:
        int option;
        int again;
        char hold[100];

        //STL lists/containers
        queue <int> q;
        stack <char> s;
        stack <char> temp;

        //average length
        double prev_al;
        double al;

        //random number
        int N;

        //parameters for buffer
        int append_percentage;
        int remove_percentage;
        int rounds;

        //parameter for palindrome
        string str;

    public:
        void beginning();

        int random_1000(); //N gets appended
        int random_100();  //decides if a number is removed or added, the percentage

        void buffer_menu();
        void buffer();

        double average_length(int i);

        void print_queue();

        void palindrome_menu();
        void palindrome();

        void print_stack();

        void end();
};
#endif