// Lab03B.cpp
//Joe Certo
//9/11/2025
//This program fills and prints arrays 
//showing the difference between stack and heap arrays
//using indexing vs pointer arithmetic, 
//and how arrays decay to pointers when passed to functions
#include <iostream>
using namespace std;

// Print all elements of the array "arr" on one line
void printArr(float arr[], int len) {
    
    // 1) Write a for-loop and anything else you need to complete the function.
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}

// Set all elements of the array at "arr" with length "len" to "val." 
void fillArr1(float *arr, int len, float val) {
    
    // 2) Write a for-loop and anything else you need to complete the function.
    //    You MUST use [] to access array elements.
    for(int i = 0; i < len; i++){
        arr[i] = val;
    }
    
}

// Set all elements of the array at "arr" with length "len" to "val." 
void fillArr2(float *arr, int len, float val) {
    
    // 3) Write a for-loop and anything else you need to complete the function.
    //    You MAY NOT use [] to access array elements.
    for(int i = 0; i < len; i++){
        *(arr + i) = val;
    }
    
}

// Main method
// The output from this program should be
// 1.2 1.2 1.2 1.2 1.2 
// 1.3 1.3 1.3 1.3 1.3
// 1.4 1.4 1.4 1.4 1.4

int main() {

    // Declare a float array on the stack
    float arr1[5];

    // Declare a float array on the heap
    float *arr2 = new float[5];

    // Fill array with 1.2 and print
    fillArr1(arr2, 5, 1.2);
    printArr(arr2, 5);

    // Fill array with 1.3 and print
    fillArr2(arr1, 5, 1.3);
    printArr(arr1, 5);

    // Fill array with 1.4 and print
    fillArr2(&arr1[0], 5, 1.4);
    printArr(arr1, 5);

    // 4) Explain why the above function call works with the first argument &arr[0]
    /*
        The above function call works with the first argument &arr[0]
        because in C++, array names decay to pointers to the first element.
        By passing &arr1[0] we are explicitly passing the memory address of
        the first element of the float array which the float *arr parameter is waiting for.
        Passing arr1 and &arr1[0] are equivalent, as in C++ array names decay to 
        pointers to the first elements memory location.
        From there, the function can use pointer arithmetic to iterate through the array.
    */

    return 0;
}