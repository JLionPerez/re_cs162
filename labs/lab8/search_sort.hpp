/*
* File name: search_sort.hpp
* Purpose: Holds prototypes for search_sort.cpp
*/

#ifndef SEARCH_SORT_HPP
#define SEARCH_SORT_HPP

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::fstream;

#include <cstdlib>

//files to array and arrays to file
void file_to_arr(int arr[], ifstream &file);
void arr_to_file(int arr[], ofstream &file);

//display information
void print_arr(int arr[]);
void print_all(int num_arr[], int early_arr[], int mid_arr[], int end_arr[]);

void validate(int &value);
void play_again(int &again);

//simple search
int linear_search(int arr[], int size, int val);

//binary search
int binary_search(int arr[], int size, int val);

//sorting
void bubble_sort(int arr[], int size);

#endif