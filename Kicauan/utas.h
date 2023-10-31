#ifndef utas_H
#define utas_H

#include "kicauan.h"
#include "listDinamis.h"
#include "sentenceMachine.h"
typedef struct
{
  int id;
  int IDKicau;
  ListDinKicauanSambungan kicauanSambungan;
} Utas;

typedef struct
{
  Sentence pesan[280];
  Sentence author;
  int jumlahDisukai;
  TIME dateTime;
} KicauanSambungan;
/* KicauanSambungan tidak memiliki id dan tidak bisa dibalas*/

typedef struct
{
  Kicauan Buffer[100];
  int Neff;
} TabUtas;
/* Tab untuk menyimpan utas, memiiki Neff*/
/* TabUtas berisi kicauan yang merupakan utas*/

void Create_Utas(int IDKicau);
void Sambung_Utas(int IDUtas, int index);
void Hapus_Utas(int IDUtas, int index);
void Cetak_Utas(int IDUtas);
#endif