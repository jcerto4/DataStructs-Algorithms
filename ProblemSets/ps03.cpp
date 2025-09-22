// ps03.cpp
// Test driver class
#include <iostream>
#include "ThreeState.h"

using namespace std;

int main() {
    ThreeState btn1 = ThreeState();

    // Test the ThreeState button class
    cout << btn1.state() << endl;
    cout << btn1 << endl;
    cout << btn1.up() << endl;
    cout << btn1.up() << endl;
    cout << btn1.up() << endl;
    cout << btn1.up().down() << endl;
    cout << btn1.up().down().down() << endl;
    cout << btn1.up().down().up().down().up() << endl;

    ThreeState btn2( btn1 );
    cout << btn2 << endl;

    return 0;
}