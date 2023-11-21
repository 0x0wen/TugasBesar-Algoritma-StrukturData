#include "kicauan.h"
#include <stdio.h>
#include <stdlib.h>
#include "../global.h"

/*** Kreator/Deletor Tab Kicauan ***/
void createTabKicauan(TabKicauan *t, int capacity)
{

    TAB_TabKicauan(*t) = (Kicauan *)malloc(capacity * sizeof(Kicauan));

    /* Kalau malloc berhasil capacity(t) = capacity
       kalau gagal capacity = 0;*/
    if (TAB(*t) != NULL)
    {
        CAPACITY_TabKicauan(*t) = capacity;
    }
    else
    {
        CAPACITY_TabKicauan(*t) = 0;
    }

    NEFF_TabKicauan(*t) = 0;
    MAXID_TabKicauan(*t) = 0;
}

void deleteTabKicauan(TabKicauan *t)
{

    free(TAB(*t));
    CAPACITY_TabKicauan(*t) = 0;
    NEFF_TabKicauan(*t) = 0;
}

/*** Copy List ***/
void copyListKicauan(TabKicauan lIn, TabKicauan *lOut){

    int i;
    CreateTabKicauan(lOut, CAPACITY_TabKicauan(lIn));

    for (i = 0; i < NEFF_TabKicauan(lIn); i++)
    {
        ELMT_TabKicauan(*lOut, i) = ELMT_TabKicauan(lIn, i);
    }
    NEFF_TabKicauan(*lOut) = NEFF_TabKicauan(lIn);
    MAXID_TabKicauan(*lOut) = MAXID_TabKicauan(lIn);
};


/*** Add/Delete Kicauan from Tab ***/
void addKicauanToTab(TabKicauan *t, Kicauan k)
{
    k.IDKicau = MAXID(dataKicauan) + 1;

    if (NEFF_TabKicauan(*t) < CAPACITY_TabKicauan(*t))
    {
        // do nothing
    }
    else
    {
        // expand dulu list nya by 1P
        expandList(t, 1);
    }
    // assign k ke indeks ke-neff di t
    ELMT_TabKicauan(*t, NEFF_TabKicauan(*t)) = k;
    NEFF_TabKicauan(*t)++;
    MAXID_TabKicauan(*t)++;
}
// Owen : nambahin fungsi buat ngecek ada kicauan dengan id tertentu di tab atau tidak
boolean isKicauanInTab(TabKicauan *t, int id)
{
    int i;
    boolean found;
    found = false;
    for (i = 0; i < NEFF_TabKicauan(*t); i++)
    {
        if ((ELMT_TabKicauan(*t, i)).IDKicau == id)
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

    for (i = 0; i < NEFF_TabKicauan(t); i++){
        if (ELMT_TabKicauan(t, i).IDKicau == id){
            idx = i;
        }
    }
    return idx;
}
void deleteKicauanFromTab(TabKicauan *t, Kicauan *k, int id){

    int idxStart, i;
    boolean found = false;

    for (i = 0; i < NEFF_TabKicauan(*t); i++)
    {

        if (found)
        { // geser elemen ke-i mundur ke-(i-1)
            ELMT_TabKicauan(*t, i - 1) = ELMT_TabKicauan(*t, i);
        }
        if ((ELMT_TabKicauan(*t, i)).IDKicau == id){
            *k = ELMT_TabKicauan(*t, i);
            found = true;
        }
    }
    if (found)
    {
        NEFF_TabKicauan(*t)--;
    }
}

/*** Mengubah Ukuran Tab ***/
void expandListKicauan(TabKicauan *t, int num){
    TabKicauan temp;
    int cap, nEff, maxId, i;

    copyListKicauan(*t, &temp);
    cap = CAPACITY_TabKicauan(*t) + num;
    nEff = NEFF_TabKicauan(*t);
    maxId = MAXID_TabKicauan(*t);

    dealocateList(t);

    CreateTabKicauan(t, cap);
    NEFF_TabKicauan(*t) = nEff;
    MAXID_TabKicauan(*t) = maxId;

    for (i = 0; i < nEff; i++)
    {
        ELMT_TabKicauan(*t, i) = ELMT_TabKicauan(temp, i);
    }
    dealocateList(&temp);
}

void shrinkListKicauan(TabKicauan *t, int num){
    TabKicauan temp;
    int cap, nEff, maxId, i;

    copyListKicauan(*t, &temp);
    cap = CAPACITY_TabKicauan(*t) - num;
    nEff = NEFF_TabKicauan(*t);
    maxId = MAXID_TabKicauan(*t);

    dealocateList(t);

    CreateTabKicauan(t, cap);
    NEFF_TabKicauan(*t) = nEff;
    MAXID_TabKicauan(*t) = maxId;

    for (i = 0; i < nEff; i++)
    {
        ELMT_TabKicauan(*t, i) = ELMT_TabKicauan(temp, i);
    }
    dealocateList(&temp);
}

void compressListKicauan(TabKicauan *t){
    TabKicauan temp;
    int cap, nEff, maxId, i;

    copyListKicauan(*t, &temp);
    cap = NEFF_TabKicauan(*t);
    nEff = NEFF_TabKicauan(*t);
    maxId = MAXID_TabKicauan(*t);

    dealocateList(t);

    CreateTabKicauan(t, cap);
    NEFF_TabKicauan(*t) = nEff;
    MAXID_TabKicauan(*t) = maxId;

    for (i = 0; i < nEff; i++)
    {
        ELMT_TabKicauan(*t, i) = ELMT_TabKicauan(temp, i);
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
    Pengguna penggunaSekarang;
    Pengguna author = penggunaSekarang;
    newKicau.Author = author;
    // 

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

/*** Prosedur Kicauan yang berkaitan dengan spek ***/
void KICAU(){

    printf("\nMasukkan kicauan:\n");
    Kicauan newKicau = createKicauan();

    // add newKicau ke tab
    addKicauanToTab(&dataKicauan, newKicau);

    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:");
    newKicau.IDKicau = MAXID_TabKicauan(dataKicauan);

    printKicauan(newKicau);
}

void KICAUAN(){

    int i;
    for (i = 0; i < NEFF_TabKicauan(dataKicauan); i++){
        if (ELMT_TabKicauan(dataKicauan, i).Author == penggunaSekarang){
            printf("\n");
            printKicauan(ELMT_TabKicauan(dataKicauan, i));
        } 
    }
}

void SUKA_KICAUAN(id){


    if (isKicauanInTab(&dataKicauan, id)){

        int i, idx = getKicauanIdx(dataKicauan, id);

        Word Publik = {"Publik", 6};
   
        if (dataKicauan[idx].Author == penggunaSekarang || 
            IsWordEqual(dataKicauan[idx].Author.jenisAkun,Publik) /*|| 
            isFriend(penggunaSekarang, dataKicauan[idx].Author) */){
            
            dataKicauan.buffer_TabKicauan[idx].Like++;
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detil kicauan:");

            printKicauan(dataKicauan.buffer_TabKicauan[idx]);
            
        } else {
            printf("\nWah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya");
        }

    } else {
        printf("Tidak ditemukan kicauan dengan ID = %d;", id);
    }
}

void UBAH_KICAUAN(id){

    if (isKicauanInTab(&dataKicauan, id)){

        int i, idx = getKicauanIdx(dataKicauan, id);

        if (dataKicauan.buffer_TabKicauan[idx].Author != penggunaSekarang){
            printf("\nKicauan dengan ID = %d bukan milikmu!", id);
        } else {

            printf("\nMasukkan kicauan baru: \n");
            Word text; InputWordWithBlank(&text);
            dataKicauan.buffer_TabKicauan[idx].Text = text;
            printf("\nSelamat! kicauan telah diterbitkan!");
            printKicauan(dataKicauan.buffer_TabKicauan[idx]);
        }
    } else {
        printf("\nTidak ditemukan kicauan dengan ID = %d!;", id);
    }
}
