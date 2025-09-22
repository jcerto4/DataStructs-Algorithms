//Joe Certo
//Lab02.cpp
//9/4/2025
//This program will read a Word Search file in the format of a 1-D array, and then prints the grid to the screen as a grid of proper dimensions

#include <iostream>
#include <fstream>

using namespace std;

bool initGame(string filename);
void printGrid(char grid[]);

int nrows;
int ncols;
char input[1000];

int main(){
    if(!initGame("grid1.txt")){ return -1; }
    printGrid(input);
    return 0;
}

bool initGame(string filename){
    
    ifstream fin(filename);

    if(!fin.is_open()){
        cout << filename << " not found" << endl;
        return false;
    }
    
    //Read in the number of rows and columns
    fin >> nrows >> ncols;

    //Read in the grid data to the array
    for(int i = 0; i < nrows * ncols; i++){
        fin >> input[i];
    }

    return true;
}

void printGrid(char grid[]){

    //Print the grid to the screen in grid format
    for(int r = 0; r < nrows; r++){
        for(int c = 0; c < ncols; c++){
            cout << grid[r*ncols+c] << " ";
        }
        cout << endl;
    }
}