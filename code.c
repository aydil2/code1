#include <stdio.h>   // library input output (printf, scanf, fopen)
#include <stdlib.h>  // library system("cls")

// ===== STRUCT =====

// Struct untuk menyimpan data siswa (gabungan beberapa tipe data)
typedef struct {
    char nama[30];    // menyimpan nama siswa (string)
    int nis;          // menyimpan NIS (integer)
    char kelas[20];   // menyimpan kelas
    char sekolah[30]; // menyimpan nama sekolah
} Siswa;

// Struct untuk menyimpan data nilai per mata pelajaran
typedef struct {
    char nama[30];  // nama mata pelajaran
    int kkm;        // nilai KKM
    int nilai;      // nilai siswa
} datanilai;


// ===== FUNCTION DECLARATION =====
// Declaration agar fungsi bisa dipanggil sebelum didefinisikan

void tampilMapel(datanilai mapel[]); // procedure (tidak return nilai)
void inputSiswa(Siswa *s);           // procedure pakai pointer
void inputNilai(datanilai mapel[]);
float hitungRata(datanilai mapel[]); // function return float
char predikat(float rata);           // function return char
void cetakFile(Siswa s, datanilai mapel[], float rata, char huruf);


// ===== MAIN =====
// Program mulai dari sini
int main() {

    Siswa siswa;   // membuat variabel siswa dari struct Siswa
    char ulang;    // untuk menyimpan pilihan Y/N

    // Array struct karena jumlah mapel sudah diketahui (5)
    datanilai mapel[5] = {
        {"Pemrograman Web",76,0},
        {"Pemrograman Mobile",76,0},
        {"Basis Data",76,0},
        {"PBO",76,0},
        {"Kewirausahaan",79,0}
    };

    tampilMapel(mapel);      // menampilkan daftar mapel
    inputSiswa(&siswa);      // input data siswa (pakai pointer supaya data asli berubah)

    // do-while agar program minimal berjalan 1 kali
    do {

        inputNilai(mapel);   // input nilai semua mapel

        float rata = hitungRata(mapel); // hitung rata-rata (function return float)
        char huruf = predikat(rata);    // menentukan predikat (function return char)

        system("cls");  // membersihkan layar

        printf("\n====================================================\n");
        printf("              RAPOR SMK NEGERI 1 DENPASAR\n");
        printf("====================================================\n");

        printf("Nama Siswa : %s\n", siswa.nama);
        printf("NIS        : %d\n", siswa.nis);
        printf("Kelas      : %s\n", siswa.kelas);
        printf("Sekolah    : %s\n", siswa.sekolah);

        printf("----------------------------------------------------\n");
        printf("No  Nama Mapel           KKM  Nilai  Status\n");
        printf("----------------------------------------------------\n");

        // for loop karena jumlah mapel sudah pasti 5
        for(int i=0;i<5;i++){
            printf("%-3d %-20s %-4d %-6d ",
                   i+1,
                   mapel[i].nama,
                   mapel[i].kkm,
                   mapel[i].nilai);

            // percabangan untuk menentukan lulus atau tidak
            if(mapel[i].nilai >= mapel[i].kkm)
                printf("LULUS\n");
            else
                printf("TIDAK LULUS\n");
        }

        printf("----------------------------------------------------\n");
        printf("Rata-rata Nilai : %.2f\n", rata); // %.2f untuk 2 angka desimal
        printf("Predikat        : %c\n", huruf);
        printf("====================================================\n");

        // validasi input Y/N menggunakan do-while
        do{
            printf("\nApakah data sudah benar?\n");
            printf("Tekan Y untuk cetak rapor\n");
            printf("Tekan N untuk input ulang nilai\n");
            printf("Pilihan Anda: ");
            scanf(" %c", &ulang);

            if(ulang!='Y' && ulang!='y' && ulang!='N' && ulang!='n'){
                printf("Input salah! Harus Y atau N.\n"); // validasi agar hanya Y/N
            }

        }while(ulang!='Y' && ulang!='y' && ulang!='N' && ulang!='n');

        // jika user pilih Y maka simpan ke file
        if(ulang=='Y' || ulang=='y'){
            cetakFile(siswa, mapel, rata, huruf); // memanggil procedure cetak file
            printf("\nRapor berhasil disimpan!\n");
        }

    }while(ulang!='Y' && ulang!='y'); // ulang jika belum pilih Y

    printf("\nProgram selesai. Terima kasih!\n");
    return 0; // mengakhiri program
}


// ===== TAMPIL MAPEL =====
void tampilMapel(datanilai mapel[]){
    printf("\n====================================================\n");
    printf("           DAFTAR MATA PELAJARAN DAN KKM\n");
    printf("====================================================\n");
    printf("No  Mata Pelajaran         KKM\n");
    printf("----------------------------------------------------\n");

    // for loop karena jumlah mapel sudah diketahui (5)
    for(int i=0;i<5;i++){
        printf("%-3d %-20s %-3d\n",
               i+1, mapel[i].nama, mapel[i].kkm);
    }

    printf("====================================================\n");
}


// ===== INPUT SISWA =====
void inputSiswa(Siswa *s){  // pointer supaya perubahan langsung ke variabel asli

    int cek;  // variabel untuk validasi

    printf("\n=== INPUT IDENTITAS SISWA ===\n");

    // validasi nama tidak boleh ada angka
    do{
        printf("Nama Siswa : ");
        scanf(" %[^\n]", s->nama);

        cek = 0;
        for(int i=0; s->nama[i]; i++){ // cek tiap karakter
            if(s->nama[i] >= '0' && s->nama[i] <= '9'){
                cek = 1;
                break;
            }
        }

        if(cek)
            printf("Nama tidak boleh mengandung angka!\n");

    }while(cek);

    // validasi NIS harus angka
    do{
        printf("NIS        : ");
        if(scanf("%d", &s->nis) != 1){
            printf("NIS harus angka!\n");
            fflush(stdin);
            cek = 1;
        } else cek = 0;
    }while(cek);

    printf("Kelas      : ");
    scanf(" %[^\n]", s->kelas);

    printf("Sekolah    : ");
    scanf(" %[^\n]", s->sekolah);
}


// ===== INPUT NILAI =====
void inputNilai(datanilai mapel[]){

    printf("\n=== INPUT NILAI MATA PELAJARAN ===\n");

    // for loop karena jumlah mapel 5
    for(int i=0;i<5;i++){

        // while(1) untuk validasi sampai input benar
        while(1){
            printf("Nilai %s : ", mapel[i].nama);

            if(scanf("%d", &mapel[i].nilai) != 1){
                printf("Input salah! Harus angka!\n");
                fflush(stdin);
            }
            else if(mapel[i].nilai < 0 || mapel[i].nilai > 100){
                printf("Nilai harus antara 0 - 100!\n");
            }
            else{
                break; // keluar jika valid
            }
        }
    }
}


// ===== HITUNG RATA =====
float hitungRata(datanilai mapel[]){

    int total = 0;

    // for loop untuk menjumlahkan semua nilai
    for(int i=0;i<5;i++){
        total += mapel[i].nilai;
    }

    return total / 5.0; // dibagi 5.0 agar hasil float
}


// ===== PREDIKAT =====
char predikat(float rata){

    if(rata >= 86) return 'A';
    else if(rata >= 80) return 'B';
    else if(rata >= 76) return 'C';
    else return 'D';
}


// ===== CETAK FILE =====
void cetakFile(Siswa s, datanilai mapel[], float rata, char huruf){

    char filename[30];

    sprintf(filename,"rapor%d.txt", s.nis); // membuat nama file berdasarkan NIS

    FILE *fp = fopen(filename,"w"); // membuka file mode write

    if(fp == NULL){
        printf("File gagal dibuat!\n");
        return;
    }

    // for loop untuk menulis semua mapel ke file
    for(int i=0;i<5;i++){

        fprintf(fp,"%-3d %-20s %-4d %-6d ",
                i+1,
                mapel[i].nama,
                mapel[i].kkm,
                mapel[i].nilai);

        if(mapel[i].nilai >= mapel[i].kkm)
            fprintf(fp,"LULUS\n");
        else
            fprintf(fp,"TIDAK LULUS\n");
    }

    fprintf(fp,"Rata-rata Nilai : %.2f\n", rata);
    fprintf(fp,"Predikat        : %c\n", huruf);

    fclose(fp); // menutup file
}