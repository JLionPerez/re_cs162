/*
* Program name: Lab 2 - Frequency Finder
* Author: Joelle Perez
* Date: 20 January 2019
* Description: This program recieves a file then finds the frequencies of letters and output those into an output file.
*/

#include "frequency.hpp"

using namespace std;

int main()
{
    string in_str, out_str;
    char find_enter;
    int alpha[27] = {0};    //initialize with 0s

    cout << "Enter the name of an existing text file: ";
    getline(cin, in_str);

    ifstream is(in_str.c_str());     // open file
    ofstream os;

    while(!is.eof())
    {
        count_letters(is, alpha);
        cout << "Enter output file name: ";
        getline(cin, out_str);        //asks user for output files

        os.open(out_str.c_str());
        output_letters(os, alpha);    //outputs file in output files
        os.close();
        memset(alpha, 0, sizeof(alpha));    //resets integer list to 0 again
    }

    is.close();     //close files

}