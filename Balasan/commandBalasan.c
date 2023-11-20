#include "commandBalasan.h"

// Command Balasan
void Balas(int IDKicau, int IDBalasan)
{
    if (!isKicauanInTab(IDKicau))
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

void Show_Balasan(int IDKicau)
{
    if (jumlahBalasan(IDKicau) == 0)
    {
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!");
    }
    else if (!isFriend(IdPengguna(penggunaSekarang), IDKicau) && PrivasiPengguna(cariPengguna(IDKicau)))
    {
        printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!");
    }
    else if (isKicauanInTab(IDKicau))
    {
        printf("Tidak terdapat kicauan dengan id tersebut!");
    }
    else
    {
        // anjay
    }
};

void Hapus_Balasan(int IDKicau, int IDBalasan)
{
    if (!isBalasanExistInKicauan(IDKicau, IDBalasan))
    {
        printf("Balasan tidak ditemukan")
    }
    else if (PENULIS_BALASAN(cariBalasan(IDBalasan)))
    {
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!");
    }
    else
    {
        printf("Balasan berhasil dihapus");
    }
};