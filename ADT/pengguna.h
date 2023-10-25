/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef pengguna_H
#define pengguna_H

#include "boolean.h"
#include "sentenceMachine.h"

#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef int infotype;
typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
    int id;
    Sentence nama;
    Sentence kataSandi;
    Sentence bio;
    Word weton;
    int noHP;
    boolean jenisAkun;
    Matriks foto;
    Kicauan TabKicauan[];
    Balasan TabBalasan[];
    Utas TabUtas[];
} Pengguna;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Id(P) (P).id;
#define Nama(P) (P).nama;
#define KataSandi(P) (P).KataSandi;
#define Bio(P) (P).Bio;
#define Weton(P) (P).Weton;
#define NoHP(P) (P).NoHP;
#define JenisAkun(P) (P).JenisAkun;
#define Foto(P) (P).Foto;
#define Kicauan(P, i) (P).TabKicauan[i];
#define Balasan(P, i) (P).TabBalasan[i];
#define Utas(P, i) (P).TabUtas[i];

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */

#endif