#include <stdio.h>
#include <string.h>

// Maksimum jumlah mahasiswa yang dapat disimpan
#define MAX_MAHASISWA 10

// Struktur data mahasiswa
struct Mahasiswa {
    char nama[50];
    int nim;
    float ipk;
};

// Deklarasi array untuk menyimpan data mahasiswa
struct Mahasiswa daftarMahasiswa[MAX_MAHASISWA];

// Jumlah mahasiswa yang saat ini ada dalam daftar
int jumlahMahasiswa = 0;

// Fungsi untuk menambahkan data mahasiswa
void tambahMahasiswa() {
    if (jumlahMahasiswa < MAX_MAHASISWA) {
        struct Mahasiswa m;
        printf("Masukkan Nama Mahasiswa: ");
        scanf("%s", m.nama);
        printf("Masukkan NIM Mahasiswa: ");
        scanf("%d", &m.nim);
        printf("Masukkan IPK Mahasiswa: ");
        scanf("%f", &m.ipk);
        
        daftarMahasiswa[jumlahMahasiswa++] = m;
        printf("Mahasiswa berhasil ditambahkan!\n");
    } else {
        printf("Daftar sudah penuh!\n");
    }
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa() {
    if (jumlahMahasiswa > 0) {
        printf("Daftar Mahasiswa:\n");
        for (int i = 0; i < jumlahMahasiswa; i++) {
            printf("Nama: %s\n", daftarMahasiswa[i].nama);
            printf("NIM: %d\n", daftarMahasiswa[i].nim);
            printf("IPK: %.2f\n", daftarMahasiswa[i].ipk);
            printf("\n");
        }
    } else {
        printf("Daftar Mahasiswa kosong!\n");
    }
}

// Fungsi untuk menghapus data mahasiswa
void hapusMahasiswa(int nim) {
    int found = 0;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (daftarMahasiswa[i].nim == nim) {
            found = 1;
            for (int j = i; j < jumlahMahasiswa - 1; j++) {
                daftarMahasiswa[j] = daftarMahasiswa[j + 1];
            }
            jumlahMahasiswa--;
            printf("Mahasiswa dengan NIM %d berhasil dihapus.\n", nim);
            break;
        }
    }
    if (!found) {
        printf("Mahasiswa dengan NIM %d tidak ditemukan.\n", nim);
    }
}

// Fungsi untuk mengubah data mahasiswa
void ubahMahasiswa(int nim) {
    int found = 0;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (daftarMahasiswa[i].nim == nim) {
            found = 1;
            printf("Masukkan nama baru: ");
            scanf("%s", daftarMahasiswa[i].nama);
            printf("Masukkan NIM baru: ");
            scanf("%d", &daftarMahasiswa[i].nim);
            printf("Masukkan IPK baru: ");
            scanf("%f", &daftarMahasiswa[i].ipk);
            printf("Data mahasiswa berhasil diubah!\n");
            break;
        }
    }
    if (!found) {
        printf("Mahasiswa dengan NIM %d tidak ditemukan.\n", nim);
    }
}

int main() {
    int pilihan;
    int nim;
    
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tampilkan Mahasiswa\n");
        printf("3. Hapus Mahasiswa\n");
        printf("4. Ubah Mahasiswa\n");
        printf("5. Keluar\n");
        printf("Pilih operasi (1/2/3/4/5): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahMahasiswa();
                break;
            case 2:
                tampilkanMahasiswa();
                break;
            case 3:
                printf("Masukkan NIM Mahasiswa yang akan dihapus: ");
                scanf("%d", &nim);
                hapusMahasiswa(nim);
                break;
            case 4:
                printf("Masukkan NIM Mahasiswa yang akan diubah: ");
                scanf("%d", &nim);
                ubahMahasiswa(nim);
                break;
            case 5:
                printf("Terima kasih! Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 5);

    return 0;
}
