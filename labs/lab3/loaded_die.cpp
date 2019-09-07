/*
* File name: loaded_die.cpp
* Purpose: Holds definitions for prototypes in loaded_die.hpp.
*/
#include "loaded_die.hpp"

/*
* Function Name: cheat()
* Purpose: To return a biased value when rolled.
* Arguments: none
* Returns: integer
*/
int LoadedDie::cheat()
{
    srand(time(NULL));

    int norm = roll(), high = rand() % sides + 1;

    if(high > norm)
    {
        return high;
    }

    else if (norm % 2 == 0)
    {
        if(high % 2 > 0)
        {
            return high;
        }
        return norm;
    }

    else
    {
        if(high > norm)
        {
            return high;
        }
    }

}