#ifndef kicauan_H
#define kicauan_H

#include "sentenceMachine.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "time.h"
#include "utas.h"

typedef struct {  
  int id;
  Sentence pesan[280];
  int jumlahDisukai;
  Sentence author;
  TIME dateTime;
  Balasan TabBalasan[];

  /*** Utas ***/
  int IDUtas; 
  KicauanSambungan Sambungan[100]; 
  int NSambungan; 
  /* IDUtas = 0 jika kicauan bukan utas, IDUtas akan auto-increment dimulai dari 1*/
  /* Sambungan tidak bisa diakses jika IDUtas = 0*/
  /* NSambungan = 0 jika kicauan bukan utas*/

} Kicauan;

#define Id(P) (P).id;
#define Pesan(P) (P).pesan;
#define Likes(P) (P).jumlahDisukai;
#define Author(P) (P).Author;
#define Time(P) (P).dateTime;

#endif