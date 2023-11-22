/* Modul ADT Kicauan dengan ADT TabKicauan yang berupa list dinamis */

#ifndef kicauan_H
#define kicauan_H

#include "../General/wordmachine.h"
#include "../General/charmachine.h"
#include "../General/sentenceMachine.h"
#include "../General/datetime.h"
#include "../General/time_adt.h"
#include "../General/boolean.h"
#include "../Pengguna/pengguna.h"
#include "../Balasan/balasan.h"

/*** Struct Kicauan ***/
typedef struct
{
  int IDKicau;
  Sentence Text; // 280 char + 1 mark
  int Like;
  Sentence Author;
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


#endif