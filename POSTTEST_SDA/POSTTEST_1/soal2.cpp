#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    const int JML = 5;
    Mahasiswa mhs[JML];
    
    for(int i = 0; i < JML; i++) {
        cout << "Data Mahasiswa ke-" << i+1 << endl;
        cout << "NAMA : "; getline(cin >> ws, mhs[i].nama);
        cout << "NIM : "; cin >> mhs[i].nim;
        cout << "IPK : "; cin >> mhs[i].ipk;
        cout << "--------------------" << endl;
    }

    int bestIdx = 0;
    for(int i = 1; i < JML; i++) {
        if(mhs[i].ipk > mhs[bestIdx].ipk) {
            bestIdx = i;
        }
    }

    cout << "\n Mahasiswa dengan IPK Tertinggi:" << endl;
    cout << "NAMA: " << mhs[bestIdx].nama << " (" << mhs[bestIdx].nim << ")" << endl;
    cout << "IPK : " << mhs[bestIdx].ipk << endl;

    return 0;
}