//Project4.cpp
//Joe Certo
//11/20/2025
//The purpose of this project is to to utilize the Needleman-Wunsch algorithm
//to find the most optimal global alignment between two sequences using 
//a scoring function of matches, misses, and gaps
//In this project we examine COVID and find matching DNA

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

string s1;
string s2;
int* matrix;
int rows;
int cols;

const int match = 2;
const int miss = -1;
const int gap = -2;

int score; 

bool initStrings(string filename){
    ifstream fin(filename);
    if(!fin.is_open()){
        cout << filename << " not found" << endl;
        return false;
    }
    //Extract strings from file
    fin >> s1 >> s2;
    return true;
}

void printBlocks(string& ss1, string& ss2, string& ssA){
    reverse(ss1.begin(), ss1.end());
    reverse(ss2.begin(), ss2.end());
    reverse(ssA.begin(), ssA.end());
    int width = 100;
    for(int i = 0; i < ss1.length(); i+=width){
        cout <<  ss1.substr(i, width) << "\n" 
             <<  ssA.substr(i, width) << "\n"
             <<  ss2.substr(i, width) << "\n\n";
    }
    cout << "Total Score: " << matrix[(rows-1) * cols + (cols-1)];
}

void LCS(){
    rows = s1.length() + 1;
    cols = s2.length() + 1;
    matrix = new int[rows * cols];
    matrix[0] = 0;
    for(int r = 1; r < rows; r++){
        matrix[r * cols + 0] = r * gap;
    }

    for(int c = 1; c < cols; c++){
        matrix[0 * cols + c] = c * gap;
    }

    for(int r = 1; r < rows; r++){
        for(int c = 1; c < cols; c++){
            score = s1[r-1] == s2[c-1] ? match : miss;
            matrix[r * cols + c] = max(
                {
                matrix[(r-1) * cols + (c-1)] + score, 
                matrix[(r-1) * cols + c] + gap, 
                matrix[r * cols + (c-1)] + gap
                }
            );
        }
    }
}

void display(){
    string ss1;
    string ssA;
    string ss2;

    int r = rows - 1;
    int c = cols - 1;
    while(r > 0 && c > 0){
        score = s1[r-1] == s2[c-1] ? match : miss;
        if(matrix[(r-1) * cols + (c-1)] + score == matrix[r*cols+c]){
            ss1 += s1[r-1];
            ss2 += s2[c-1];
            if(score == match){
                ssA += "|";
            }else{
                ssA += "*";
            }
            --r;
            --c;
        }else if(matrix[(r-1) * cols + c] + gap == matrix[r*cols+c]){
            ss1 += s1[r-1];
            ss2 += "-";
            ssA += " ";
            --r;
        }else{
            ss1 += "-";
            ss2 += s2[c-1];
            ssA += " ";
            --c;
        }
    }
    printBlocks(ss1, ss2, ssA);
}

int main(){
    if(!initStrings("alpha_omicron.txt")) { return -1; }
    LCS();
    display();
    return 0;
}