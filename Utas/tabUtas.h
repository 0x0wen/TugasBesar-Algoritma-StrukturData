#ifndef TAB_UTAS_H
#define TAB_UTAS_H

#include "utas.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

typedef struct
{
  Utas *buffer; /* memori tempat penyimpan elemen (container) */
  int nEff;       /* >=0, banyaknya elemen efektif */
  int capacity;   /* ukuran elemen */
} TabUtas;
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

/* Tab untuk menyimpan utas, memiiki Neff*/
/* TabUtas berisi kicauan yang merupakan utas*/

/* ********** SELEKTOR ********** */
#define NEFF_UTAS(l) (l).nEff
#define BUFFER_UTAS(l) (l).buffer
#define SELECT_UTAS(l, i) (l).buffer[i]
#define CAPACITY_UTAS(l) (l).capacity

/* ********** KONSTRUKTOR & DESTRUKTOR ********** */
void createTabUtas(int capacity);

void deallocateTabUtas();
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

int lengthTabUtas();
/* Mengirimkan banyaknya elemen efektif list */

/* ********** Test Indeks yang valid ********** */
boolean isIdxTabUtasValid(IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxTabUtasEff(IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

boolean isTabUtasEmpty();

boolean isTabUtasFull();

Utas cariUtas(int IDUtas);
IdxType indexOfTabUtas(Utas val);

void insertLastTabUtas(Utas val);
void deleteLastTabUtas(Utas *val);

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandTabUtas(int num);

#endif