#include <iostream>
#include <iomanip>
using namespace std;

struct Data
{
    int id;
    char nama[50];
    int gaji;
};

const int MAX_DATA = 1000;

int bacaFile(Data dataPegawai[])
{
    FILE *file = fopen("pegawai.dat", "rb");
    if (!file)
    {
        cout << "File tidak ditemukan!" << endl;
        return 0;
    }

    int count = 0;
    while (fread(&dataPegawai[count], sizeof(Data), 1, file))
    {
        count++;
    }

    fclose(file);
    return count;
}
// void tulisFile(Data dataPegawai[], int jumlah)
// {
// }

void tambahData(Data dataPegawai[], int &jumlah)
{
    if (jumlah >= MAX_DATA)
    {
        cout << "Data penuh!" << endl;
        return;
    }
    cout << "Masukkan id pegawai: ";
    cin >> dataPegawai[jumlah].id;
    cout << "Masukkan nama: ";
    cin >> dataPegawai[jumlah].nama;
    cout << "Masukkan gaji: ";
    cin >> dataPegawai[jumlah].gaji;
    jumlah++;

    FILE *file = fopen("pegawai.dat", "wb");
    if (!file)
    {
        cout << "Gagal membuka file!" << endl;
        return;
    }

    for (int i = 0; i < jumlah; i++)
    {
        fwrite(&dataPegawai[i], sizeof(Data), 1, file);
    }

    fclose(file);
    cout << "Data berhasil ditambahkan!\n";
}

void tampilkanData(Data dataPegawai[], int jumlah)
{

    FILE *file = fopen("pegawai.dat", "rb");
    if (!file)
    {
        cout << "Gagal membuka file!" << endl;
        return;
    }
    int i = 0;
    cout << "\ndata pegawai:\n";

    int k = jumlah - 1;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k - i; j++)
        {
            if (dataPegawai[j].id > dataPegawai[j + 1].id)
            {
                swap(dataPegawai[j], dataPegawai[j + 1]);
            }
        }
    }

    while (fread(&dataPegawai[jumlah], sizeof(Data), 1, file) && i < jumlah)
    {
        cout << "ID Pegawai: " << dataPegawai[i].id << endl;
        cout << "Nama Pegawai: " << dataPegawai[i].nama << endl;
        cout << "Gaji Pegawai: " << dataPegawai[i].gaji << endl
             << endl;
        i++;
    }
    fclose(file);
}

void cariData(Data dataPegawai[], int jumlah, int cari)
{
    FILE *file = fopen("pegawai.dat", "rb");
    if (!file)
    {
        cout << "Gagal membuka file!" << endl;
        return;
    }
    int i = 0;
    bool found = false;
    while (fread(&dataPegawai[jumlah], sizeof(Data), 1, file) && i < jumlah)
    {
        if (dataPegawai[i].id == cari)
        {
            cout << "ID Pegawai: " << dataPegawai[i].id << endl;
            cout << "Nama Pegawai: " << dataPegawai[i].nama << endl;
            cout << "Gaji Pegawai: " << dataPegawai[i].gaji << endl;
            found = true;
            break;
        }
        else
        {
            i++;
        }
    }
    if (!found)
    {
        cout << "Data tidak ditemukan!" << endl;
    }
    fclose(file);
}

void updateGaji(Data dataPegawai[], int jumlah, int cari)
{
    FILE *file = fopen("pegawai.dat", "rb+");
    if (!file)
    {
        cout << "Gagal membuka file!" << endl;
        return;
    }
    int i = 0;
    bool found = false;
    while (fread(&dataPegawai[jumlah], sizeof(Data), 1, file) && i < jumlah)
    {
        if (dataPegawai[i].id == cari)
        {
            cout << "ID Pegawai: " << dataPegawai[i].id << endl;
            cout << "Nama Pegawai: " << dataPegawai[i].nama << endl;
            cout << "Gaji Pegawai: " << dataPegawai[i].gaji << endl;
            int gajiBaru;
            cout << "Masukkan gaji baru: ";
            cin >> gajiBaru;
            dataPegawai[i].gaji = gajiBaru;
            found = true;
            break;
        }
        i++;
    }
    fclose(file);
    if (found)
    {
        file = fopen("pegawai.dat", "wb");
        for (int i = 0; i < jumlah; i++)
        {
            fwrite(&dataPegawai[i], sizeof(Data), 1, file);
        }
        fclose(file);
        cout << "Gaji berhasil diupdate!" << endl;
    }
    else
    {
        cout << "Data tidak ditemukan!" << endl;
    }
}

int main()
{
    Data dataPegawai[MAX_DATA];
    int pilihan;
    int jumlah = bacaFile(dataPegawai);
    int cari;
    int tambah;
    do
    {
        cout << "\nSI Kepegawaian" << endl;
        cout << "1. Tambah Data Pegawai" << endl;
        cout << "2. Tampilkan Semua Data" << endl;
        cout << "3. Cari Pegawai ID" << endl;
        cout << "4. Perbarui Gaji Pegawai" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "Masukkan jumlah data yang ingin ditambahkan: ";

            cin >> tambah;
            for (int i = 0; i < tambah; i++)
            {
                tambahData(dataPegawai, jumlah);
            }

            break;
        case 2:
            tampilkanData(dataPegawai, jumlah);
            break;
        case 3:
            cout << "Masukkan ID yang dicari: ";
            cin >> cari;
            cariData(dataPegawai, jumlah, cari);
            break;
        case 4:
            cout << "Masukkan ID yang dicari: ";
            cin >> cari;
            updateGaji(dataPegawai, jumlah, cari);
            break;
        case 5:
            cout << "Keluar dari program..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);
}