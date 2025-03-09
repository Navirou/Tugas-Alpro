#include <iostream>
#include <iomanip>
using namespace std;

struct StructFilm
{
    string judul;
    string kode;
    float rating;
}; 
StructFilm film[5] = {{"Dear Nathan", "K001", 8.9},
    {"Mariposa", "K002", 7.0},
    {"Agak Laen", "K003", 9.0},
    {"Dilan 1990", "K004", 7.4},
    {"Sekawan Limo", "K005", 6.5}};

void quick_sort (StructFilm *film, int awal, int akhir) {
    int low = awal;
    int high = akhir;
    int pivot = film[(awal + akhir) / 2].rating;
    int temp;
    do {
    while (film[low].rating > pivot)
        low++;
    while (film[high].rating < pivot)
        high--;
    if (low <= high) {
        swap(film[low], film[high]);
        low++;
        high--;
        }
    } while (low <= high);
    if (awal < high)
        quick_sort(film, awal, high);
    if (low < akhir)
        quick_sort(film, low, akhir);
} 

int main() {
    film;
    int jumlah = sizeof(film) /sizeof(film[0]);
    int pilihan;
    string cari;

    while (true)
    {
        cout << "==============================" << endl;
        cout << "|         BIOSKOP            |" << endl;
        cout << "==============================" << endl;
        cout << "| [1] Tampilkan Film         |" << endl;
        cout << "| [2] Cari Berdasarkan Kode  |" << endl;
        cout << "| [3] Cari Berdasarkan Judul |" << endl;
        cout << "| [4] Sort Rating Film (asc)  |" << endl;                
        cout << "| [5] Sort Rating Film (desc) |" << endl;
        cout << "| [0] Keluar                 |" << endl;
        cout << "==============================" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;
        switch(pilihan){
            case 1: {
                cout << "Daftar Film: " << endl; 
                cout << setfill('=') << setw(40) << "=" << endl;
                cout << setfill(' ');
                cout << left << setw(20) << "Judul" << setw(10) << "Kode" << setw(10) << "Rating" << endl;
                cout << setfill('=') << setw(40) << "=" << endl;
                cout << setfill(' ');
                cout << left << setw(20) << film[0].judul << setw(10) << film[0].kode
                << setw(10) << film[0].rating << endl;
                cout << left << setw(20) << film[1].judul << setw(10) << film[1].kode
                << setw(10) << film[1].rating << endl;
                cout << left << setw(20) << film[2].judul << setw(10) << film[2].kode
                << setw(10) << film[2].rating << endl;
                cout << left << setw(20) << film[3].judul << setw(10) << film[3].kode
                << setw(10) << film[3].rating << endl;
                cout << left << setw(20) << film[4].judul << setw(10) << film[4].kode
                << setw(10) << film[4].rating << endl;
                cout << setfill('=') << setw(40) << "=" << endl;
            }
            system("pause");
            break;


            case 2: {
                bool found = false;
                int c = 0;
                cout << "Masukkan Kode : ";
                cin >> cari;
                
                while (c < jumlah && found == false)
                {
                    if (film[c].kode == cari)
                    {
                        found = true;
                    } else {
                        c++;
                    }
                }
                if (found)
                    {
                        cout << "Judul : " << film[c].judul << " Kode : " << film[c].kode << " Rating : " << film[c].rating << endl;
                    } else {
                        cout << "Film tidak ditemukan" << endl;
                    }
            }
            system("pause");
            break;

            case 3: {
                bool found = false;
                int c = 0;
                int i = 0;
                int k = jumlah - 1;
                cin.ignore();
                cout << "Masukkan Judul : ";
                getline(cin, cari);
                for (int i = 0; i < k; i++) {
                    for (int j = 0; j < k - i; j++) {
                        if (film[j].judul > film[j + 1].judul) {
                            swap(film[j], film[j + 1]);
                        }
                    }
                }
                while ((!found) && (i <= k))
                {
                    c = (i+k)/2;
                    if (cari == film[c].judul)
                    {
                        found = true;
                    } else {
                        if (cari < film[c].judul)
                        {
                            k = c - 1;
                        } else {
                            i = c + 1;
                        }
                    }
                }
                if (found)
                    {
                        cout << "Judul : " << film[c].judul << " Kode : " << film[c].kode << " Rating : " << film[c].rating << endl;
                    } else {
                        cout << "Film tidak ditemukan" << endl;
                    }
            }
            system("pause");
            break;

            case 4: {
                int c = jumlah;
                for (int i = 0; i < c - 1; i++) {
                    for (int j = 0; j < c - 1 - i; j++) {
                        if (film[j].rating > film[j + 1].rating) {
                            swap(film[j], film[j + 1]);
                        }
                    }
                }
                cout << "\nData yang diurutkan (Ascending) :" << endl;
                cout << setfill('=') << setw(30) << "=" << endl;
                cout << setfill(' ');
                for (int i = 0; i < c; i++) {
                    cout << setw(15) << left << film[i].judul << setw(10) << film[i].kode << setw(5) << film[i].rating << endl;
                }
                cout << setfill('=') << setw(30) << "=" << endl;
                cout << setfill(' ');
            }
            system("pause");
            break;
 
            case 5:{
                int awal = 0;
                int akhir = jumlah - 1;
                quick_sort(film, awal, akhir);
                cout << "\nData yang diurutkan (descending) :" << endl;
                cout << setfill('=') << setw(30) << "=" << endl;
                cout << setfill(' ');
                for (int i = 0; i < jumlah; i++)
                {
                    cout << setw(15) << left << film[i].judul << setw(10) << film[i].kode << setw(5) << film[i].rating << endl;
                }
                cout << setfill('=') << setw(30) << "=" << endl;
                cout << setfill(' ');
            }
            system("pause");
            break;

            case 0: {
                cout << "gapunya duit yaa? kok cuma liat liat doang.." << endl;
                return 0;
            }
            
            default:
            cout << "Maaf, pilihan tidak valid" << endl;
        }
    }
    

}


