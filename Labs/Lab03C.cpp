// Lab03C.cpp
//Joe Certo
//9/11/2025
//This program demonstrates function overloading, 
//creating strings on the stack vs heap, 
//and passing strings by reference or pointer
#include <iostream>
#include <string>
using namespace std;

// Return the first string char using the at() method
char getFirstChar(string &s) {
    cout << "first overload" << endl;

    // 3) Get and return the first character of the string s
    return s.at(0);
}

char getFirstChar(string* ps) {
    cout << "second overload" << endl;

    // 4) Get and return the first character of the string pointer ps
    return ps->at(0); //We can also use (*ps).at(0); these are equivalent
}

// Main function
int main() {

    // 1) Declare a string variable named fruit1 ON THE STACK and init to "Apple"
    string fruit1 = "Apple";

    // 2) Declare a string pointer variable named fruit2 with a string ON THE HEAP and init to "Banana"
    string* fruit2 = new string("Banana");

    // Call two overloads
    cout << getFirstChar(fruit1) << endl;
    cout << getFirstChar(fruit2) << endl;

    return 0;
}
