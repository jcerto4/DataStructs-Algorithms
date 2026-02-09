//Joe Certo
//10/29/2025
//Lab09.cpp
//The purpose of this lab is to see the difference between balanced and skewed trees 
//while searching for values that do not exist

/*
Experiment 1: 1175
Experiment 2: 99
Experiment 3: 22
Experiment 4: 101

1. Did you observe a difference in the average elapsed times required to search for 64 in the two BSTs?
How about 0?
    Yes, there is an observable difference between the average elapsed times to search for 64 and 0. 
    In experiments 1 and 2, there is a clear difference in time with t1 being 1175 ms and t2 being a fraction of that at 99 ms.
    In experiments 3 and 4, there is also a difference in time, with t1 being faster than t2 in this case.

2. If you saw a difference, how much faster/slower was the search for 64 between the two BSTs? What
was the speedup/slow down when searching for 0 between the two BSTs?
    Searching for 64 saw a significant speedup from t1 to t2 with t2 being 11.9x faster
    Searching for 0 between the two BSTs saw t1 being faster instead of t2, with t2 being 4.6x slower. 

3. What caused these results? Explain the outcome.
    The reason for these results is that t1 is skewed to the right since integers are added sequentially, and t2 is a more balanced tree.
    t1 is degraded to a linked list with O(N) search time, which is why the time for searching for 64 is considerably longer than t2.
    However, in the case of searching for 0, searching fails immediately since 0 < 1 current->left is null,
    unlike t2 which has to search the tree to confirm 0 is not there. 

*/

#include <chrono> 
#include <iostream>
#include "BST.h"
using namespace std;

long elapsed_time(chrono::steady_clock::time_point start_time) {
    auto end_time = chrono::steady_clock::now();
    auto elapsed_duration = end_time - start_time;
    auto ms = chrono::duration_cast<std::chrono::milliseconds>(elapsed_duration);
    return ms.count();
}

int main(){
    BST<int> t1, t2;
    for(int i = 1; i <= 63; i++){
        t1.insert(i);
    }
    int holder[] = {
                    32,16,48,8,24,40,56,4,12,20,28,36,44,52,60,
                    2,6,10,14,18,22,26,30,34,38,42,46,50,54,58,
                    62,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,
                    31,33,35,37,39,41,43,45,47,49,51,53,55,57,
                    59,61,63
                };
    for(int i = 0; i < 63; i++){
        t2.insert(holder[i]);
    }

    cout << "\nExperiment 1\n";
    int average1 = 0;
    for(int i = 0; i < 4; i++){
       auto start_time = chrono::steady_clock::now();
        for(int j = 0; j < 10000000; j++){
            bool search = t1.search(64);
        }
        long time = elapsed_time(start_time);
        cout << time << endl;
        average1+=time;
    }
    cout << "Average: " << average1/4 << endl;

    cout << "\nExperiment 2\n";
    int average2 = 0;
    for(int i = 0; i < 4; i++){
       auto start_time = chrono::steady_clock::now();
        for(int j = 0; j < 10000000; j++){
            bool search = t2.search(64);
        }
        long time = elapsed_time(start_time);
        cout << time << endl;
        average2 += time;
    }
    cout << "Average: " << average2/4 << endl;

    cout << "\nExperiment 3\n";
    int average3 = 0;
    for(int i = 0; i < 4; i++){
       auto start_time = chrono::steady_clock::now();
        for(int j = 0; j < 10000000; j++){
            bool search = t1.search(0);
        }
        long time = elapsed_time(start_time);
        cout << time << endl;
        average3+=time;
    }
    cout << "Average: " << average3/4 << endl;

    cout << "\nExperiment 4\n";
    int average4 = 0;
    for(int i = 0; i < 4; i++){
       auto start_time = chrono::steady_clock::now();
        for(int j = 0; j < 10000000; j++){
            bool search = t2.search(0);
        }
        long time = elapsed_time(start_time);
        cout << time << endl;
        average4+=time;
    }
    cout << "Average: " << average4/4 << endl;

    return 0;
}
