//Joe Certo
//Project01.cpp
//9/16/2025
//This program reads a word search grid from file, prints it, 
//then searches the grid using an exhaustive search strategy for the words
//written in the command line

#include <iostream>
#include <fstream>

using namespace std;

int nrows;
int ncols;
char* input;
char* output;

bool isWordAtInput(string word, int r, int c, int rincr, int cincr);
void setWordAtOutput(string word, int r, int c, int rincr, int cincr);
void findWord(string word);
void printGrid(char* grid);
bool initGame(string filename);

int main(int argc, char* argv[]){
    string filename(argv[1]);

    if(!initGame(filename)) { return -1; }
    printGrid(input);

    for(int i = 2; i < argc; i++){
        string word(argv[i]);
        cout << "Searching for " << word << endl;
        findWord(word);
    }

    printGrid(output);
    delete[] input;
    delete[] output;
}

bool initGame(string filename){
    ifstream fin(filename);

    if(!fin.is_open()){
        cout << filename << " not found" << endl;
        return false;
    }
    
    //Read in the number of rows and columns
    fin >> nrows >> ncols;

    //Initalize input and output arrays
    input = new char[nrows * ncols];
    output = new char[nrows * ncols];

    //Read in the grid data to the array
    for(int i = 0; i < nrows * ncols; i++){
        fin >> input[i];
        output[i] = '-';
    }

    return true;
}

void printGrid(char* grid){
    for(int r = 0; r < nrows; r++){
        for(int c = 0; c < ncols; c++){
            cout << grid[r * ncols + c] << " ";
        }
        cout << endl;
    }
}

bool isWordAtInput(string word, int r, int c, int rincr, int cincr){
    
    //Repetively checks all directions that a word could possibly be in word search
    //If the word goes beyond the bounds, or the ith position char is not a match 
    //it returns false, otherwise it returns true and that means the word is there
    for(int i = 0; i < word.length(); i++){
        if(c < 0 || c >= ncols || r < 0 || r >= nrows) return false;
        if(word[i] != input[r * ncols + c]) return false;
        r += rincr;
        c += cincr;
    }

    return true;
}

void setWordAtOutput(string word, int r, int c, int rincr, int cincr){

    //We rely on isWordAtInput() for bounds checking
    //To reduce redunancy there is no need to recheck
    //This function can focus on setting the word on the output grid
    for(int i = 0; i < word.length(); i++){
        output[r * ncols + c] = word[i];
        r += rincr;
        c += cincr;
    }
}

void findWord(string word){

    //we loop over the grid of elements and check all possible directions
    //i.e, n, s, w, e, nw, ne, se, sw
    //isWordAtInput() will only return true if the word exists there 
    //and does not go beyond the bounds
    //If isWordAtInput() returns true, then we set that word on the output grid
    //in the same direction as the input grid

    for(int r = 0; r < nrows; r++){
        for(int c = 0; c < ncols; c++){
            if(isWordAtInput(word, r, c, 0, 1)) setWordAtOutput(word, r, c, 0, 1);
            if(isWordAtInput(word, r, c, 1, 0)) setWordAtOutput(word, r, c, 1, 0);
            if(isWordAtInput(word, r, c, 1, 1)) setWordAtOutput(word, r, c, 1, 1);
            if(isWordAtInput(word, r, c, -1, 0)) setWordAtOutput(word, r, c, -1, 0);
            if(isWordAtInput(word, r, c, 0, -1)) setWordAtOutput(word, r, c, 0, -1);
            if(isWordAtInput(word, r, c, -1, -1)) setWordAtOutput(word, r, c, -1, -1);
            if(isWordAtInput(word, r, c, -1, 1)) setWordAtOutput(word, r, c, -1, 1);
            if(isWordAtInput(word, r, c, 1, -1)) setWordAtOutput(word, r, c, 1, -1);
        }
    }
}
