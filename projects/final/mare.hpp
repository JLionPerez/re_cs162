#ifndef MARE_HPP
#define MARE_HPP

#include "characters.hpp"

class Mare : public Characters
{
    public:
        Mare();

        int attack_func();
        void defense_func(int attack_recieved);
        bool persuaded();
};

#endif