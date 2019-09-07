/*
* File name: instructor.hpp
* Purpose: Holds prototypes for instructor.cpp
*/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "person.hpp"

class Instructor : public Person
{
    private:
        float rating;  //0.0 to 5.0

    public:
        Instructor();

        float get_rating();
        void set_rating(float rating);
        
        float do_work(); 
};

#endif