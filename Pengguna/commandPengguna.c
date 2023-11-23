#include "commandPengguna.h"

void GANTI_PROFIL() {
    for (int i = 0; i < len(dataPengguna); i++) {
        if (IdPengguna(SelectPengguna(dataPengguna, i)) == IdPengguna(penggunaSekarang)) {
            Pengguna penggunaSekarang = SELECT_PENGGUNA(dataPengguna, i);
        }
    }

    if (ID_PENGGUNA(penggunaSekarang) == -1) {
        printf("Anda Belum Login! Masuk terlebih dahulu untuk mengganti profil.\n");
    } else {
        /* Menampilkan profil pengguna */
        printf("|  Nama: ");
        printSentence(NAMA_PENGGUNA(penggunaSekarang));
        printf("\n");
        printf("|  Bio Akun: ");
        printSentence(BIO_PENGGUNA(penggunaSekarang));
        printf("\n");
        printf("|  No HP: ");
        printWord(HP_PENGGUNA(penggunaSekarang));
        printf("\n");
        printf("|  Weton: ");
        printWord(WETON_PENGGUNA(penggunaSekarang));
        printf("\n");

        Word empty = {';', 1};

        /* Mengganti bio pengguna */
        boolean IsValidBio = false;
        Sentence Bio;
        while (!IsValidBio) {
            printf("Masukkan Bio Akun:\n");
            InputSentence(&Bio);

            if (currentWord.Length <= 135) {
                IsValidBio = true;
            }

            if (!IsValidBio) {
                printf("\nBio melebihi panjang maksimum!\n\n");
            }
        }

        BIO_PENGGUNA(penggunaSekarang) = Bio; printf("\n");

        /* Mengganti nomor handphone pengguna */
        boolean IsValidNoHP = false;
        while (!IsValidNoHP) {
            printf("Masukkan No HP: \n");
            STARTSENTENCE();

            for (int i = 0; i < currentWord.Length; i++) {
                if (currentWord.TabWord[i] > '0' && currentWord.TabWord[i] < '9') {
                    IsValidNoHP = true;
                }
            }

            if (!IsValidNoHP) {
                printf("\nNo HP tidak valid, Masukkan lagi yuk!\n\n");
            }
        }

        HP_PENGGUNA(penggunaSekarang) = currentWord; printf("\n");

        Word weton[] = {{"Pahing", 6}, {"Kliwon", 6}, {"Wage", 6}, {"Legi", 4}, {"Pon", 3}}; // deklarasi Weton

        /* Mengganti weton pengguna */
        boolean IsValidWeton = false;
        while (!IsValidWeton) {
            printf("Masukkan Weton:\n");
            STARTSENTENCE();
            if (IsWordEqual(currentWord, empty)) {
                IsValidWeton = true;
            }

            for (int i = 0; i < 4; i++) {
                if (IsWordEqual(currentWord, weton[i])) {
                    IsValidWeton = true;
                }
            }

            if (!IsValidWeton) {
                printf("\nWeton anda tidak valid\n\n");
            }
        }

        WETON_PENGGUNA(penggunaSekarang) = currentWord;

        printf("Profil anda sudah berhasil diperbarui!\n");
    }
}

void LIHAT_PROFIL() {
    for (int i = 0; i < len(dataPengguna); i++) {
        if (ID_PENGGUNA(SELECT_PENGGUNA(dataPengguna, i)) == ID_PENGGUNA(penggunaSekarang)) {
            Pengguna penggunaSekarang = SELECT_PENGGUNA(dataPengguna, i);
        }
    }

    if (ID_PENGGUNA(penggunaSekarang) == -1) {
        printf("Anda Belum Login! Masuk terlebih dahulu untuk melihat profil.\n");
    } else {
        Sentence Nama;
        InputSentence(&Nama);
        int idPengguna = ID_PENGGUNA(penggunaSekarang);
        Word Privat = {"Privat", 6};
        Word Publik = {"Publik", 6};
        boolean TipeAkun = PRIVASI_PENGGUNA(penggunaSekarang);

        if (IsSentenceEqual(Nama, NAMA_PENGGUNA(penggunaSekarang))) {
            DISPLAY_PROFIL(penggunaSekarang);
        } else {
            Pengguna penggunaSekarang1;
            for (int i = 0; i < len(dataPengguna); i++) {
                if (IsSentenceEqual(Nama, NAMA_PENGGUNA(SELECT_PENGGUNA(dataPengguna, i)))) {
                    Pengguna penggunaSekarang1 = SELECT_PENGGUNA(dataPengguna, i);
                }
            }

            if (IsWordEboolean(TipeAkun, Privat) && !isFriend()) {
                printf("Wah, akun ");
                printSentence(Nama);
                printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
                printSentence(Nama);
            } else {
                DISPLAY_PROFIL(penggunaSekarang1);
            }
        }
    }
}

void ATUR_JENIS_AKUN() {
    for (int i = 0; i < len(dataPengguna); i++) {
        if (ID_PENGGUNA(SELECT_PENGGUNA(dataPengguna, i)) == ID_PENGGUNA(penggunaSekarang)) {
            Pengguna penggunaSekarang = SELECT_PENGGUNA(dataPengguna, i);
        }
    }

    if (ID_PENGGUNA(penggunaSekarang) == -1) {
        printf("Anda Belum Login!\n");
    } else
    {
        boolean TipeAkun = PRIVASI_PENGGUNA(penggunaSekarang);
        Word Privat = {"Privat", 6};
        Word Publik = {"Publik", 6};
        Word YA = {"YA", 2};
        Word TIDAK = {"TIDAK", 5};

        printf("Saat ini, akun Anda adalah akun");
        printboolean(TipeAkun);
        if (IsWordEboolean(TipeAkun, Privat)) {
            printf("Ingin mengubah ke akun Publik?");
            printf("\n");
            printf("(YA/TIDAK)");
            STARTWORD();
            if (IsWordEqual(currentWord, TIDAK)) {
                printf("Perubahan akun dibatalkan.");
            } else
            {
                PRIVASI_PENGGUNA(penggunaSekarang) = false;
                printf("Akun anda sudah diubah menjadi akun Publik.");
            }
        } else {
            printf("Ingin mengubah ke akun Privat?");
            printf("\n");
            printf("(YA/TIDAK)");
            STARTWORD();
            if (IsWordEqual(currentWord, TIDAK)) {
                printf("Perubahan akun dibatalkan.\n");
            } else
            {
                penggunaSekarang.privat = true;
                printf("Akun anda sudah diubah menjadi akun Privat.\n");
            }
        }
    }
}

void UBAH_FOTO_PROFIL() {
    for (int i = 0; i < len(dataPengguna); i++) {
        if (ID_PENGGUNA(SELECT_PENGGUNA(dataPengguna, i)) == ID_PENGGUNA(penggunaSekarang)) {
            Pengguna penggunaSekarang = SELECT_PENGGUNA(dataPengguna, i);
        }
    }

    if (ID_PENGGUNA(penggunaSekarang) == -1) {
        printf("Anda Belum Login! Masuk terlebih dahulu untuk mengganti foto profil.\n");
    } else {
        printf("Foto profil Anda saat ini adalah\n");
        DISPLAY_FOTO_PROFIL(penggunaSekarang);
        printf("\n");
        printf("Masukkan foto profil yang baru\n");
        FotoProfil fp;
        START();
        IgnoreBlanks();
        IgnoreEnters();
        createFotoProfil(5, 10, &fp);
        int i, j;
        for (i = 0; i < ROW_EFF(fp); i++)
        {
            for (j = 0; j < COL_EFF(fp); j++)
            {
                ELMT(fp, i, j) = currentChar;
                ADV();
                IgnoreBlanks();
                IgnoreEnters();
            }
            IgnoreEnters();
        }
        FOTO_PENGGUNA(penggunaSekarang) = fp;
        printf("\n");
        printf("Foto profil anda sudah berhasil diganti!\n\n");
        DISPLAY_FOTO_PROFIL(penggunaSekarang);
    }
}

void DISPLAY_FOTO_PROFIL(Pengguna p)
{
    displayFotoProfil(FOTO_PENGGUNA(p));
}

void DISPLAY_PROFIL(Pengguna P)
{
    printf("|  Nama: ");
    printSentence(NAMA_PENGGUNA(P));
    printf("\n");
    printf("|  Bio Akun: ");
    printSentence(BIO_PENGGUNA(P));
    printf("\n");
    printf("|  No HP: ");
    printWord(HP_PENGGUNA(P));
    printf("\n");
    printf("|  Weton: ");
    printWord(WETON_PENGGUNA(P));
    printf("\n");
    printf("Foto profil akun :");
    displayFotoProfil(FOTO_PENGGUNA(P));
    printf("\n");
}