#include <iostream>
using namespace std;

int findMin(int A[], int n, int &index) {
    int minVal = A[0];
    index = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < minVal) {
            minVal = A[i];
            index = i;
        }
    }
    return minVal;
}

int main() {
    int fibo[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int minIdx;

    int minVal = findMin(fibo, n, minIdx);

    cout << "Nilai Minimum: " << minVal << endl;
    cout << "Terdapat pada Indeks: " << minIdx << endl;

    return 0;
}