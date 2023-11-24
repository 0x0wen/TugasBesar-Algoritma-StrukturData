/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDIN_H
#define LISTDIN_H

#include "boolean.h"

/*  Kamus Umum */
#define IDX_MIN_LIST_DIN 0
/* Indeks minimum list */
#define IDX_UNDEF_LIST_DIN -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct
{
    int *buffer;  /* memori tempat penyimpan elemen (container) */
    int nEff;     /* >=0, banyaknya elemen efektif */
    int capacity; /* ukuran elemen */
} ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF_LIST_DIN(l) (l).nEff
#define BUFFER_LIST_DIN(l) (l).buffer
#define ELMT_LIST_DIN(l, i) (l).buffer[i]
#define CAPACITY_LIST_DIN(l) (l).capacity

void CreateListDin(ListDin *l, int capacity);
void dealocateListDin(ListDin *l);
int listLengthListDin(ListDin l);
int getFirstIdxListDin(ListDin l);
int getLastIdxListDin(ListDin l);
boolean isIdxValidListDin(ListDin l, int i);
boolean isEmptyListDin(ListDin l);
boolean isFullListDin(ListDin l);
void readListDin(ListDin *l);
void printListDin(ListDin l);
ListDin plusMinusListDin(ListDin l1, ListDin l2, boolean plus);
boolean isListEqualListDin(ListDin l1, ListDin l2);
int indexOfListDin(ListDin l, int val);
void extremeValuesListDin(ListDin l, int *max, int *min);
void copyListDin(ListDin lIn, ListDin *lOut);
int sumListDin(ListDin l);
int countValListDin(ListDin l, int val);
void sortListDin(ListDin *l, boolean asc);
void insertLastListDin(ListDin *l, int val);
void deleteLastListDin(ListDin *l, int *val);
void deleteValListDin(ListDin *l, int val);
void expandListDin(ListDin *l, int num);
void shrinkListDin(ListDin *l, int num);
void compressListDin(ListDin *l);

#endif