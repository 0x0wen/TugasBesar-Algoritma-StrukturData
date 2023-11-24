#ifndef utas_H
#define utas_H

#include "../General/sentenceMachine.h"
#include "../General/datetime.h"
typedef struct
{
  int IDUtas;
  Sentence author;
  Sentence pesan;
  int IDPengguna;
  DATETIME waktu;
} KicauanSambungan;

#define PESAN_KICAUAN_SAMBUNGAN(k) (k).pesan
#define AUTHOR_KICAUAN_SAMBUNGAN(k) (k).author
#define KONTEN_KICAUAN_SAMBUNGAN(k) (k).pesan
// #define SUKA_KICAUAN_SAMBUNGAN(k) (k).jumlahSuka
#define WAKTU_KICAUAN_SAMBUNGAN(k) (k).waktu
/* Definisi elemen dan koleksi objek */

/* Definisi Node : */
typedef struct node *Address;
typedef struct node
{
  KicauanSambungan info;
  Address next;
} NodeKicauanSambungan;
/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

#define INFO_UTAS(p) (p)->info
#define NEXT_UTAS(p) (p)->next

Address newKicauanSambungan(KicauanSambungan val);
typedef Address TabKicauanSambungan;

#define IDX_UNDEF_UTAS (-1)
#define FIRST_UTAS(l) (l)

typedef struct
{
  Sentence author;
  int IDUtas;
  int IDKicau;
  TabKicauanSambungan dataKicauanSambungan;
} Utas;

#define ID_UTAS(p) (p).IDUtas
#define AUTHOR_UTAS(p) (p).author
#define ID_KICAU_UTAS(p) (p).IDKicau
#define KICAUAN_SAMBUNGAN(p) (p).dataKicauanSambungan

void createTabKicauanSambungan(TabKicauanSambungan *T);

boolean isTabKicauanSambunganEmpty(TabKicauanSambungan T);

/*** Penambahan ***/
void insertFirstTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val);
void insertLastTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val);
void insertAtTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val, int idx);

/*** Penghapusan ***/
void deleteFirstTabKicauanSambungan(TabKicauanSambungan *T);
void deleteLastTabKicauanSambungan(TabKicauanSambungan *T);
void deleteAtTabKicauanSambungan(TabKicauanSambungan *T, int idx);

void displayTabKicauanSambungan(TabKicauanSambungan T);
int lengthTabKicauanSambungan(TabKicauanSambungan T);

#endif