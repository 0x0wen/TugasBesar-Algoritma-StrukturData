#ifndef NEWMUAT_H
#define NEWMUAT_H
#include "../Balasan/balasan.h"
#include "../Balasan/commandBalasan.h"

#include "../DrafKicauan/commandDraf.h"
#include "../DrafKicauan/draf.h"

#include "../FotoProfil/fotoProfil.h"
#include "../Kicauan/tabKicauan.h"

#include "../Pengguna/tabPengguna.h"

#include "../PermintaanTeman/commandPermintaanTeman.h"
#include "../PermintaanTeman/permintaanTeman.h"

#include "../Teman/commandTeman.h"
#include "../Teman/teman.h"

#include "../Utas/commandUtas.h"
#include "../Utas/tabUtas.h"
#include "../Utas/utas.h"

#include "charmachinefile.h"
#include "wordmachinefile.h"

DATETIME muatDateTime();
void muatPenggunaNew(Word inputFile,TabPengguna dataPengguna,AdjacencyMatrix mteman);
void muatKicauanNew(Word inputFile,TabKicauan *tabkicau);
void muatBalasanNew(Word inputFile,TabPengguna *tabuser);
void muatDrafNew(Word inputFile,TabPengguna *tabuser);
void muatUtasNew(Word inputFile, TabUtas *dataUtas);

void muat(TabPengguna* datauser, AdjacencyMatrix* matrikstemen, TabKicauan* tabkicauan, TabUtas* datautas);
#endif