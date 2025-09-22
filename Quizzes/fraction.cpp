// fraction.cpp
#include <iostream>
#include "fraction.h"

using namespace std;

int main() {

    try {
        fraction a(1, 2), b(4);
        cout << a << " + " << b << " = " << (a + b) << endl;
        cout << a << " - " << b << " = " << (a - b) << endl;
        cout << a << " * " << b << " = " << (a * b) << endl;
        cout << a << " / " << b << " = " << (a / b) << endl;
        cout << -a << " " << a << endl;
        
        cout << a << " += " << b << endl;
        a += b;
        cout << a << endl;

        fraction z(0);
        cout << a / z << endl;
        
    } catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}