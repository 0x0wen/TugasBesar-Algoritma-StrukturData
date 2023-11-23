// save_load.h

#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "../General/wordmachine.h"

Word writefilename(Word input1, Word input2);
void createFile(char *fullPath, char *filename);
void simpanPengguna(int jumlahUser, Word inputfile);
void simpanKicauan(int jumlahKicauan, Word inputfile);
void simpanBalasan(int jumlahKicauan, Word inputfile);
void simpanDraf(int jumlahUser, Word inputfile);
void simpanUtas(int jumlahKicauan, Word inputfile);
void simpan();
void muat();

#endif