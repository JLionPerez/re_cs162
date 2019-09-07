#include "queue.hpp"
#include "menu.hpp"

int main()
{
    Queue q;
    Queue* list = new Queue;    //a list to start
    
    Menu m;
    m.startup(q, list);

    delete list;

    return 0;
}