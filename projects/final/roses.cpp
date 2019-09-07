#include "roses.hpp"

Roses::Roses()
{
    enemy = new Snake();
}

Roses::~Roses()
{
    delete enemy;
}

void Roses::special()
{
    
}

void Roses::description()
{

}

void Roses:map()
{
    cout << "\nThis is your current location:" << endl;
    cout << "           ------------" << endl;
    cout << "           |          |" << endl;
    cout << "           |   \033[1;94mBEACH\033[0m  |" << endl;
    cout << "           |          |" << endl;
    cout << "---------------------------------" << endl;
    cout << "|          |          |         |" << endl;
    cout << "|  \033[1;31mDESERT\033[0m  |  \033[1;35mFOREST\033[0m  |  \033[1;92mCABIN\033[0m  |" << endl;
    cout << "|          |          |         |" << endl;
    cout << "---------------------------------" << endl;
    cout << "           |          |" << endl;
    cout << "           |  ( -_-)  |" << endl;
    cout << "           |          |" << endl;
    cout << "           ------------" << endl;
    cout << "           |          |" << endl;
    cout << "           |   \033[1;36mLAKE\033[0m   |" << endl;
    cout << "           |          |" << endl;
    cout << "           ------------" << endl;
}

void Roses::menu()
{
    map();

    str = "You wake in a field of black \033[1;90mroses\033[0m.\nThe field stretch for miles, but you can spot a forest in front at the north side of the field\nand a lake at the south side of the field.";
    typewriter(str, 30);

    str = "\nIn the middle of the field lays a white snake.\nHer scales contrast amongst the black roses making her very easy to spot.";
    typewriter(str, 30);

    str = "\nYou confront the snake";
    typewriter(str, 30);

    cout << "\nThe snake speaks." << endl;
    str = "";
}
