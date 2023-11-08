#ifndef utas_H
#define utas_H

#include "kicauan.h"
#include "listDinamis.h"
#include "sentenceMachine.h"

typedef struct
{
  Sentence pesan[280];
  Sentence author;
  int jumlahSuka;
  TIME dateTime;
} KicauanSambungan;

/* Definisi elemen dan koleksi objek */
typedef KicauanSambungan ElType; /* type elemen list */
typedef int IdxType;

/* Definisi Node : */
typedef struct node *Address;
typedef struct node
{
  ElType info;
  Address next;
} Node;
/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElType val);
typedef Address TabKicauanSambungan;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

typedef struct
{
  int id;
  int IDKicau;
  TabKicauanSambungan dataKicauanSambungan;
} Utas;

void createTabKicauanSambungan(TabKicauanSambungan *T);

boolean isTabKicauanSambunganEmpty(TabKicauanSambungan T);

int indexOfTabKicauanSambungan(TabKicauanSambungan T, ElType val);

/*** Penambahan ***/
void insertFirstTabKicauanSambungan(TabKicauanSambungan *T, ElType val);
void insertLastTabKicauanSambungan(TabKicauanSambungan *T, ElType val);
void insertAtTabKicauanSambungan(TabKicauanSambungan *T, ElType val, int idx);

/*** Penghapusan ***/
void deleteFirstTabKicauanSambungan(TabKicauanSambungan *T, ElType *val);
void deleteLastTabKicauanSambungan(TabKicauanSambungan *T, ElType *val);
void deleteAtTabKicauanSambungan(TabKicauanSambungan *T, int idx, ElType *val);

void displayTabKicauanSambungan(TabKicauanSambungan T);
int lengthTabKicauanSambungan(TabKicauanSambungan T);

void Create_Utas(int IDKicau);
void Sambung_Utas(int IDUtas, int index);
void Hapus_Utas(int IDUtas, int index);
void Cetak_Utas(int IDUtas);

#endif