#include <stdio.h>
#include "wordmachine.c"
#include "wordmachine.h"

void inisialisasi(){
    printf(".______    __    __  .______      .______    __  .______\n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\\n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |\n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /\n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n");
    printf("\n");
    printf("Selamat datang di BurBir.\n");
    printf("\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode\n");
    printf("(pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
    printf("\n");
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");

    STARTWORD();

    printf("\n");
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");

    FILE* fptr;
    fptr = fopen("config-1/pengguna.config","r");
    char content[10];
    char content2[100];
    fgets(content,10,fptr);
    int i;
    for(i = 0; i < 33; i++){
        fgets(content2,100,fptr);
        printf("%s",content2);
    }

    /* =========== MAIN =========== */

    STARTWORD(); // Ini harus diganti

    if (IsWordEqual(currentWord, 'DAFTAR')) {
        DAFTAR();
    } 
    if (IsWordEqual(currentWord, 'MASUK')) {
        MASUK();
    }
    if (IsWordEqual(currentChar, 'TUTUP_PROGRAM')) {
        TUTUP_PROGRAM();
    }

    while(/* Pengguna valid, terdaftar, dan beleum keluar */) {

        STARTWORD();

        if (IsWordEqual(currentChar, 'KELUAR')) {
            KELUAR();
        }

        /* =========== PROFIL =========== */
        if (IsWordEqual(currentChar, 'GANTI_PROFIL')) {
            GANTI_PROFIL();
        }
        if (IsWordEqual(currentChar, 'LIHAT_PROFIL')) {
            LIHAT_PROFIL();
        } 
        if (IsWordEqual(currentChar, 'ATUR_JENIS_AKUN')) {
            ATUR_JENIS_AKUN();
        } 
        if (IsWordEqual(currentChar, 'UBAH_FOTO_PROFIL')) {
            UBAH_FOTO_PROFIL();
        }       

        /* ========== TEMAN =========*/
        if (IsWordEqual(currentChar, 'DAFTAR_TEMAN')) {
            DAFTAR_TEMAN();
        }
        if (IsWordEqual(currentChar, 'HAPUS_TEMAN')) {
            HAPUS_TEMAN();
        }

        /* ========== PERMINTAAN PERTEMANAN =========*/
        if (IsWordEqual(currentChar, 'TAMBAH_TEMAN')) {
            TAMBAH_TEMAN();
        }
        if (IsWordEqual(currentChar, 'DAFTAR_PERMINTAAN_PERTEMANAN')) {
            DAFTAR_PERMINTAAN_PERTEMAN();
        }
        if (IsWordEqual(currentChar, 'SETUJUI_PERTEMANAN')) {
            SETUJUI_PERTEMANAN();
        }

        /* ========== KICUAN =========*/
        if (IsWordEqual(currentChar, 'KICAU')) {
            KICAU();
        if (IsWordEqual(currentChar, 'KICAUAN')) {
            KICAU();
        }
        if (IsWordEqual(currentChar, 'SUKA_KICAUAN')) {
            SUKA_KICAU();
        }
        if (IsWordEqual(currentChar, 'UBAH_KICAUAN')) {
            UBAH_KICAUAN();
        }

        /* ========== BALASAN =========*/
        if (IsWordEqual(currentChar, 'BALAS')) {
            BALAS();
        }
        if (IsWordEqual(currentChar, 'BALASAN')) {
            BALASAN();
        }
        if (IsWordEqual(currentChar, 'HAPUS_BALASAN')) {
            HAPUS_BALASAN();
        }

        /* ========== DRAF =========*/
        if (IsWordEqual(currentChar, 'BUAT_DRAF')) {
            BUAT_DRAF();
        }
        if (IsWordEqual(currentChar, 'LIHAT_DRAF')) {
            LIHAT_DRAF();
        }

        /* ========== UTAS =========*/
        if (IsWordEqual(currentChar, 'UTAS')) {
            UTAS();
        }
        if (IsWordEqual(currentChar, 'SAMBUNG_UTAS')) {
            SAMBUNG_UTAS();
        }
        if (IsWordEqual(currentChar, 'HAPUS_UTAS')) {
            HAPUS_UTAS();
        }
        if (IsWordEqual(currentChar, 'CETAK_UTAS')) {
            CETAK_UTAS();
        }

        /* ========== SIMPAN DAN MUAT =========*/
        if (IsWordEqual(currentChar, 'SIMPAN')) {
            SIMPAN();
        }
        if (IsWordEqual(currentChar, 'MUAT')) {
            MUAT();
        }
    }
}