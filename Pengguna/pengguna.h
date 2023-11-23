#ifndef PENGGUNA_H
#define PENGGUNA_H


#include "../General/boolean.h"
#include "../General/sentenceMachine.h"
#include "../DrafKicauan/draf.h"
#include "../PermintaanTeman/permintaanTeman.h"
#include "../FotoProfil/fotoProfil.h"
#include "../General/listDinamis.h"


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
    Word noHP;
    boolean privat;
    FotoProfil foto;
    ListDin daftarKicauan;
    ListDin daftarBalasan;
    ListDin daftarUtas;
    PrioQueueRequest daftarPermintaanTeman;
    Draf drafKicauan;
} Pengguna;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define ID_PENGGUNA(P) (P).id
#define NAMA_PENGGUNA(P) (P).nama
#define PASSWORD_PENGGUNA(P) (P).kataSandi
#define BIO_PENGGUNA(P) (P).bio
#define WETON_PENGGUNA(P) (P).weton
#define HP_PENGGUNA(P) (P).noHP
#define PRIVASI_PENGGUNA(P) (P).privat
#define FOTO_PENGGUNA(P) (P).foto
#define KICAUAN_PENGGUNA(P, i) (P).daftarKicauan[i]
#define BALASAN_PENGGUNA(P, i) (P).daftarBalasan[i]
#define UTAS_PENGGUNA(P, i) (P).daftarUtas[i]
#define PERMINTAAN_PENGGUNA(P, i) (P).daftarPermintaanTeman[i]
#define DRAF_PENGGUNA(P, i) (P).drafKicauan[i]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */

void DAFTAR();
void MASUK();
void KELUAR();
void TUTUP_PROGRAM();

#endif