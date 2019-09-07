/*
* File name: university.cpp
* Purpose: Holds definitions for university.hpp
*/

#include "university.hpp"

/*
* Function name: University()
* Purpose: Default constructor to initialize members
* Argument: none
* Returns: none
*/
University::University()
{
    name = "Oregon State Unviversity";

    num_buildings = 2;
    buildings = new Building[num_buildings];
    
    num_people = 2;     //1 student, 1 instructor
    people = new Person[num_people];
}

/*
* Function name: ~University()
* Purpose: Deletes allocated memory on the heap
* Argument: none
* Returns: none
*/
University::~University()
{
    delete [] buildings;
    delete [] people;
}

/*
* Function name: get_name() 
* Purpose: Returns private member in University class
* Argument: none
* Returns: string
*/
string University::get_name()
{
    return name;
}

/*
* Function name: set_name()
* Purpose: Sets private member to given value
* Argument: string
* Returns: none
*/
void University::set_name(string name)
{
    this->name = name;
}

/*
* Function name: get_num_buildings()
* Purpose: Returns private member in University class
* Argument: none
* Returns: integer
*/
int University::get_num_buildings()
{
    return num_buildings;
}

/*
* Function name: set_num_buildings()
* Purpose: Sets private member to given value
* Argument: integer
* Returns: none
*/
void University::set_num_buildings(int buildings)
{
    num_buildings = buildings;
}

/*
* Function name: get_num_people()
* Purpose: Returns private member in University class
* Argument: none
* Returns: integer
*/
int University::get_num_people()
{
    return num_people;
}

/*
* Function name: set_num_peopl()
* Purpose: Sets private member to given value
* Argument: integer
* Returns: none
*/
void University::set_num_people(int persons)
{
    num_people = persons;
}

/*
* Function name: chosen_building()
* Purpose: Returns position of building list in University class
* Argument: integer
* Returns: Building object
*/
Building University::chosen_building(int chosen)
{
    return buildings[chosen];
}

/*
* Function name: chosen_person()
* Purpose: Returns position of person list in University class
* Argument: integer
* Returns: Person object
*/
Person University::chosen_person(int chosen)
{
    return people[chosen];
}

/*
* Function name: assign_building_info()
* Purpose: Initializes the two buildings' data
* Argument: none
* Returns: none
*/
void University::assign_building_info()
{
    buildings[0].set_name("Austin Hall");
    buildings[0].set_size(107613);
    buildings[0].set_address("2751 SW JEFFERSON WAY");

    buildings[1].set_name("Bates Hall");
    buildings[1].set_size(16134);
    buildings[1].set_address("110 SW 26TH STREET");
}

/*
* Function name: print_info_buildings()
* Purpose: Prints building information
* Argument: none
* Returns: none
*/
void University::print_info_buildings()
{
    int j = 1;
    for(int i = 0; i < num_buildings; i++)
    {
        cout << "\n" << j << ") Building's name: " << buildings[i].get_name() << endl;
        cout << "\tSize: " << buildings[i].get_size() << " sqft" << endl;
        cout << "\tAddress: " << buildings[i].get_address() << endl;
        j++;
    }
}

/*
* Function name: assign_people_info()
* Purpose: Initializes two persons' data
* Argument: none
* Returns: none
*/
void University::assign_people_info()
{
    people[0].set_name("Avery Joe");    //student (average joe)
    people[0].set_age(21);

    people[1].set_name("Salph Maed");    //instructor (self made)
    people[1].set_age(30);
}

/*
* Function name: print_info_people()
* Purpose: Prints people information
* Argument: none
* Returns: none
*/
void University::print_info_people()
{
    Student s;
    Instructor k;

    int j = 1;
    for(int i = 0; i < num_people; i++)
    {   
        cout << "\n" << j << ") Person's name: " << people[i].get_name() << endl;
        cout << "\tAge: " << people[i].get_age() << endl;

        if(j == 1)
        {
            cout << "\tGPA: " << s.get_gpa() << endl;
        }

        else if(j== 2)
        {
            cout << "\tRating: " << k.get_rating() << endl;
        }
        j++;
    }
}