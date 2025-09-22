//Joe Certo
//##/##/####
//Lab05.cpp
//This lab....

#include <cstdlib> 
#include <ctime> 
#include <chrono> 
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// Helper function to generate a random int in the range [min, max]
int randint(int min, int max) { return min + (rand() % (max - min + 1)); }

// Measure the elapsed time after start_time and return milliseconds
long elapsed_time(chrono::steady_clock::time_point start_time) {
    auto end_time = chrono::steady_clock::now();
    auto elapsed_duration = end_time - start_time;
    auto ms = chrono::duration_cast<std::chrono::milliseconds>(elapsed_duration);
    return ms.count();
}

void doubleSize(vector<int>& a, int size){
    int currentSize = a.size();
    for(int i = 0; i < size - currentSize; i++){
        a.push_back(randint(-10, 10));
    }
}

int two_sum(vector<int>& a){
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = i + 1; j < a.size(); j++){
            if((a[i] + a[j]) == 0){
                ++count;
            }
        }
    }
    return count;
}

int three_sum(vector<int>& a){
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = i + 1; j < a.size(); j++){
            for(int z = j + 1; z < a.size(); z++){
                if((a[i] + a[j] + a[z]) == 0){
                    ++count;
                }
            }
        }
    }
    return count;
}

int main(){
    //Two-Sum Tests
    ofstream twoSumOut("two_sum_results.csv");
    twoSumOut << ("Size,Elapsed(ms)") << endl;
    srand(static_cast<unsigned int>(time(0)));
    int twoSumSize = 1000;
    vector<int> twoSumVec;
    for(int i = 0; i < twoSumSize; i++){
        twoSumVec.push_back(randint(-10, 10));
    }
    for(int i = 0; i < 5; i++){
        auto start_time = chrono::steady_clock::now();
        int result = two_sum(twoSumVec);
        long time = elapsed_time(start_time);
        cout << "Size: " << twoSumVec.size() << " Elapsed Time: " << time << endl;
        twoSumOut << twoSumVec.size() << "," << time << endl;
        doubleSize(twoSumVec, twoSumVec.size()*2);
    }

                                                                                                                                                                /*
    --------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                                                                                                                */

    //Three-Sum Tests
    ofstream threeSumOut("three_sum_results.csv");
    threeSumOut << ("Size,Elapsed(ms)") << endl;
    int& threeSumSize = twoSumSize;
    threeSumSize = 250;
    vector<int> threeSumVec;
    
    for(int i = 0; i < threeSumSize; i++){
        threeSumVec.push_back(randint(-10, 10));
    }

    for(int i = 0; i < 5; i++){
        auto start_time = chrono::steady_clock::now();
        int result = three_sum(threeSumVec);
        long time = elapsed_time(start_time);
        cout << "Size: " << threeSumVec.size() << " Elapsed Time: " << time << endl;
        threeSumOut << threeSumVec.size() << "," << time << endl;  
        doubleSize(threeSumVec, threeSumVec.size()*2);
    }

}

