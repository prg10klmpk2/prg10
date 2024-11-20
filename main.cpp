#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan informasi kos
struct kos {
    string nama;
    float jarak;
    float harga;
    string daerah;
    float hargaSetelahDiskon;
};

// Fungsi untuk input data kos
void inputData(kos data[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nInput data kos ke-" << i + 1 << ":\n";
        cout << "Nama kos-kosan: ";
        getline(cin, data[i].nama);
        cout << "Jarak dari kampus (km): ";
        cin >> data[i].jarak;
        cout << "Harga sewa per bulan: ";
        cin >> data[i].harga;

        char adaDiskon;
        cout << "Apakah ada diskon? (y/n): ";
        cin >> adaDiskon;

        if (adaDiskon == 'y' || adaDiskon == 'Y') {
            float diskon;
            cout << "Masukkan diskon (0-1): ";
            cin >> diskon;
            data[i].hargaSetelahDiskon = data[i].harga - (data[i].harga * diskon);
        } else {
            data[i].hargaSetelahDiskon = data[i].harga;
        }

        cin.ignore();
        cout << "Nama daerah: ";
        getline(cin, data[i].daerah);
    }
}

// Fungsi untuk mengurutkan berdasarkan harga menggunakan rekursi (Bubble Sort)
void urutkanBerdasarkanHarga(kos data[], int n) {
    if (n == 1) return; // Kasus basis: jika hanya 1 elemen, selesai

    for (int i = 0; i < n - 1; i++) {
        if (data[i].hargaSetelahDiskon > data[i + 1].hargaSetelahDiskon) {
            kos temp = data[i];
            data[i] = data[i + 1];
            data[i + 1] = temp;
        }
    }

    urutkanBerdasarkanHarga(data, n - 1);
}

// Fungsi untuk menampilkan daftar kos menggunakan rekursi
void tampilkanData(kos data[], int n, int index = 0) {
    if (index == n) return; // Kasus basis: jika indeks sudah melebihi jumlah data
    cout << "Nama: " << data[index].nama
         << "\nJarak: " << data[index].jarak << " km"
         << "\nHarga (Setelah Diskon Jika Ada): Rp" << data[index].hargaSetelahDiskon
         << "\nDaerah: " << data[index].daerah << "\n";

    tampilkanData(data, n, index + 1); 
}

// Fungsi untuk mencari kos-kosan sesuai nama
void cariBerdasarkanNama(kos data[], int n, string carinama) {
    for (int i = 0; i < n; i++) {
        if (data[i].nama == carinama) {
            cout << "data kos dengan nama " << data[i].nama
                 << "\nJarak: " << data[i].jarak << " km"
                 << "\nHarga (Setelah Diskon Jika Ada): Rp" << data[i].hargaSetelahDiskon
                 << "\nDaerah: " << data[i].daerah << "\n";
                 return;
        }
    }
    cout << "Kos dengan nama tersebut tidak ditemukan \n";
}

int main() {
    while (true) {
        int n;
        do {
            cout << "Berapa banyak data kos yang ingin diinput? ";
            cin >> n;
            cin.ignore();

            if (n <= 0) {
                cout << "Jumlah data harus lebih dari nol.\n";
            }
        } while (n <= 0);

        kos data[n];
        int pilihan;

        while (true) {
            bool lanjut = true;
            cout << "\nMenu:\n";
            cout << "1. Input data kos\n";
            cout << "2. Urutkan berdasarkan harga\n";
            cout << "3. Cari kos-kosan berdasarkan nama\n";
            cout << "4. Tampilkan semua data kos\n";
            cout << "5. Ulangi seluruh program\n";
            cout << "6. Keluar\n";
            cout << "Masukkan pilihan Anda: ";
            cin >> pilihan;
            cin.ignore();
            cout << endl;

            switch (pilihan) {
                case 1:
                    inputData(data, n);
                    break;
                case 2:
                    urutkanBerdasarkanHarga(data, n);
                    cout << "Data berhasil diurutkan berdasarkan harga.\n";
                    tampilkanData(data, n);
                    break;
                case 3: {
                    string carinama;
                    cout << "\nMasukkan nama kos-kosan: ";
                    getline(cin, carinama);
                    cariBerdasarkanNama(data, n, carinama);
                    break;
                }
                case 4:
                    tampilkanData(data, n);
                    break;
                case 5:
                    lanjut = false;
                    break;
                case 6:
                    cout << "Keluar dari program.\n"; 
                    return 0;
                default:
                    cout << "Pilihan tidak valid. Coba lagi.\n";
            }
            if (lanjut == false) break;
        }
    }
    return 0;
}
