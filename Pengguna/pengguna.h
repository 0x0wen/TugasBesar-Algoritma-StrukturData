/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef pengguna_H
#define pengguna_H

#include "boolean.h"
#include "global.h"
#include "matrix.h"

#include "sentenceMachine.h"
#include "kicauan.h"

#include "balasan.h"
#include "tabBalasan.h"

#include "utas.h"
#include "tabUtas.h"

#include "listDinamis.h"
#include "prioqueue.h"

#include "../DrafKicauan/draf.h"

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
    Matrix foto;
    TabKicauan kicauan;
    TabBalasan balasan;
    TabUtas utas;
    TabTeman teman;
    PrioQueueChar permintaan_teman;
    Draf drafkicauan;
} Pengguna;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define IdPengguna(P) (P).id
#define NamaPengguna(P) (P).nama
#define KataSandiPengguna(P) (P).KataSandi
#define BioPengguna(P) (P).Bio
#define WetonPengguna(P) (P).Weton
#define NoHPPengguna(P) (P).NoHP
#define JenisAkunPengguna(P) (P).JenisAkun
#define FotoPengguna(P) (P).Foto
#define KicauanPengguna(P, i) (P).kicauan[i]
#define BalasanPengguna(P, i) (P).balasan[i]
#define UtasPengguna(P, i) (P).utas[i]


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */

#endif