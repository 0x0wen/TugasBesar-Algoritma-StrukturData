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
  Kicauan *buffer_TabKicauan;
  int nEff_TabKicauan;
  int capacity_TabKicauan;
  int maxID_TabKicauan;
} TabKicauan;

/*** Selektor Struct TabKicauan ***/
#define NEFF_TabKicauan(T) (T).nEff_TabKicauan
#define TAB_TabKicauan(T) (T).buffer_TabKicauan
#define ELMT_TabKicauan(T, i) (T).buffer_TabKicauan[i]
#define CAPACITY_TabKicauan(T) (T).capacity_TabKicauan
#define MAXID_TabKicauan(T) (T).maxID_TabKicauan

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
void KICAU();
void KICAUAN();
void SUKA_KICAUAN(int id);
void UBAH_KICAUAN(int id);
#endif