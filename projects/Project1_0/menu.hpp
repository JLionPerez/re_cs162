/*
* File name: menu.hpp
* Purpose: Holds prototypes for definitions in menu.cpp.
*/
#ifndef MENU_HPP
#define MENU_HPP
#include "ant.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

void ant_info(int** board, Ant &a, int width, int length);
int start_menu(int &option);
void menu(int** &board, int &width, int &length);   //main menu
int end_menu(int** &board, int &option);

int validate_int(const char* str, int min, int max);    //validates ints

bool validation(int width, int length);     //also validates ints but returns bools

void allocate_board(int** &board, int width, int length);
void initial_board(int** &board, int width, int length);
void cover_board(int** board, int width, int length, Ant a);

void delete_board(int** board, int width, int length);

#endif