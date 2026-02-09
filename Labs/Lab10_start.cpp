// Lab10.cpp
//Joe Certo
//11/13/2025
//The purpose of this lab is to heapify 
//a tree into a max heap  
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

// Convert tree in vector to Max Heap
void heapify(vector<int>& tree, int N, int i) {
    int largest = i;
    int left = (2*i) + 1;
    int right = (2*i) + 2;
    
    if(left < N && tree[left] > tree[largest]){
        largest = left;
    }

    if(right < N && tree[right] > tree[largest]){
        largest = right;
    }

    if(largest != i){
        swap(tree[i], tree[largest]);
        heapify(tree, N, largest);
    }

}

// Convert tree in vector to Max Heap
void max_heap(vector<int>& tree) {
    int N = tree.size();
    int lastLeaf = (N / 2) - 1;
    for(int i = lastLeaf; i >= 0; i--){
        heapify(tree, N, i);
    }
}

// Serialize a tree stored in a vector<int> in level order
string string_tree(vector<int>& tree) {
    ostringstream oss;
    int N   = tree.size();                  // Number of items in tree
    int lvl = 0;                            // Tracks level number
    int nli = 0;                            // Init next endl index
    for (int i=0; i < N; ++i) {             // Loop over all items
        oss << tree[i] << " ";              // Print item on same line
        if (i == nli) {                     // Is it time for an endl?
            oss << endl;                    // Start new line
            nli += (int) pow(2, ++lvl);           // Update level and next endl index
        }
    }
    oss << endl;
    return oss.str();
}

// Serialize item to dot language for display in GraphViz
void dot_item(vector<int>& vec, int root, ostringstream& oss) {
    int left  = 2*root + 1;                 // Left child index
    int right = 2*root + 2;                 // right child index

    if (left < vec.size()) {                // Add left edge in dot language
        oss << "\"" << vec[root] << " (" << root << ")\" -> \"" << vec[left] << " (" << left << ")\"" << endl;
        dot_item( vec, left,  oss);         // Invoke recursively
    }
    if (right < vec.size()) {               // Add right edge in dot language
        oss << "\"" << vec[root] << " (" << root << ")\" -> \"" << vec[right] << " (" << right << ")\"" << endl;
        dot_item( vec, right, oss);         // Invoke recursively
    }
}

// Serialize an entire heap stored in a vector to dot language for display in GraphViz.
// Return a string.
string dot_tree(vector<int>& vec, string name = "G") {
    ostringstream oss;
    oss << "digraph " << name << " {" << endl;
    dot_item(vec, 0, oss);
    oss << "}" << endl;
    return oss.str();
}

int main() {
    // A complete binary tree stored serially in a vector
    vector<int> tree {2, 6, 8, 15, 15, 16, 17, 19, 21, 27, 30};

    // or...
    // vector<int> tree;
    // tree.push_back(2);
    // tree.push_back(6);
    // tree.push_back(8);
    // ...
    cout << string_tree(tree) << endl;
    max_heap(tree);
    cout << string_tree(tree) << endl;

    // For display using https://dreampuf.github.io/GraphvizOnline/
    // https://graphviz.org/
    // cout << "Tree in Dot for Graphviz" << endl;
    // cout << dot_tree(tree) << endl;

    return 0;
}