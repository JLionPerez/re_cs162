/*
* File name: frequency.hpp
* Purpose: To hold definitions for prototypes in frequency.cpp
*/

#ifndef FREQUENCY_HPP
#define FREQUENCY_HPP

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstring>
using std::string;

#include <string>
using std::getline;

#include <cctype>
#include <cstdio>
#include <fstream>

void count_letters(ifstream &file, int* arr);
void output_letters(ofstream &file, int* arr);

#endif