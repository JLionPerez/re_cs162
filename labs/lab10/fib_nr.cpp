/*
* File name: fib_nr.cpp
* Purpose: Holds defintiions for fib_nr.hpp
*/

#include "fib_nr.hpp"

/*
* Function name: it_fib()
* Purpose: Iterate fibonacci number
* Arguments: integer
* Returns: integer
* Cited works: Iterative and Recusrive Fibonacci: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*/
int it_fib(int N)
{
    int first = 0;
    int second = 1;
    int counter = 2;

    while(counter < N)
    {
        int temp = second;
        second = first + second;
        first = temp;
        counter++;
    }

    if(N == 0) { return 0; }

    else { return first+second; }
}

/*
* Function name: print_it_fib()
* Purpose: Prints fibonacci number
* Arguments: integer
* Returns: none
* Cited works: Iterative and Recusrive Fibonacci: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*/
void print_it_fib(int N)
{
    int result = it_fib(N);

    cout << '\t' << N << "th fibonacci Number: " << result << endl;
}