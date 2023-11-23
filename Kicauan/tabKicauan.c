#include "tabKicauan.h"
#include <stdio.h>
#include <stdlib.h>

/*** Kreator/Deletor Tab Kicauan ***/
void createTabKicauan(TabKicauan *t, int capacity)
{

    SELECT_TAB_KICAUAN(*t) = (Kicauan *) malloc (capacity * sizeof(Kicauan));

    /* Kalau malloc berhasil capacity(t) = capacity
       kalau gagal capacity = 0;*/
    if (SELECT_TAB_KICAUAN(*t) != NULL)
    {
        CAPACITY_TAB_KICAUAN(*t) = capacity;
    }
    else
    {
        CAPACITY_TAB_KICAUAN(*t) = 0;
    }

    NEFF_TAB_KICAUAN(*t) = 0;
    MAXID_TAB_KICAUAN(*t) = 0;
}

void deleteTabKicauan(TabKicauan *t)
{
    free(SELECT_TAB_KICAUAN(*t));
    CAPACITY_TAB_KICAUAN(*t) = 0;
    NEFF_TAB_KICAUAN(*t) = 0;
}

/*** Copy List ***/
void copyListKicauan(TabKicauan lIn, TabKicauan *lOut){

    int i;
    CreateTabKicauan(lOut, CAPACITY_TAB_KICAUAN(lIn));

    for (i = 0; i < NEFF_TAB_KICAUAN(lIn); i++)
    {
        SELECT_KICAUAN(*lOut, i) = SELECT_KICAUAN(lIn, i);
    }
    NEFF_TAB_KICAUAN(*lOut) = NEFF_TAB_KICAUAN(lIn);
    MAXID_TAB_KICAUAN(*lOut) = MAXID_TAB_KICAUAN(lIn);
};


/*** Add/Delete Kicauan from Tab ***/
void addKicauanToTab(TabKicauan *t, Kicauan k){

    if (NEFF_TAB_KICAUAN(*t) < CAPACITY_TAB_KICAUAN(*t))
    {
        // do nothing
    }
    else
    {
        // expand dulu list nya by 1P
        expandListKicauan(t, 1);
    }
    // assign k ke indeks ke-neff di t
    SELECT_KICAUAN(*t, NEFF_TAB_KICAUAN(*t)) = k;
    NEFF_TAB_KICAUAN(*t)++;
    MAXID_TAB_KICAUAN(*t)++;
}
// Owen : nambahin fungsi buat ngecek ada kicauan dengan id tertentu di tab atau tidak
boolean isKicauanInTab(TabKicauan *t, int id)
{
    boolean found;
    found = false;

    int i;
    for (i = 0; i < NEFF_TAB_KICAUAN(*t); i++)
    {
        if (SELECT_KICAUAN(*t, i).IDKicau == id)
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

    for (i = 0; i < NEFF_TAB_KICAUAN(t); i++){
        if (SELECT_KICAUAN(t, i).IDKicau == id){
            idx = i;
            break;
        }
    }
    return idx;
}
void deleteKicauanFromTab(TabKicauan *t, int id){

    int idxStart, i;
    boolean found = false;

    for (i = 0; i < NEFF_TAB_KICAUAN(*t); i++) {
        if (found) { // geser elemen ke-i mundur ke-(i-1)
            SELECT_KICAUAN(*t, i-1) = SELECT_KICAUAN(*t, i);

        } else if ((SELECT_KICAUAN(*t, i)).IDKicau == id){
            found = true;
        }
    }
    if (found) {
        NEFF_TAB_KICAUAN(*t)--;
    }
}

/*** Mengubah Ukuran Tab ***/
void expandListKicauan(TabKicauan *t, int num){
    TabKicauan temp;
    int cap, nEff, maxId, i;

    copyListKicauan(*t, &temp);
    cap = CAPACITY_TAB_KICAUAN(*t) + num;
    nEff = NEFF_TAB_KICAUAN(*t);
    maxId = MAXID_TAB_KICAUAN(*t);

    deleteTabKicauan(t);

    CreateTabKicauan(t, cap);
    NEFF_TAB_KICAUAN(*t) = nEff;
    MAXID_TAB_KICAUAN(*t) = maxId;

    for (i = 0; i < nEff; i++)
    {
        SELECT_KICAUAN(*t, i) = SELECT_KICAUAN(temp, i);
    }
    deleteTabKicauan(&temp);
}

// void shrinkListKicauan(TabKicauan *t, int num){
//     TabKicauan temp;
//     int cap, nEff, maxId, i;

//     copyListKicauan(*t, &temp);
//     cap = CAPACITY_TAB_KICAUAN(*t) - num;
//     nEff = NEFF_TAB_KICAUAN(*t);
//     maxId = MAXID_TAB_KICAUAN(*t);

//     dealocateList(t);

//     CreateTabKicauan(t, cap);
//     NEFF_TAB_KICAUAN(*t) = nEff;
//     MAXID_TAB_KICAUAN(*t) = maxId;

//     for (i = 0; i < nEff; i++)
//     {
//         SELECT_KICAUAN(*t, i) = SELECT_KICAUAN(temp, i);
//     }
//     dealocateList(&temp);
// }

// void compressListKicauan(TabKicauan *t){
//     TabKicauan temp;
//     int cap, nEff, maxId, i;

//     copyListKicauan(*t, &temp);
//     cap = NEFF(*t);
//     nEff = NEFF(*t);
//     maxId = MAXID(*t);

//     dealocateList(t);

//     CreateTabKicauan(t, cap);
//     NEFF(*t) = nEff;
//     MAXID(*t) = maxId;

//     for (i = 0; i < nEff; i++)
//     {
//         ELMT(*t, i) = ELMT(temp, i);
//     }
//     dealocateList(&temp);
// }


/*** Prosedur Kicauan ***/

/** Membuat kicauan baru kemudian memasukkannya ke list **/
// Kicauan createKicauan(){
//     Kicauan newKicau;

//     // id 
//     int newID = 0;
//     newKicau.IDKicau = newID;

//     // text 
//     Word text; InputWordWithBlank(&text);
//     newKicau.Text = text;

//     // like 
//     newKicau.Like = 0;

//     // author
//     Pengguna author = penggunaSekarang;
//     newKicau.Author = author;

//     // time 
//     DATETIME time = getDATETIME();
//     newKicau.DateTime = time;
    
//     return newKicau;
// }

// void printKicauan(Kicauan k){   
//     printf("\n");
//     printf("| ID = %d\n", k.IDKicau);
//     printf("| "); printSentence(k.Author.nama); printf("\n");
//     printf("| "); printTime(k.DateTime); printf("\n");
//     printf("| "); printSentence(k.Text); printf("\n");
//     printf("| Disukai = %d\n", k.Like);
// }

