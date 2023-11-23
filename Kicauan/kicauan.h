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
  Balasan TabBalasan; /* Pointer ke Tree Balasan */
} Kicauan;            /* tiap elemen pada list tsb merupakan root dari tree balasan */

/*** Selektor Struct Kicauan***/
#define ID_KICAUAN(K) (K).IDKicau
#define TEXT_KICAUAN(K) (K).Text
#define LIKE_KICAUAN(K) (K).Like
#define AUTHOR_KICAUAN(K) (K).Author
#define TIME_KICAUAN(K) (K).DateTime
#define TREE_BALASAN(K) (K).TabBalasan // nge retrieve tree of balasan

#endif