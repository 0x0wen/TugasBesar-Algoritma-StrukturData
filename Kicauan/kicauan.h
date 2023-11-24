/* Modul ADT Kicauan dengan ADT TabKicauan yang berupa list dinamis */

#ifndef kicauan_H
#define kicauan_H

#include "../General/wordmachine.h"
#include "../General/charmachine.h"
#include "../General/sentenceMachine.h"
#include "../General/datetime.h"
#include "../General/time_adt.h"
#include "../General/boolean.h"
#include "../Balasan/balasan.h"
#include "../Utas/utas.h"

/*** Struct Kicauan ***/
typedef struct
{
  int IDKicau;
  Sentence Text;
  int Like;
  Sentence Author;
  DATETIME DateTime;
  TreeBalasan TabBalasan; /* Pointer ke Tree Balasan */
  int JumlahBalasan;
  Utas *UtasPointer;
} Kicauan; /* tiap elemen pada list tsb merupakan root dari tree balasan */

/*** Selektor Struct Kicauan***/
#define ID_KICAU(K) (K).IDKicau
#define TEXT_KICAU(K) (K).Text
#define LIKE_KICAU(K) (K).Like
#define AUTHOR_KICAU(K) (K).Author
#define TIME_KICAU(K) (K).DateTime
#define LIST_BALASAN(K) (K).TabBalasan // nge retrieve list dinamis of balasan
#define UTAS_KICAU(K) (K).UtasPointer  // nge retrieve list dinamis of balasan
#define JUMLAH_BALASAN(K) (K).JumlahBalasan

Kicauan createKicauan(int id, Sentence text, Sentence author);
void printDetilKicau(Kicauan k);

#endif