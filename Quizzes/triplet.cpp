// triplet.cpp
#include <iostream>
#include <string>
using namespace std;

// Templated class holds three instances of a given type
template <class T>
class triplet {
private:
    T x, y, z;
public:             // Constructor
    triplet (T x, T y, T z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    T max() {       // Find the max
        T tmp = x > y? x : y;
        tmp = z > tmp? z: tmp;
        return tmp;
    }
    T min() {       // Find the min
        T tmp = x < y? x : y;
        tmp = z < tmp? z: tmp;
        return tmp;
    }
};

// Test triplet
int main () {
  triplet<int> trip1(12, 15, 13);
  cout << trip1.max() << endl;

  triplet<string> trip2("A", "B", "C");
  cout << trip2.max() << endl;
  return 0;
}
