/*
* File name: student.hpp
* Purpose: Holds prototypes for student.cpp
*/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"

class Student : public Person
{
    private:
        float GPA; //0.0 to 4.0
    
    public:
        Student();

        float get_gpa();
        void set_gpa(float gpa);

        float do_work();
};

#endif