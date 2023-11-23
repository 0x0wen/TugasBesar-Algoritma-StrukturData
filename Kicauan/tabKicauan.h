#ifndef TAB_KICAUAN_H
#define TAB_KICAUAN_H

#include "kicauan.h"

#define IDX_MIN_TAB_KICAUAN 0
/* Indeks minimum list */
#define IDX_UNDEF_TAB_KICAUAN -1
/* Indeks tak terdefinisi*/
/*** Struct TabKicauan berupa List Dinamis ***/
typedef struct
{
  Kicauan *buffer;
  int nEff;
  int capacity;
  int maxID;
} TabKicauan;

/*** Selektor Struct TabKicauan ***/
#define NEFF_TAB_KICAUAN(T) (T).nEff
#define SELECT_TAB_KICAUAN(T) (T).buffer
#define SELECT_KICAUAN(T, i) (T).buffer[i]
#define CAPACITY_TAB_KICAUAN(T) (T).capacity
#define MAXID_TAB_KICAUAN(T) (T).maxID

/*** Kreator/Deletor Tab Kicauan ***/
void createTabKicauan(TabKicauan *t, int capacity);
void deleteTabKicauan(TabKicauan *t);

/*** Copy List ***/
void copyListKicauan(TabKicauan lIn, TabKicauan *lOut);

/*** Cek Kicauan di Tab***/
boolean isKicauanInTab(TabKicauan *t, int id);
int getKicauanIdx(TabKicauan t, int id);

/*** Add/Delete Kicauan from Tab ***/
void addKicauanToTab(TabKicauan *t, Kicauan k);
void deleteKicauanFromTab(TabKicauan *t, int id);

/*** Mengubah Ukuran Tab ***/
void expandListKicauan(TabKicauan *t, int num);
// void shrinkListKicauan(TabKicauan *t, int num);
// void compressListKicauan(TabKicauan *t);

/*** Prosedur Kicauan ***/
// Kicauan createKicauan();
// void printKicauan(Kicauan k);

/*** Prosedur Kicauan yang berkaitan dengan spek ***/
Kicauan *searchKicauan(TabKicauan t, int id);

#endif