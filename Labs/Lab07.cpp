// Lab07.cpp
//Joe Certo
//10/21/2025
//Test Program for str_tbl hash table template class

#include <iostream>
#include "str_tbl.h"
using namespace std;

int main() {
    str_tbl<int> tbl(5); // Fruit calories
    tbl.insert("apricot", 22);
    tbl.insert("apple", 95);
    tbl.insert("banana", 111);
    tbl.insert("fig", 30);
    tbl.insert("guava", 7);
    tbl.insert("peach", 59);
    tbl.insert("pear", 101);
    tbl.insert("pinapple", 453);
    tbl.display(cout);
    cout << "Load factor: " << tbl.load_factor() << endl;
    cout << "Size: " << tbl.size() << endl;
    cout << endl;
    cout << "Searching for 'banana': ";
    int* val = tbl.search("banana");
    if (val) {
        cout << *val << endl;
    } else {
        cout << "Not found" << endl;
    }
    cout << "Searching for 'grape': ";
    val = tbl.search("grape");
    if (val) {
        cout << *val << endl;
    } else {
        cout << "Not found" << endl;
    }
    cout << endl;
    tbl.remove("banana");
    cout << "Hash Table after removing 'banana':" << endl;
    tbl.display(cout);
    cout << "Load factor: " << tbl.load_factor() << endl;
    cout << "Size: " << tbl.size() << endl;


    //Testing updating values of exisiting keys in the hash table
    tbl.insert("apple", 99);
    tbl.display(cout);
    cout << tbl.size() << endl;
    return 0;
}