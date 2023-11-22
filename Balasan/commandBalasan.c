#include "commandBalasan.h"
#include <stdio.h>
// Command Balasan
void BALAS(int IDKicau, int IDBalasan)
{
    if (!IsKicauanInTab(IDKicau))
    {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!");
    }
    else if (IDBalasan != 1 && !isBalasanExistInKicauan(IDKicau, IDBalasan))
    {
        printf("Wah, tidak terdapat balasan yang ingin Anda balas!");
    }
    else if (!isFriend(IdPengguna(penggunaSekarang), IDKicau) && PrivasiPengguna(cariPengguna(IDKicau)))
    {
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!");
    }
    else
    {
        if (IDBalasan == -1)
        {
        }
        printf("Masukkan Balasan:\n");
        AcquireSentence();
        printf("Selamat! balasan telah diterbitkan!\n");
        printf("Detil balasan:\n");
        printf("| ID = %d", anjay);
        printf("\n| %d", anjay);
        printf("\n| ");
        printTime();
        printf("\n| ");
        printSentence();
        printf("/n");
    }
};

void CETAK_BALASAN(int IDKicau)
{
    if (jumlahBalasan(IDKicau) == 0)
    {
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!");
    }
    else if (!isFriend(IdPengguna(penggunaSekarang), IDKicau) && PrivasiPengguna(cariPengguna(IDKicau)))
    {
        printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!");
    }
    else if (IsKicauanInTab(IDKicau))
    {
        printf("Tidak terdapat kicauan dengan id tersebut!");
    }
    else
    {
        // anjay
    }
}

void HAPUS_BALASAN(int IDKicau, int IDBalasan)
{
    if (!isBalasanExistInKicauan(IDKicau, IDBalasan))
    {
        printf("Balasan tidak ditemukan");
    }
    else if (PENULIS_BALASAN(searchBalasan(IDBalasan)))
    {
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!");
    }
    else
    {
        printf("Balasan berhasil dihapus");
    }
};