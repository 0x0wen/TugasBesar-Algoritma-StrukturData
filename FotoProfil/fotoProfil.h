#ifndef FOTO_PROFIL
#define FOTO_PROFIL

#include "../General/boolean.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

/**
print_xxx(c) will print c with xxx color. Import this header to use the declared functions.
We only provide 8 colors. Feel free to modify/add colors if you want to.
**/
#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"

void print_red(char c);
void print_green(char c);
void print_blue(char c);

typedef struct
{
    char mem[ROW_CAP][COL_CAP];
    int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
    int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} FotoProfil;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk FotoProfil *** */
void createFotoProfil(int nRows, int nCols, FotoProfil *m);
/* Membentuk sebuah FotoProfil "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

boolean isFotoProfilIdxValid(int i, int j);
int getLastIdxRow(FotoProfil m);
int getLastIdxCol(FotoProfil m);
boolean isIdxEff(FotoProfil m, int i, int j);
char getElmtDiagonal(FotoProfil m, int i);
void copyFotoProfil(FotoProfil mIn, FotoProfil *mOut);
void readFotoProfil(FotoProfil *m, int nRow, int nCol);
void displayFotoProfil(FotoProfil m);
FotoProfil addFotoProfil(FotoProfil m1, FotoProfil m2);
FotoProfil subtractFotoProfil(FotoProfil m1, FotoProfil m2);
FotoProfil multiplyFotoProfil(FotoProfil m1, FotoProfil m2);
FotoProfil multiplyFotoProfilWithMod(FotoProfil m1, FotoProfil m2, int mod);
FotoProfil multiplyByConst(FotoProfil m, char x);
void pMultiplyByConst(FotoProfil *m, char k);
boolean isFotoProfilEqual(FotoProfil m1, FotoProfil m2);
boolean isFotoProfilNotEqual(FotoProfil m1, FotoProfil m2);
boolean isFotoProfilSizeEqual(FotoProfil m1, FotoProfil m2);
int countElmt(FotoProfil m);
boolean isSquare(FotoProfil m);
boolean isSymmetric(FotoProfil m);
boolean isIdentity(FotoProfil m);
boolean isSparse(FotoProfil m);
FotoProfil negation(FotoProfil m);
void pNegation(FotoProfil *m);
float determinant(FotoProfil m);
FotoProfil transpose(FotoProfil m);
void pTranspose(FotoProfil *m);
#endif