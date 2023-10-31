/* File : listlinier.c */
/* Library ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

/* *** Kreator *** */

/* I.S. sembarang */
/* F.S. Mengembalikan alamat dari node baru yang memiliki nilai val */
Address newNode(ElType val){

    Address NODE = (Address) malloc (sizeof(Node));

    if (NODE != NULL){
        INFO(NODE) = val;
        NEXT(NODE) = NULL;
    }
 
    return NODE;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/

/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
void CreateList(List *l){

    FIRST(*l) = NULL;
}


/****************** TEST LIST KOSONG ******************/

/* Mengirim true jika list kosong */
boolean isEmpty(List l){

    return FIRST(l) == NULL;
}


/****************** GETTER SETTER ******************/

/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
ElType getElmt(List l, int idx){

    Address NODE = FIRST(l);
    int i;

    for(i = 0; i < idx; i++){
        NODE = NEXT(NODE);
    }

    return INFO(NODE);
}

/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
void setElmt(List *l, int idx, ElType val){

    Address NODE = FIRST(*l);
    int i;

    for(i = 0; i < idx; i++){
        NODE = NEXT(NODE);
    }

    INFO(NODE) = val;
}

/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
int indexOf(List l, ElType val){

    Address NODE = FIRST(l);

    int IDX = 0;
    boolean FOUND = false;

    while(NODE != NULL && !FOUND){
        if(INFO(NODE) == val){
            FOUND = true;
        } else {
            IDX++;
            NODE = NEXT(NODE);
        }
    }

    if (FOUND){
        return IDX;
    } else {
        return IDX_UNDEF;
    }
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/

/*** PENAMBAHAN ELEMEN ***/

/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
void insertFirst(List *l, ElType val){

    Address NEWNODE = newNode(val);

    if (NEWNODE != NULL){
        NEXT(NEWNODE) = FIRST(*l);
        FIRST(*l) = NEWNODE;
    }
}

/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void insertLast(List *l, ElType val){

    if (isEmpty(*l)){
        insertFirst(l, val);
    } else {

        Address NODE = FIRST(*l);

        while(NEXT(NODE) != NULL){
            NODE = NEXT(NODE);
        }

        Address NEWNODE = newNode(val);

        if (NEWNODE != NULL){
            NEXT(NODE) = NEWNODE;
        }
    }
}

/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void insertAt(List *l, ElType val, int idx){

    if(idx == 0){
        insertFirst(l, val);
    } else {

        Address NEWNODE = newNode(val);

        if (NEWNODE != NULL){
            Address NODE = FIRST(*l);

            int i;
            for(i = 0; i < idx-1; i++){
                NODE = NEXT(NODE);
            }
            NEXT(NEWNODE) = NEXT(NODE);
            NEXT(NODE) = NEWNODE;
        }
    }
}


/*** PENGHAPUSAN ELEMEN ***/

/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteFirst(List *l, ElType *val){

    Address NODE = FIRST(*l);
    *val = INFO(NODE);

    FIRST(*l) = NEXT(NODE);
    free(NODE);
}

/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
void deleteLast(List *l, ElType *val){

    Address NODE = NULL;
    Address LAST = FIRST(*l);

    while(NEXT(LAST) != NULL){
        NODE = LAST;
        LAST = NEXT(LAST);
    }

    if(NODE == NULL){
        FIRST(*l) = NULL;
    } else {
        NEXT(NODE) = NULL;
    }
    
    *val = INFO(LAST);
    free(LAST);
}

/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
void deleteAt(List *l, int idx, ElType *val){

    if (idx == 0){
        deleteFirst(l, val);
        
    } else {
        Address NODE = FIRST(*l);

        int i;
        
        for(i = 0; i < idx-1; i++){
            NODE = NEXT(NODE);
        }

        Address DELETE = NEXT(NODE);

        *val = INFO(DELETE);

        NEXT(NODE) = NEXT(DELETE);
        free(DELETE);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/

/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void displayList(List l){

    printf("[");

    if (!isEmpty(l)){
        Address NODE = FIRST(l);

        while(NEXT(NODE) != NULL){
            printf("%d,", INFO(NODE));
            NODE = NEXT(NODE);
        }
        printf("%d", INFO(NODE));
    }

    printf("]");
}
    
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int length(List l){

    if (isEmpty(l)){
        return 0;
    }

    int len = 1;
    Address NODE = FIRST(l);

    while(NEXT(NODE) != NULL){
        NODE = NEXT(NODE);
        len++;
    }

    return len;
}


/****************** PROSES TERHADAP LIST ******************/

/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
List concat(List l1, List l2){

    List l3;
    CreateList(&l3);

    Address NODE = FIRST(l1);

    while (NODE != NULL){
        insertLast(&l3, INFO(NODE));
        NODE = NEXT(NODE);
    }

    NODE = FIRST(l2);
    
    while (NODE != NULL){
        insertLast(&l3, INFO(NODE));
        NODE = NEXT(NODE);
    }

    FIRST(l1) = NULL;
    FIRST(l2) = NULL;

    return l3;
}
