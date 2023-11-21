#include "tabKicauan.h"
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
void copyListKicauan(TabKicauan lIn, TabKicauan *lOut){

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
    k.IDKicau = MAXID(dataKicauan) + 1;

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

int getKicauanIdx(TabKicauan t, int id){

    int idx = -1;
    int i;

    for (i = 0; i < NEFF(t); i++){
        if (ELMT(t, i).IDKicau == id){
            idx = i;
        }
    }
    return idx;
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
void expandListKicauan(TabKicauan *t, int num){
    TabKicauan temp;
    int cap, nEff, maxId, i;

    copyListKicauan(*t, &temp);
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

void shrinkListKicauan(TabKicauan *t, int num){
    TabKicauan temp;
    int cap, nEff, maxId, i;

    copyListKicauan(*t, &temp);
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

void compressListKicauan(TabKicauan *t){
    TabKicauan temp;
    int cap, nEff, maxId, i;

    copyListKicauan(*t, &temp);
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
Kicauan createKicauan(){
    Kicauan newKicau;

    // id 
    int newID = 0;
    newKicau.IDKicau = newID;

    // text 
    Word text; InputWordWithBlank(&text);
    newKicau.Text = text;

    // like 
    newKicau.Like = 0;

    // author
    Pengguna author = penggunaSekarang;
    newKicau.Author = author;

    // time 
    DATETIME time = getDATETIME();
    newKicau.DateTime = time;
    
    return newKicau;
}

void printKicauan(Kicauan k){   
    printf("\n");
    printf("| ID = %d\n", k.IDKicau);
    printf("| "); printSentence(k.Author.nama); printf("\n");
    printf("| "); printTime(k.DateTime); printf("\n");
    printf("| "); printWord(k.Text); printf("\n");
    printf("| Disukai = %d\n", k.Like);
}

