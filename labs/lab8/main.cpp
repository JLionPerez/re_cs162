/*
* Program: Lab 8 - Searching and Sorting
* Description: A program that searches for certain values and sorts through lists.
* Author name: Joelle Perez
* Date: 27 February 2019
* Cited Works:
*       Lectures: Searching and Sorting
*           -Introduction to Searching
*           -Bubble Sort
*/

#include "search_sort.hpp"

int main()
{
    const int size = 9;
    int value, again = 2;

    //arrays (static)
    int num_arr[size], early_arr[size], mid_arr[size], end_arr[size];

    //open files
    //input files
    ifstream num;
    num.open("num.txt");

    ifstream early;
    early.open("early.txt");

    ifstream mid;
    mid.open("mid.txt");

    ifstream end;
    end.open("end.txt");

    //output files
    ofstream num_o;
    num_o.open("num_o.txt");

    ofstream early_o;
    early_o.open("early_o.txt");

    ofstream mid_o;
    mid_o.open("mid_o.txt");

    ofstream end_o;
    end_o.open("end_o.txt");

    do
    {
        cout << "Welcome to Searching and Sorting!" << endl;

        // 1) Read Values from Files
        file_to_arr(num_arr, num);
        file_to_arr(early_arr, early);
        file_to_arr(mid_arr, mid);
        file_to_arr(end_arr, end);

        // 2) Simple Search
        cout << "\n\t_____Simple Search_____" << endl;

        validate(value);    //asks and validates inputted value

        cout << "\nnum.txt: ";
        linear_search(num_arr, size, value);

        cout << "early.txt: ";
        linear_search(early_arr, size, value);

        cout << "mid.txt: ";
        linear_search(mid_arr, size, value);

        cout << "end.txt: ";
        linear_search(end_arr, size, value);

        // 3) Sorting
        cout << "\n\t_____Sorting_____" << endl;

        bubble_sort(num_arr, size);
        bubble_sort(early_arr, size);
        bubble_sort(mid_arr, size);
        bubble_sort(end_arr, size);

        //arrays to files
        arr_to_file(num_arr, num_o);
        arr_to_file(early_arr, early_o);
        arr_to_file(mid_arr, mid_o);
        arr_to_file(end_arr, end_o);

        //prints arrays
        print_all(num_arr, early_arr, mid_arr, end_arr);

        // 4) Binary Search
        cout << "\n\t_____Binary Search_____" << endl;

        validate(value);    //asks and validates inputted value

        cout << "\nnum.txt: ";
        binary_search(num_arr, size, value);

        cout << "early.txt: ";    
        binary_search(early_arr, size, value);

        cout << "mid.txt: ";    
        binary_search(mid_arr, size, value);

        cout << "end.txt: ";    
        binary_search(end_arr, size, value);

        //close files
        //input files
        num.close();
        early.close();
        mid.close();
        end.close();

        //output files
        num_o.close();
        early_o.close();
        mid_o.close();
        end_o.close();

        //asks user to play again
        play_again(again);

    } while(again == 1);

    return 0;
}