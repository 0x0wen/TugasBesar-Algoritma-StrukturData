#ifndef utas_H
#define utas_H

#include "kicauan.h"

typedef struct {   
  Sentence pesan[280];
  Sentence author;
  int jumlahDisukai;
  TIME dateTime;
} KicauanSambungan;
/* KicauanSambungan tidak memiliki id dan tidak bisa dibalas*/

typedef struct {
    Kicauan Buffer[100];
    int Neff;
} TabUtas;
/* Tab untuk menyimpan utas, memiiki Neff*/
/* TabUtas berisi kicauan yang merupakan utas*/

#endif