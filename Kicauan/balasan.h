#ifndef BALASAN_H
#define BALASAN_H

#include "sentenceMachine.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "sentenceMachine.h"
#include "datetime.h"
#include "pengguna.h"
#include "kicauan.h"

typedef struct
{
    int idBalasan;
    Sentence teks;
    int IDPengguna;
    DATETIME waktu;
    address root;
} Balasan;

#define Id(P) (P).id;
#define Teks(P) (P).teks;
#define Writer(P) (P).penulis;
#define Time(P) (P).dateTime;
#define DaftarBalasan(P) (P).daftarBalasan;

void Balas(int IDKicau, int IDBalasan);

void Show_Balasan(int IDKicau);

void Hapus_Balasan(int IDKicau, int IDBalasan);

#endif