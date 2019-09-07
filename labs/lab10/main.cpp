/*
* Program Name: Lab 10 - Iterative vs. Recursive
* Author: Joelle Perez
* Description: This program measures the times for iterative and recursive fibonacci functions.
* Date: 17 March 2019
* Cited Works:
*       Iterative and Recusrive Fibonacci: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*       Measuring Execution Time: https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
*/

#include "fib_nr.hpp"
#include "fib_r.hpp"

#include <chrono>
using namespace std::chrono;

//protoype
void input(int &N);

int main()
{
    int N = 0;

    cout << "\nWelcome to the fibonacci number calculator!" << endl;

    //iterate fib
    cout << "\n\tIterative fibonacci" << endl;
    input(N);

    //start time for iterate fib (Measuring Execution Time)
    auto start1 = high_resolution_clock::now();

    //function
    it_fib(N);
    print_it_fib(N);

    //stop time for iterate fib (Measuring Execution Time)
    auto stop1 = high_resolution_clock::now(); 
    //calculate duration and print time for iterate fib (Measuring Execution Time)
    auto duration1 = duration_cast<microseconds>(stop1 - start1); 
    cout << "\tTime taken by function: " << duration1.count() << " microseconds" << endl; 
    
    //recurse fib
    cout << "\n\n\tRecursive fibonacci" << endl;
    input(N);

    //start time for recurse fib (Measuring Execution Time)
    auto start2 = high_resolution_clock::now();

    //function
    rec_fib(N);
    print_rec_fib(N);

    //stop time for recurse fib (Measuring Execution Time)
    auto stop2 = high_resolution_clock::now(); 
    //calculate duration and print time for recurse fib (Measuring Execution Time)
    auto duration2 = duration_cast<microseconds>(stop2 - start2); 
    cout << "\tTime taken by function: " << duration2.count() << " microseconds" << endl; 

    return 0;
}

/*
* Function name: input()
* Purpose: Validates the user input
* Arguments: referenced integer
* Returns: none
*/
void input(int &N)
{
    do
    {
        cout << "\nPlease enter a number you want to calculate: ";
        cin >> N;

        if (cin.fail() || N < 0) 
        {
            cout << "\nPlease try again." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }

    } while(cin.fail() || N < 0);
}