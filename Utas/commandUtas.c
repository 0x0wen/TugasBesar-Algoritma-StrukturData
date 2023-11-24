#include "../global.h"
void CREATE_UTAS(int IDKicau)
{
    Kicauan K = *searchKicauan(dataKicauan, IDKicau);
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
        Utas U;
        KicauanSambungan KS;
        U = createUtas(AUTHOR_KICAU(K), lengthTabUtas(dataUtas), IDKicau, TEXT_KICAU(K), TIME_KICAU(K));
        insertLastTabUtas(&dataUtas, U);
        insertLastListDin(&DAFTAR_UTAS(*searchPengguna(&dataPengguna, ID_PENGGUNA(penggunaSekarang))), ID_UTAS(U));
        UTAS_KICAU(K) = &U;
        printf("Utas berhasil dibuat!\n");
        do
        {
            Sentence kalimat;
            printf("Masukkan kicauan: \n");
            InputSentence(&kalimat);
            KS = createKicauanSambungan(kalimat, AUTHOR_KICAU(K), ID_PENGGUNA(penggunaSekarang), lengthTabKicauanSambungan(KICAUAN_SAMBUNGAN(U)));
            insertLastTabKicauanSambungan(&KICAUAN_SAMBUNGAN(U), KS);
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)");
        } while (isWordEqualStr(currentWord, "YA"));
        printf("Utas selesai!\n");
    }
}
void SAMBUNG_UTAS(int IDUtas, int index)
{
    if (isIdxTabUtasEff(dataUtas, index) == false)
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
    else
    {
        Sentence kalimat;
        printf("Masukkan kicauan: \n");
        InputSentence(&kalimat);
    }
};
void HAPUS_UTAS(int IDUtas, int index)
{
    if (searchUtas(dataUtas, IDUtas) == NULL)
    {
        printf("Utas tidak ditemukan!");
    }
    else if (index <= 0 || index > lengthTabKicauanSambungan(KICAUAN_SAMBUNGAN(*searchUtas(dataUtas, IDUtas))))
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
        deleteAtTabKicauanSambungan(&KICAUAN_SAMBUNGAN(*searchUtas(dataUtas, IDUtas)), index - 1);
        printf("Kicauan sambungan berhasil dihapus!");
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
        printUtas(*searchUtas(dataUtas, IDUtas));
    }
};