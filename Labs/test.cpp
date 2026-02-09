#include <array>
#include <iostream>

using namespace std;

int ProdEven(int n){
    if(n==1){
        return 2;
    }
    return (2*n) * ProdEven(n - 1);
}

int main(){
   
    int test = ProdEven(3);
    cout << test;

}


