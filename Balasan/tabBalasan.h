#ifndef TAB_BALASAN_H
#define TAB_BALASAN_H

#include "balasan.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF_TAB_BALASAN -1
/* Indeks tak terdefinisi*/

typedef int IdxType; /* type indeks */

typedef struct
{
  Balasan *buffer; /* memori tempat penyimpan elemen (container) */
  int nEff;        /* >=0, banyaknya elemen efektif */
  int capacity;    /* ukuran elemen */
} TabBalasan;
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
#define NEFF_TAB_BALASAN(l) (l).nEff
#define BUFFER_TAB_BALASAN(l) (l).buffer
#define SELECT_BALASAN(l, i) (l).buffer[i]
#define CAPACITY_TAB_BALASAN(l) (l).capacity

/* ********** KONSTRUKTOR & DESTRUKTOR ********** */
void createTabBalasan(int capacity);

void deallocateTabBalasan();
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

int lengthTabBalasan();
/* Mengirimkan banyaknya elemen efektif list */

/* ********** Test Indeks yang valid ********** */
boolean isIdxTabBalasanValid(int i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxTabBalasanEff(int i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

boolean isTabBalasanEmpty();

boolean isTabBalasanFull();

int indexOfTabBalasan(Balasan val);

void insertLastTabBalasan(Balasan val);
void deleteLastTabBalasan(Balasan *val);

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandTabBalasan(int num);

#endif