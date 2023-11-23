#include "commandBalasan.h"
#include <stdio.h>
// Command Balasan
void BALAS(int IDKicau, int IDBalasan)
{
    Kicauan K = *searchKicauan(dataKicauan, IDKicau);
    if (LIST_BALASAN(*searchKicauan(dataKicauan, IDKicau)) == NULL)
    {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!");
    }
    else if (IDBalasan != 1 && searchBalasan(LIST_BALASAN(K), IDBalasan) == NULL)
    {
        printf("Wah, tidak terdapat balasan yang ingin Anda balas!");
    }
    else if (isFriend(matrixTeman, ID_PENGGUNA(penggunaSekarang), PENULIS_BALASAN(*searchBalasan(LIST_BALASAN(*searchKicauan(dataKicauan, IDKicau)), IDBalasan))) == false && PRIVASI_PENGGUNA(*searchPengguna(dataPengguna, IDKicau)))
    {
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!");
    }
    else
    {
        if (IDBalasan == -1)
        {
            printf("Masukkan Balasan:\n");
            AcquireSentence();
            printf("Selamat! balasan telah diterbitkan!\n");
            printf("Detil balasan:\n");
            printf("| ID = %d", ID_KICAU(K));
            printf("\n| ");
            printSentence(NAMA_PENGGUNA(penggunaSekarang));
            printf("\n| ");
            TulisDATETIME(WAKTU_BALASAN(*searchBalasan(LIST_BALASAN(K), IDBalasan)));
            printf("\n| ");
            printf("/n");
        }
        else
        {
            printf("Masukkan Balasan:\n");
            AcquireSentence();
            printf("Selamat! balasan telah diterbitkan!\n");
            printf("Detil balasan:\n");
            printf("| ID = %d", ID_KICAU(K));
            printf("\n| ");
            printSentence(NAMA_PENGGUNA(penggunaSekarang));
            printf("\n| ");
            TulisDATETIME(WAKTU_BALASAN(*searchBalasan(LIST_BALASAN(K), IDBalasan)));
            printf("\n| ");
            printf("/n");
        }
    }
};

void CETAK_BALASAN(int IDKicau)
{
    if (LIST_BALASAN(*searchKicauan(dataKicauan, IDKicau)) == 0)
    {
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!");
    }
    else if (isFriend(matrixTeman, ID_PENGGUNA(penggunaSekarang), getIDPengguna(dataPengguna, AUTHOR_KICAU(*searchKicauan(dataKicauan, IDKicau)))) == false && PRIVASI_PENGGUNA(*searchPengguna(dataPengguna, IDKicau)))
    {
        printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!");
    }
    else if (LIST_BALASAN(*searchKicauan(dataKicauan, IDKicau)) == NULL)
    {
        printf("Tidak terdapat kicauan dengan id tersebut!");
    }
    else
    {
        printTreeBalasan(LIST_BALASAN(*searchKicauan(dataKicauan, IDKicau)), 0);
    }
}

void HAPUS_BALASAN(int IDKicau, int IDBalasan)
{
    Balasan *B = searchBalasan(LIST_BALASAN(*searchKicauan(dataKicauan, IDKicau)), IDBalasan);
    if (B == NULL)
    {
        printf("Balasan tidak ditemukan");
    }
    else if (IsSentenceEqual(AUTHOR_BALASAN(*B), NAMA_PENGGUNA(penggunaSekarang)) == false)
    {
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!");
    }
    else
    {
        printf("Balasan berhasil dihapus");
    }
};