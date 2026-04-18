#include <iostream>
using namespace std;

#define MAX 5

struct Hewan {
    int id;
    string nama;
    string jenis;
};

struct Tiket {
    string nama;
    string rute;
};


struct AntrianHewan {
    Hewan data[MAX];
    int depan, belakang;
};

struct RiwayatHewan {
    Hewan data[MAX];
    int top;
};

struct AntrianTiket {
    Tiket data[MAX];
    int depan, belakang;
};

struct RiwayatTiket {
    Tiket data[MAX];
    int top;
};


void initHewan(AntrianHewan *a, RiwayatHewan *r){
    a->depan = a->belakang = -1;
    r->top = -1;
}

void initTiket(AntrianTiket *a, RiwayatTiket *r){
    a->depan = a->belakang = -1;
    r->top = -1;
}


void daftarHewan(AntrianHewan *a, Hewan h){
    if(a->belakang == MAX-1){
        cout<<"Antrian penuh bro\n";
        return;
    }

    if(a->depan == -1) a->depan = 0;

    a->belakang++;
    *(a->data + a->belakang) = h; // pake pointer biar sesuai syarat

    cout<<"Hewan masuk antrian...\n";
}


Hewan panggilHewan(AntrianHewan *a){
    Hewan h;

    if(a->depan == -1){
        cout<<"Belum ada antrian\n";
        return h;
    }

    h = *(a->data + a->depan);

    if(a->depan == a->belakang)
        a->depan = a->belakang = -1;
    else
        a->depan++;

    return h;
}


void simpanRiwayatHewan(RiwayatHewan *r, Hewan h){
    if(r->top == MAX-1){
        cout<<"Riwayat penuh\n";
        return;
    }

    r->top++;
    *(r->data + r->top) = h;
}


void undoHewan(RiwayatHewan *r){
    if(r->top == -1){
        cout<<"Belum ada riwayat\n";
        return;
    }

    cout<<"Ngapus data: "<<(r->data + r->top)->nama<<endl;
    r->top--;
}


void lihatAntrianHewan(AntrianHewan *a){
    if(a->depan == -1){
        cout<<"Kosong\n";
        return;
    }

    cout<<"\n-- list antrian hewan --\n";
    for(Hewan *p = a->data + a->depan; p <= a->data + a->belakang; p++){
        cout<<p->id<<" | "<<p->nama<<" | "<<p->jenis<<endl;
    }
}

// tampil riwayat
void lihatRiwayatHewan(RiwayatHewan *r){
    if(r->top == -1){
        cout<<"Kosong\n";
        return;
    }

    cout<<"\n-- riwayat tindakan --\n";
    for(Hewan *p = r->data; p <= r->data + r->top; p++){
        cout<<p->id<<" | "<<p->nama<<" | "<<p->jenis<<endl;
    }
}


void pesanTiket(AntrianTiket *a, Tiket t){
    if(a->belakang == MAX-1){
        cout<<"Antrian tiket full\n";
        return;
    }

    if(a->depan == -1) a->depan = 0;

    a->belakang++;
    *(a->data + a->belakang) = t;

    cout<<"Masuk antrian tiket\n";
}

Tiket prosesTiket(AntrianTiket *a){
    Tiket t;

    if(a->depan == -1){
        cout<<"Ga ada antrian\n";
        return t;
    }

    t = *(a->data + a->depan);

    if(a->depan == a->belakang)
        a->depan = a->belakang = -1;
    else
        a->depan++;

    return t;
}

void simpanRiwayatTiket(RiwayatTiket *r, Tiket t){
    if(r->top == MAX-1){
        cout<<"Riwayat penuh\n";
        return;
    }

    r->top++;
    *(r->data + r->top) = t;
}

void undoTiket(RiwayatTiket *r){
    if(r->top == -1){
        cout<<"Kosong\n";
        return;
    }

    cout<<"Hapus: "<<(r->data + r->top)->nama<<endl;
    r->top--;
}

void lihatAntrianTiket(AntrianTiket *a){
    if(a->depan == -1){
        cout<<"Kosong\n";
        return;
    }

    cout<<"\n-- antrian tiket --\n";
    for(Tiket *p = a->data + a->depan; p <= a->data + a->belakang; p++){
        cout<<p->nama<<" | "<<p->rute<<endl;
    }
}

void lihatRiwayatTiket(RiwayatTiket *r){
    if(r->top == -1){
        cout<<"Kosong\n";
        return;
    }

    cout<<"\n-- riwayat transaksi --\n";
    for(Tiket *p = r->data; p <= r->data + r->top; p++){
        cout<<p->nama<<" | "<<p->rute<<endl;
    }
}

int main(){
    AntrianHewan aH; RiwayatHewan rH;
    AntrianTiket aT; RiwayatTiket rT;

    initHewan(&aH, &rH);
    initTiket(&aT, &rT);

    int pilih, sub;
    Hewan h;
    Tiket t;

    do{
        cout<<"\n=== MENU UTAMA ===\n";
        cout<<"1. Pawcare\n2. Kereta\n0. Keluar\n";
        cin>>pilih;

        if(pilih==1){
            do{
                cout<<"\n[PAWCARE]\n";
                cout<<"1. Daftar\n2. Panggil\n3. Undo\n4. Lihat Antrian\n5. Lihat Riwayat\n0. Back\n";
                cin>>sub;

                if(sub==1){
                    cout<<"id nama jenis: ";
                    cin>>h.id>>h.nama>>h.jenis;
                    daftarHewan(&aH,h);
                }
                else if(sub==2){
                    h = panggilHewan(&aH);
                    if(h.nama!=""){
                        cout<<">> Dipanggil: "<<h.nama<<endl;
                        simpanRiwayatHewan(&rH,h);
                    }
                }
                else if(sub==3) undoHewan(&rH);
                else if(sub==4) lihatAntrianHewan(&aH);
                else if(sub==5) lihatRiwayatHewan(&rH);

            }while(sub!=0);
        }

        else if(pilih==2){
            do{
                cout<<"\n[KERETA]\n";
                cout<<"1. Pesan\n2. Proses\n3. Undo\n4. Antrian\n5. Riwayat\n0. Back\n";
                cin>>sub;

                if(sub==1){
                    cout<<"nama rute: ";
                    cin>>t.nama>>t.rute;
                    pesanTiket(&aT,t);
                }
                else if(sub==2){
                    t = prosesTiket(&aT);
                    if(t.nama!=""){
                        cout<<">> Diproses: "<<t.nama<<endl;
                        simpanRiwayatTiket(&rT,t);
                    }
                }
                else if(sub==3) undoTiket(&rT);
                else if(sub==4) lihatAntrianTiket(&aT);
                else if(sub==5) lihatRiwayatTiket(&rT);

            }while(sub!=0);
        }

    }while(pilih!=0);
}