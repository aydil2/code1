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
    char nama[20];
    int kkm;
    int nilai;
} datanilai;

// ===== Function Declaration =====
void tampilMapel(datanilai mapel[]);
void inputSiswa(Siswa *s);
void inputNilai(datanilai mapel[]);
float hitungRata(datanilai mapel[]);
char predikat(float rata);
void cetakFile(Siswa s, datanilai mapel[], float rata, char huruf);

int main() {

    Siswa siswa;
    char ulang;

    datanilai mapel[5] = {
        {"WEB",75,0},
        {"BasisData",75,0},
        {"PBO",75,0},
        {"UIUX",80,0},
        {"PKK",80,0}
    };

    tampilMapel(mapel);
    inputSiswa(&siswa);

    do {
        inputNilai(mapel);

        float rata = hitungRata(mapel);
        char huruf = predikat(rata);

        system("cls");

        printf("\n================ HASIL ================\n");
        printf("|No  |Mapel       |KKM  |Nilai |Status|\n");
        printf("=======================================\n");

        for(int i=0;i<5;i++){
            printf("|%d   |%-10s  |%d   |%d    |",
                   i+1, mapel[i].nama, mapel[i].kkm, mapel[i].nilai);

            if(mapel[i].nilai >= mapel[i].kkm)
                printf("LULUS |\n");
            else
                printf("TIDAK |\n");
        }

        printf("=======================================\n");
        printf("Rata-rata : %.2f\n", rata);
        printf("Predikat  : %c\n", huruf);

        do {
            printf("\nData sudah benar? (Y/N): ");
            scanf(" %c", &ulang);

            if(ulang!='Y' && ulang!='y' && ulang!='N' && ulang!='n'){
                printf("Input salah! Harus Y atau N.\n");
            }
        } while(ulang!='Y' && ulang!='y' && ulang!='N' && ulang!='n');

        if(ulang=='Y' || ulang=='y'){
            cetakFile(siswa, mapel, rata, huruf);
            printf("Rapor berhasil dibuat!\n");
        }

    } while(ulang!='Y' && ulang!='y');

    return 0;
}

// ===== TAMPIL MAPEL =====
void tampilMapel(datanilai mapel[]){
    printf("\n=======================================\n");
    printf("| No | Mapel       | KKM              |\n");
    printf("=======================================\n");

    for(int i=0;i<5;i++){
        printf("| %-2d | %-11s | %-3d              |\n",
               i+1, mapel[i].nama, mapel[i].kkm);
    }

    printf("=======================================\n");
}

// ===== INPUT SISWA =====
void inputSiswa(Siswa *s){
    int cek;

    do{
        printf("Nama     : ");
        scanf(" %[^\n]", s->nama);

        cek = 0;
        for(int i=0; s->nama[i]; i++){
            if(s->nama[i] >= '0' && s->nama[i] <= '9'){
                cek = 1;
                break;
            }
        }

        if(cek)
            printf("Nama tidak boleh angka!\n");
    }while(cek);

    do{
        printf("NIS      : ");
        if(scanf("%d", &s->nis) != 1){
            printf("NIS harus angka!\n");
            fflush(stdin);
            cek = 1;
        } else cek = 0;
    }while(cek);

    printf("Kelas    : ");
    scanf(" %[^\n]", s->kelas);

    printf("Sekolah  : ");
    scanf(" %[^\n]", s->sekolah);
}

// ===== INPUT NILAI =====
void inputNilai(datanilai mapel[]){
    printf("\n===== INPUT NILAI =====\n");

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
                break; // valid → keluar loop
            }
        }
    }
}

// ===== HITUNG RATA =====
float hitungRata(datanilai mapel[]){
    int total=0;
    for(int i=0;i<5;i++){
        total += mapel[i].nilai;
    }
    return total / 5.0;
}

// ===== PREDIKAT =====
char predikat(float rata){
    if(rata>=85) return 'A';
    else if(rata>=75) return 'B';
    else if(rata>=65) return 'C';
    else return 'D';
}

// ===== CETAK FILE =====
void cetakFile(Siswa s, datanilai mapel[], float rata, char huruf){

    char filename[30];
    sprintf(filename,"rapor%d.txt", s.nis);

    FILE *fp = fopen(filename,"w");

    fprintf(fp,"=========== RAPOR SISWA ===========\n");
    fprintf(fp,"Nama     : %s\n", s.nama);
    fprintf(fp,"NIS      : %d\n", s.nis);
    fprintf(fp,"Kelas    : %s\n", s.kelas);
    fprintf(fp,"Sekolah  : %s\n\n", s.sekolah);

    fprintf(fp,"No  Mapel       KKM  Nilai  Status\n");

    for(int i=0;i<5;i++){
        fprintf(fp,"%d   %-10s  %d   %d    ",
                i+1, mapel[i].nama, mapel[i].kkm, mapel[i].nilai);

        if(mapel[i].nilai >= mapel[i].kkm)
            fprintf(fp,"LULUS\n");
        else
            fprintf(fp,"TIDAK\n");
    }

    fprintf(fp,"\nRata-rata : %.2f\n", rata);
    fprintf(fp,"Predikat  : %c\n", huruf);

    fclose(fp);
}
