#include <iostream>
using namespace std;

// fungsi untuk mencari nilai minimum
int cariMin(int arr[], int n, int &posisi) {
    int min = arr[0];
    posisi = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            posisi = i;
        }
    }

    return min;
}

int main() {
    int n;

    cout << "=== Program Mencari Nilai Minimum ===" << endl;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    int data[n]; // array sesuai jumlah input user

    cout << "Masukkan " << n << " angka:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i << " : ";
        cin >> data[i];
    }

    int indexMin;
    int hasil = cariMin(data, n, indexMin);

    cout << "\nNilai minimum = " << hasil << endl;
    cout << "Terdapat pada index = " << indexMin << endl;

    return 0;
}