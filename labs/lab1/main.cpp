/*
* Program Name: Lab 1 - Matrix Determinant Calculator
* Author: Joelle Perez
* Date: 13 January 2019
* Description: This program calculates the determinant of a matrix using integers from the user, and returns the matrix and determinant.
* Cited Works:
*   Print 2D Array: https://stackoverflow.com/questions/12311149/how-to-print-2d-arrays-in-c
*   Delete 2D Array: https://www.learncpp.com/cpp-tutorial/6-14-pointers-to-pointers/
*   Allocate 2D Array: https://www.learncpp.com/cpp-tutorial/6-14-pointers-to-pointers/
*   How to Create a Simple Makefile: https://www.youtube.com/watch?v=_r7i5X0rXJk
*/
#include "determinant.hpp"
#include "read_matrix.hpp"

void print_grid(double** arr, int size);    //prototypes
void delete_mem(double** arr, int size);    //

int main()
{
    char buffer[100];   //for holding chars
    int choice, size;
    double **arr;       //dynamic array

    do  //continuously asks the user for the right input
    {
        cout << "\nPlease choose the size of the Matrix:\n";
        cout << "1. 2x2\n";
        cout << "2. 3x3\n";
        cout << "\nChoice: ";
        cin >> buffer;
        
        choice = atoi(buffer);  //converts non-integers into 0

        if(choice == 1) 
        {
            cout << "Chose 2x2." << endl;
            size = 2;
            readMatrix(arr, size);  //initializes matrix with numbers
            print_grid(arr, size);  //prints matrix
            cout << "\nDeterminant: " << determinant(arr, size) << endl;    //calculates determinant and displays it
        }

        else if(choice == 2) 
        {
            cout << "Chose 3x3." << endl;
            size  = 3;
            readMatrix(arr, size);
            print_grid(arr, size);
            cout << "\nDeterminant: " << determinant(arr, size) << endl;
        }

        else
        {
            cout << "\nPlease choose a valid option." << endl;
        }
    }   while(choice != 1 && choice != 2);

    delete_mem(arr, size);  //deletes allocated memory
}

/*
* Function Name: print_grid()
* Purpose: Prints matrix on screen.
* Arguments: takes in double 2D array, and integer size
* Returns: nothing
* Based on: https://stackoverflow.com/questions/12311149/how-to-print-2d-arrays-in-c
*/
void print_grid(double** arr, int size)
{
    cout << "\nMatrix: " << endl;
    for (int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {
            cout << ' ' << arr[row][col] << ' ';    //seperates numbers with spaces
        }
        cout << endl;
    }
}

/*
* Function Name: delete_mem()
* Purpose: Deletes allocated memory on heap.
* Arguments: takes in double 2D array, and integer size
* Returns: nothing
* Based on: https://www.learncpp.com/cpp-tutorial/6-14-pointers-to-pointers/
*/
void delete_mem(double** arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;   //delete remaining array
}