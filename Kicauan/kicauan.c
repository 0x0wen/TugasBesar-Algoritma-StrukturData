#include "kicauan.h"
#include <stdio.h>
#include <stdlib.h>
#include "../global.h"

/*** Kreator/Deletor Tab Kicauan ***/

/** Membuat kicauan baru kemudian memasukkannya ke list **/
Kicauan createKicauan()
{
    Kicauan newKicau;

    // id
    int newID = 0;
    newKicau.IDKicau = newID;

    // text
    Word text;
    InputWordWithBlank(&text);
    newKicau.Text = text;

    // like
    newKicau.Like = 0;

    // author
    Pengguna penggunaSekarang;
    Pengguna author = penggunaSekarang;
    newKicau.Author = author;
    //

    // time
    DATETIME time = getDATETIME();
    newKicau.DateTime = time;

    return newKicau;
}

void printKicauan(Kicauan k)
{
    printf("\n");
    printf("| ID = %d\n", k.IDKicau);
    printf("| ");
    printSentence(k.Author.nama);
    printf("\n");
    printf("| ");
    printTime(k.DateTime);
    printf("\n");
    printf("| ");
    printWord(k.Text);
    printf("\n");
    printf("| Disukai = %d\n", k.Like);
}

/*** Prosedur Kicauan yang berkaitan dengan spek ***/
void KICAU()
{

    printf("\nMasukkan kicauan:\n");
    Kicauan newKicau = createKicauan();

    // add newKicau ke tab
    addKicauanToTab(&dataKicauan, newKicau);

    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:");
    newKicau.IDKicau = MAXID_TabKicauan(dataKicauan);

    printKicauan(newKicau);
}

void KICAUAN()
{

    int i;
    for (i = 0; i < NEFF_TabKicauan(dataKicauan); i++)
    {
        if (ELMT_TabKicauan(dataKicauan, i).Author == penggunaSekarang)
        {
            printf("\n");
            printKicauan(ELMT_TabKicauan(dataKicauan, i));
        }
    }
}

void SUKA_KICAUAN(int id)
{

    if (isKicauanInTab(&dataKicauan, id))
    {

        int i, idx = getKicauanIdx(dataKicauan, id);
        Word Publik = {"Publik", 6};
        if (dataKicauan[idx].Author == penggunaSekarang ||
            IsWordEqual(dataKicauan[idx].Author.jenisAkun, Publik) /*||
             isFriend(penggunaSekarang, dataKicauan[idx].Author) */
        )
        {

            dataKicauan.buffer_TabKicauan[idx].Like++;
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detil kicauan:");

            printKicauan(dataKicauan.buffer_TabKicauan[idx]);
        }
        else
        {
            printf("\nWah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya");
        }
    }
    else
    {
        printf("Tidak ditemukan kicauan dengan ID = %d;", id);
    }
}

void UBAH_KICAUAN(int id)
{

    if (isKicauanInTab(&dataKicauan, id))
    {

        int i, idx = getKicauanIdx(dataKicauan, id);

        if (dataKicauan.buffer_TabKicauan[idx].Author != penggunaSekarang)
        {
            printf("\nKicauan dengan ID = %d bukan milikmu!", id);
        }
        else
        {

            printf("\nMasukkan kicauan baru: \n");
            Word text;
            InputWordWithBlank(&text);
            dataKicauan.buffer_TabKicauan[idx].Text = text;
            printf("\nSelamat! kicauan telah diterbitkan!");
            printKicauan(dataKicauan.buffer_TabKicauan[idx]);
        }
    }
    else
    {
        printf("\nTidak ditemukan kicauan dengan ID = %d!;", id);
    }
}
