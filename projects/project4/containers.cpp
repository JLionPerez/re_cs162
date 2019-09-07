/*
* File name: containers.cpp
* Purpose: Holds definitions for containers.hpp
*/

#include "containers.hpp"

/*
* Function name: Queue()
* Purpose: Constructor for the class, initializes members
* Arguments: none
* Returns: none
*/
Queue::Queue() 
{
    head = NULL; //head points to NULL
}

/*
* Function name: ~Queue()
* Purpose: Deconstructor for the class, deletes allocated memory
* Arguments: none
* Returns: none
* Cited Works: C++ Early Objects pg. 1107 & pg. 1108
*/
Queue::~Queue()
{
    QueueNode* garbage = head;
    while(garbage != NULL)
    {
        head = head->next;
        garbage->next = NULL;
        delete garbage;
        garbage = head;
    }
}

/*
* Function name: get_head()
* Purpose: returns node memeber
* Arguments: none
* Returns: node
*/
QueueNode* Queue::get_head()
{
    return head;
}

/*
* Function name: set_head()
* Purpose: Sets pointer head to a value
* Arguments: node
* Returns: none
*/
void Queue::set_head(QueueNode* head)
{
    this->head = head;
}

/*
* Function name: isEmpty()
* Purpose: Determines if list is empty
* Arguments: none
* Returns: boolean
*/
bool Queue::isEmpty()
{
    return get_head() == NULL;
}

/*
* Function name: addBack()
* Purpose: Adds to the back of the list
* Arguments: Characters*
* Returns: none
*/
void Queue::addBack(Characters* teammate)
{

    QueueNode* node = new QueueNode(teammate);

    if(isEmpty())
    {
        set_head(node);
    }

    else
    {
        QueueNode* temp = head;
        
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = node;
        node->prev = temp;
        node->next = NULL;
    }
}

/*
* Function name: remove_front()
* Purpose: Deletes first node
* Arguments: none
* Returns: none
* Cited Works: C++ Early Objects pg. 1108
*/
void Queue::remove_front()
{
    QueueNode *temp = NULL;
    Characters* dummy;

    if(isEmpty()) { cout << "\nThe queue is already empty." << endl; }

    else
    {
        dummy = head->teammate;
        temp = head;
        head = head->next;

        if (head != NULL) { head->prev = NULL; }

        delete temp;
    }
}

/*
* Function name: print_player()
* Purpose: Prints the name of a character within a node
* Arguments: node
* Returns: none
*/
void Queue::print_player(QueueNode* player)
{
    if(player != NULL)
    {
        cout << player->teammate->get_name() << ". ";
    }
}

/*
* Function name: print_queue()
* Purpose: Prints the list with their given names
* Arguments: none
* Returns: none
*/
void Queue::print_queue()
{
    if(isEmpty()) { cout << "List is empty." << endl; }

    else
    {
        QueueNode* player = head;
        do
        {
            print_player(player);
            player = player->next;

        } while (player != NULL);
        
        cout << endl;
    }
}

/*
* Function name: clear()
* Purpose: Deletes remaining lists
* Arguments: none
* Returns: none
*/
void Queue::clear()
{
    while(!isEmpty())
    {
        remove_front();
    }
}