#ifndef TAB_KICAUAN_H
#define TAB_KICAUAN_H

#include "kicauan.h"

/*** Struct TabKicauan berupa List Dinamis ***/
typedef struct
{
  Kicauan *buffer;
  int nEff;
  int capacity;
  int maxID;
} TabKicauan;

/*** Selektor Struct TabKicauan ***/
#define NEFF(T) (T).nEff
#define TAB(T) (T).buffer
#define ELMT(T, i) (T).buffer[i]
#define CAPACITY(T) (T).capacity
#define MAXID(T) (T).maxID

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
void deleteKicauanFromTab(TabKicauan *t, Kicauan *k, int id);

/*** Mengubah Ukuran Tab ***/
void expandListKicauan(TabKicauan *t, int num);
void shrinkListKicauan(TabKicauan *t, int num);
void compressListKicauan(TabKicauan *t);

/*** Prosedur Kicauan ***/
Kicauan createKicauan();
void printKicauan(Kicauan k);

/*** Prosedur Kicauan yang berkaitan dengan spek ***/


#endif