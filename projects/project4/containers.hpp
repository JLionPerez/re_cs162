/*
* File name: containers.hpp
* Purpose: Holds prototypes for containers.cpp
*/

#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP

#include "characters.hpp"
#include "barbarian.hpp"
#include "vampires.hpp"
#include "blue_men.hpp"
#include "harry_potter.hpp"
#include "medusa.hpp"

struct QueueNode
{
    Characters* teammate;   //data the node is holding, in this case a character object
    QueueNode* prev;        //points to previous node
    QueueNode* next;        //points to next node

    //constructor
    QueueNode(Characters* mate, QueueNode* previous = NULL, QueueNode* next1 = NULL)
    {
        teammate = mate;
        prev = previous;
        next = next1;
    }
};

class Queue
{
    private:
        QueueNode* head;

    public:
        Queue();
        ~Queue();

        QueueNode* get_head();
        void set_head(QueueNode* head);

        bool isEmpty();
        void addBack(Characters* teammate);
        void remove_front();
        void print_queue();
        void print_player(QueueNode* player);
        void clear();
};

#endif