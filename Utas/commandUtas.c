#include "commandUtas.h"
#include <stdio.h>

void CREATE_UTAS(int IDKicau)
{
    if (IDKicau bukan punya user)
    {
        printf("Utas ini bukan milik anda!");
    }
    else if (Kicauan sudah menjadi kicauan utama utas lain)
    {
    }
    else if (!adaKicau(IDKicau))
    {
        printf("Kicauan tidak ditemukan\n");
    }
    else
    {

        printf("Utas berhasil dibuat!\n");
        do
        {
            printf("Masukkan kicauan: \n");
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)");
        } while (kata == "YA");
        printf("Utas selesai!\n");
    }
}
void SAMBUNG_UTAS(int IDUtas, int index)
{
    if (index lewat batas)
    {
        printf("Index terlalu tinggi!\n");
    }
    else if (!adaUtas(IDUtas))
    {
        printf("Utas tidak ditemukan!\n");
    }
    else if (Utas not owned by user)
    {
        printf("Anda tidak bisa menyambung utas ini!");
    }
};
void HAPUS_UTAS(int IDUtas, int index)
{
    if (!adaUtas(IDUtas))
    {
        printf("Utas tidak ditemukan!");
    }
    else if (index not found)
    {
        printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!", index);
    }
    else if (index == 0)
    {
        printf("Anda tidak bisa menghapus kicauan utama!");
    }
    else if (utas is not owned by user)
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
    if (!adaUtas(IDUtas))
    {
        printf("Utas tidak ditemukan!");
    }
    else if (utas owner is private)
    {
        printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!");
    }
    else
    {
        int i;
        printf("| ID = %d", IDUtas);
        printf("| %s");
        printf("| %s");
        printf("| ");
        PrintSentence();
        for (i = 0; i < lengthTabKicauanSambungan(KICAUAN_SAMBUNGAN(cariUtas(IDUtas))); i++)
        {
            printf("\t| INDEX = %d");
            printf("\t| %s");
            printf("\t| %s");
            printf("\t| ");
            PrintSentence();
            printf("\n");
        }
    }
};