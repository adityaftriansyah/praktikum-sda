#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAX 100

// =======================
// STRUCT
// =======================
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

// =======================
// QUEUE & STACK
// =======================
struct Queue {
    Transaksi data[MAX];
    int front, rear;
};

struct Stack {
    Transaksi data[MAX];
    int top;
};

// =======================
// INIT
// =======================
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

void initStack(Stack *s) {
    s->top = -1;
}

// =======================
// CEK
// =======================
bool isQueueFull(Queue *q) { return q->rear == MAX - 1; }
bool isQueueEmpty(Queue *q) { return q->front == -1; }

bool isStackFull(Stack *s) { return s->top == MAX - 1; }
bool isStackEmpty(Stack *s) { return s->top == -1; }

// =======================
// QUEUE
// =======================
void enqueue(Queue *q, Transaksi t) {
    if (isQueueFull(q)) {
        cout << "Antrian penuh!\n";
        return;
    }
    if (isQueueEmpty(q)) q->front = 0;

    q->rear++;
    *(q->data + q->rear) = t;

    cout << "Masuk antrian!\n";
}

Transaksi dequeue(Queue *q) {
    Transaksi t;

    if (isQueueEmpty(q)) {
        cout << "Antrian kosong!\n";
        return t;
    }

    t = *(q->data + q->front);

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return t;
}

// =======================
// STACK
// =======================
void push(Stack *s, Transaksi t) {
    if (isStackFull(s)) {
        cout << "Riwayat penuh!\n";
        return;
    }

    s->top++;
    *(s->data + s->top) = t;
}

void pop(Stack *s) {
    if (isStackEmpty(s)) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Hapus transaksi: "
         << (s->data + s->top)->namaPembeli << endl;

    s->top--;
}

// =======================
// FITUR LAMA
// =======================
void swapKereta(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr, int n) {
    cout << "\n=== JADWAL KERETA ===\n";
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
    cout << "\n=== INPUT DATA ===\n";
    cout << "No: "; cin >> (arr + n)->no;
    cin.ignore();
    cout << "Nama: "; getline(cin, (arr + n)->nama);
    cout << "Asal: "; getline(cin, (arr + n)->asal);
    cout << "Tujuan: "; getline(cin, (arr + n)->tujuan);
    cout << "Jam Berangkat: "; getline(cin, (arr + n)->jamBerangkat);
    cout << "Jam Tiba: "; getline(cin, (arr + n)->jamTiba);
    cout << "Harga: "; cin >> (arr + n)->harga;
    cout << "Tiket: "; cin >> (arr + n)->tiket;
    n++;
}

void linearSearch(Kereta *arr, int n, string asal, string tujuan) {
    bool ketemu = false;
    for (int i = 0; i < n; i++) {
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Tidak ditemukan\n";
}

// =======================
// BELI → MASUK QUEUE
// =======================
void beliTiket(Kereta *arr, int n, Queue *q) {
    Transaksi t;
    int no;

    cout << "No kereta: "; cin >> no;
    cout << "Nama pembeli: "; cin >> t.namaPembeli;
    cout << "Jumlah tiket: "; cin >> t.jumlah;

    for (int i = 0; i < n; i++) {
        if ((arr + i)->no == no) {
            t.noKereta = (arr + i)->no;
            t.namaKereta = (arr + i)->nama;
            enqueue(q, t);
            return;
        }
    }

    cout << "Kereta tidak ditemukan\n";
}

// =======================
// PROSES TIKET
// =======================
void prosesTiket(Kereta *arr, int n, Queue *q, Stack *s) {
    Transaksi t = dequeue(q);

    if (t.namaPembeli == "") return;

    for (int i = 0; i < n; i++) {
        if ((arr + i)->no == t.noKereta) {

            if ((arr + i)->tiket >= t.jumlah) {
                (arr + i)->tiket -= t.jumlah;

                cout << "Diproses: "
                     << t.namaPembeli << " | "
                     << t.namaKereta << endl;

                push(s, t);
            } else {
                cout << "Tiket tidak cukup!\n";
            }
            return;
        }
    }
}

// =======================
// TAMPIL
// =======================
void tampilQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    for (Transaksi *p = q->data + q->front; p <= q->data + q->rear; p++) {
        cout << p->namaPembeli << " | "
             << p->namaKereta << " | "
             << p->jumlah << endl;
    }
}

void tampilStack(Stack *s) {
    if (isStackEmpty(s)) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    for (Transaksi *p = s->data; p <= s->data + s->top; p++) {
        cout << p->namaPembeli << " | "
             << p->namaKereta << " | "
             << p->jumlah << endl;
    }
}

// =======================
// PEEK
// =======================
void peek(Queue *q, Stack *s) {
    if (!isQueueEmpty(q))
        cout << "Depan: " << (q->data + q->front)->namaPembeli << endl;

    if (!isStackEmpty(s))
        cout << "Terakhir: " << (s->data + s->top)->namaPembeli << endl;
}

// =======================
// MAIN
// =======================
int main() {
    Kereta data[100] = {
        {311, "Argojak", "Samarinda", "Balikpapan", "08:00", "10:00", 150000, 10},
        {109, "Mahakam", "Samarinda", "Bontang", "09:00", "11:30", 90000, 10},
        {206, "Borneo", "Balikpapan", "Samarinda", "07:30", "09:30", 120000, 10}
    };

    int n = 3;

    Queue q;
    Stack s;

    initQueue(&q);
    initStack(&s);

    int pilih;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tampil\n";
        cout << "2. Tambah\n";
        cout << "3. Cari Rute\n";
        cout << "5. Beli (Antrian)\n";
        cout << "6. Proses Tiket\n";
        cout << "7. Tampil Antrian\n";
        cout << "8. Tampil Riwayat\n";
        cout << "9. Pop Riwayat\n";
        cout << "10. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
        case 1: tampil(data, n); break;
        case 2: tambah(data, n); break;
        case 3: {
            string a, t;
            cout << "Asal: "; cin >> a;
            cout << "Tujuan: "; cin >> t;
            linearSearch(data, n, a, t);
            break;
        }
        case 5: beliTiket(data, n, &q); break;
        case 6: prosesTiket(data, n, &q, &s); break;
        case 7: tampilQueue(&q); break;
        case 8: tampilStack(&s); break;
        case 9: pop(&s); break;
        case 10: peek(&q, &s); break;
        }

    } while (pilih != 0);

    return 0;
}