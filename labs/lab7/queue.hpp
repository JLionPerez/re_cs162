#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct QueueNode
{
    QueueNode* next;
    QueueNode* prev;
    int val;

    //constructor, from book
    QueueNode(int val, QueueNode *next = nullptr, QueueNode *prev = nullptr)
    {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class Queue
{
    private:
        QueueNode* head;
    
    public:
        Queue();
        ~Queue();

        QueueNode* getHead();   //returns pointer

        bool isEmpty();
        
        void addBack(int val);

        int getFront();
        void removeFront();

        void printQueue();
};
#endif