//Joe Certo
//10/11/2025
//Node.h
//This template class can hold any data type, and can be linked together

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <class T>
class Node{

public:
    T data;
    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;
    Node() {} //default constructor, per Lab requirments no delegation
    Node(const T data) {
        this->data = data;
    }
};

template <class T>
Node<T>* insert_after(Node<T>* n, const T &data){
    
    if(n == nullptr) return nullptr;
    
    Node<T>* newNode = new Node<T>(data);
    newNode->next = n->next;
    newNode->prev = n;
    if(n->next != nullptr) n->next->prev = newNode;
    n->next = newNode;

    return newNode;

}

template <class T>
Node<T>* insert_before(Node<T> *n, const T &data){
   
    if(n == nullptr) return nullptr;
    
    Node<T>* newNode = new Node<T>(data);
    newNode->prev = n->prev;
    newNode->next = n;
    if(n->prev != nullptr) n->prev->next = newNode;
    n->prev = newNode;

    return newNode;

}

template <class T>
void erase(Node<T> *n){

    if(n == nullptr) return;

    if(n->prev != nullptr){
        n->prev->next = n->next;
    }

    if(n->next != nullptr){
        n->next->prev = n->prev;
    }

    delete n;

}

template <class T>
ostream& operator<<(ostream& os, const Node<T>& n){
    os << "[";
    const Node<T>* pNode = &n;
    while(pNode != nullptr){
        os << pNode->data;
        if(pNode->next != nullptr) os << ", ";
        pNode = pNode->next;
    }
    os << "]";
    return os;
}



#endif 