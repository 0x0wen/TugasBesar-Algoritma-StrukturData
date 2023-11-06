#include "kicauan.h"
#include <stdio.h>
#include <stdlib.h>

/*** Kreator/Deletor Tab Kicauan ***/
void createTabKicauan(TabKicauan *t, int capacity){

    TAB(*t) = (Kicauan *) malloc (capacity * sizeof(Kicauan));

    /* Kalau malloc berhasil capacity(t) = capacity
       kalau gagal capacity = 0;*/
    if(TAB(*t) != NULL){
        CAPACITY(*t) = capacity;
    } else {
        CAPACITY(*t) = 0;
    }

    NEFF(*t) = 0;
    MAXID(*t) = 0;
}

void deleteTabKicauan(TabKicauan *t){

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
void addKicauanToTab(TabKicauan *t, Kicauan k){

    if(NEFF(*t) < CAPACITY(*t)){
        // do nothing
    } else {
        // expand dulu list nya by 1P
        expandList(t, 1);
    }
    // assign k ke indeks ke-neff di t
    ELMT(*t, NEFF(*t)) = k;
    NEFF(*t)++;
}

void deleteKicauanFromTab(TabKicauan *t, Kicauan *k, int id){

    int idxStart, i;
    boolean found = false;

    for (i = 0; i < NEFF(*t); i++){

        if (found){ // geser elemen ke-i mundur ke-(i-1)
            ELMT(*t, i-1) = ELMT(*t, i);
        }
        else if ((ELMT(*t, i)).IDKicau == id){
            *k = ELMT(*t, i);
            found = true;
        }
    }
    if (found){
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

    // inisialisasi
    Kicauan newKicau;

    // id kicauan baru adalah id kicauan terakhir pada list ditambah 1
    int newID = ID(ELMT(*t, NEFF(*t)-1)) + 1; 

    // ini gtw napa kalo make selektor
    // ID(newKicau) = newID;
    // TEXT(newKicau) = "kicauan baru";
    // LIKE(newKicau) = 0;
    // AUTHOR(newKicau) = "rafi";
    // TIME(newKicau) = "otw";

    addKicauanToTab(t, newKicau);
}

void printKicauan(Kicauan k){

    // printf();
}