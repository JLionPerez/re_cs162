#ifndef MENU_HPP
#define MENU_HPP
#include "ant.hpp"

void ant_info(int** board, Ant &a, int width, int length);
int start_menu(int &option);
void menu(int** &board, int &width, int &length);
int end_menu(int** &board, int &option);

int validate_int(); // working progress

bool validation(int width, int length);

void allocate_board(int** &board, int width, int length);
void initial_board(int** &board, int width, int length);
void cover_board(int** board, int width, int length, Ant a);
void print_board(int** board, int width, int length, Ant a);

//void borders_board(int** board, int width, int length);

void delete_board(int** board, int width, int length);

#endif