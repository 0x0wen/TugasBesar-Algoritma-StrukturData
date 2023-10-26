#ifndef utas_H
#define utas_H

#include "kicauan.h"

typedef Kicauan KicauanUtama; 
/* KicauanUtama memiliki sifat yang sama seperti kicauan biasa*/

typedef struct {   
  Sentence pesan[280];
  Sentence author;
  int jumlahDisukai;
  Time dateTime;
} KicauanSambungan;
/* KicauanSambungan tidak memiliki id dan tidak bisa dibalas*/

typedef struct {
    int IDUtas;
    KicauanUtama Utama;
    KicauanSambungan Sambungan[100];
    int NSambungan;
} Utas;
/* Setiap utas memiliki id berurut yang dimulai dari 1,
   Setiap utas terdiri dari kicauan utama dan array of kicauan sambungan
   NSambungan adalah banyaknya utas sambungan*/

typedef struct {
    Utas Buffer[100];
    int Neff;
} TabUtas;
/* Tab untuk menyimpan utas, memiiki Neff*/

#endif