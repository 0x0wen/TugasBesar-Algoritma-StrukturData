#ifndef TAB_PENGGUNA_H
#define TAB_PENGGUNA_H

/*  Kamus Umum */
#define CAPACITYPENGGUNA 20
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF_TAB_PENGGUNA -1
/* Indeks tak terdefinisi*/
#define MARK_PENGGUNA NULL
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct
{
   Pengguna contents[CAPACITYPENGGUNA]; /* memori tempat penyimpan elemen (container) */
   int length;
} TabPengguna;

/* Indeks yang digunakan [0..CapacityPengguna-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define SELECT_PENGGUNA(l, i) (l).contents[(i)]
#define BANYAK_PENGGUNA(l) (l).length

void createTabPengguna(TabPengguna *T);
boolean isIdxEffTabPengguna(int i);
boolean isTabPenggunaEmpty();
boolean isTabPenggunaFull();
void printTabPengguna();
int indexOfTabPengguna(Pengguna val);
void insertFirstTabPengguna(Pengguna val);
void insertAtTabPengguna(Pengguna val, int idx);
void insertLastTabPengguna(Pengguna val);
void deleteFirstTabPengguna(Pengguna *val);
void deleteAtTabPengguna(Pengguna *val, int idx);
void deleteLastTabPengguna(Pengguna *val);
boolean checkUsernameExist(TabPengguna T, Sentence username, int numUsers);
boolean checkPassword(TabPengguna T, Sentence password, int numUsers);

#endif