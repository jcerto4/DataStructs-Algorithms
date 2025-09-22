// Lab03A.cpp
//Joe Certo
//9/11/2025
//This program demonstrates passing by value, passing by refernece, and passing by pointer
#include <iostream>
using namespace std;

// Double an argument passed by value and return the doubled value
double doubleIt1(double v) {
    v = 2.0*v;          // Uh oh, v is reassigned. Does that matter here?
    return v;
}

// Double the value referenced by v
void doubleIt2(double &v) {
    v = 2.0*v;          // Uh oh, there is no return value. Is this function broken?
}

// Double the value at pv
void doubleIt3(double *pv) {
    (*pv) = 2.0*(*pv);  // What the heck is this?
}

// Main method
// The output from this program should be 2 4 8 .

int main() {

    double v = 1.0;
    cout << v << endl;

    // 1) Double the value of v using doubleIt1.
    v = doubleIt1(v); //Passing by value

    cout << v << " ";

    // 2) Double the value of v using doubleIt2.
    doubleIt2(v); //Passing by reference

    cout << v << " ";

    // 3) Double the value of v using doubleIt3.
    doubleIt3(&v); //Passing by pointer

    cout << v << endl;

    return 0;
}