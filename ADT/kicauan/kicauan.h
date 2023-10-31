#ifndef kicauan_H
#define kicauan_H

#include "../sentenceMachine.h"
#include "../datetime.h"

typedef struct {  
  /*** Kicauan ***/
  int IDKicau;
  char Text[281]; // 280 char + 1 mark
  int Like;
  Sentence Author;
  DATETIME DateTime;
  // Balasan TabBalasan[];
  
  /*** Utas ***/
  // int IDUtas; 
  // KicauanSambungan Sambungan[100]; 
  // int NSambungan; 
  /* IDUtas = 0 jika kicauan bukan utas, IDUtas akan auto-increment dimulai dari 1*/
  /* Sambungan tidak bisa diakses jika IDUtas = 0*/
  /* NSambungan = 0 jika kicauan bukan utas*/
} Kicauan;

/*** Selektor ***/
#define ID(P) (P).IDKicau;
#define TEXT(P) (P).Text;
#define LIKE(P) (P).Like;
#define AUTHOR(P) (P).Author;
#define TIME(P) (P).DateTime;



#endif