#ifndef GAME_HPP
#define GAME_HPP

#include "typewriter.hpp"
#include "space.hpp"
#include "roses.hpp"
#include "forest.hpp"
#include "cabin.hpp"
#include "desert.hpp"
#include "beach.hpp"
#include "lake.hpp"

class Game
{
    private:
        Space* area1;   //roses
        Space* area2;   //forest
        Space* area3;   //desert
        Space* area4;   //cabin
        Space* area5;   //beach
        Space* area6;   //lake

    public:
        void set_areas();
        void battle(Characters* enemy);
        void persuade(Characters* enemy);
};

#endif