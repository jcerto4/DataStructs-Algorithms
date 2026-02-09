//Joe Certo
//10/29/2025
//BST.h
//The purpose of this is to create a node and bst class to insert and search a tree recursievly

#ifndef BST_H
#define BST_H

template <typename T>
class Node {
public:
    T data;
    Node* left  = nullptr;
    Node* right = nullptr;
    
    Node() {}
    Node(const T& data){
        this->data = data;
    }
};

template <typename T>
class BST {
private:
    Node<T>* root = nullptr;
    Node<T>* insert(Node<T>* current, T val){
        if(current == nullptr) return new Node<T>(val); 
        if(val < current->data){
            current->left = insert(current->left, val);
        } 
        if(val > current->data) {
            current->right = insert(current->right, val);
        }
        return current;
    }
    Node<T>* search(Node<T>* current, T val){
        if(current == nullptr) return nullptr;
        if(current->data == val) {
            return current;
        }else if(val < current->data) {
            return search(current->left, val);
        }else{
            return search(current->right, val);
        }
    }
public:
    BST() {}
    void insert(T val){
        root = insert(root, val);
    }
    bool search(T val){
        return search(root, val) != nullptr;
    }

};


#endif