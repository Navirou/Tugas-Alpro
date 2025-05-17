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

struct stack
{
    pelanggan *pelanggan;
    stack *next;
};

struct riwayat
{
    string nama;
    string jenis_roti;
    int harga;
};

const int MAX_HISTORY = 100;
riwayat history[MAX_HISTORY];
int count = 0;

queue *depan, *belakang;
stack *top = NULL;

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

    stack *NS = new stack;
    NS->pelanggan = NB->pelanggan;
    NS->next = top;
    top = NS;
    cout << nama << " berhasil ditambahkan ke antrean!" << endl;
}

void dequeue()
{
    if (queuekosong())
    {
        cout << "Antrean kosong!" << endl;
    }
    else
    {
        queue *hapus = depan;

        if (count < MAX_HISTORY)
        {
            history[count].nama = hapus->pelanggan->nama;
            history[count].jenis_roti = hapus->pelanggan->jenis_roti;
            history[count].harga = hapus->pelanggan->harga;
            count++;
            cout << "Pesanan atas nama " << hapus->pelanggan->nama << " telah dilayani dan disimpan ke history." << endl;
        }
        else
        {
            cout << "History penuh, pesanan dilayani tetapi tidak disimpan ke history." << endl;
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
        cout << bantu->pelanggan->nama << endl;
        cout << bantu->pelanggan->jenis_roti << endl;
        cout << bantu->pelanggan->harga << endl;
        cout << "------------------------\n";
        bantu = bantu->next;
    }
}

void batalkanPesanan()
{
    if (top == NULL)
    {
        cout << "Antrean kosong!" << endl;
        return;
    }

    pelanggan *batal = top->pelanggan;
    string nama_dibatalkan = batal->nama;

    stack *temp = top;
    top = top->next;
    delete temp;

    if (queuekosong())
    {
        cout << "Antrean kosong!" << endl;
        return;
    }

    queue *current = depan;
    while (current->next != NULL && current->next->pelanggan != batal)
    {
        current = current->next;
    }

    if (current->next != NULL)
    {
        queue *temp_queue = current->next;
        current->next = temp_queue->next;

        if (temp_queue == belakang)
        {
            belakang = current;
        }

        delete temp_queue->pelanggan;
        delete temp_queue;
    }

    cout << "Pesanan atas nama " << nama_dibatalkan << " telah dibatalkan." << endl;
}

void tampilkanHistory()
{
    if (count == 0)
    {
        cout << "Belum ada riwayat pesanan!" << endl;
        return;
    }

    cout << "\n===== HISTORY PESANAN =====\n";
    cout << "Menampilkan " << count << " pesanan terakhir yang dilayani:\n" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "Pesanan #" << (i + 1) << endl;
        cout << "Nama: " << history[i].nama << endl;
        cout << "Jenis Roti: " << history[i].jenis_roti << endl;
        cout << "Harga: Rp" << history[i].harga << endl;
        cout << "------------------------\n";
    }
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
        cout << "| [5] History Pesanan     |" << endl;
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
