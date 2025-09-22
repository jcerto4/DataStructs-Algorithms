//Joe Certo
//9/18/2025
//Lab04.cpp
//Program used to test new Node class
//Firstly, we create three strings "Lather", "Rinse", "Repeat"
//We link them together in a circle
//Then we iterate 30 times, printing each as we move from Node to Node
//We then repeat but with double values to ensure our template class functions correctly

#include <iostream>
#include "Node.h"

using namespace std;

int main(){
    Node<string> n1("Lather");
    Node<string> n2("Rinse");
    Node<string> n3("Repeat");

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n1;

    Node<string>* pnode = &n1;

    for(int i = 0; i < 30; i++){
        cout << pnode->data << endl;
        pnode = pnode->next;
    }
    cout << endl;

    Node<double> d1(3.14);
    Node<double> d2(2.71);
    Node<double> d3(1.41);

    d1.next = &d2;
    d2.next = &d3;
    d3.next = &d1;

    Node<double>* dnode = &d1;

    for(int i = 0; i < 30; i++){
        cout << dnode->data << endl;
        dnode = dnode->next;
    }

    return 0;
}
