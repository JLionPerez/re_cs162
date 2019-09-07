/*
* File name: search_sort.cpp
* Purpose: Holds definitions for search_sort.hpp
*/

#include "search_sort.hpp"

/*
* Function name: file_to_arr()
* Purpose: Gets integers from file into array
* Arguments: integer array, ifstream file
* Returns: none
*/
void file_to_arr(int arr[], ifstream &file)
{
    int temp = 0;

    for(int i = 0; !file.eof(); i++)
    {
        file >> temp;
        arr[i] = temp;
    }
}

/*
* Function name: arr_to_file()
* Purpose: Puts sorted integers into an output file
* Arguments: integer array, ofstream file
* Returns: none
*/
void arr_to_file(int arr[], ofstream &file)
{
    int temp = 0;
    for (int i = 0; i < 9; i++)
    {
        temp = arr[i];
        file << temp << " ";
    }
}

/*
* Function name: print_arr()
* Purpose: Prints out the integers within an array
* Arguments: integer array
* Returns: none
*/
void print_arr(int arr[])
{
    for(int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

/*
* Function name: print_all()
* Purpose: To print out the sorted arrays
* Arguments: integer arrays
* Returns: none
*/
void print_all(int num_arr[], int early_arr[], int mid_arr[], int end_arr[])
{
    cout << endl;

    cout << "num_o.txt list: ";
    print_arr(num_arr);

    cout << "early_o.txt list: ";
    print_arr(early_arr);

    cout << "mid_o.txt list: ";
    print_arr(mid_arr);

    cout << "end_o.txt list: ";
    print_arr(end_arr);
}

/*
* Function name: validate()
* Purpose: Validates the user's input
* Arguments: referenced integer
* Returns: none
*/
void validate(int &value)
{
    cout << "\nPlease enter a target to search for (No spaces): ";
    cin >> value;

    while(cin.fail())
    {
        cout << "\nPlease try again: ";
        cin >> value;
        cin.clear();
        cin.ignore(9999, '\n');
    }
}

/*
* Function name: play_again()
* Purpose: Asks the player if they want to play again
* Arguments: referenced integer
* Returns: none
*/
void play_again(int &again)
{
    int option;
    char buffer[100];

    do
    {
        cout << "\nDo you want to play again? (No spaces)" << endl;
        cout << "\t1) Yes" << "\t2) No" << endl;
        cout << "Enter: ";
        cin >> buffer;

        option = atoi(buffer);

        if(option < 1 || option > 2) { cout << "\nPlease try again." << endl; }

        else if(option == 1) { again = 1; }

        else if(option == 2) { cout << "\nBye bye" << endl; again = 2; }

    } while(option < 1 || option > 2);
}

/*
* Function name: linear_search()
* Purpose: Searches through array to find a value
* Arguments: integer array, integers
* Returns: integer
* Cited Works: Lectures: Searching and Sorting - Introduction to Searching
*/
int linear_search(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == val)
        {
            cout << "target found" << endl;
            return i;
        }
    }

    cout << "target not found" << endl;
    return -1;
}

/*
* Function name: binary_search()
* Purpose: Searches through array to find a value
* Arguments: integer array, integers
* Returns: integer
* Cited Works: Lectures: Searching and Sorting - Introduction to Searching
*/
int binary_search(int arr[], int size, int val)
{
    int low = 0;
    int high = size - 1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        int diff = arr[mid] - val;

        if(diff == 0)   //as in arr[mid] == val
        {
            cout << "target found" << endl;
            return mid;
        }

        else if (diff < 0 ) //as in arr[mid] < val
        {
            low = mid + 1;
        }

        else 
        {
            high = mid - 1;
        }
    }
    cout << "target not found" << endl;
    return -1;
}

/*
* Function name: bubble_sort()
* Purpose: Sorts integers from least to greatest
* Arguments: integer array, integer
* Returns: none
* Cited Works: Lectures: Searching and Sorting - Bubble Sort
*/
void bubble_sort(int arr[], int size)
{
    for(int i = (size - 1); i > 0; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            if(arr[j - 1] > arr[j])
            {
                //swap elements at j - 1 and j
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] =  temp;
            }
        }
    }
}