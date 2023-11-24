#include "../global.h"
// Command Balasan
void BALAS(int IDKicau, int IDBalasan)
{
    TreeBalasan TB = searchBalasan(LIST_BALASAN(*searchKicauan(dataKicauan, IDKicau)), IDBalasan);
    Kicauan K = *searchKicauan(dataKicauan, IDKicau);
    if (LIST_BALASAN(*searchKicauan(dataKicauan, IDKicau)) == NULL)
    {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!");
    }
    else if (IDBalasan != 1 && searchBalasan(LIST_BALASAN(K), IDBalasan) == NULL)
    {
        printf("Wah, tidak terdapat balasan yang ingin Anda balas!");
    }
    else if (isFriend(matrixTeman, ID_PENGGUNA(penggunaSekarang), PENULIS_BALASAN(DATA_NODE_BALASAN(TB))) == false && PRIVASI_PENGGUNA(*searchPengguna(&dataPengguna, IDKicau)) == true)
    {
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!");
    }
    else
    {
        if (IDBalasan == -1)
        {
            Balasan B;
            Sentence kalimat;
            printf("Masukkan Balasan:\n");
            InputSentence(&kalimat);
            B = createBalasan(kalimat, NAMA_PENGGUNA(penggunaSekarang), ID_PENGGUNA(penggunaSekarang), JUMLAH_BALASAN(K));
            TreeBalasan TB2 = createBalasanNode(B);
            addBalasan(&LIST_BALASAN(K), &TB2);
            JUMLAH_BALASAN(K) += 1;
            printf("Selamat! balasan telah diterbitkan!\n");
            printf("Detil balasan:\n");
            printf("| ID = %d", ID_BALASAN(B));
            printf("\n| ");
            printSentence(AUTHOR_BALASAN(B));
            printf("\n| ");
            TulisDATETIME(WAKTU_BALASAN(DATA_NODE_BALASAN(TB)));
            printf("\n| ");
            printf("/n");
        }
        else
        {
            Balasan B;
            Sentence kalimat;
            printf("Masukkan Balasan:\n");
            InputSentence(&kalimat);
            B = createBalasan(kalimat, NAMA_PENGGUNA(penggunaSekarang), ID_PENGGUNA(penggunaSekarang), JUMLAH_BALASAN(K));
            createBalasanNode(B);
            TreeBalasan TB2 = createBalasanNode(B);
            addBalasan(&TB, &TB2);
            JUMLAH_BALASAN(K) += 1;
            printf("Selamat! balasan telah diterbitkan!\n");
            printf("Detil balasan:\n");
            printf("| ID = %d", ID_BALASAN(B));
            printf("\n| ");
            printSentence(AUTHOR_BALASAN(B));
            printf("\n| ");
            TulisDATETIME(WAKTU_BALASAN(DATA_NODE_BALASAN(TB)));
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
    else if (isFriend(matrixTeman, ID_PENGGUNA(penggunaSekarang), getIDPengguna(dataPengguna, AUTHOR_KICAU(*searchKicauan(dataKicauan, IDKicau)))) == false && PRIVASI_PENGGUNA(*searchPengguna(&dataPengguna, IDKicau)))
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
    TreeBalasan TB = searchBalasan(LIST_BALASAN(*searchKicauan(dataKicauan, IDKicau)), IDBalasan);
    if (TB == NULL)
    {
        printf("Balasan tidak ditemukan");
    }
    else if (IsSentenceEqual(AUTHOR_BALASAN(DATA_NODE_BALASAN(TB)), NAMA_PENGGUNA(penggunaSekarang)) == false)
    {
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!");
    }
    else
    {
        removeBalasan(&TB);
        printf("Balasan berhasil dihapus");
    }
};