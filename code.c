#include <stdio.h>
#include <stdlib.h>

// ===== STRUCT =====
typedef struct {
    char nama[30];
    int nis;
    char kelas[20];
    char sekolah[30];
} Siswa;

typedef struct {
    char nama[30];
    int kkm;
    int nilai;
} datanilai;

// ===== FUNCTION DECLARATION =====
void tampilMapel(datanilai mapel[]);
void inputSiswa(Siswa *s);
void inputNilai(datanilai mapel[]);
float hitungRata(datanilai mapel[]);
char predikat(float rata);
void cetakFile(Siswa s, datanilai mapel[], float rata, char huruf);

// ===== MAIN =====
int main() {

    Siswa siswa;
    char ulang;

    datanilai mapel[5] = {
        {"Pemrograman Web",76,0},
        {"Pemrograman Mobile",76,0},
        {"Basis Data",76,0},
        {"PBO",76,0},
        {"Kewirausahaan",79,0}
    };

    tampilMapel(mapel);
    inputSiswa(&siswa);

    do {

        inputNilai(mapel);

        float rata = hitungRata(mapel);
        char huruf = predikat(rata);

        system("cls");

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

        for(int i=0;i<5;i++){
            printf("%-3d %-20s %-4d %-6d ",
                   i+1,
                   mapel[i].nama,
                   mapel[i].kkm,
                   mapel[i].nilai);

            if(mapel[i].nilai >= mapel[i].kkm)
                printf("LULUS\n");
            else
                printf("TIDAK LULUS\n");
        }

        printf("----------------------------------------------------\n");
        printf("Rata-rata Nilai : %.2f\n", rata);
        printf("Predikat        : %c\n", huruf);
        printf("====================================================\n");

        // ===== KONFIRMASI =====
        do{
            printf("\nApakah data sudah benar?\n");
            printf("Tekan Y untuk cetak rapor\n");
            printf("Tekan N untuk input ulang nilai\n");
            printf("Pilihan Anda: ");
            scanf(" %c", &ulang);

            if(ulang!='Y' && ulang!='y' && ulang!='N' && ulang!='n'){
                printf("Input salah! Harus Y atau N.\n");
            }

        }while(ulang!='Y' && ulang!='y' && ulang!='N' && ulang!='n');

        if(ulang=='Y' || ulang=='y'){
            cetakFile(siswa, mapel, rata, huruf);
            printf("\nRapor berhasil disimpan!\n");
        }

    }while(ulang!='Y' && ulang!='y');

    printf("\nProgram selesai. Terima kasih!\n");
    return 0;
}

// ===== TAMPIL MAPEL =====
void tampilMapel(datanilai mapel[]){
    printf("\n====================================================\n");
    printf("           DAFTAR MATA PELAJARAN DAN KKM\n");
    printf("====================================================\n");
    printf("No  Mata Pelajaran         KKM\n");
    printf("----------------------------------------------------\n");

    for(int i=0;i<5;i++){
        printf("%-3d %-20s %-3d\n",
               i+1, mapel[i].nama, mapel[i].kkm);
    }

    printf("====================================================\n");
}

// ===== INPUT SISWA =====
void inputSiswa(Siswa *s){
    int cek;

    printf("\n=== INPUT IDENTITAS SISWA ===\n");

    do{
        printf("Nama Siswa : ");
        scanf(" %[^\n]", s->nama);

        cek = 0;
        for(int i=0; s->nama[i]; i++){
            if(s->nama[i] >= '0' && s->nama[i] <= '9'){
                cek = 1;
                break;
            }
        }

        if(cek)
            printf("Nama tidak boleh mengandung angka!\n");

    }while(cek);

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

    for(int i=0;i<5;i++){
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
                break;
            }
        }
    }
}

// ===== HITUNG RATA =====
float hitungRata(datanilai mapel[]){
    int total = 0;
    for(int i=0;i<5;i++){
        total += mapel[i].nilai;
    }
    return total / 5.0;
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
    sprintf(filename,"rapor%d.txt", s.nis);

    FILE *fp = fopen(filename,"w");

    if(fp == NULL){
        printf("File gagal dibuat!\n");
        return;
    }

    fprintf(fp,"====================================================\n");
    fprintf(fp,"              RAPOR SMK NEGERI 1 DENPASAR\n");
    fprintf(fp,"====================================================\n");

    fprintf(fp,"Nama Siswa : %s\n", s.nama);
    fprintf(fp,"NIS        : %d\n", s.nis);
    fprintf(fp,"Kelas      : %s\n", s.kelas);
    fprintf(fp,"Sekolah    : %s\n", s.sekolah);

    fprintf(fp,"----------------------------------------------------\n");
    fprintf(fp,"No  Nama Mapel           KKM  Nilai  Status\n");
    fprintf(fp,"----------------------------------------------------\n");

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

    fprintf(fp,"----------------------------------------------------\n");
    fprintf(fp,"Rata-rata Nilai : %.2f\n", rata);
    fprintf(fp,"Predikat        : %c\n", huruf);
    fprintf(fp,"====================================================\n");

    fclose(fp);
}