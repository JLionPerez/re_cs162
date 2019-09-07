/*
* File name: person.hpp
* Purpose: Holds prototypes for person.cpp
*/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <ctime>
#include <cstdlib>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstring>
#include <string>
using std::string;

class Person
{
    protected:
        string name;
        int age;

    public:
        string get_name();
        void set_name(string name);

        int get_age();
        void set_age(int age);

        float random_foat(float max);

        virtual float do_work();
};

#endif