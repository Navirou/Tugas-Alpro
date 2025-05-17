#include <iostream>
using namespace std;

struct pelanggan
{
    string nama;
    string jenis_roti;
    int harga;
};

struct queue
{
    pelanggan *pelanggan;
    queue *next;
};

struct riwayat
{
    string nama;
    string jenis_roti;
    int harga;
};

struct stack
{
    riwayat *riwayat;
    stack *next;
};

// const int MAX_HISTORY = 100;
// riwayat history[MAX_HISTORY];
// int count = 0;

queue *depan, *belakang;
stack *awal, *top = NULL;

void buatstack()
{
    awal = top = NULL;
}

bool stackkosong()
{
    return awal == NULL;
}

void buatqueue()
{
    depan = NULL;
    belakang = NULL;
};

int queuekosong()
{
    return (depan == NULL);
}

void enqueue(string nama, string jenis_roti, int harga)
{
    queue *NB = new queue;
    NB->pelanggan = new pelanggan;
    NB->pelanggan->nama = nama;
    NB->pelanggan->jenis_roti = jenis_roti;
    NB->pelanggan->harga = harga;
    NB->next = NULL;

    if (depan == NULL)
    {
        depan = NB;
    }
    else
    {
        belakang->next = NB;
    }
    belakang = NB;
    cout << nama << " berhasil ditambahkan ke antrean!" << endl;
}

void dequeue()
{
    stack *NS = new stack();
    NS->riwayat = new riwayat;
    if (queuekosong())
    {
        cout << "Antrean kosong!" << endl;
    }
    else
    {
        queue *hapus = depan;

        NS->riwayat->nama = hapus->pelanggan->nama;
        NS->riwayat->jenis_roti = hapus->pelanggan->jenis_roti;
        NS->riwayat->harga = hapus->pelanggan->harga;
        NS->next = NULL;
        cout << "Pesanan atas nama " << hapus->pelanggan->nama << " telah dilayani dan disimpan ke history." << endl;
        if (stackkosong())
        {
            awal = top = NS;
        }
        else
        {
            NS->next = awal;
            awal = NS;
        }

        depan = depan->next;
        if (depan == NULL)
        {
            belakang = NULL;
        }

        delete hapus->pelanggan;
        delete hapus;
    }
}

void cetakqueue()
{
    int i = 0;
    queue *bantu = depan;
    if (bantu == NULL)
    {
        cout << "Antrean kosong!" << endl;
        return;
    }
    cout << "\n======= ANTREAN =======\n";
    cout << "------------------------\n";
    while (bantu != NULL)
    {
        cout << "Antrean #" << (i + 1) << endl;
        cout << "Nama       : " << bantu->pelanggan->nama << endl;
        cout << "Jenis Roti : " << bantu->pelanggan->jenis_roti << endl;
        cout << "Harga      : Rp" << bantu->pelanggan->harga << ",00" << endl;
        cout << "------------------------\n";
        bantu = bantu->next;
    }
}

void batalkanPesanan()
{
    if (queuekosong())
    {
        cout << "Antrean kosong!" << endl;
        return;
    }

    if (depan == belakang)
    {
        delete depan->pelanggan;
        delete depan;
        depan = NULL;
        belakang = NULL;
        return;
    }

    queue *bantu = depan;
    while (bantu->next != belakang)
    {
        bantu = bantu->next;
    }

    delete belakang->pelanggan;
    delete belakang;
    belakang = bantu;
    belakang->next = NULL;

    cout << "Pesanan terakhir telah dibatalkan." << endl;
}

void tampilkanHistory()
{
    int count = 0;
    stack *bantu = awal;
    if (stackkosong())
    {
        cout << "History Kosong!" << endl;
        return;
    }
    cout << "\n===== HISTORY PESANAN =====\n"; // dari yang terbaru ke yang lama
    cout << "------------------------\n";
    while (bantu != NULL)
    {
        cout << "Pesanan #" << (count + 1) << endl;
        cout << "Nama       : " << bantu->riwayat->nama << endl;
        cout << "Jenis Roti : " << bantu->riwayat->jenis_roti << endl;
        cout << "Harga      : Rp" << bantu->riwayat->harga << ",00" << endl;
        cout << "------------------------\n";
        bantu = bantu->next;
        count++;
    }
    cout << endl;
}

int main()
{
    system("cls");
    int pilihan;
    string a, b;
    int c;
    while (true)
    {
        cout << "===========================" << endl;
        cout << "|       Manis Lezat       |" << endl;
        cout << "===========================" << endl;
        cout << "| [1] Ambil Antrean       |" << endl;
        cout << "| [2] Layani Pembeli      |" << endl;
        cout << "| [3] Tampilkan Pesanan   |" << endl;
        cout << "| [4] Batalkan Pesanan    |" << endl;
        cout << "| [5] History Terbaru     |" << endl;
        cout << "| [0] Keluar              |" << endl;
        cout << "===========================" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "input nama : ";
            cin >> a;
            cout << "input jenis roti : ";
            cin >> b;
            cout << "input harga : ";
            cin >> c;
            enqueue(a, b, c);
            system("pause");
            system("cls");
            break;

        case 2:
            dequeue();
            system("pause");
            system("cls");
            break;

        case 3:
            cetakqueue();
            system("pause");
            system("cls");
            break;

        case 4:
            batalkanPesanan();
            system("pause");
            system("cls");
            break;

        case 5:
            tampilkanHistory();
            system("pause");
            system("cls");
            break;

        case 0:
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            return 0;

        default:
            cout << "Pilihan tidak valid!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}
