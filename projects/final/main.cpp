//cited: https://www.youtube.com/watch?v=iWnVBmdf5a0

#include "menu.hpp"
#include "game.hpp"
#include "item.hpp"

#include "characters.hpp"
#include "dog.hpp"
#include "mermaid.hpp"
#include "snake.hpp"
#include "mare.hpp"

#include "space.hpp"
#include "forest.hpp"
#include "beach.hpp"
#include "cabin.hpp"
#include "desert.hpp"
#include "roses.hpp"
#include "lake.hpp"

int main()
{
    srand(time(NULL));

    Menu m;
    m.beginning();

    return 0;
}