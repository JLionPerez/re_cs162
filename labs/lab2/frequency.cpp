/*
* File name: frequency.cpp
* Purpose: To hold definitions for prototypes in frequency.hpp
*/

#include "frequency.hpp"

/*
* Function Name: count_letters()
* Purpose: Counts the letters in each line of text
* Arguments: takes in an ifstream file and an integer array
* Returns: none
*/
void count_letters(ifstream &file, int* arr)
{
    string line;
    char letter;
    getline(file, line);
    for(int i = 0; i < line.length(); i++)
    {
        letter = line[i];
        letter = tolower(letter);   //decapitlizes letters
        arr[letter - 'a']++;        
    }
}

/*
* Function Name: output_letters()
* Purpose: Outputs letters the their corresponding numbers into a text file
* Arguments: takes in an ofstream file and an integer array
* Returns: none
*/
void output_letters(ofstream &file, int* arr)
{
    char letter = 'a', letters[27] = {letter}, colon = ':', space = ' ';
    int max_letters = 26;
    for(int i = 0; i < max_letters; i++)
    {
        letters[i] = letter + i;    //moves onto next letter
        file << letters[i] << colon << space << arr[i] << endl;
    }
    
}