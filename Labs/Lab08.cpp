//Joe Certo
//Lab08.cpp
//10/22/2025
//The purpose of this lab is to test the insertion and selection sort 
//alogorithms with various cases to measure their big O time complexity

/*

1. Does either algorithm perform better when array elements are initially in ascending order?
    Yes, the insertion sort algorithm performs significantly better when elements are in ascending order.
    Insertion executes at O(N) for elements in ascending order, while selection is O(N^2).

2. Does either algorithm perform better when array elements are initially in descending order?
    No, both execute at O(N^2) for elements that are initially in descending order. 

3. Does either algorithm perform better when array elements are initially randomly ordered?
    No, both execute at O(N^2) for elements that are initially random.

4. Which algorithm seems best overall? In order words, which algorithm would you choose if you did not know
what type of data might be encountered?
    I would choose insertion sort because using selection sort is a guarenteed O(N^2) from best case
    to worst case. Insertion sort however, has a best case of O(N). Knowing this leads me to conclude
    that the insertion sort alogorithm is better overall since its best case is better than selections.

5. In each case, briefly explain your answer based on what you know about how the algorithms work
    
    Insertion sort assumes the first element is already sorted, and then inserts each following element 
    into its correct position within that sorted section. Because of this, if the array starts in ascending
    order, very few comparisons or shifts are needed, making it much faster. The algorithm just moves
    linearly through the data structure which is O(N). Otherwise, it operates at O(N^2).

    Selection sort builds the sorted portion one index at a time by repeatedly finding the smallest 
    element from the unsorted portion and swapping it into place. Since it always scans the remaining
    elements regardless of order, its performance remains O(N^2) for all cases.

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include <ctime> 
#include <chrono>

using namespace std;

int randint(int min, int max) { return min + (rand() % (max - min + 1)); }

long elapsed_time(chrono::steady_clock::time_point start_time) {
    auto end_time = chrono::steady_clock::now();
    auto elapsed_duration = end_time - start_time;
    auto ms = chrono::duration_cast<std::chrono::milliseconds>(elapsed_duration);
    return ms.count();
}

void shuffle(vector<int>& v){
    for(int i = v.size()-1; i > 0; i--){
        int j = randint(0, i);
        swap(v[i], v[j]);
    }
}

void selectionSort( vector<int>& v ){
    for (int i = 0; i < v.size()-1; i++) { 
        int minIndex = i; 
        for (int j = i+1; j < v.size(); j++) { 
            if (v[j] < v[minIndex]) 
                minIndex = j;
            }
    swap(v[minIndex], v[i]); 
    }
}

void insertionSort(vector<int>& v){
for (int i = 1; i < v.size(); i++) {
    int key = v[i];
    int j = i - 1;
    while (j >= 0 && v[j] > key) {
        v[j + 1] = v[j];
        j = j - 1;
    }   
        v[j + 1] = key;
    }
}

void doubleAsc(vector<int>& v){
    int doubleIt = v.size() * 2;
    v.clear(); v.reserve(doubleIt);
    for (int i = 0; i < doubleIt; ++i) v.push_back(i);
}

void doubleDesc(vector<int>& v){
    int doubleIt = v.size() * 2;
    v.clear(); v.reserve(doubleIt);
    for (int i = 0; i < doubleIt; ++i) v.push_back(doubleIt - 1 - i);
}

void doubleRnd(vector<int>& v){
    int doubleIt = v.size() * 2;
    v.clear(); v.reserve(doubleIt);
    for (int i = 0; i < doubleIt; ++i) v.push_back(i);
    shuffle(v);
}

int main(){
    srand(static_cast<unsigned int>(time(0)));

    vector<int> ascending;
    vector<int> descending;
    vector<int> random;

    int startingSize = 2000;

    for(int i = 0; i < startingSize; i++){
        ascending.push_back(i);
        descending.push_back(startingSize - i - 1);
    }
    random = ascending;
    shuffle(random);

    cout << "Selection Sort Tests" << endl;
    cout << "Ascending Test : Selection Sort" << endl;
    for(int i = 0; i < 4; i++){
        auto start_time = chrono::steady_clock::now();
        selectionSort(ascending);
        long time = elapsed_time(start_time);
        cout << "Size: " << ascending.size() << " Elapsed Time: " << time << endl;
        doubleAsc(ascending);
    }

      cout << endl;

    cout << "Descending Test : Selection Sort" << endl;
    for(int i = 0; i < 4; i++){
        auto start_time = chrono::steady_clock::now();
        selectionSort(descending);
        long time = elapsed_time(start_time);
        cout << "Size: " << descending.size() << " Elapsed Time: " << time << endl;
        doubleDesc(descending);
    }

      cout << endl;

     cout << "Random Test : Selection Sort" << endl;
    for(int i = 0; i < 4; i++){
        auto start_time = chrono::steady_clock::now();
        selectionSort(random);
        long time = elapsed_time(start_time);
        cout << "Size: " << random.size() << " Elapsed Time: " << time << endl;
        doubleRnd(random);
    }

      cout << endl;
//--------------------------------------------------------------------------------------------------------------------

    ascending.clear();
    descending.clear();
    random.clear();

    int startingAsc = 700000;

    for(int i = 0; i < startingAsc; i++){
        ascending.push_back(i);
    }

    for(int i = 0; i < startingSize; i++){
        descending.push_back(startingSize - i - 1);
    }
    random = descending;
    shuffle(random);

    cout << "Insertion Sort Tests" << endl;
    cout << "Ascending Test : Insertion Sort" << endl;
    for(int i = 0; i < 4; i++){
        auto start_time = chrono::steady_clock::now();
        insertionSort(ascending);
        long time = elapsed_time(start_time);
        cout << "Size: " << ascending.size() << " Elapsed Time: " << time << endl;
        doubleAsc(ascending);
    }

    cout << endl;

     cout << "Descending Test : Insertion Sort" << endl;
    for(int i = 0; i < 4; i++){
        auto start_time = chrono::steady_clock::now();
        insertionSort(descending);
        long time = elapsed_time(start_time);
        cout << "Size: " << descending.size() << " Elapsed Time: " << time << endl;
        doubleDesc(descending);
    }

      cout << endl;

     cout << "Random Test : Insertion Sort" << endl;
    for(int i = 0; i < 4; i++){
        auto start_time = chrono::steady_clock::now();
        insertionSort(random);
        long time = elapsed_time(start_time);
        cout << "Size: " << random.size() << " Elapsed Time: " << time << endl;
        doubleRnd(random);
    }

    return 0;
}