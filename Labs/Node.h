//Joe Certo
//9/18/2025
//Node.h
//This template class can hold any data type, and can be linked together

#ifndef NODE_H
#define NODE_H

template <class T>
class Node{

public:
    T data;
    Node<T> *next = nullptr;
    Node() {} //default constructor, per Lab requirments no delegation
    Node(const T data) {
        this->data = data;
    }
};





#endif 