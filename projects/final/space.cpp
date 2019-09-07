#include "space.hpp"

Space::Space()
{
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    friends = nullptr;
}

Space* Space::get_top() { return top; }

void Space::set_top(Space* top) { this->top = top; }

Space* Space::get_bottom() { return bottom; }

void Space::set_bottom(Space* bottom) { this->bottom = bottom; }

Space* Space::get_left() { return left; }

void Space::set_left(Space* left) { this->left = left; }

Space* Space::get_right() { return right; }

void Space::set_right(Space* right) { this->right = right; }

string Space::get_name() { return name; }

void Space::set_name(string name) { this->name = name; }