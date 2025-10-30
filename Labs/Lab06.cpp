// Lab06.cpp
// Name: ...
// Date: ...
// Description: ...

#include <iostream>
#include "Node.h"

using namespace std;

// Test Node functions
int main() {
    // Build a list of Nodes
    Node<string> *first, *last, *pnode;
    first = new Node<string>("maple");
    pnode = insert_after<string>(first, "oak");
    last  = insert_after<string>(pnode, "willow");

    // Woops. birch should be second. Insert that now.
    insert_after<string>(first, "birch");

    // Print the Node list starting at first
    cout << *first << endl;

    // Insert a new Node before first and update the first pointer
    first = insert_before<string>(first, "pine");
    cout << *first << endl;

    // Insert a new node before last
    insert_before<string>(last, "elm");
    cout << *first << endl;

    // Erase two penultimate Nodes from list
    erase<string>(last->prev);
    erase<string>(last->prev);
    cout << *first << endl;

    // Erase the first and last and update pointers
    Node<string>* tmp = first->next;
    erase<string>(first);
    first = tmp;

    tmp = last->prev;
    erase<string>(last);
    last = tmp;

    // Print what's left
    cout << *first << endl;

    return 0;
}
