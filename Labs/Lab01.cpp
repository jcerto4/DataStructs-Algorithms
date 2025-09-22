//Lab01.cpp
//Joe Certo
//8-28-2025
//This program prints the hailstone sequence starting from a user-input positive integer

#include <iostream>

using namespace std;

void printHailstone(int n){
    //Print the hailstone sequence starting at n
    //Count variable to track the numbers printed and insert a newline every 10 numbers
    //While loop to continue until n is 1
    int count = 0;
    while(n != 1){
        cout << n << "\t";
        count++;
        if(n % 2 == 0){
        n = n / 2;
     }else{
        n = 3 * n + 1;
    }
    //Prints newline every 10 numbers
    if(count % 10 == 0){
        cout << endl;
    }
  }
  cout << n << endl;
}

int main(){
    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;
    printHailstone(n);
    return 0;
}