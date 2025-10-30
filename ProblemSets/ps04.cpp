// ps04.cpp
#include <iostream>
#include <string>

// TODO: Add any necessary STL data structure includes
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>

using namespace std;

void q01() {
    // TODO: 
    // Declare an array of three ints on the call stack.
    // In separate statements, assign values -3, -2, -1 to indexes 0, 1, 2, in that order.
    // Write a loop that prints all values of the array the same line. Do not assume size of array.
    array<int, 3> arr;
    arr[0] = -3;
    arr[1] = -2;
    arr[2] = -1;
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << *it << " ";
    }

    cout << endl;

}

void q02() {
    // TODO:
    // Declare a vector of chars on the heap.
    // One at a time, add the chars 'T', 'C', 'N', and 'J' to the back.
    // Using a loop and an iterator, print all chars on same line, no spaces. Do not assume size.
    // Using a while loop, access each character at end of vector using an iterator
    // Then pop char off end and repeat until no chars remain. 
    // Do not assume size.
    vector<char>* vec = new vector<char>;
    vec->push_back('T');
    vec->push_back('C');
    vec->push_back('N');
    vec->push_back('J');
    
    for(auto it = vec->begin(); it != vec->end(); it++){
        cout << *it;
    }

     cout << endl;

    while(!vec->empty()){
        auto it = vec->end();
        --it;
        cout << *it;
        vec->pop_back();
    }

     cout << endl;

}

void q03() {
    // TODO:
    // Declare a stack of chars on the call stack.
    // Push the chars 'T', 'C', 'N', and 'J' on to the stack, in order.
    // Use a while loop to print the char at the top of the stack on the same line.
    // Pop the top of the stack and repeat until the stack is empty.
    // How does the order of the output compare to the order input?
        //The order of output is opposite that of the order of input,
        //last in, first out
    stack<char> stack;
    stack.push('T');
    stack.push('C');
    stack.push('N');
    stack.push('J');

    while(!stack.empty()){
        cout << stack.top();
        stack.pop();
    }

     cout << endl;
}

void q04() {
    // TODO:
    // Declare a queue of chars on the call stack.
    // Repeat the task from q03, replacing top() with front()
    // How does the order of the output compare to the order input?
        //The order of output is the same as the order of input,
        //first in, first out
    
    queue<char> queue;
    queue.push('T');
    queue.push('C');
    queue.push('N');
    queue.push('J');

    while(!queue.empty()){
        cout << queue.front();
        queue.pop();
    }

     cout << endl;
}

void q05() {
    // TODO:
    // Declare a list of string on the heap.
    // To the back of the list push the strings "left" and "down", in that order.
    // To the front of the list push the strings "right" and "up", in that order.
    // Use a loop and an iterator to print all list strings in order on the same line.
    // Use a loop and a reverse iterator to print all list strings in reverse on the same line.
    // Use the functions rbegin and rend for the reverse print.
    list<string>* arrows = new list<string>;
    arrows->push_back("left");
    arrows->push_back("down");
    arrows->push_front("right");
    arrows->push_front("up");

    for(auto it = arrows->begin(); it != arrows->end(); it++){
        cout << *it << " ";
    }

    cout << endl;

    for(auto it = arrows->rbegin(); it != arrows->rend(); it++){
        cout << *it << " ";
    }

     cout << endl;

}

void q06() {
    vector<string> insulinA {"Gly","Ile","Val","Glu","Gln","Cys","Cys","Asn","Ser","Arg","Glu","Leu","Gln","Ala","Tyr","Leu","Val","Cys","Gly","Glu","Arg","Gly","Phe","Phe","Tyr","Thr","Pro","Lys","Thr"};
    vector<string> insulinB {"Val","His","Leu","Phe","Arg","Cys","Asp","Ser","Gly","Ser","His","Leu","Val","Glu","Ala","Leu","Tyr","Leu","Val","Cys","Gly","Glu","Arg","Gly","Phe","Phe","Tyr","Thr","Pro","Lys","Thr"};

    // TODO:
    // Answer the question, What are the amino acids in both chains of insulin?
    // Create a set of strings on the call stack;
    // Iterate over both strings above and add each string to the set.
    // Print all elements of the final set on the same line.
    set<string> acids;

    for(string a : insulinA){
       acids.insert(a);
    }

    for(string b : insulinB){
        acids.insert(b);      
    }

    for(string acid : acids){
        cout << acid << " ";
    }

     cout << endl;

}

void q07() {
    // apple: 72, banana: 105, carrots: 52, bread: 66
    // oatmeal: 147, pizza: 298, chicken: 142, egg: 102

    // TODO:
    // Create a map named cals on the call stack that maps string to int.
    // Fill the map with the previous food names paired with calories of each.
    // Calculate calories for the following meals.
    // meal1: a chicken sandwich on two slices of bread and an apple
    // meal2: two eggs and oatmeal
    // meal3: one slice of pizza and carrots
    map<string, int> cals;
    cals["apple"] = 72;
    cals["banana"] = 105;
    cals["carrots"] = 52;
    cals["bread"] = 66;
    cals["oatmeal"] = 147;
    cals["pizza"] = 298;
    cals["chicken"] = 142;
    cals["egg"] = 102;

    int meal1 = cals["chicken"] + (2 * cals["bread"]) + cals["apple"];
    int meal2 = (2 * cals["egg"]) + cals["oatmeal"];
    int meal3 = cals["pizza"] + cals["carrots"];

    cout << "Meal 1: " << meal1 << endl; //Expected value: 346
    cout << "Meal 2: " << meal2 << endl; //Expected Value: 351
    cout << "Meal 3: " << meal3 << endl; //Expected Value: 350

}

int main() {
    // Complete all following functions as specified in comments of each.
    q01();
    q02();
    q03();
    q04();
    q05();
    q06();
    q07();

    return 0;
}