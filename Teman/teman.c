#include <stdio.h>
#include "tabTeman.h"
#include "pengguna.h"
#include "tabPengguna.h"

boolean IsFriendWord(Word user1, Word user2) {
    int idx1 = IdPengguna(user1);
    int idx2 = idPengguna(user2);

    return (HUBUNGAN(dataTeman, idx1, idx2) == 1);
}

int JUMLAH_TEMAN(Word P)
{
    int countTeman = 0;
    for (int i = 0; i < lengthTabPengguna(); i++) {
        if (IsFriend(P, SelectPengguna(dataPengguna, i).nama)) {
            countTeman++;
        }
    }
    return countTeman;
}

void DAFTAR_TEMAN(Pengguna p) {
    for (int i = 0; i < len(dataPengguna); i++)
    {
        if (IdPengguna(SelectPengguna(dataPengguna, i)) == IdPengguna(penggunaSekarang))
        {
            Pengguna penggunaSekarang = SelectPengguna(dataPengguna, i);
        }
    }

    if (IdPengguna(penggunaSekarang) == -1)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }else{
        printWord(penggunaSekarang.nama) ;
        int countTeman = JUMLAH_TEMAN(penggunaSekarang.nama) ;
        if (countTeman == 0 ){
            printf(" belum mempunyai teman") ;
        }else{
            printf(" memiliki %d teman\n") ;
            printf("Daftar teman ") ;
            printWord(penggunaSekarang.nama);
            for (int i = 0; i < lengthTabPengguna(); i++) {
                if (IsFriend(penggunaSekarang.nama, SelectPengguna(dataPengguna, i).nama)) {
                    if(!IsWordEqual(penggunaSekarang.nama, SelectPengguna(dataPengguna, i).nama)){
                        printf("| ");
                        printWord(SelectPengguna(dataPengguna, i).nama) ;
                        printf("\n") ;
                    }
                }
            }
        }
    }
}

void HAPUS_TEMAN(Pengguna p) {
    for (int i = 0; i < len(dataPengguna); i++)
    {
        if (IdPengguna(SelectPengguna(dataPengguna, i)) == IdPengguna(penggunaSekarang))
        {
            Pengguna penggunaSekarang = SelectPengguna(dataPengguna, i);
        }
    }

    if (IdPengguna(penggunaSekarang) == -1)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }else{
        printf("Masukkan nama pengguna :\n") ;
        STARTWORD();
        Word name = currentWord ;
        if(!IsFriendWord(penggunaSekarang.nama, name)){
            printWord(name) ;
            printf(" bukan teman Anda.\n");
        }else{
            printf("Apakah anda yakin ingin menghapus ");
            printWord(name);
            printf(" dari daftar teman anda? (YA/TIDAK) ") ;
            STARTWORD() ;
            Word pilihan = currentWord;
            Word YA = {"YA", 2};
            Word TIDAK = {"TIDAK", 5};
            if (IsWordEqual(pilihan, TIDAK))
            {
                printf("Penghapusan teman dibatalkan.");
            }
            else
            {
                removeFriend(IDPengguna(penggunaSekarang), IDPengguna(name));
                printWord(name);
                printf(" berhasil dihapus dari daftar teman Anda.\n");
            }
        }
    }
}