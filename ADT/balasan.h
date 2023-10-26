#ifndef BALASAN_H
#define BALASAN_H

#include "sentenceMachine.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "datetime.h"

typedef struct
{
    int id;
    Sentence teks[280];
    Sentence penulis;
    DATETIME dateTime;
    Sentence daftarBalasan[];
} BALASAN;

#define Id(P) (P).id;
#define Teks(P) (P).teks;
#define Writer(P) (P).penulis;
#define Time(P) (P).dateTime;
#define DaftarBalasan(P) (P).daftarBalasan;

#endif