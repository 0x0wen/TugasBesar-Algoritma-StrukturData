#include <stdio.h>
#include "pengguna.h"
#include "../global.h"
#include "../Teman/tabTeman.h"
#include "../General/wordmachine.h"

/* PENGGUNA  */
void DAFTAR() {
    Word Username, Password;

    if (statusProgram) {
      printf("Anda sudah masuk. Keluar terlebih dahulu\nuntuk melakukan daftar.\n");
    } else {
        do {
            printf("Masukkan nama:\n");
            STARTWORD();

            if (checkUsernameExist(&dataPengguna, currentWord, 20)) {
              printf("Wah, sayang sekali nama tersebut telah diambil.\n");
            }
        } while (checkUsernameExist(&dataPengguna, currentWord, 20));
        Username = currentWord;

        printf("Masukkan kata sandi:\n");
        STARTWORD();
        Password = currentWord;

        signingUser(Username, Password);
        printf("Pengguna telah berhasil terdaftar. Masuk\nuntuk menikmati fitur-fitur BurBir.\n");
    }

    signingUser(Username, Password, &dataPengguna);
}

void MASUK() {
    Word username, password;

    if (statusLogin) {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
    } else {
        do {
            printf("Masukkan nama:\n");
            STARTWORD();

            if (!checkUsernameExist(&dataPengguna, currentWord, 20)) {
                printf("Wah, nama yang Anda cari tidak ada.\nMasukkan nama lain!\n");
            }

            username = currentWord;
        } while (!checkUsernameExist(&dataPengguna, currentWord, 20));

        do {
            print("Masukkan kata sandi:\n");
            STARTWORD();

            if (!checkPassword(&dataPengguna, currentWord, 20)) {
                printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            }
        } while (!checkPassword(&dataPengguna, currentWord, 20));

        statusLogin = true;
    }

    CURRENT_PENGGUNA(username);
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

// Fungsi untuk menyalin string secara manual
void copyString(char *destination, const char *source, int maxSize) {
    for (int i = 0; i < maxSize - 1 && source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }

    // Pastikan string diakhiri dengan karakter null
    destination[maxSize - 1] = '\0';
}


void Display_PROFIL(Pengguna user)
{
    printf("|  Nama: ");
    printWord(NamaPengguna(user));
    printf("\n");
    printf("|  Bio Akun: ");
    printWord(BioPengguna(user));
    printf("\n");
    printf("|  No HP: ");
    printWord(NoHPPengguna(user));
    printf("\n");
    printf("|  Weton: ");
    printWord(WetonPengguna(user));
    printf("\n");
    printf("Foto profil akun :");
    DISPLAY_FOTO_PROFIL(user);
    printf("\n");
}