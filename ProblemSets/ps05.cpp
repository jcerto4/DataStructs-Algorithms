// ps05.cpp
// Consider the following 21 functions.
// Predict Big-O runtime for each function.
// Submit a table summarizing your predictions.

// Joe Certo
// 9/25/2025
// Problem Set 5
//
//  q#   |  Big-O
// ------+--------
//  q01  | ...

#include <iostream>
#include <vector>
using namespace std;

int* q01(int N) {
    int *a = new int[N];
    a[0] = 0;
    a[1] = 1;
    for (int i=2; i<N; i = i + 1) {
        a[i] = a[i-1] + a[i-2];
    }
    return a;

    //O(N)
}

int* q02(int *m1, int *m2, int nrows, int ncols) {
    int *m3 = new int[nrows*ncols];
    for (int r=0; r<nrows; r++) {
        for (int c=0; c<ncols; c++) {
            int idx = r*ncols+c;
            m3[idx] = m1[idx] * m1[idx];
        }
    }
    return m3;

    //O(N^2)
}

void q03(int* a, int N) {
    for (int i=0; i<N; i*=2) {
        a[i] *= 2;
    }

    //O(logN)
}

void q04(vector<int> &a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;

    //O(1)
}

void q05(int* a, int N) {
    for (int i=0; i<N; i+=2) {
        a[i] *= 2;
    }

    //O(N)
}

void q06(char a[], int last) {
    for (int i=0; i<last; i++) {
        for (int j=last; j>=0; j/=2) {
            a[j] = '*';
        }
    }

    //O(N logN)
}

double q07(double length) {
    double area = length*length;
    return area;

    //O(1)
}

int q08(int N) {
    int sum = 0;
    for (int i=0; i<N; i++) {
        sum += i;
    }
    for (int j=0; j<N; j+=3) {
        sum += j;
    }
    return sum;

    //O(N)
}

void q09(int* a, int N) {
    for (int i=N; i>=0; i/=2) {
        a[i] *= 2;
    }

    //O(logN)
}

int q10(int start, int delta) {
    for (int i=0; i<3; i++) {
        start += delta;
    }
    return start;

    //O(1)
}

void q11(double x, double y) {
    double z = 0.0;
    for (int i=100; i>=0; i/=2) {
        for (int j=y; j>=0; j = j / 2) {
            z = z*j;
        }
    }

    //O(logN)
}

void q12(double a[], int N) {
    int count = 0;
    for (int i=N; i>=0; i/=2) {
        for (int j=0; j<N; j++) {
            count += 1;
        }
    }
    cout << count << endl;

    //O(N logN)
}

int q13(int x[], int y[], int N) {
    int sum = 0.0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            sum += x[i]*y[j];
        }
    }
    return sum;

    //O(N^2)
}

int q14(int N, int target) {
    int count = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                if (i+j+k == target) {
                    count++;
                }
            }
        }
    }
    return target;

    //O(N^3)
}

int q15(int N, int target) {
    int count = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                if (i*j*k > 100) {
                    return -1;
                 } else if (i+j+k == target) {
                    count++;
                 }
            }
        }
    }
    return target;

    //O(N^3)
}

int q16(int N) {
    int total = 0;
    for (int a=-N; a<N; a++) 
        for (int b=-N; b<N; b++) 
            for (int c=-N; c<N; c++) 
                if (a+b+c == 0) total++;
    return total;

    //O(N^3)
}

void q17(int start, int N) {
    for (int i=0; i<N; i*=2) {
        for (int j=0; j<N; j*=2) {
            start *= 2;
        }
    }

    //O((logN)^2)
}

void q18(vector<int>& a) {
    bool swapped = false;
    int N = a.size();
    for (int i=0; i < N-1; i++) {
        swapped = false;
        for (int j=0; j < N-i-1; j++)
            if (a[j] > a[j+1]) {
                q04(a, j, j+1);
                swapped = true;
            }
        if (!swapped) break;
    }

    //O(N^2)
}

bool q19( vector<int>& a, int t ) {
    int N  = a.size();
    int lo = 0;
    int hi = N-1;
    while (lo <= hi) {
        int m = (hi + lo) / 2;
        if (a[m] == t) return true;
        if (t < a[m])  hi = m - 1;
        else           lo = m + 1;
    }
    return false;

    //O(logN)
}

int q20( int N ) {
    int count = 0;
    while (N > 1) {
        N /= 2;
        ++count;
    }
    return count;

    //O(logN)
}

double q21(double T, double P, double n) {
    double R = 8.314;
    double V = n*R*T/P;
    return V;

    //O(1)
}

int main()
{
    return 0;
}