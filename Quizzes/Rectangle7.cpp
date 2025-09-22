// Rectangle7.cpp
// Implements all Rectangle methods
#include <iostream>
#include "Rectangle7.h"

// All methods must be scoped to Rectangle class with ::

// Constructor implementations
Rectangle::Rectangle(int w, int h) {
    width  = w;
    height = h;
    id = ++count;   // Increment count
};

// Method implementations
void Rectangle::set_size(int width, int height) {
    this->width  = width;
    this->height = height;
};
void Rectangle::set_size(int length) {
    this->width  = length;
    this->height = length;
};
int Rectangle::get_area() const {
    return width*height;
}
int Rectangle::get_id() const {
    return id;
}

// Declare static member of Rectangle
int Rectangle::count;

// Overload the Stream Insertion operator
std::ostream& operator<<(std::ostream& os, const Rectangle &r) {
    os << "Rectangle: id=" << r.get_id() << " (" << r.width << "x" << r.height << ")";
    return os;
}

