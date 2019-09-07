/*
* File name: fib_r.cpp
* Purpose: Holds definitions for gib_r.cpp
*/

#include "fib_r.hpp"

/*
* Function name: rec_fib()
* Purpose: Recursively find the fibonacci number
* Arguments: integer
* Returns: integer
* Cited Works: Iterative and Recusrive Fibonacci: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*/
int rec_fib(int N)
{
    if(N == 0) { return 0; }

    else if(N == 1) { return 1; }

    return rec_fib(N - 1) + rec_fib(N - 2);
}

/*
* Function name: print_rec_fib()
* Purpose: Prints the fibonacci numbers
* Arguments: integer
* Returns: none
* Cited Works: Iterative and Recusrive Fibonacci: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*/
void print_rec_fib(int N)
{
  	int FibonaciNum = rec_fib(N);
    
  	cout << '\t' << N << "th fibonaci number: " << FibonaciNum << endl;
}