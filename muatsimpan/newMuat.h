#ifndef NEWMUAT_H
#define NEWMUAT_H

#include "../global.h"

DATETIME muatDateTime();
void muatPenggunaNew(Word inputFile,TabPengguna* dataPengguna,AdjacencyMatrix *mteman);
void muatKicauanNew(Word inputFile,TabKicauan *tabkicau);
void muatBalasanNew(Word inputFile,TabPengguna tabuser);
void muatDrafNew(Word inputFile,TabPengguna tabuser);
void muatUtasNew(Word inputFile, TabUtas *dataUtas);

void muat(TabPengguna* datauser, AdjacencyMatrix* matrikstemen, TabKicauan* tabkicauan, TabUtas* datautas);
#endif