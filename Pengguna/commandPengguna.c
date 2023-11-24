#include "../global.h"

/* PENGGUNA  */
void DAFTAR()
{
    Sentence Username, Password;
    int Length = dataPengguna.length;

    if (statusLogin) {
      printf("Anda sudah masuk. Keluar terlebih dahulu\nuntuk melakukan daftar.\n");
    } else {
        do {
            printf("Masukkan nama:\n");
            InputSentence(&Username);

            if (checkUsernameExist(dataPengguna, Username, Length))
            {
                printf("Wah, sayang sekali nama tersebut telah diambil.\n");
            }
        } while (checkUsernameExist(dataPengguna, Username, Length));

        printf("Masukkan kata sandi:\n");
        InputSentence(&Password);

        Pengguna newUser;
        NAMA_PENGGUNA(newUser) = Username;
        PASSWORD_PENGGUNA(newUser) = Password;
        ID_PENGGUNA(newUser) = lengthTabPengguna(dataPengguna);
        PRIVASI_PENGGUNA(newUser) = false;
        CreateListDin(&DAFTAR_UTAS(newUser), 10);
        CreateListDin(&DAFTAR_KICAUAN(newUser), 10);
        create_PQR(&(newUser.daftarPermintaanTeman));

        FotoProfil FP;
        createFotoProfil(5, 10, &FP);

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                if (j % 2 != 0) {
                    ELMT(FP, i, j) = '*';
                } else {
                    ELMT(FP, i, j) = 'R';
                }
            }
        }

        FOTO_PENGGUNA(newUser) = FP;

        insertLastTabPengguna(&dataPengguna, newUser);

        printf("Pengguna telah berhasil terdaftar. Masuk\nuntuk menikmati fitur-fitur BurBir.\n");
    }
}

void MASUK()
{
    Sentence Username, Password;
    int Length = dataPengguna.length;

    if (statusLogin)
    {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
    }
    else
    {
        do
        {
            printf("Masukkan nama:\n");
            InputSentence(&Username);

            if (!checkUsernameExist(dataPengguna, Username, Length))
            {
                printf("Wah, nama yang Anda cari tidak ada.\nMasukkan nama lain!\n");
            }

        } while (!checkUsernameExist(dataPengguna, Username, Length));

        do
        {
            printf("Masukkan kata sandi:\n");
            InputSentence(&Password);

            if (!checkPassword(dataPengguna, Password, Length))
            {
                printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            }
        } while (!checkPassword(dataPengguna, Password, Length));

        penggunaSekarang = *searchPenggunaByName(&dataPengguna, Username);
        printf("\nPengguna "); printSentence(penggunaSekarang.nama); printf(" berhasil login!\n");
        statusLogin = true;
    }
}

void KELUAR()
{
    if (!statusLogin)
    {
        printf("Anda belum login! Masuk terlebih dahulu\nuntuk menikmati layanan BurBir.\n");
    }
    else
    {
        statusLogin = false;
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    }
}

void TUTUP_PROGRAM()
{
    statusProgram = false;
    printf("Anda telah keluar dari program BurBir.\nSampai jumpa di penjelajahan berikutnya.\n");
}

// Fungsi untuk menyalin string secara manual
void copyString(char *destination, const char *source, int maxSize)
{
    for (int i = 0; i < maxSize - 1 && source[i] != '\0'; ++i)
    {
        destination[i] = source[i];
    }

    // Pastikan string diakhiri dengan karakter null
    destination[maxSize - 1] = '\0';
}

void GANTI_PROFIL()
{
    if (ID_PENGGUNA(penggunaSekarang) == -1)
    {
        printf("Anda Belum Login! Masuk terlebih dahulu untuk mengganti profil.\n");
    }
    else
    {
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

        /* Mengganti bio pengguna */
        boolean IsValidBio = false;
        Sentence Bio;
        while (!IsValidBio)
        {
            printf("\nMasukkan Bio Akun:\n");
            InputSentence(&Bio);

            if (currentWord.Length <= 135)
            {
                IsValidBio = true;
            }

            if (!IsValidBio)
            {
                printf("\nBio melebihi panjang maksimum!\n\n");
            }
        }

        BIO_PENGGUNA(penggunaSekarang) = Bio;
        printf("\n");

        /* Mengganti nomor handphone pengguna */
        boolean IsValidNoHP = false;
        while (!IsValidNoHP)
        {
            printf("Masukkan No HP: \n");
            startSentence();

            for (int i = 0; i < currentWord.Length; i++)
            {
                if (currentWord.TabWord[i] > '0' && currentWord.TabWord[i] < '9')
                {
                    IsValidNoHP = true;
                }
            }

            if (!IsValidNoHP)
            {
                printf("\nNo HP tidak valid, Masukkan lagi yuk!\n\n");
            }
        }

        HP_PENGGUNA(penggunaSekarang) = currentWord;
        printf("\n");

        Word weton[5] = {{"Pahing", 6}, {"Kliwon", 6}, {"Wage", 6}, {"Legi", 4}, {"Pon", 3}}; // deklarasi Weton

        /* Mengganti weton pengguna */
        Word Weton;
        boolean IsValidWeton = false;
        while (!IsValidWeton)
        {
            printf("Masukkan Weton:\n");
            InputWord(&Weton);

            if (isOnlyBlank(Weton))
            {
                IsValidWeton = true;
            }

            for (int i = 0; i < 4; i++)
            {
                if (IsWordEqual(Weton, weton[i]))
                {
                    IsValidWeton = true;
                }
            }

            if (!IsValidWeton)
            {
                printf("\nWeton anda tidak valid\n\n");
            }
        }

        WETON_PENGGUNA(penggunaSekarang) = Weton;

        printf("\nProfil anda sudah berhasil diperbarui!\n");
    }
}

void LIHAT_PROFIL()
{
    if (ID_PENGGUNA(penggunaSekarang) == -1)
    {
        printf("Anda Belum Login! Masuk terlebih dahulu untuk melihat profil.\n");
    }
    else
    {
        Sentence Nama;
        printf("Masukkan nama pengguna yang ingin dilihat profilnya: ");
        InputSentence(&Nama);

        if (IsSentenceEqual(Nama, NAMA_PENGGUNA(penggunaSekarang)))
        {
            DISPLAY_PROFIL(penggunaSekarang);
        }
        else
        {
            Pengguna penggunaSekarang1;
            for (int i = 0; i < dataPengguna.length; i++)
            {
                if (IsSentenceEqual(Nama, NAMA_PENGGUNA(SELECT_PENGGUNA(dataPengguna, i))))
                {
                    penggunaSekarang1 = SELECT_PENGGUNA(dataPengguna, i);
                }
            }

            if (!PRIVASI_PENGGUNA(penggunaSekarang1) || !isFriend(matrixTeman, ID_PENGGUNA(penggunaSekarang), ID_PENGGUNA(penggunaSekarang1)))
            {
                printf("Wah, akun ");
                printSentence(Nama);
                printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
                printSentence(Nama);
            }
            else
            {
                DISPLAY_PROFIL(penggunaSekarang1);
            }
        }
    }
}

void ATUR_JENIS_AKUN()
{
    if (ID_PENGGUNA(penggunaSekarang) == -1)
    {
        printf("Anda Belum Login!\n");
    }
    else
    {
        boolean isPrivate = PRIVASI_PENGGUNA(penggunaSekarang);
        Word TIDAK = {"TIDAK", 5};

        printf("Saat ini, akun Anda adalah akun ");
        if (isPrivate)
        {
            printf("Privat.\n");
        }
        else
        {
            printf("Publik.\n");
        }

        Word Action;

        if (isPrivate)
        {
            printf("Ingin mengubah ke akun Publik?\n");
            printf("\n(YA/TIDAK)\n");
            printf(">> ");

            InputWord(&Action); printf("\n");

            if (IsWordEqual(Action, TIDAK))
            {
                printf("Perubahan akun dibatalkan.\n");
            }
            else
            {
                PRIVASI_PENGGUNA(penggunaSekarang) = false;
                printf("Akun anda sudah diubah menjadi akun Publik.\n");
            }
        }
        else
        {
            printf("Ingin mengubah ke akun Privat?\n");
            printf("\n(YA/TIDAK) ");
            printf(">> ");

            InputWord(&Action); printf("\n");

            if (IsWordEqual(Action, TIDAK))
            {
                printf("Perubahan akun dibatalkan.\n");
            }
            else
            {
                PRIVASI_PENGGUNA(penggunaSekarang) = true;
                printf("Akun anda sudah diubah menjadi akun Privat.\n");
            }
        }
    }
}

void UBAH_FOTO_PROFIL()
{
    if (ID_PENGGUNA(penggunaSekarang) == -1)
    {
        printf("Anda Belum Login! Masuk terlebih dahulu untuk mengganti foto profil.\n");
    }
    else
    {
        printf("Foto profil Anda saat ini adalah\n");
        DISPLAY_FOTO_PROFIL(penggunaSekarang);
        printf("\nMasukkan foto profil yang baru\n");

        FotoProfil FP;
        createFotoProfil(5, 10, &FP);
        readFotoProfil(&FP, 5, 10);

        FOTO_PENGGUNA(penggunaSekarang) = FP;

        printf("\nFoto profil anda sudah berhasil diganti!\n");
        DISPLAY_FOTO_PROFIL(penggunaSekarang);
    }
}

void DISPLAY_FOTO_PROFIL(Pengguna p)
{
    displayFotoProfil(FOTO_PENGGUNA(p));
}

void DISPLAY_PROFIL(Pengguna P)
{
    printf("\n|  Nama: ");
    printSentence(NAMA_PENGGUNA(P));
    printf("\n|  Bio Akun: ");
    printSentence(BIO_PENGGUNA(P));
    printf("\n|  No HP: ");
    printWord(HP_PENGGUNA(P));
    printf("\n|  Weton: ");
    printWord(WETON_PENGGUNA(P));
    printf("\n\nFoto profil akun :\n");
    displayFotoProfil(FOTO_PENGGUNA(P));
    printf("\n");
}