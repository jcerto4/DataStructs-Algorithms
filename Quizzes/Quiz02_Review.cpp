// Quiz2_review.cpp
#include <iostream>
#include <string>
using namespace std;

// Increment first by second given pointers
void increment(double* px, double dx) {
    *px = *px + dx;
}

// Increment first by second given references
void increment(double& x, double dx) {
    x = x + dx;
}

int main() {
    
    int arr[] = {1, 2, 3, 4, 5};
    int i = 0, len = 5;

    // Arrays implement the element access operator []
    for (i=0; i<len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // When calculating the result of a pointer expression, 
    // the compiler multiplies the operand by the size of the element stored. 
    // This is called "pointer scaling."

    // Pointer arithmetic is used to offset storage location by the size of an element.
    // Array names "decay to" the address of the first array element
    int *parr = arr;
    for (i=0; i<len; ++i) {
        cout << *parr << " ";
        parr++;
    }
    cout << endl;

    // You may access an array element using array name that has decayed to a pointer to first element.
    // Unlike pointer variables, array names may NOT be reassigned.
    for (i=0; i<len; ++i) {
        cout << *(arr+i) << " ";  // Same thing as arr[i]
    }
    cout << endl;

    // The pointer ++ operator also "scales" the pointer value by element size.
    parr = &arr[0];
    for (i=0; i<len; ++i) {
        cout << *parr << " ";
        //++parr;
        parr = parr + 1;
    }
    cout << endl;

    // Other arithmetic operators may be used to offset an array address or modify a pointer variable.
    // These include +, - ++, --, +=, -=, ...

    // The [] operator can be used on pointers to offset the number of elements
    // arr[2], parr[2], *(parr+2) access the same element
    parr = arr;
    cout << parr[2] << " " << arr[2] << " " << *(parr + 2) << endl;

    // A reference to a variable is just another name for the same variable.
    // A reference MUST be initialized at the time of declaration.
    // A reference may be used any place that the original variable is used
    double x = 3.14;
    double& pi = x;

    if (x == pi)   { cout << "same values" << endl;}
    if (&x == &pi) { cout << "same addresses (pointer values)" << endl;}

    // Update x by pointer
    double* px = &x;
    cout << x << endl;

    // Change by pointer
    increment(px, 10);
    cout << x << endl;

    // References are useful when passing variables to functions with intention
    // of changing original variable.
    
    // Change by reference
    increment(x, 10);
    cout << x << endl;

    // We can hold arrays of pointers
    int age1 = 20;
    int age2 = 22;
    int age3 = 23;
    int *ages[] = {&age1, &age2, &age3};

    // Loop over array of pointers and access each pointer and each element by value
    for (int i=0; i<3; i++) {
        cout << *ages[i] << " is stored at " << ages[i] << endl;
    }

    return 0;
}