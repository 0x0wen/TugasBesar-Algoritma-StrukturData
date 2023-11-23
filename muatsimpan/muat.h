#ifndef MUAT_H
#define MUAT_H

#include "../General/wordmachine.h"
#include "../Pengguna/pengguna.h"

Word writefilename(Word input1, Word input2);
int compareCharArrays(const char *array1, const char *array2);
DATETIME muatDateTime();
int muatPengguna(Word inputFile);
// int muatKicauan(Word inputFile);
// void muatBalasan(Word inputFile, int jumlahKicauan);
// void muatDraf(Word inputFile, int jumlahUser);
// void muatUtas(Word inputFile, int jumlahKicauan);
void muat();

#endif