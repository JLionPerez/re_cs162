#include "game.hpp"

void Game::set_areas()
{
    //area 1 ROSES
    area1 = new Roses();
    area1->set_name("\033[1;90mroses\033[0m");
    area1->set_top(area2);
    area1->set_bottom(area6);
    area1->set_left(nullptr);
    area1->set_right(nullptr);

    //area 2 FOREST
    area2 = new Forest();
    area2->set_name("\033[1;35mforest\033[0m");
    area2->set_top(area5);
    area2->set_bottom(area1);
    area2->set_left(area3);
    area2->set_right(area4);

    //area 3 DESERT
    area3 = new Desert();
    area3->set_name("\033[1;31mdesert\033[0m");
    area3->set_top(nullptr);
    area3->set_bottom(nullptr);
    area3->set_left(nullptr);
    area3->set_right(area2);

    //area 4 CABIN
    area4 = new Cabin();
    area4->set_name("\033[1;92mcabin\033[0m");
    area4->set_top(nullptr);
    area4->set_bottom(nullptr);
    area4->set_left(area2);
    area4->set_right(nullptr);

    //area 5 BEACH
    area5 = new Beach();
    area5->set_name("\033[1;94mbeach\033[0m");
    area5->set_top(nullptr);
    area5->set_bottom(area2);
    area5->set_left(nullptr);
    area5->set_right(nullptr);

    //area 6 LAKE
    area6 = new Lake();
    area6->set_name("\033[1;36mlake\033[0m");
    area6->set_top(area1);
    area6->set_bottom(nullptr);
    area6->set_left(nullptr);
    area6->set_right(nullptr);
}