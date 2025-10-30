// stl_tour
// A scenic tour of STL data structures and their iterator side-kicks
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main() {
    // Because the STL contains template classes, they can hold any data type specified.
    // All STL data structures support use of iterators.
    
    // An array is a fixed-size sequential data structure.
    // It improves the standard C array in several ways, including bounds checking.
    // Elements are accessible by index.
    // It's size may not change.
    cout << "--- array ---" << endl;

    array<int, 4> asizes {32, 36, 40, 42};

    // Use index to access elements
    for (int i=0; i<asizes.size(); ++i) {
        cout << asizes[i] << " ";
    }
    cout << endl;

    // Use a iterator. Get each value using derference operator on the iterator.
    for (array<int, 4>::iterator it=asizes.begin(); it != asizes.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Type is too hard to write down. Use auto instead because compiler can figure it out.
    for (auto it=asizes.begin(); it != asizes.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Using the ranged for to access elements
    for ( int size : asizes) {
        cout << size << " ";
    }
    cout << endl;

    // A vector is a dynamically sized sequential data structure, like a managed array.
    // Elements are accessible by index.
    // It's size may change. vector methods handle all work automatically.
    // Insertion is proportional to the length of the list O(N)
    cout << "--- vector ---" << endl;

    vector<int> vsizes {32, 36, 40, 42};
    for (int i=0; i<vsizes.size(); ++i) {
        cout << vsizes[i] << " ";
    }
    cout << endl;

    // Adding a new item to the vector is easy
    vsizes.push_back(46);
    
    // An iterator may be used as well.
    for (auto it = vsizes.begin(); it!=vsizes.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Using the ranged for to access elements
    for ( int size : vsizes) {
        cout << size << " ";
    }
    cout << endl;

    // A list is a dynamically sized sequential data structure
    // Organized as a list of linked objects.
    // Links are in both directions.
    // Insertion is constant time (O(1))
    cout << "--- list ---" << endl;
    
    list<string> steps {"lather", "rinse", "repeat"};
    
    for (auto it = steps.begin(); it != steps.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    auto it = steps.begin();            // Starting iterator
    // ++(++it);                           // Iterate twice
    advance(it, 2);                   // Helper fxn to advance iterator by two steps
    steps.insert(it, "condition");    // Insert at location

    for (auto it = steps.begin(); it != steps.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // A queue is linked linear data structure
    // Data items are added by pushing to one end of the data structure
    // Data items are removed by popping from the other end.
    // Pushing and popping are constant time.
    cout << "--- queue ---" << endl;

    queue<string> waitList;

    waitList.push("Neumann party of 2");
    waitList.push("Amdahl party of 3");
    waitList.push("Flynn party of 4");

    while (waitList.size() > 0)     {
        cout << "Serving: " << waitList.front() << endl;
        waitList.pop();
    }

    // A stack is linked linear data structure
    // Data items are added by pushing to and popping from the same end of the data structure
    // Pushing and popping are constant time.
    cout << "--- stack ---" << endl;

    deque<string> tripRoute;

    cout << "Depart Tokyo" << endl;
    tripRoute.push_front("Tokyo");

    cout << "Transfer at Osaka" << endl;
    tripRoute.push_front("Osaka");

    cout << "Arrive in Nara" << endl;
    tripRoute.push_front("Nara");

    cout << "\nReturn trip: " << endl;
    cout << "Depart " + tripRoute.front() << endl;
    tripRoute.pop_front();

    cout << "Transfer at " + tripRoute.front() << endl;
    tripRoute.pop_front();

    cout << "Arrive in " + tripRoute.front() << endl;
    tripRoute.pop_front();

    // A set is a data structure containing unique items called keys
    cout << "--- set ---" << endl;

    set<int> unique {32, 36, 40, 42, 36, 40, 42, 36, 40};
    for (int item : unique) {
        cout << item << " ";
    }
    cout << endl;

    // A dictionary is like a set but where each key is associated with a value
    // Dictionary keys must be unique, but their values do not
    cout << "--- map ---" << endl;
    
    // Map the heights in inches of the three stooges with initializer
    map<string, int> height {{"Moe", 5*12+3}, {"Larry", 5*12+4}, {"Curly", 5*12+5}};

    // How tall would they be if they stood on each other's shoulders?
    cout << height["Moe"] + height["Larry"] + height["Curly"] << " inches" << endl;

    // Add Shemp to the map
    height["Shemp"] = 5*12 + 6;

    // New total height
    cout << height["Moe"] + height["Larry"] + height["Curly"] + height["Shemp"]<< " inches" << endl;

    return 0;
}