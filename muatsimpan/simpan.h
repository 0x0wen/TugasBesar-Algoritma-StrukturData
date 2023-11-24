// save_load.h

#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "../global.h"

Word writefilename(Word input1, Word input2);
void createFile(char *fullPath, char *filename);
void simpanPengguna(TabPengguna datapengguna, Word inputfile, AdjacencyMatrix mteman);
void simpanKicauan(Word inputfile,TabKicauan tabkicau);
void simpanBalasan(int jumlahKicauan, Word inputfile);
void simpanDraf(Word inputfile,TabPengguna datapengguna);
void simpanUtas(Word inputfile,TabUtas datautas);
void simpan(TabPengguna tabuser,AdjacencyMatrix matriksteman, TabKicauan tabkicau, TabUtas tabutas);

#endif