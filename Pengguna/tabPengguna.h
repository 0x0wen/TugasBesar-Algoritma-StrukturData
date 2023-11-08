#ifndef TAB_PENGGUNA_H
#define TAB_PENGGUNA_H

#include "boolean.h"
#include "pengguna.h"

/*  Kamus Umum */
#define CAPACITY 20
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define MARK NULL
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Pengguna ElType; /* type elemen List */
typedef int IdxType;
typedef struct
{
   ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} TabPengguna;

/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define SelectPengguna(l, i) (l).contents[(i)]

void createTabPengguna(TabPengguna *T);

int lengthTabPengguna();

IdxType getFirstIdxTabPengguna();

IdxType getLastIdxTabPengguna();

boolean isIdxValidTabPengguna(IdxType i);

boolean isIdxEffTabPengguna(IdxType i);

boolean isTabPenggunaEmpty();

boolean isTabPenggunaFull();

void printTabPengguna();

int indexOfTabPengguna(ElType val);

void insertFirstTabPengguna(ElType val);

void insertAtTabPengguna(ElType val, IdxType idx);

void insertLastTabPengguna(ElType val);

void deleteFirstTabPengguna(ElType *val);

void deleteAtTabPengguna(ElType *val, IdxType idx);

void deleteLastTabPengguna(ElType *val);

void sortTabPengguna(boolean asc);

#endif