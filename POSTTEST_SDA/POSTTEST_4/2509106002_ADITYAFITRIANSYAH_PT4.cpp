#include <iostream>
using namespace std;

struct Kereta {
    int no;
    string nama, asal, tujuan;
    string berangkat, tiba;
    int harga, tiket;
};

struct Node {
    int noKereta;
    string namaKereta;
    string pembeli;
    int jumlah;
    Node* next;
};

// antrian
Node *depan = NULL, *belakang = NULL;
// riwayat
Node *atas = NULL;

void tambahAntrian(int no, string kereta, string orang, int jml) {
    Node* baru = new Node{no, kereta, orang, jml, NULL};

    if (belakang == NULL) {
        depan = belakang = baru;
    } else {
        belakang->next = baru;
        belakang = baru;
    }

    cout << ">> masuk antrian ya\n";
}

Node ambilAntrian() {
    Node kosong = {0,"","",0,NULL};

    if (depan == NULL) {
        cout << "antrian lagi kosong...\n";
        return kosong;
    }

    Node* hapus = depan;
    Node data = *hapus;

    depan = depan->next;
    if (depan == NULL) belakang = NULL;

    delete hapus;
    return data;
}

void masukRiwayat(Node data) {
    Node* baru = new Node{data.noKereta, data.namaKereta, data.pembeli, data.jumlah, atas};
    atas = baru;
}

void hapusRiwayat() {
    if (atas == NULL) {
        cout << "riwayat kosong\n";
        return;
    }

    cout << "hapus data: " << atas->pembeli << endl;

    Node* hapus = atas;
    atas = atas->next;
    delete hapus;
}

void lihatTerakhir() {
    if (atas == NULL) {
        cout << "belum ada riwayat\n";
        return;
    }

    cout << "terakhir diproses: " << atas->pembeli << endl;
}


void lihatAntrian() {
    if (depan == NULL) {
        cout << "ga ada antrian\n";
        return;
    }

    Node* p = depan;
    cout << "\n-- list antrian --\n";
    while (p != NULL) {
        cout << p->pembeli << " | "
             << p->namaKereta << " | "
             << p->jumlah << endl;
        p = p->next;
    }
}

void lihatRiwayat() {
    if (atas == NULL) {
        cout << "riwayat masih kosong\n";
        return;
    }

    Node* p = atas;
    cout << "\n-- riwayat --\n";
    while (p != NULL) {
        cout << p->pembeli << " | "
             << p->namaKereta << " | "
             << p->jumlah << endl;
        p = p->next;
    }
}

void beli(Kereta *k, int n) {
    int no, jml;
    string nama;

    cout << "no kereta: "; cin >> no;
    cout << "nama: "; cin >> nama;
    cout << "jumlah: "; cin >> jml;

    for (int i = 0; i < n; i++) {
        if ((k+i)->no == no) {
            tambahAntrian(no, (k+i)->nama, nama, jml);
            return;
        }
    }

    cout << "kereta ga ada\n";
}

void proses(Kereta *k, int n) {
    Node t = ambilAntrian();

    if (t.pembeli == "") return;

    for (int i = 0; i < n; i++) {
        if ((k+i)->no == t.noKereta) {

            if ((k+i)->tiket >= t.jumlah) {
                (k+i)->tiket -= t.jumlah;

                cout << "diproses: " << t.pembeli << endl;

                masukRiwayat(t);
            } else {
                cout << "tiketnya ga cukup\n";
            }
            return;
        }
    }
}

int main() {

    Kereta data[3] = {
        {1,"argo","smd","bpn","08","10",150000,5},
        {2,"mahakam","smd","btg","09","11",90000,5},
        {3,"borneo","bpn","smd","07","09",120000,5}
    };

    int pilih;

    do {
        cout << "\n1 beli\n2 proses\n3 antrian\n4 riwayat\n5 hapus riwayat\n6 lihat terakhir\n0 keluar\npilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: beli(data,3); break;
            case 2: proses(data,3); break;
            case 3: lihatAntrian(); break;
            case 4: lihatRiwayat(); break;
            case 5: hapusRiwayat(); break;
            case 6: lihatTerakhir(); break;
        }

    } while(pilih != 0);
}