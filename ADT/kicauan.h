#ifndef kicauan_H
#define kicauan_H

#include "sentenceMachine.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "datetime.h"

typedef struct {  
  int id;
  Sentence pesan[280];
  int jumlahDisukai;
  Sentence author;
  Time dateTime;
  Balasan TabBalasan[];
  Utas TabUTas[];
} Kicauan;

#define Id(P) (P).id;
#define Pesan(P) (P).pesan;
#define Likes(P) (P).jumlahDisukai;
#define Author(P) (P).Author;
#define Time(P) (P).dateTime;

#endif