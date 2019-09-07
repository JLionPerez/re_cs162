/*
* File name: recursive.cpp
* Description: Holds defintions for recursive.hpp
*/

#include "recursive.hpp"

/*
* Function name: reverse_str()
* Purpose: Reverses the string
* Arguments: string
* Returns: string
* Cited source: Reverse String - //http://www.cplusplus.com/forum/beginner/184744/
*/
string reverse_str(string str)
{
    int size = str.length();
    char first_pos = str[0];
    string copy_str = str.substr(1, size);

    if(size == 1)   //base case
        return str;
    else
        return reverse_str(copy_str) + first_pos;
}

/*
* Function name: sum()
* Purpose: Adds integers together within a list
* Arguments: integer array, integer
* Returns: integer
*/
int sum(int* list, int size)
{
    int total = list[size];

    if (size < 0)   //base case
        return 0;
    else
        return total + sum(list, size - 1);     //adds to next integer
}

/*
* Function name: triangulate()
* Purpose: Calculates the triangular of a number
* Arguments: integer
* Returns: integer
* Cited work: The Recursive Factorial Function - Chapter 14 in C++ Early Objects by Gaddis, Walters, and Muganda
*/
int triangulate(int n)
{
    if (n == 0)     //base case
        return 0;
    else
        return n + triangulate(n - 1);
}