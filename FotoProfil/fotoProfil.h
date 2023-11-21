#ifndef FOTO_PROFIL
#define FOTO_PROFIL

#include "../General/boolean.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

/**
Filename: pcolor.h
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

/**
Details

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

typedef int IdxType; /* Index baris, kolom */
typedef int ElType;
typedef struct
{
    ElType mem[ROW_CAP][COL_CAP];
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

/* *** Selektor "Dunia FotoProfil" *** */
boolean isFotoProfilIdxValid(int i, int j);
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(FotoProfil m);
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(FotoProfil m);
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(FotoProfil m, IdxType i, IdxType j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(FotoProfil m, IdxType i);
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  FotoProfil ********** */
void copyFotoProfil(FotoProfil mIn, FotoProfil *mOut);
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readFotoProfil(FotoProfil *m, int nRow, int nCol);
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateFotoProfil(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void displayFotoProfil(FotoProfil m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
FotoProfil addFotoProfil(FotoProfil m1, FotoProfil m2);
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
FotoProfil subtractFotoProfil(FotoProfil m1, FotoProfil m2);
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
FotoProfil multiplyFotoProfil(FotoProfil m1, FotoProfil m2);
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
FotoProfil multiplyFotoProfilWithMod(FotoProfil m1, FotoProfil m2, int mod);
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen FotoProfil hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
FotoProfil multiplyByConst(FotoProfil m, ElType x);
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(FotoProfil *m, ElType k);
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP FotoProfil ********** */
boolean isFotoProfilEqual(FotoProfil m1, FotoProfil m2);
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isFotoProfilNotEqual(FotoProfil m1, FotoProfil m2);
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isFotoProfilSizeEqual(FotoProfil m1, FotoProfil m2);
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(FotoProfil m);
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP FotoProfil ********** */
boolean isSquare(FotoProfil m);
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(FotoProfil m);
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(FotoProfil m);
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(FotoProfil m);
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
FotoProfil negation(FotoProfil m);
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(FotoProfil *m);
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinant(FotoProfil m);
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
FotoProfil transpose(FotoProfil m);
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(FotoProfil *m);
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

#endif