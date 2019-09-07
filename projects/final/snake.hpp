#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "characters.hpp"

class Snake : public Characters
{
    public:
        Snake();

        int attack_func();
        void defense_func(int attack_recieved);
        bool persuaded();
};

#endif