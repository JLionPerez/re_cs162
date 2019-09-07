/*
* File name: node.hpp
* Purpose: Holds prototypes for node.cpp
*/

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

struct node
{
    node* next;
    node* prev;
    int val;
};

class Node
{
    private:
        Node* next;
        Node* prev;
        int val;

    public:
        void menu();

        void add_node_head();
        void add_node_tail();

        void delete_node_first();
        void delete_node_last();

        void print_rev_list();
        void print_list();
};

#endif