/* Modul ADT Kicauan dengan ADT TabKicauan yang berupa list dinamis */

#ifndef kicauan_H
#define kicauan_H

#include "../General/wordmachine.h"
#include "../General/charmachine.h"
#include "../General/sentenceMachine.h"
#include "../General/datetime.h"
#include "../General/time_adt.h"
#include "../General/boolean.h"
#include "../global.h"
#include "../Pengguna/pengguna.h"
#include "balasan.h"

#define IDX_MIN 0

/*** Struct Kicauan ***/
typedef struct
{
  int IDKicau;
  Word Text; // 280 char + 1 mark
  int Like;
  Pengguna Author;
  DATETIME DateTime;
  Balasan *TabBalasan; /* Pointer ke list dinamis TabBalasan */
} Kicauan;             /* tiap elemen pada list tsb merupakan root dari tree balasan */

/*** Selektor Struct Kicauan***/
#define ID(K) (K).IDKicau;
#define TEXT(K) (K).Text;
#define LIKE(K) (K).Like;
#define AUTHOR(K) (K).Author;
#define TIME(K) (K).DateTime;
#define LIST_BALASAN(K) *((K).TabBalasan); // nge retrieve list dinamis of balasan

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
void copyList(TabKicauan lIn, TabKicauan *lOut);

/*** Cek Kicauan di Tab***/
boolean isKicauanInTab(TabKicauan *t, int id);
int getKicauanIdx(TabKicauan t, int id);

/*** Add/Delete Kicauan from Tab ***/
void addKicauanToTab(TabKicauan *t, Kicauan k);
void deleteKicauanFromTab(TabKicauan *t, Kicauan *k, int id);

/*** Mengubah Ukuran Tab ***/
void expandList(TabKicauan *t, int num);
void shrinkList(TabKicauan *t, int num);
void compressList(TabKicauan *t);

/*** Prosedur Kicauan ***/
Kicauan createKicauan();
void printKicauan(Kicauan k);

/*** Prosedur Kicauan yang berkaitan dengan spek ***/
void KICAU();
void KICAUAN();
void SUKA_KICAUAN(int id);
void UBAH_KICAUAN(int id);
#endif