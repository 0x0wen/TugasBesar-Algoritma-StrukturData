#include <stdio.h>
#include "pengguna.h"
#include "tabTeman.h"

/* ========== PENGGUNA ========== */
void DAFTAR()
{
    if (true /* Pengguna telah masuk sebelumnya */)
    {
        printf("Anda sudah masuk. Keluar terlebih dahulu\nuntuk melakukan daftar.\n");
    }
    else
    {
        do
        {
            printf("Masukkan nama:\n");
            STARTWORD();

            if (checkpenggunaSekarangname(currentWord))
            {
                printf("Wah, sayang sekali nama tersebut telah diambil.\n");
            }
        } while (checkpenggunaSekarangname(/* Apakah penggunaSekarangname unik */));

        printf("Masukkan kata sandi:\n");
        STARTWORD();

        DaftarPengguna(/* Mendaftarkan nama pengguna dan password ke databse */);
        printf("Pengguna telah berhasil terdaftar. Masuk\nuntuk menikmati fitur-fitur BurBir.\n");
    }
}

void MASUK()
{
    if (true /* Pengguna telah masuk sebelumnya */)
    {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
    }
    else
    {
        do
        {
            printf("Masukkan nama:\n");
            STARTWORD();

            if (!checkpenggunaSekarangname(currentWord))
            {
                printf("Wah, nama yang Anda cari tidak ada.\nMasukkan nama lain!\n");
            }
        } while (!checkpenggunaSekarangname(/* Apakah penggunaSekarangname ada */));

        do
        {
            print("Masukkan kata sandi:\n");
            STARTWORD();

            if (!checkKatasandi(currentWord))
            {
                printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            }
        } while (!checkKatasandiI(true /* Mengecheck kata sandi pengguna*/));

        // Disini ada fungsi yang mengubah status login menjadi true
    }
}

void KELUAR()
{
    if (true /* Pengguna belum login */)
    {
        printf("Anda belum login! Masuk terlebih dahulu\nuntuk menikmati layanan BurBir.\n");

        // Status login tetap true
    }
    else
    {
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");

        // Status login menjadi false
    }
}

void TUTUP_PROGRAM()
{

    // status program menjadi false

    printf("Anda telah keluar dari program BurBir.\nSampai jumpa di penjelajahan berikutnya.\n");
}

int CURRENT_PENGGUNA()
{
}

/* ========== PROFIL ========== */

void GANTI_PROFIL()
{
    for (int i = 0; i < len(dataPengguna); i++)
    {
        if (IdPengguna(SelectPengguna(dataPengguna, i)) == IdPengguna(penggunaSekarang))
        {
            Pengguna penggunaSekarang = SelectPengguna(dataPengguna, i);
        }
    }

    if (IdPengguna(penggunaSekarang) == -1)
    {
        printf("Anda Belum Login! Masuk terlebih dahulu untuk mengganti profil.\n");
    }
    else
    {
        printf("|  Nama: ");
        printWord(penggunaSekarang.nama);
        printf("\n");
        printf("|  Bio Akun: ");
        printWord(penggunaSekarang.bio);
        printf("\n");
        printf("|  No HP: ");
        printWord(penggunaSekarang.noHP);
        printf("\n");
        printf("|  Weton: ");
        printWord(penggunaSekarang.weton);
        printf("\n");

        Word empty = {';', 1};

        boolean IsValidBio = false;
        Word Bio;
        while (!IsValidBio)
        {
            printf("Masukkan Bio Akun:\n");
            STARTWORD();

            Bio = currentWord;
            if (currentWord.Length <= 135)
            {
                IsValidBio = true;
            }
            if (!IsValidBio)
            {
                printf("\n");
                printf("Bio melebihi panjang maksimum!\n");
                printf("\n");
            }
        }
        penggunaSekarang.Bio = Bio;
        printf("\n");

        boolean IsValidNoHP = false;
        while (!IsValidNoHP)
        {
            printf("Masukkan No HP:\n");
            STARTSENTENCE();

            for (int i = 0; i < currentWord.Length; i++)
            {
                if (currentWord.TabWord[i] > '0' && currentWord.TabWord[i] < '9')
                {
                    IsValidNoHP = true;
                }
            }
            if (!IsValidNoHP)
            {
                printf("\n");
                printf("No HP tidak valid, Masukkan lagi yuk!\n");
                printf("\n");
            }
        }
        penggunaSekarang.NoHP = currentWord;
        printf("\n");

        Word weton[] = {{"Pahing", 6}, {"Kliwon", 6}, {"Wage", 6}, {"Legi", 4}, {"Pon", 3}}; // deklarasi Weton

        boolean IsValidWeton = false;
        while (!IsValidWeton)
        {
            printf("Masukkan Weton:\n");
            STARTSENTENCE();
            if (IsWordEqual(currentWord, empty))
            {
                IsValidWeton = true;
            }

            for (int i = 0; i < 4; i++)
            {
                if (IsWordEqual(currentWord, weton[i]))
                {
                    IsValidWeton = true;
                }
            }
            if (!IsValidWeton)
            {
                printf("\n");
                printf("Weton anda tidak valid\n");
                printf("\n");
            }
        }
        penggunaSekarang.Weton = currentWord;
        printf("Profil anda sudah berhasil diperbarui!\n\n");
    }
}

void LIHAT_PROFIL()
{
    for (int i = 0; i < len(dataPengguna); i++)
    {
        if (IdPengguna(SelectPengguna(dataPengguna, i)) == IdPengguna(penggunaSekarang))
        {
            Pengguna penggunaSekarang = SelectPengguna(dataPengguna, i);
        }
    }

    if (IdPengguna(penggunaSekarang) == -1)
    {
        printf("Anda Belum Login! Masuk terlebih dahulu untuk melihat profil.\n");
    }
    else
    {
        STARTWORD();
        Word name = currentWord;
        int idPengguna = IdPengguna(penggunaSekarang);
        Word Privat = {"Privat", 6};
        Word Publik = {"Publik", 6};
        Word TipeAkun = penggunaSekarang.jenisAkun;

        if (IsWordEqual(name, penggunaSekarang.nama))
        {
            Display_PROFIL(penggunaSekarang);
        }
        else
        {
            Pengguna penggunaSekarang1;
            for (int i = 0; i < len(dataPengguna); i++)
            {
                if (IsWordEqual(name, NamaPengguna(SelectPengguna(dataPengguna, i))))
                {
                    Pengguna penggunaSekarang1 = SelectPengguna(dataPengguna, i);
                }
            }
            if (IsWordEqual(TipeAkun, Privat) && !IsFriend)
            {
                printf("Wah, akun ");
                printWord(name);
                printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
                printWord(name);
            }
            else
            {
                Display_PROFIL(penggunaSekarang1);
            }
        }
    }
}

void ATUR_JENIS_AKUN()
{
    for (int i = 0; i < len(dataPengguna); i++)
    {
        if (IdPengguna(SelectPengguna(dataPengguna, i)) == IdPengguna(penggunaSekarang))
        {
            Pengguna penggunaSekarang = SelectPengguna(dataPengguna, i);
        }
    }

    if (IdPengguna(penggunaSekarang) == -1)
    {
        printf("Anda Belum Login!\n");
    }
    else
    {
        Word TipeAkun = penggunaSekarang.jenisAkun;
        Word Privat = {"Privat", 6};
        Word Publik = {"Publik", 6};
        Word YA = {"YA", 2};
        Word TIDAK = {"TIDAK", 5};

        printf("Saat ini, akun Anda adalah akun");
        printWord(TipeAkun);
        if (IsWordEqual(TipeAkun, Privat))
        {
            printf("Ingin mengubah ke akun Publik?");
            printf("\n");
            printf("(YA/TIDAK)");
            STARTWORD();
            if (IsWordEqual(currentWord, TIDAK))
            {
                printf("Perubahan akun dibatalkan.");
            }
            else
            {
                penggunaSekarang.jenisAkun = Publik;
                printf("Akun anda sudah diubah menjadi akun Publik.");
            }
        }
        else
        {
            printf("Ingin mengubah ke akun Privat?");
            printf("\n");
            printf("(YA/TIDAK)");
            STARTWORD();
            if (IsWordEqual(currentWord, TIDAK))
            {
                printf("Perubahan akun dibatalkan.\n");
            }
            else
            {
                penggunaSekarang.jenisAkun = Privat;
                printf("Akun anda sudah diubah menjadi akun Privat.\n");
            }
        }
    }
}

void UBAH_FOTO_PROFIL()
{
    for (int i = 0; i < len(dataPengguna); i++)
    {
        if (IdPengguna(SelectPengguna(dataPengguna, i)) == IdPengguna(penggunaSekarang))
        {
            Pengguna penggunaSekarang = SelectPengguna(dataPengguna, i);
        }
    }

    if (IdPengguna(penggunaSekarang) == -1)
    {
        printf("Anda Belum Login! Masuk terlebih dahulu untuk mengganti foto profil.\n");
    }
    else
    {
        printf("Foto profil Anda saat ini adalah\n");
        DISPLAY_FOTO_PROFIL(penggunaSekarang);
        printf("\n");
        printf("Masukkan foto profil yang baru\n");
        Matrix fp;
        START();
        IgnoreBlanks();
        IgnoreEnters();
        createMatrix(5, 10, &fp);
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
        IdPengguna(penggunaSekarang).foto = fp;
        printf("\n");
        printf("Foto profil anda sudah berhasil diganti!\n\n");
        PrintFoto(IdPengguna(penggunaSekarang));
    }
}

void DISPLAY_FOTO_PROFIL(Pengguna p)
{
    Matrix m = p.foto;
    createMatrix(5, 10, &m);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j + 2)
        {
            if (MAtELMT(m, i, j) == 'R')
            {
                print_red(MatELMT(m, i, j + 1));
            }
            else if (MatELMT(m, i, j) == 'G')
            {
                print_green(MatELMT(m, i, j + 1));
            }
            else if (MatELMT(m, i, j) == 'B')
            {
                print_blue(MatELMT(m, i, j + 1));
            }
        }
    }
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