#ifndef DOG_HPP
#define DOG_HPP

#include "characters.hpp"

class Dog : public Characters
{
    public:
        Dog();

        int attack_func();
        void defense_func(int attack_recieved);
        bool persuaded();
};

#endif