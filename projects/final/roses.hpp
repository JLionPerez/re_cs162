#ifndef ROSES_HPP
#define ROSES_HPP

#include "space.hpp"

class Roses : public Space
{
    public:
        Roses();
        ~Roses();
        
        void special();
        void description();
        void map();
        void menu();
};

#endif