#ifndef SPACE_HPP
#define SPACE_HPP

#include "typewriter.hpp"
#include "characters.hpp"

class Space
{
    protected:
        Space* top;
        Space* bottom;
        Space* left;
        Space* right;

        string name;
        Characters* enemy;

    public:
        Space();

        Space* get_top();
        void set_top(Space* top);

        Space* get_bottom();
        void set_bottom(Space* bottom);

        Space* get_left();
        void set_left(Space* left);

        Space* get_right();
        void set_right(Space* right);

        string get_name();
        void set_name(string name);

        virtual void special() = 0;
        virtual void description() = 0;
        virtual void map() = 0;
        virtual void menu() = 0;
};

#endif