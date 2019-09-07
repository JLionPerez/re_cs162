/*
* File name: university.hpp
* Purpose: Holds prototypes for university.cpp
*/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp" 

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstring>
#include <string>
using std::string;

class University
{
    private:
        string name;

        Building* buildings;    //number of building objects
        int num_buildings;

        Person* people;         //number of person objects
        int num_people;

    public:
        University();
        ~University();

        int get_num_buildings();
        void set_num_buildings(int buildings);
        void assign_building_info();
        void print_info_buildings();    //name, address, building size
        Building chosen_building(int chosen);

        int get_num_people();
        void set_num_people(int persons);
        void assign_people_info();
        void print_info_people();       //name, age, GPA or Rating
        Person chosen_person(int chosen);

        string get_name();
        void set_name(string name);
};

#endif