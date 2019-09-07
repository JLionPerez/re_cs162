#include "menu.hpp"

void Menu::startup(Queue q, Queue* list)
{
    int val;
    //start up menu
    cout << "\nWelcome to Circular Linked List!" << endl;

    do
    {
        cout << "\n\t1) Enter a value to be added to the back of queue" << endl;
        cout << "\t2) Display first node (front) value" << endl;
        cout << "\t3) Remove first node (front) value" << endl;
        cout << "\t4) Display the queue contents" << endl;
        cout << "\t5) Exit" << endl;
        cout << "Enter: ";
        cin >> buffer;

        option = atoi(buffer);

        switch(option)
        {
            case 1:
                cout << "\nPlease enter an integer: ";
                cin >> val; //needs input validation
                //cout << "\nValue added to back of list" << endl;
                q.addBack(val);
                break;
            
            case 2:
                //cout << "\nFront value" << endl;
                q.getFront();
                break;

            case 3:
                //cout << "\nRemoved front value" << endl;
                q.removeFront();
                break;

            case 4:
                //cout << "\nDisplay content" << endl;
                q.printQueue();
                break;

            case 5:
                cout << "\nBye bye!" << endl;
                return;

            default:
                cout << "Please enter a valid option." << endl;
                break;
        }

        do
        {
            cout << "\nDo you want to play again?" << endl;
            cout << "\t1) Yes\t2) No" << endl;
            cout << "Enter: ";
            cin >> buffer;

            again = atoi(buffer);   
            cout << again << endl; 

            if(again < 1 || again > 2) { cout << "Please enter a valid option." << endl; }

            else if(again == 2) { cout << "\nBye bye!" << endl; return; }

        } while (again < 1 || again > 2);

    } while (option < 1 || option > 5 || again == 1);
    
}