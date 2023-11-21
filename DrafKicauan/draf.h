/* File: Draflinked.h */

#ifndef DrafLINKED_H
#define DrafLINKED_H

#include "../General/wordmachine.h"
#include "../General/charmachine.h"
#include "../General/sentenceMachine.h"
#include "../General/datetime.h"
#include "../General/time_adt.h"
#include "../General/boolean.h"
#include "../Kicauan/kicauan.h"
#include "../global.h"
#include "../Pengguna/pengguna.h"
#include <stdlib.h>

#define NIL NULL
/* Draf dengan representasi berkait dengan pointer */
typedef struct node* Address;
typedef struct node { 
    Kicauan info;
    Address next; 
} Node; 

/* Type Draf dengan ciri Top: */
typedef struct { 
    Address addrTop; /* alamat Top: elemen puncak */
} Draf;

/* Selektor */
#define     NEXT(p) (p)->next
#define     INFO(p) (p)->info
#define ADDR_TOP(s) (s).addrTop
#define      TOP(s) (s).addrTop->info 

/* Prototype manajemen memori */
Address newNode(Kicauan x);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   

/* ********* PROTOTYPE REPRESENTASI LOJIK Draf ***************/
boolean isEmpty(Draf s);
/* Mengirim true jika Draf kosong: TOP(s) = NIL */

int length(Draf s);
/* Mengirimkan banyaknya elemen Draf. Mengirimkan 0 jika Draf s kosong */

void CreateDraf(Draf *s);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah Draf s yang kosong */

void DisplayDraf(Draf s);
/* Proses : Menuliskan isi Draf, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1 (TOP), 20, 30 akan dicetak: [1,20,30] */
/* Jika Draf kosong : menulis [] */

void push(Draf *s, Kicauan x);
/* Menambahkan x sebagai elemen Draf s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void pop(Draf *s, Kicauan *x);
/* Menghapus Top dari Draf s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */

void BUAT_DRAF(Draf *s);
void LIHAT_DRAF(Draf *s);

#endif