/*
* File name: menu.cpp
* Purpose: Holds definitions for menu.hpp
*/

#include "menu.hpp"

/*
* Function name: menu()
* Purpose: Let's the user choose an option and shows results
* Argument: referenced integer
* Returns: none
*/
void menu(int &option)
{
    University OSU;
    OSU.assign_building_info();
    OSU.assign_people_info();

    char buffer[100];
    int num = option;

    do
    {    
        if(num < 1 || num > 4)
        {
            cout << "\nPlease enter a valid option." << endl;
            cout << "Option: ";
            cin >> buffer;

            num = atoi(buffer);
        }

        else if(num == 1)
        {
            OSU.print_info_buildings();
        }

        else if(num == 2)
        {
            OSU.print_info_people();
        }

        else if(num == 3)
        {
            nested_menu(OSU);
        }

        else if(num == 4)
        {
            cout << "\nTerminated." << endl;
            return;
        }
    } while(num < 1 || num > 4);
}

/*
* Function name: nested_menu()
* Purpose: The second menu when the user selects the third option
* Argument: referenced University object
* Returns: none
*/
void nested_menu(University &school)
{
    int option;
    char buffer[100];
    Person *p;

    school.print_info_people();

    do
    {   cout << "\nChoose a person to do work: ";
        cin >> buffer;

        option = atoi(buffer);

        if(option < 1 || option > school.get_num_people())
        {
            cout << "Please enter one of the options." << endl;
        }

        else if (option == 1)   //make student
        {
            Student s;
            p = &s;

            p->do_work();
        }

        else if (option == school.get_num_people()) //make instructor
        {
            Instructor i;
            p = &i;

            p->do_work();
        }

    } while(option < 1 || option > school.get_num_people());
}