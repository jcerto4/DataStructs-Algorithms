#include <array>
#include <iostream>

using namespace std;

int main(){
    array<int, 3> scores = {0, 10, 20};

    cout << scores[0] << endl;
    ++scores[0];
    cout << scores[0] << endl;

}


