#ifndef utas_H
#define utas_H

#include "kicauan.h"
#include "listDinamis.h"
#include "sentenceMachine.h"

typedef struct
{
  int Index;
  Sentence pesan[280];
  int IDPengguna;
  DATETIME waktu;
} KicauanSambungan;

#define PESAN(k) (k).IDUtas
#define ID_PENGGUNA(k) (k).IDPengguna
#define SUKA(k) (k).jumlahSuka
#define WAKTU(k) (k).waktu
/* Definisi elemen dan koleksi objek */

/* Definisi Node : */
typedef struct node *Address;
typedef struct node
{
  KicauanSambungan info;
  Address next;
} Node;
/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newKicauanSambungan(KicauanSambungan val);
typedef Address TabKicauanSambungan;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

typedef struct
{
  Sentence author;
  int IDUtas;
  int IDKicau;
  TabKicauanSambungan dataKicauanSambungan;
} Utas;

#define ID_UTAS(p) (p).IDUtas
#define ID_KICAU_UTAS(p) (p).IDKicau
#define KICAUAN_SAMBUNGAN(p) (p).dataKicauanSambungan

void createTabKicauanSambungan(TabKicauanSambungan *T);

boolean isTabKicauanSambunganEmpty(TabKicauanSambungan T);

int indexOfTabKicauanSambungan(TabKicauanSambungan T, KicauanSambungan val);

/*** Penambahan ***/
void insertFirstTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val);
void insertLastTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val);
void insertAtTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val, int idx);

/*** Penghapusan ***/
void deleteFirstTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan *val);
void deleteLastTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan *val);
void deleteAtTabKicauanSambungan(TabKicauanSambungan *T, int idx, KicauanSambungan *val);

void displayTabKicauanSambungan(TabKicauanSambungan T);
int lengthTabKicauanSambungan(TabKicauanSambungan T);

#endif