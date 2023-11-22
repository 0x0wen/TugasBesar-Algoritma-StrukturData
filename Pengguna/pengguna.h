#ifndef PENGGUNA_H
#define PENGGUNA_H

/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "../General/boolean.h"
#include "../General/sentenceMachine.h"
#include "../Balasan/tabBalasan.h"
#include "../Utas/tabUtas.h"
#include "../DrafKicauan/draf.h"
#include "../PermintaanTeman/permintaanTeman.h"
#include "../FotoProfil/fotoProfil.h"

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
    boolean privat;
    FotoProfil foto;
    TabKicauan kicauan;
    TabBalasan balasan;
    TabUtas utas;
    PermintaanTeman permintaan_teman;
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
#define KataSandiPengguna(P) (P).kataSandi
#define BioPengguna(P) (P).bio
#define WetonPengguna(P) (P).weton
#define NoHPPengguna(P) (P).noHP
#define PrivasiPengguna(P) (P).privat
#define FotoPengguna(P) (P).foto
#define KicauanPengguna(P, i) (P).kicauan[i]
#define BalasanPengguna(P, i) (P).balasan[i]
#define UtasPengguna(P, i) (P).utas[i]


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */

void DAFTAR();
void MASUK();
void KELUAR();
void TUTUP_PROGRAM();
boolean checkUsernameExist(TabPengguna *tabPengguna, Word username, int numUsers);
boolean checkPassword(TabPengguna *tabPengguna, Word password, int numUsers);
void signingUser(Word username, Word password, TabPengguna *dataPengguna);
Pengguna CURRENT_PENGGUNA(Word penggunaBaru);

#endif