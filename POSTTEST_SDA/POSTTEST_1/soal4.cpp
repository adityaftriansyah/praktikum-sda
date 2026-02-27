#include <iostream>
using namespace std;


void tukarNilai(int *ptrA, int *ptrB) {
    
    if (*ptrA != *ptrB) { 
        int temp = *ptrA;
        *ptrA = *ptrB;
        *ptrB = temp;
    }
}

int main() {
    int nmr1, nmr2;

    cout << "=== Program Tukar Nilai (Pointer) ===" << endl;
    cout << "Masukkan nilai pertama: "; cin >> nmr1;
    cout << "Masukkan nilai kedua: "; cin >> nmr2;

    cout << "\n[Sebelum Ditukar]" << endl;
    cout << "Nilai 1: " << nmr1 << " (Alamat: " << &nmr1 << ")" << endl;
    cout << "Nilai 2: " << nmr2 << " (Alamat: " << &nmr2 << ")" << endl;

    tukarNilai(&nmr1, &nmr2);

    cout << "\n[Sesudah Ditukar]" << endl;
    cout << "Nilai 1: " << nmr1 << " (Alamat: " << &nmr1 << ")" << endl;
    cout << "Nilai 2: " << nmr2 << " (Alamat: " << &nmr2 << ")" << endl;

    cout << "\nAnalisis: Perhatikan bahwa alamat memori tetap, namun nilai di dalamnya berubah." << endl;
    return 0;
}