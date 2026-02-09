
// A Huffman Tree node
#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H

#include <sstream>
using namespace std;

class Node {
public:
    static int count;
    char   ch;               // Character represented by this node
    double freq;             // Frequency with which the character appears in the string
    Node*  left  = nullptr;  // Pointer to left Node, if there is one
    Node*  right = nullptr;  // Pointer to right Node, if there is one
    int    id;               // Unique ID of Node

    // Constructors
    Node() : Node('\0', 0.0) { }
    Node(char ch, double freq) : Node(ch, freq, nullptr, nullptr) { }
    Node(char ch, double freq, Node* left, Node* right) {
        this->ch    = ch;
        this->freq  = freq;
        this->left  = left;
        this->right = right;
        this->id    = ++count;
    }

    // Overload the function call operator (operator()) for priority queue ordering
    // Causes this class to become a FunctionObject type. 
    bool operator() (const Node* n1, const Node* n2) {
        return n1->freq > n2->freq;
    }

    // Utility to check if Node is leaf
    bool isLeaf() {
        return this->left == nullptr && this->right == nullptr;
    }

    // Build and return a GraphViz string for all edges starting at this node
    string toGraphviz() {
        ostringstream ss, spar, sleft, sright;

        char c = this->ch == '\0'? ' ': this->ch;
        char l = this->left->ch == '\0'? ' ': this->left->ch;
        char r = this->right->ch == '\0'? ' ': this->right->ch;

        spar   << "\"" << c << ":" << this->freq        << " (" << this->id << ")\"";
        sleft  << "\"" << l << ":" << this->left->freq  << " (" << this->left->id << ")\"";
        sright << "\"" << r << ":" << this->right->freq << " (" << this->right->id << ")\"";

        ss << spar.str() << " -> " << sleft.str()  << " [label=0];" << endl;
        ss << spar.str() << " -> " << sright.str() << " [label=1];" << endl;

        return ss.str();
    }
};
int Node::count = 0;        // Initialize static member of class

#endif
