#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;
    while (start < end) {

        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void cetakArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " (alamat: " << (arr + i) << ")" << endl;
    }
}

int main() {
    int prima[] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "--- sebelum Dibalik ---" << endl;
    cetakArray(prima, n);

    reverseArray(prima, n);

    cout << "\n--- sesudah Dibalik ---" << endl;
    cetakArray(prima, n);

    return 0;
}