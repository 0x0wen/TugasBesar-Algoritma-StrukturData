#include "commandUtas.h"
#include <stdio.h>
#include <stdlib.h>
void CREATE_UTAS(int IDKicau)
{
    Word currentWord;
    STARTWORD();

    if (ID_PENGGUNA(penggunaSekarang) != getIDPengguna(dataPengguna, AUTHOR_KICAU(*searchKicauan(dataKicauan, IDKicau))))
    {
        printf("Utas ini bukan milik anda!");
    }
    else if (UTAS_KICAU(*searchKicauan(dataKicauan, IDKicau)) != NULL)
    {
        printf("Utas sudah dibuat!");
    }
    else if (searchKicauan(dataKicauan, IDKicau) == NULL)
    {
        printf("Kicauan tidak ditemukan!\n");
    }
    else
    {
        printf("Utas berhasil dibuat!\n");
        do
        {
            printf("Masukkan kicauan: \n");
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)");
        } while (isWordEqualStr(&currentWord, "YA"));
        printf("Utas selesai!\n");
    }
}
void SAMBUNG_UTAS(int IDUtas, int index)
{
    if (isIdxTabUtasEff(dataUtas, index))
    {
        printf("Index terlalu tinggi!\n");
    }
    else if (searchUtas(dataUtas, IDUtas) == NULL)
    {
        printf("Utas tidak ditemukan!\n");
    }
    else if (ID_PENGGUNA(penggunaSekarang) != getIDPengguna(dataPengguna, AUTHOR_UTAS(*searchUtas(dataUtas, IDUtas))))
    {
        printf("Anda tidak bisa menyambung utas ini!");
    }
};
void HAPUS_UTAS(int IDUtas, int index)
{
    if (searchUtas(dataUtas, IDUtas) == NULL)
    {
        printf("Utas tidak ditemukan!");
    }
    else if (searchUtas(dataUtas, IDUtas) == NULL)
    {
        printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!", index);
    }
    else if (index == 0)
    {
        printf("Anda tidak bisa menghapus kicauan utama!");
    }
    else if (ID_PENGGUNA(penggunaSekarang) != getIDPengguna(dataPengguna, AUTHOR_UTAS(*searchUtas(dataUtas, IDUtas))))
    {
        printf("Anda tidak bisa menghapus kicauan dalam utas ini!");
    }
    else
    {
        printf("Kicauan sambungan berhasil dihapus!");
        // algoritma hapus
        // ...
    }
}
void CETAK_UTAS(int IDUtas)
{
    if (searchUtas(dataUtas, IDUtas) == NULL)
    {
        printf("Utas tidak ditemukan!");
    }
    else if (isFriend(matrixTeman, ID_PENGGUNA(penggunaSekarang), getIDPengguna(dataPengguna, AUTHOR_UTAS(*searchUtas(dataUtas, IDUtas)))))
    {
        printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!");
    }
    else
    {
        displayTabKicauanSambungan(KICAUAN_SAMBUNGAN(*searchUtas(dataUtas, IDUtas)));
    }
};