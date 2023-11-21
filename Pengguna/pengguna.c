#include <stdio.h>
#include "pengguna.h"
#include "tabTeman.h"
#include "wordmachine.h"

/* PENGGUNA  */
void DAFTAR() {
    Word Username, Password;

    if (statusProgram) {
      printf("Anda sudah masuk. Keluar terlebih dahulu\nuntuk melakukan daftar.\n");
    } else {
        do {
            printf("Masukkan nama:\n");
            STARTWORD();

            if (checkUsernameExist(currentWord)) {
              printf("Wah, sayang sekali nama tersebut telah diambil.\n");
            }
        } while (checkUsernameExist(currentWord));
        Username = currentWord;

        printf("Masukkan kata sandi:\n");
        STARTWORD();
        Password = currentWord;

        signingUser(Username, Password);
        printf("Pengguna telah berhasil terdaftar. Masuk\nuntuk menikmati fitur-fitur BurBir.\n");
    }
}

void MASUK() {
    if (statusLogin) {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
    } else {
        do {
            printf("Masukkan nama:\n");
            STARTWORD();

            if (!checkUsernameExist(currentWord)) {
                printf("Wah, nama yang Anda cari tidak ada.\nMasukkan nama lain!\n");
            }
        } while (!checkUsernameExist(currentWord));

        do {
            print("Masukkan kata sandi:\n");
            STARTWORD();

            if (!checkPassword(currentWord)) {
                printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            }
        } while (!checkPassword(currentWord));

        statusLogin = true;
    }
}

void KELUAR() {
    if (statusLogin) {
        printf("Anda belum login! Masuk terlebih dahulu\nuntuk menikmati layanan BurBir.\n");
    } else {
        statusLogin = false;
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    }
}

void TUTUP_PROGRAM() {
    statusProgram = false;
    printf("Anda telah keluar dari program BurBir.\nSampai jumpa di penjelajahan berikutnya.\n");
}

// Fungsi untuk memeriksa apakah username sudah ada atau belum
boolean checkUsernameExist(Word username) {
    FILE *file = fopen("config-1/pengguna.config", "r");
    if (file == NULL) {
        printf("File tidak ditemukan\n");
        return false;
    }

    Word temp;
    boolean found = false;

    while (FSCANWORD(file, &temp)) {
        if (IsWordEqual(temp, username)) {
            found = true;
            break;
        }
    }

    fclose(file);
    return found;
}

// Fungsi untuk memeriksa apakah password sudah benar atau belum
boolean checkPassword(Word password) {
    FILE *file = fopen("config-1/pengguna.config", "r");
    if (file == NULL) {
        printf("File tidak ditemukan\n");
        return false;
    }

    Word temp, tempUsername, tempPassword;
    boolean found = false;

    while (FSCANWORD(file, &tempUsername) && FSCANWORD(file, &tempPassword)) {
        if (IsWordEqual(tempPassword, password)) {
            found = true;
            break;
        }
    }

    fclose(file);
    return found;
}

// Fungsi untuk mendaftarkan pengguna baru
void signingUser(Word username, Word password) {
    FILE *file = fopen("config-1/pengguna.config", "a");
    if (file == NULL) {
        printf("File tidak ditemukan\n");
        return;
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);
}


int CURRENT_PENGGUNA();



void Display_PROFIL(Pengguna p)
{
    printf("|  Nama: ");
    printWord(p.nama);
    printf("\n");
    printf("|  Bio Akun: ");
    printWord(p.bio);
    printf("\n");
    printf("|  No HP: ");
    printWord(p.noHP);
    printf("\n");
    printf("|  Weton: ");
    printWord(p.weton);
    printf("\n");
    printf("Foto profil akun :");
    DISPLAY_FOTO_PROFIL(p);
    printf("\n");
}