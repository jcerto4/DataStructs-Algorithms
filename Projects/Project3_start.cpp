// Project3.cpp
// Joe Certo
// 11/3/2025
// The following program constructs a Hoffman tree for 26 letters and the space character based on frequency.
//It encodes and decodes messages into binary using the Hoffman tree 

#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <map>
#include "Node.h"
using namespace std;

// Encode a string using the given Huffman Code table
string encodeString(string msg, map<char, string>& huffmanCodes) {
    string tstr;
    for (char c: msg) {
        tstr.append(huffmanCodes[c]);
    }
    return tstr;
}

// Decode the next symbol on the encoded string
int decodeNext(const string& encoded, Node* n, int idx, ostringstream& ss) {
    
    // No Node. No action.
    if (n == nullptr) { return idx; }

    // Found a leaf node. Add char to decoded string.
    if (n->isLeaf()) {
        ss << n->ch;
        return idx;
    }

    // Advance to the next character
    idx++;

    // Decode bits represented as chars '0' and '1'
    n = (encoded.at(idx) == '0') ? n->left : n->right;
    idx = decodeNext(encoded, n, idx, ss);

    return idx;
}

// Decode the encoded string starting at the Huffman tree root node
string decodeString(string& encoded, Node* root) {
    ostringstream ss;
    int idx = -1;
    int max = encoded.length() - 1;

    // Traverse the Huffman Tree and decode the encoded string
    while (idx < max) { idx = decodeNext(encoded, root, idx, ss); }
    return ss.str();
}

// Builds Huffman Tree
//Builds Hoffman tree from a map of character frequencies
//Combines two-lowest frequencies into a new parent
//Repeats until one node remains which is the root
Node* buildHuffmanTree(map<char, double> lfreq) {
    priority_queue<Node*, vector<Node*>, Node> pq;
    for(auto it = lfreq.begin(); it != lfreq.end(); it++){
        pq.push(new Node(it->first, it->second));
    }
    while(pq.size() > 1){
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* tmp = new Node('\0', left->freq+right->freq, left, right);
        pq.push(tmp);
    }
    return pq.top();
}

// Get Huffman codes from a tree
//Traverses the Huffman tree recursievly to assign binary code for each character
void getHuffmanCodes(Node* n, map<char, string>& huffmanCodes, string code="") {
    if(n == nullptr){
        return;
    }else if(n->isLeaf()){
        huffmanCodes[n->ch] = code;
        return;
    }else{
        getHuffmanCodes(n->left, huffmanCodes, code + "0");
        getHuffmanCodes(n->right, huffmanCodes, code + "1");
    }

    

}

// Serialize all edges in one Node and then invoke recursively
void serializeNode(Node* n, ostringstream& oss) {
    if (n->left != nullptr && n->right != nullptr) {
        oss << n->toGraphviz();
        serializeNode( n->left,  oss ); 
        serializeNode( n->right, oss ); 
    }
}

// Serialize an entire Tree starting at given Node
string serializeTree(Node* n, string name = "G") {
    ostringstream oss;
    oss << "digraph " << name << " {" << endl;
    if(n) serializeNode(n, oss);
    oss << "}" << endl;
    return oss.str();
}

// Test Huffman Encoding
int main() {

    map<char, double> lfreq 
       {{' ',12.0000}, {'E',11.1607}, {'A', 8.4966}, {'R', 7.5809}, {'I', 7.5448}, {'O', 7.1635},
        {'T', 6.9509}, {'N', 6.6544}, {'S', 5.7351}, {'L', 5.4893}, {'C', 4.5388}, {'U', 3.6308}, 
        {'D', 3.3844}, {'P', 3.1671}, {'M', 3.0129}, {'H', 3.0034}, {'G', 2.4705}, {'B', 2.0720},
        {'F', 1.8121}, {'Y', 1.7779}, {'W', 1.2899}, {'K', 1.1016}, {'V', 1.0074}, {'X', 0.2902}, 
        {'Z', 0.2722}, {'J', 0.1965}, {'Q', 0.1962}};

    Node* root = buildHuffmanTree(lfreq);

    // dot Project3.dot -Tsvg > Project3.svg
    // https://dreampuf.github.io/GraphvizOnline/
    // ofstream ofs("Project3.dot");
    // ofs << serializeTree(root) << endl;
    // ofs.close();

    // Traverse the Huffman tree and store Huffman codes in a map
    map<char, string> huffmanCodes;
    getHuffmanCodes(root, huffmanCodes);

    cout << "Huffman Codes:" << endl;
    for ( pair<char, string> pair: huffmanCodes ) {
        cout << pair.first << ": " << pair.second << endl;
    }

    string msg = "THE COLLEGE OF NEW JERSEY IS A HIGHLY SELECTIVE INSTITUTION THAT IS CONSISTENTLY RECOGNIZED AS ONE OF THE TOP COMPREHENSIVE COLLEGES IN THE NATION";

    // Encode string and print
    string encoded = encodeString(msg, huffmanCodes);
    cout << "Encoded string: " << encoded << endl;

    // Decode string and print
    string decoded = decodeString(encoded, root);
    cout << "Decoded string: " << decoded << endl;
}