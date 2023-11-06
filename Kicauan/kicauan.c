#include "kicauan.h"
#include <stdio.h>
#include <stdlib.h>

/*** Kreator/Deletor Tab Kicauan ***/
void createTabKicauan(TabKicauan *t, int capacity)
{

    TAB(*t) = (Kicauan *)malloc(capacity * sizeof(Kicauan));

    /* Kalau malloc berhasil capacity(t) = capacity
       kalau gagal capacity = 0;*/
    if (TAB(*t) != NULL)
    {
        CAPACITY(*t) = capacity;
    }
    else
    {
        CAPACITY(*t) = 0;
    }

    NEFF(*t) = 0;
    MAXID(*t) = 0;
}

void deleteTabKicauan(TabKicauan *t)
{

    free(TAB(*t));
    CAPACITY(*t) = 0;
    NEFF(*t) = 0;
}

/*** Copy List ***/
void copyList(TabKicauan lIn, TabKicauan *lOut){

    int i;
    CreateTabKicauan(lOut, CAPACITY(lIn));

    for (i = 0; i < NEFF(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
    MAXID(*lOut) = MAXID(lIn);
};


/*** Add/Delete Kicauan from Tab ***/
void addKicauanToTab(TabKicauan *t, Kicauan k)
{

    if (NEFF(*t) < CAPACITY(*t))
    {
        // do nothing
    }
    else
    {
        // expand dulu list nya by 1P
        expandList(t, 1);
    }
    // assign k ke indeks ke-neff di t
    ELMT(*t, NEFF(*t)) = k;
    NEFF(*t)++;
    MAXID(*t)++;
}
// Owen : nambahin fungsi buat ngecek ada kicauan dengan id tertentu di tab atau tidak
boolean isKicauanInTab(TabKicauan *t, int id)
{
    int i;
    boolean found;
    found = false;
    for (i = 0; i < NEFF(*t); i++)
    {
        if ((ELMT(*t, i)).IDKicau == id)
        {
            found = true;
            break;
        }
    }
    return found;
}
void deleteKicauanFromTab(TabKicauan *t, Kicauan *k, int id){

    int idxStart, i;
    boolean found = false;

    for (i = 0; i < NEFF(*t); i++)
    {

        if (found)
        { // geser elemen ke-i mundur ke-(i-1)
            ELMT(*t, i - 1) = ELMT(*t, i);
        }
        if ((ELMT(*t, i)).IDKicau == id){
            *k = ELMT(*t, i);
            found = true;
        }
    }
    if (found)
    {
        NEFF(*t)--;
    }
}

/*** Mengubah Ukuran Tab ***/
void expandList(TabKicauan *t, int num){
    TabKicauan temp;
    int cap, nEff, maxId, i;

    copyList(*t, &temp);
    cap = CAPACITY(*t) + num;
    nEff = NEFF(*t);
    maxId = MAXID(*t);

    dealocateList(t);

    CreateTabKicauan(t, cap);
    NEFF(*t) = nEff;
    MAXID(*t) = maxId;

    for (i = 0; i < nEff; i++)
    {
        ELMT(*t, i) = ELMT(temp, i);
    }
    dealocateList(&temp);
}

void shrinkList(TabKicauan *t, int num){
    TabKicauan temp;
    int cap, nEff, maxId, i;

    copyList(*t, &temp);
    cap = CAPACITY(*t) - num;
    nEff = NEFF(*t);
    maxId = MAXID(*t);

    dealocateList(t);

    CreateTabKicauan(t, cap);
    NEFF(*t) = nEff;
    MAXID(*t) = maxId;

    for (i = 0; i < nEff; i++)
    {
        ELMT(*t, i) = ELMT(temp, i);
    }
    dealocateList(&temp);
}

void compressList(TabKicauan *t){
    TabKicauan temp;
    int cap, nEff, maxId, i;

    copyList(*t, &temp);
    cap = NEFF(*t);
    nEff = NEFF(*t);
    maxId = MAXID(*t);

    dealocateList(t);

    CreateTabKicauan(t, cap);
    NEFF(*t) = nEff;
    MAXID(*t) = maxId;

    for (i = 0; i < nEff; i++)
    {
        ELMT(*t, i) = ELMT(temp, i);
    }
    dealocateList(&temp);
}


/*** Prosedur Kicauan ***/

/** Membuat kicauan baru kemudian memasukkannya ke list **/
void createKicauan(TabKicauan *t){
    Kicauan newKicau;

    // id 
    int newID = MAXID(*t) + 1;
    newKicau.IDKicau = newID;

    // text 
    printf("Masukkan kicauan:\n");
    Word text; InputWordWithBlank(&text);
    newKicau.Text = text;

    // like 
    newKicau.Like = 0;

    // author
    Sentence author = penggunaSekarang.nama;
    newKicau.Author = author;

    // time 
    DATETIME time;
    newKicau.DateTime = time;
    
    // add newKicau ke tab
    addKicauanToTab(t, newKicau);

    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:");

    printKicauan(newKicau);
}

void printKicauan(Kicauan k){   
    printf("\n");
    printf("| ID = %d\n", k.IDKicau;);
    printf("| "); printSentence(k.Author); printf("\n");
    printf("| "); printTime(k.DateTime); printf("\n");
    printf("| "); printWord(k.Text); printf("\n");
    printf("| ID = %d\n", k.Like);
}

/*** Prosedur Kicauan yang berkaitan dengan spek ***/
void KICAU(){
    createKicauan(&dataKicauan);
}

void KICAUAN(){

    int i;
    for (i = 0; i < NEFF(dataKicauan); i++){
        if (ELMT(dataKicauan, i).Author == penggunaSekarang.nama){
            printKicauan(ELMT(dataKicauan, i));
        } 
    }
}

void SUKA_KICAUAN(id){

    // belum di cek kalau akun private atau kalau temenan ato gk

    if (isKicauanInTab(&dataKicauan, id)){

        int i;
        for (i = 0; i < NEFF(dataKicauan); i++){
            if (dataKicauan[i].IDKicau == id){
                dataKicauan[i].Likes++;
            }
        }

    } else {
        printf("Tidak ditemukan kicauan dengan ID = %d;", id);
    }
}