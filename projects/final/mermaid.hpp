#ifndef MERMAID_HPP
#define MERMAID_HPP

#include "characters.hpp"

class Mermaid : public Characters
{
    public:
        Mermaid();

        int attack_func();
        void defense_func(int attack_recieved);
        bool persuaded();
};

#endif