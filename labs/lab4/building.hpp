/*
* File name: building.hpp
* Purpose: Holds the prototypes for building.cpp
*/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <cstring>
#include <string>
using std::string;

class Building
{
    private:
        string name;
        int size;
        string address;

    public:
        string get_name();
        void set_name(string name);

        int get_size();
        void set_size(int size);

        string get_address();
        void set_address(string address);
};

#endif