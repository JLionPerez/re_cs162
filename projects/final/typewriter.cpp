#include "typewriter.hpp"

void typewriter(string &str, int time)    //cited: https://www.youtube.com/watch?v=iWnVBmdf5a0
{
    for(int i = 0; i < str.length(); i++)
    {
        cout << str.at(i) << flush;
        sleep_for(milliseconds(time));
    }
    cout << "\n";
}