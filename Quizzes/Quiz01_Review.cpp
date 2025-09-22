// Quiz01_Review.cpp
// Answer each of the ?) questions below.

#include <iostream>
// ?) What is the name of the program that processes lines like #include?
//Preprocessor
// ?) What is the significance of the angle brackets surrounding <iostream>?
//The significance of the angle brackets is that they tell the preprocessor to look for the iostream from the standard library
// ?) What would change if we replaced <> with ""?
//If we replaced the angle brackets with quotations, the preprocessor would look for the iostream file in the current directory
// ?) Name a few of the predefined objects that are available as a result of #include <iostream>
//A few predefined objects that are availble as a result of #include <iostream> are cout, cin, and endl
using namespace std;
// ?) What is std called?
//The std is called the standard namespace
// ?) What are cin, cout, and endl?
//Cin is the standard input, cout is the standard output, and endl is the end line character
// ?) How would you have to access the cout object if the "using" line was not included?
//If the "using" line was not included, you would access the cout object using std::cout
// ?) What is the "::" operator and what does it do?
//The "::" operator is the scope resolution operator and it tells the compiler to look for the object in a specific namespace

// ?) What are the following lines called and why do we need them?
//The following lines are forward-declarations and we need them so the compiler knows about the functions before they are used
// ?) What would the C++ compiler do if we did not include these lines?
//If we did not include these function declarations, the compiler would throw an error when it encounters the function calls in the main() because the preprocessor proccesses top to bottom 
// ?) How could we rearrange the program to make it compile successfully without the following lines?
float sum_array(float x[], int n);
void fill_array(float x[], int n);
//We could rearrange the program by moving the function definitions above the main() function

// ?) What is the significance of the function signature "int main()"?
//The significance of the function signature "int main()" is that the program execution starts from the main() function
// ?) What does the leading "int" tell us about the main() function?
int main() {
    //The leading "int" tells us the return type of the main() function is an integer

    float z[] = {1., 2., 3., 4.};   // ?) How much memory is set aside for the z array?
    //There is 16 bytes of memory set aside for the z array
                                    // ?) What values are now stored in each of the z array locations?
    //The values stored in each of the z array locations are 1.0, 2.0, 3.0, and 4.0
    int y[3] = {};                  // ?) How much memory is set aside for the y array?
    //There is 12 bytes of memory set aside for the y array
                                    // ?) What values are stored in each of the y array locations?
    //The values stored in each of the y array locations are 0, 0, and 0
    float x[10];                    // ?) How much memory is set aside for the x array?
    //There is 40 bytes of memory set aside for the x array
                                    // ?) What values are stored in each of the x array locations?
    //The values stored in each of the x array locations are uninitialized garbage values
    cout << z << endl;              // ?) How many values are printed by this line?
    //There is only one value printed by this line and it is the memory address of the first element in the z array
                                    // ?) What is the significance of what is printed by the previous?
    //The significance of what is printed is that it is the memory address of the first element in the array
                                    // ?) What is the format of what is printed?
    //The format of what is printed is a hexadecimal representation of the memory address
    float result = sum_array(z, 4);
    cout << result << endl;         // ?) What is printed by this line?
    //The value printed by this line is 10, it is the sum of all the elements in the z array

    // ?) What are the "<<" and ">>" operators called?
    //The "<<" is the insertion operator, and ">>" is the extraction operator
    // ?) What do these operators do?
    //The insertion operator is used to send data to the output stream, and the extraction operator is used to get data from the input stream
    // ?) Why is it possible the chain the << operator?
    //It is possible to chain the << insertion operator because it returns the output stream object, allowing for multiple insertions in a single statement

    fill_array(x, 10);
    cout << x[2] << endl;
    // ?) Do you know the value printed by the line above? If so, what is it?
    //The value printed by the line above is 4.0
    // ?) Why is this value printed when the fill_array() function has no return value?
    //This value is printed because the function fill_array() modifies the contents of the array, and then we print the value at index 2 using cout

    return 0;
}

// ?) To what does the "a" parameter get assigned when this function is invoked?
//The "a" parameter get assigned to the memory address of the first element in the array that is passed to the function
// ?) Could we rewrite this function without the nitems parameter? Why or why not?
//We could not rewrite this function without the nitems parameter because the function would not know how many elements are in the array
float sum_array(float a[], int nitems) {
    float sum = 0;
    for (int i=0; i<nitems; ++i) {
        sum += a[i];
    }
    return sum;
}

// ?) Why isn't the b[] array parameter declared with an initial size, like b[10]?
//The b[] array parameter is not declared with an initial size because in C++, when passing arrays to functions, the size is not required and the function can work with any array
void fill_array(float b[], int nitems) {
    for (int i=0; i<nitems; ++i) {
        b[i] = 2.*i;
    }
}
