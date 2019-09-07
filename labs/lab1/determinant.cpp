#include "determinant.hpp"

/*
* Function Name: determinant()
* Purpose: Calculates and returns the determinant of the matrix.
* Arguments: takes in a double 2D array, and integer size
* Returns: integer
*/
int determinant(double** arr, int size)
{
    int determinant, first, second, outer, first_product, second_product, final_first, final_second, final_third, x = 0, y = 0;

    if(size == 2)
    {
        //for the first diagonal pair
        first = arr[x][y];          //(0,0)
        second = arr[x+1][y+1];     //(1,1)
        first_product = first*second;

        //for the second diagonal pair
        first = arr[x][y+1];        //(0,1)
        second = arr[x+1][y];       //(1,0)
        second_product = first*second;

        determinant = first_product-second_product;
    }

    if(size == 3)
    {
        //the first factor
        outer = arr[x][y];  //saves the outer multiple, (0,0)
        //first pair
        first = arr[x+1][y+1];      //(1,1)
        second = arr[x+2][y+2];     //(2,2)
        first_product = first*second;
        //second pair
        first = arr[x+1][y+2];      //(1,2)
        second = arr[x+2][y+1];     //(2,1)
        second_product = first*second;
        //saves product for first factor
        final_first = first_product-second_product;
        final_first = final_first*outer;   

        //the second factor
        outer = arr[x][y+1];        //(0,1)
        //first pair
        first = arr[x+1][y];        //(1,0)
        second = arr[x+2][y+2];     //(2,2)
        first_product = first*second;
        //second pair
        first = arr[x+1][y+2];      //(1,2)
        second = arr[x+2][y];       //(2,0)
        second_product = first*second;
        //saves product for second factor
        final_second = first_product-second_product;
        final_second = final_second*outer;

        //the third factor
        outer = arr[x][y+2];        //(0,2)
        //first pair
        first = arr[x+1][y];        //(1,0)
        second = arr[x+2][y+1];     //(2,1)
        first_product = first*second;
        //second pair
        first = arr[x+1][y+1];      //(1,1)
        second = arr[x+2][y];       //(2,0)
        second_product = first*second;
        //saves product for third factor
        final_third = first_product-second_product;
        final_third = final_third*outer;

        determinant = final_first-final_second+final_third;
    }

    return determinant;
}