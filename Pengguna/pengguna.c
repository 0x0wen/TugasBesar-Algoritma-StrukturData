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

boolean checkUsernameExist(TabPengguna *tabPengguna, Word username, int numUsers) {
    // Mengecek apakah pengguna ada dalam array TabPengguna

    boolean found = false;

    for (int i = 0; i < numUsers; ++i) {
        // Misalnya, anggaplah username disimpan dalam atribut tertentu dari Pengguna
        // Gantilah dengan atribut sebenarnya yang menyimpan username di dalam Pengguna
        if (IsWordEqual(tabPengguna->contents[i].usernameAttribute, username)) {
            found = true;
            break;
        }
    }

    return found;
}
boolean checkPassword(TabPengguna *tabPengguna, Word password, int numUsers) {
    // Mengecek apakah password ada dalam array contents

    boolean found = false;

    for (int i = 0; i < numUsers; ++i) {
        // Misalnya, anggaplah password disimpan dalam atribut tertentu dari Pengguna
        // Gantilah dengan atribut sebenarnya yang menyimpan password di dalam Pengguna
        if (IsWordEqual(tabPengguna->contents[i].passwordAttribute, password)) {
            found = true;
            break;
        }
    }

    return found;
}

// Fungsi untuk menyalin string secara manual
void copyString(char *destination, const char *source, int maxSize) {
    for (int i = 0; i < maxSize - 1 && source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }

    // Pastikan string diakhiri dengan karakter null
    destination[maxSize - 1] = '\0';
}

void signingUser(Word username, Word password, TabPengguna *dataPengguna) {
    if (&dataPengguna.length < 20) {
        // Assuming Word is an array of characters
        // Assuming Pengguna is the structure used to store user information
        Pengguna *currentUser = &dataPengguna->pengguna[dataPengguna->numUsers];

        // Copy username and password to the current user
        copyString(currentUser->usernameAttribute, &username, 20);
        copyString(currentUser->passwordAttribute, &password, 20);

        // You need to populate other attributes as well according to your structure

        // Increment the user count
        dataPengguna->numUsers++;
    } else {
        printf("DataPengguna is full. Cannot add more users.\n");
    }
}

int CURRENT_PENGGUNA(Word penggunaBaru) {
    penggunaSekarang = penggunaBaru;
}


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