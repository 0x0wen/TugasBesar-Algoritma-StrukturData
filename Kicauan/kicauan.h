/* Modul ADT Kicauan dengan ADT TabKicauan yang berupa list dinamis */

#ifndef kicauan_H
#define kicauan_H

#include "../General/sentenceMachine.h"
#include "../General/datetime.h"
#include "../General/boolean.h"
#include "balasan.h"

#define IDX_MIN 0

/*** Struct Kicauan ***/
typedef struct {  
  int IDKicau;
  char Text[281]; // 280 char + 1 mark
  int Like;
  Sentence Author;
  DATETIME DateTime;
  Balasan *TabBalasan; /* Pointer ke list dinamis TabBalasan */
 } Kicauan;            /* tiap elemen pada list tsb merupakan root dari tree balasan */ 

/*** Selektor Struct Kicauan***/
#define ID(P) (P).IDKicau;
#define TEXT(P) (P).Text;
#define LIKE(P) (P).Like;
#define AUTHOR(P) (P).Author;
#define TIME(P) (P).DateTime;
#define LIST_BALASAN(P) *((P).TabBalasan); // nge retrieve list dinamis of balasan

/*** Struct TabKicauan berupa List Dinamis ***/
typedef struct {
  Kicauan *buffer;
  int nEff;
  int capacity;
  int maxID;
} TabKicauan;

/*** Selektor Struct TabKicauan ***/
#define NEFF(P) (P).nEff
#define TAB(P) (P).buffer
#define ELMT(P, i) (P).buffer[i]
#define CAPACITY(P) (P).capacity
#define MAXID(P) (P).maxID

/*** Kreator/Deletor Tab Kicauan ***/
void createTabKicauan(TabKicauan *t, int capacity);
void deleteTabKicauan(TabKicauan *t);

/*** Copy List ***/
void copyList(TabKicauan lIn, TabKicauan *lOut);

/*** Add/Delete Kicauan from Tab ***/
void addKicauanToTab(TabKicauan *t, Kicauan k);
void deleteKicauanFromTab(TabKicauan *t, Kicauan *k, int id);

/*** Mengubah Ukuran Tab ***/
void expandList(TabKicauan *t, int num);
void shrinkList(TabKicauan *t, int num);
void compressList(TabKicauan *t);

/*** Prosedur Kicauan ***/
void createKicauan(TabKicauan *t);
void printKicauan(Kicauan k);

#endif