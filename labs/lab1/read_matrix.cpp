/*
* File Name: read_matrix.cpp
* Author: Joelle Perez
*/

#include "read_matrix.hpp"

/*
* Function Name: readMatrix()
* Purpose: Allocates memory space for 2D array, and initializes with user's integer inputs.
* Arguments: takes in a reference to a double 2D array, and integer size
* Returns: nothing
* Based on: https://www.learncpp.com/cpp-tutorial/6-14-pointers-to-pointers/
*/
void readMatrix(double** &arr, int size)
{
    double num;
    int nums = size*size;

    //allocate an array of 2 double pointers
    arr = new double*[size];        //rows
    for(int i = 0; i < size; i++)
    {
        arr[i] = new double[size];  //columns
    }

    //get users numbers and place in array
    cout << "\nPlease list " << nums <<" numbers below. " << endl;
    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {
            cin >> num;
            arr[row][col] = num;
        }
    }
}