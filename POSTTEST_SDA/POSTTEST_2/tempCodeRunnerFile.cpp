#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Kereta {
    int no;
    string nama;
    string asal;
    string tujuan;
    string jamBerangkat;
    string jamTiba;
    int harga;
    int tiket;
};

struct Transaksi {
    int noKereta;
    string namaKereta;
    string namaPembeli;   
    int jumlah;           
};

void swapKereta(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr, int n) {
    cout << "\n=== JADWAL KERETA KA KALTIMTARA XXV ===\n";
    for (int i = 0; i < n; i++) {
        cout << (arr + i)->no << " | "
             << (arr + i)->nama << " | "
             << (arr + i)->asal << " -> "
             << (arr + i)->tujuan << " | "
             << (arr + i)->jamBerangkat << " - "
             << (arr + i)->jamTiba << " | Rp"
             << (arr + i)->harga << " | Tiket: "
             << (arr + i)->tiket << endl;
    }
}

void tambah(Kereta *arr, int &n) {
    cout << "\n=== INPUT DATA KERETA KA KALTIMTARA XXV ===\n";
    cout << "No: ";
    cin >> (arr + n)->no;
    cin.ignore();
    cout << "Nama: ";
    getline(cin, (arr + n)->nama);
    cout << "Asal: ";
    getline(cin, (arr + n)->asal);
    cout << "Tujuan: ";
    getline(cin, (arr + n)->tujuan);
    cout << "Jam Berangkat: ";
    getline(cin, (arr + n)->jamBerangkat);
    cout << "Jam Tiba: ";
    getline(cin, (arr + n)->jamTiba);
    cout << "Harga: ";
    cin >> (arr + n)->harga;
    cout << "Tiket: ";
    cin >> (arr + n)->tiket;
    n++;
}

void linearSearch(Kereta *arr, int n, string asal, string tujuan) {
    bool ketemu = false;
    cout << "\nProses pencarian:\n";
    for (int i = 0; i < n; i++) {
        cout << "Cek data ke-" << i << endl;
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Tidak ditemukan\n";
}

void beliTiket(Kereta *arr, int n, Transaksi *t, int &jml) {
    int no, jumlah;
    string nama;

    cout << "Masukkan nomor kereta: ";
    cin >> no;

    cout << "Nama pembeli: ";
    cin >> nama;

    cout << "Jumlah tiket: ";
    cin >> jumlah;

    for (int i = 0; i < n; i++) {
        if ((arr + i)->no == no) {

            if ((arr + i)->tiket >= jumlah) {

                (arr + i)->tiket -= jumlah;

                (t + jml)->noKereta = (arr + i)->no;
                (t + jml)->namaKereta = (arr + i)->nama;
                (t + jml)->namaPembeli = nama;
                (t + jml)->jumlah = jumlah;

                jml++;

                cout << "Pembelian berhasil!\n";
            } else {
                cout << "Tiket tidak cukup!\n";
            }
            return;
        }
    }

    cout << "Kereta tidak ditemukan\n";
}

void lihatTransaksi(Transaksi *t, int jml) {
    cout << "\n=== RIWAYAT PEMBELIAN TIKET KA KALTIMTARA XXV===\n";

    cout << " " << left << setw(10) << "No Kereta"
         << "| " << setw(13) << "Nama Kereta"
         << "| " << setw(10) << "Pembeli"
         << "| " << setw(10) << "Jumlah" << "\n";

    cout << "--------------------------------------------------\n";

    for (int i = 0; i < jml; i++) {
        cout << "| " << left << setw(10) << (t + i)->noKereta
             << "| " << setw(13) << (t + i)->namaKereta
             << "| " << setw(10) << (t + i)->namaPembeli
             << "| " << setw(10) << (t + i)->jumlah << "\n";
    }

    cout << "--------------------------------------------------\n";
}
Transaksi riwayat[100];
int jumlahTransaksi = 0;

int jumpSearch(Kereta *arr, int n, int key) {
    int step = sqrt(n);
    int prev = 0;

    while ((arr + min(step, n) - 1)->no < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < min(step, n); i++) {
        if ((arr + i)->no == key)
            return i;
    }

    return -1;
}

void selectionSort(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + min)->harga)
                min = j;
        }
        swapKereta(arr + i, arr + min);
    }
}

void merge(Kereta *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta L[50], R[50];

    for (int i = 0; i < n1; i++)
        L[i] = *(arr + l + i);
    for (int j = 0; j < n2; j++)
        R[j] = *(arr + m + 1 + j);

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama) {
            *(arr + k) = L[i];
            i++;
        } else {
            *(arr + k) = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        *(arr + k) = L[i];
        i++; k++;
    }
    while (j < n2) {
        *(arr + k) = R[j];
        j++; k++;
    }
}

void mergeSort(Kereta *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    Kereta data[100];
    int n = 3;


   data[0] = {311, "Argojak", "Samarinda", "Balikpapan", "08:00", "10:00", 150000, 4000};
   data[1] = {109, "Mahakam I", "Samarinda", "Bontang", "09:00", "11:30", 90000, 4000};
   data[2] = {206, "Borneo V", "Balikpapan", "Samarinda", "07:30", "09:30", 120000, 4000};

    int pilih;

    do {
        cout << "\n=== MENU KA KALTIMTARA XXV ===\n";
        cout << "1. Tampil\n";
        cout << "2. Tambah\n";
        cout << "3. Cari Rute \n";
        cout << "4. Cari No \n";
        cout << "5. Beli Tiket\n";
        cout << "6. Sort Nama \n";
        cout << "7. Sort Harga \n";
        cout << "8. Lihat Riwayat\n";
        cout << "9. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) tampil(data, n);

        else if (pilih == 2) tambah(data, n);
        

        else if (pilih == 3) {
            string a, t;
            cout << "Asal: "; cin >> a;
            cout << "Tujuan: "; cin >> t;
            linearSearch(data, n, a, t);
            cout << "\nTekan ENTER untuk kembali ke menu...";
                 cin.ignore();
                 cin.get();
        }

        else if (pilih == 4) {
            int key;
            cout << "No kereta: "; cin >> key;
            int idx = jumpSearch(data, n, key);
            if (idx != -1)
                cout << "Ketemu: " << (data + idx)->nama << endl;
            else
                cout << "Tidak ditemukan\n";
                cout << "\nTekan ENTER untuk kembali ke menu...";
                    cin.ignore();
                    cin.get();
        }

        else if (pilih == 5) {
            beliTiket(data, n, riwayat, jumlahTransaksi);
            cout << "\nTekan ENTER untuk kembali ke menu...";
                 cin.ignore();
                 cin.get();
        
        }

        else if (pilih == 6) {
            mergeSort(data, 0, n - 1);
            cout << "Sudah diurutkan berdasarkan nama\n";
            cout << "\nTekan ENTER untuk kembali ke menu...";
                 cin.ignore();
                 cin.get();
    
        }

        else if (pilih == 7) {
            selectionSort(data, n);
            cout << "Sudah diurutkan berdasarkan harga\n";
            cout << "\nTekan ENTER untuk kembali ke menu...";
                 cin.ignore();
                 cin.get();
        
        }

        else if (pilih == 8) {
            lihatTransaksi(riwayat, jumlahTransaksi);
            cout << "\nTekan ENTER untuk kembali ke menu...";
                 cin.ignore();
                 cin.get();
        
        }  

        else if (pilih == 9) {
            cout << "\nTekan ENTER untuk keluar...";
                 cin.ignore();
                 cin.get();
    cout << "\n=====================================\n";
    cout << " Terima kasih telah menggunakan\n";
    cout << " Kereta Api Indonesia\n";
    cout << " KA KALTIMTARA XXV \n";
    cout << "\nSemoga perjalananmu menyenangkan \n";
    cout << "=====================================\n";
    cout << " Program selesai...\n";
    break;
}


    } while (pilih != 0);

    return 0;
}