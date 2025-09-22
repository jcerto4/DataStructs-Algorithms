// Rectangle7.h
#ifndef RECTANGLE7_H    // Include only if not already defined 
#define RECTANGLE7_H

#include <iostream>

class Rectangle {
private:
    int width;
    int height;
    int id;             // Unique id
public:
    static int count;   // Track Rectangle count

    // Constructors
    Rectangle() : Rectangle(3, 4) {}    // Inline
    Rectangle(int w, int h);            // Forward declaration

    // Destructor
    ~Rectangle() {}                     // Inline

    // Method signatures
    void set_size(int width, int height);
    void set_size(int length);
    int get_area() const;
    int get_id() const;

    // Allow following method signature to access object
    friend std::ostream& operator<<(std::ostream& os, const Rectangle &r);
};

#endif