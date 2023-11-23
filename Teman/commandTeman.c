#include "commandTeman.h"

void DAFTAR_TEMAN(){

    Sentence nama_user = NAMA_PENGGUNA(penggunaSekarang);
    int id_user = ID_PENGGUNA(penggunaSekarang);
    int banyak_teman = countTeman(matrixTeman, id_user);

    printf("\n");
    printSentence(nama_user); printf(" memiliki %d teman\n", banyak_teman);

    if (banyak_teman > 0){
        printf("Daftar teman "); printSentence(nama_user);

        Sentence nama_teman;

        int id_teman, j;
        for (id_teman = 0; id_teman < MAX_SIMPUL; id_teman++){
            if (isFriend(matrixTeman, id_user, id_teman)){

                for (j = 0; j < BANYAK_PENGGUNA(dataPengguna); j++){
                    if (SELECT_PENGGUNA(dataPengguna, j).id == j){
                        nama_teman = NAMA_PENGGUNA(SELECT_PENGGUNA(dataPengguna, j));
                        break;
                    }
                }
                printf("\n| "); printSentence(nama_teman);
            }
        }
    } else {
        printSentence(nama_user); printf(" belum memiliki teman");
    }
}

void HAPUS_TEMAN(){

    int id_user = ID_PENGGUNA(penggunaSekarang);

    printf("Masukan nama pengguna:\n");
    Sentence nama_teman; InputSentence(&nama_teman);

    int id_teman = 0;
    int i;

    for (i = 0; i < BANYAK_PENGGUNA(dataPengguna); i++){
        if (IsSentenceEqual(SELECT_PENGGUNA(dataPengguna, i).nama, nama_teman)){
            id_teman = SELECT_PENGGUNA(dataPengguna, i).id;
            break;
        }
    }

    if (id_teman != 0){
        if(!isFriend(matrixTeman, id_user, id_teman)){
            printf("\n"); printSentence(nama_teman); printf(" bukan teman Anda");
        } else {
            printf("\nApakah anda yakin ingin menghapus Bob dari daftar teman anda?(YA/TIDAK)\n");

            Word Action; InputWord(&Action);

            Word Ya = {"Ya", 2};
            Word Tidak = {"Tidak", 5};

            if (IsWordEqual(Ya, Action)){
                deleteFriend(&matrixTeman, id_user, id_teman);
                printSentence(nama_teman); printf(" berhasil dihapus dari daftar teman Anda.");
            } else {
                printf("\nPenghapusan teman dibatalkan.");
            }
        }
    } else {
        printf("Tidak ditemukan user dengan nama "); printSentence(nama_teman);
    }
}

// int JUMLAH_TEMAN(int IDPengguna)
// {
//     int countTeman = 0;
//     for (int i = 0; i < lengthTabPengguna(); i++)
//     {
//         if (IsFriend(P, SELECT_PENGGUNA(dataPengguna, i).nama))
//         {
//             countTeman++;
//         }
//     }
//     return countTeman;
// }

// void DAFTAR_TEMAN()
// {
//     for (int i = 0; i < BANYAK_PENGGUNA(dataPengguna); i++)
//     {
//         if (ID_PENGGUNA(SELECT_PENGGUNA(dataPengguna, i)) == ID_PENGGUNA(p))
//         {
//             Pengguna penggunaSekarang = SELECT_PENGGUNA(dataPengguna, i);
//         }
//     }

//     if (ID_PENGGUNA(penggunaSekarang) == IDX_UNDEF_TAB_PENGGUNA)
//     {
//         printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
//     }
//     else
//     {
//         printWord(penggunaSekarang.nama);
//         int countTeman = JUMLAH_TEMAN(penggunaSekarang.nama);
//         if (countTeman == 0)
//         {
//             printf(" belum mempunyai teman");
//         }
//         else
//         {
//             printf(" memiliki %d teman\n");
//             printf("Daftar teman ");
//             printWord(penggunaSekarang.nama);
//             for (int i = 0; i < lengthTabPengguna(); i++)
//             {
//                 if (IsFriend(penggunaSekarang.nama, SELECT_PENGGUNA(dataPengguna, i).nama))
//                 {
//                     if (!IsWordEqual(penggunaSekarang.nama, SELECT_PENGGUNA(dataPengguna, i).nama))
//                     {
//                         printf("| ");
//                         printWord(SELECT_PENGGUNA(dataPengguna, i).nama);
//                         printf("\n");
//                     }
//                 }
//             }
//         }
//     }
// }

// void HAPUS_TEMAN()
// {
//     for (int i = 0; i < BANYAK_PENGGUNA(dataPengguna); i++)
//     {
//         if (ID_PENGGUNA(SELECT_PENGGUNA(dataPengguna, i)) == ID_PENGGUNA(p))
//         {
//             Pengguna penggunaSekarang = SELECT_PENGGUNA(dataPengguna, i);
//         }
//     }

//     if (ID_PENGGUNA(penggunaSekarang) == -1)
//     {
//         printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
//     }
//     else
//     {
//         printf("Masukkan nama pengguna :\n");
//         STARTWORD();
//         Word name = currentWord;
//         if (!IsFriendWord(penggunaSekarang.nama, name))
//         {
//             printWord(name);
//             printf(" bukan teman Anda.\n");
//         }
//         else
//         {
//             printf("Apakah anda yakin ingin menghapus ");
//             printWord(name);
//             printf(" dari daftar teman anda? (YA/TIDAK) ");
//             STARTWORD();
//             Word pilihan = currentWord;
//             Word YA = {"YA", 2};
//             Word TIDAK = {"TIDAK", 5};
//             if (IsWordEqual(pilihan, TIDAK))
//             {
//                 printf("Penghapusan teman dibatalkan.");
//             }
//             else
//             {
//                 removeFriend(ID_PENGGUNA(penggunaSekarang), ID_PENGGUNA(name));
//                 printWord(name);
//                 printf(" berhasil dihapus dari daftar teman Anda.\n");
//             }
//         }
//     }
// }