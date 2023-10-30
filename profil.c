#include <stdio.h>
#include "pengguna.h"
#include "pcolor.h"
#include "matrix.h"

void GANTI_PROFIL()
{
}

void LIHAT_PROFIL()
{
}

void ATUR_JENIS_AKUN()
{
}

void UBAH_FOTO_PROFIL()
{
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
            else
            {
            }
        }
    }
}

void Display_PROFIL(Pengguna p)
{
    printf("|  Nama: ");
    printWord(p.nama);
    printf("|  Bio Akun: ");
    printWord(p.bio);
    printf("|  No HP: ");
    printWord(p.noHP);
    printf("|  Weton: ");
    printWord(p.weton);
    printf("\n");
    printf("Foto profil akun ");
    DISPLAY_FOTO_PROFIL(p);
}