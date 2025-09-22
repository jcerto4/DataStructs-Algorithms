// ps02.cpp

// CSC 230 - Problem Set 2
// Complete all questions below.

#include <iostream>
#include <string>

using namespace std;

void addTax(double& price);
void pluralize(string* thing);

int main(int argc, char* argv[]) {

    double prices[] = {5.29, 10.01, 11.11, 0.29, 4.00};

    // 1) Print the memory address of the first element of the prices array 
    //    using no operators other than insertion (<<).
    cout << prices << endl;

    // 2) Print the memory address of the first element of the prices array
    //    using both the & operator and the [] operator.
    cout << &prices[0] << endl;

    // 3) Print the second element of prices using the [] operator.
    cout << prices[1] << endl;

    // 4) Print the second element of prices without using the [] operator.
    //    You may use the * and + operators.
    cout << *(prices + 1) << endl;

    // 5) Write a loop that prints all elements of prices without using the [] operator.
    //    You may use * and ++ operators only (not +) and any other variable you like.
    double* pp = prices;
    for(int i = 0; i < 5; i++){
        cout << *pp << " ";
        pp++;
    }
    cout << endl;

    // 6) Declare a double named 'x' on the stack and init to 5.29.
    //    Print x.
    double x = 5.29;
    cout << x << endl;

    // 7) Dynamically allocate a double on the heap and init to 11.11.
    //    Assign to a variable named px. Print px and the value it points to.
    double* px = new double(11.11);
    cout << px << " " << *px << endl;


    // 8) Overwrite the memory pointed to by px with the value of x.
    //    Print the value that px points to.
    *px = x;
    cout << *px << endl;

    // 9) Dynamically allocate another double on the heap and init to the value
    //    pointed to by px. Assign to a variable named py.
    //    Print py and the value it points to.
    double* py = new double(*px);
    cout << py << " " << *py << endl;


    // 10) Delete both dynamically allocated doubles at px and py.
    delete px;
    delete py;

    // 11) Dynamically allocate an int on the heap but do not initialize it.
    //     Assign to the variable named pa.
    int* pa = new int;

    // 12) Declare an int* named pb and assign to the same address as pa.
    //     Print both addresses.
    int* pb = pa;

    cout << pb << " " << pa << endl;

    // 13) Delete pa. What is pb called?
    delete pa;
    //pb is now pointing to a memory location that is invalid

    // 14) Declare three strings on the heap named pclr1, pclr2 and pclr3.
    //     Init each to the name of a different color and print all three.

    string *pclr1 = new string("White");
    string *pclr2 = new string("Black");
    string *pclr3 = new string("Green");

    cout << *pclr1 << " " << *pclr2 << " " << *pclr3 << endl;

    // 15) Declare an array of string pointers named colors on the stack
    //     and init with the pclr1, pclr2, and pclr3
    string *colors[] = {pclr1, pclr2, pclr3};

    // 16) In a loop, print the string length and the first character of each color.
    //     Use the -> operator in your solution.
    for(int i = 0; i < 3; i++){
        cout << colors[i]->length() << " " << colors[i]->at(0) << endl;  
    }
    
    // 17) Previously you declared the variable x. Declare a new variable named x2
    //     that is a reference to x. Print the address of x and x2.
    double& x2 = x;
    cout << &x << " " << &x2 << endl;

    // 18) Below main() define a new function with the signature void addTax(double& price).
    //     This void function adds 6.625% sales tax to the double passed as an argument.
    //     Add tax to the original variable, and return nothing (void).
    //     You do not have to round the result to the nearest penny.
    //     Test your new function by call it one or more times. 
    //     Print price before and after.
    cout << x << endl;
    addTax(x);
    cout << x << endl;
    addTax(x);
    cout << x << endl;
    // 19) Below main() define a new function with named void pluralize(string* thing).
    //     This void function adds an "s" to the end of any string it is passed.
    //     Declare one or more strings and pluralize them.
    //     Print strings before and after.
    string c = "cat";
    cout << c << endl;
    pluralize(&c);
    cout << c << endl;

    // 20) Read the first argument from the command line, convert to an int,
    //     multiply by 2, and print the result.
    int num = atoi(argv[1]);
    cout << (num*2) << endl;

    return 0;
}

  void addTax(double& price){
        price = price + (price * 0.06625);
    }

  void pluralize(string* thing){
        thing->append("s");
    }
