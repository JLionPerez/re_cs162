#include "queue.hpp"

Queue::Queue()
{
    head = nullptr; //starts off as nothing
}

Queue::~Queue()
{
    delete head;
}

QueueNode* Queue::getHead()
{
    return head;
}

bool Queue::isEmpty()
{
    //checks if the queue is empty.
    //If so, returns true;
    if(getHead() == nullptr) { return true; }

    //otherwise, return false
    return false;
}

void Queue::addBack(int val)
{
    //takes a user-inputted integer,
    //creates a QueueNode with user-inputted integer,
    QueueNode* node = new QueueNode(val);
    //and appends it to the back of the list
    if (isEmpty())
    {
        node->prev = node;
        node->next = node;
    }

    else
    {
        node->next = head;
        node->prev = head->prev;
        head->prev = node;
    }

    head = node;
}

int Queue::getFront()
{
    //returns the value of the node at the front of the queue
    return getHead()->val;
}

void Queue::removeFront()
{
    //removes the front QueueNode of the queue and free the memory
}

void Queue::printQueue()
{
    //traverses through the queue from head using next pointers,
    QueueNode* node = getHead();    //starts at beginning
    //and prints the values of each QueueNode in the queue
    while(node != getHead())
    {
        cout << node->val << " ";
        node = node->next; 
    }
}