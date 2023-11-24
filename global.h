#ifndef GLOBAL_H
#define GLOBAL_H

#include "Pengguna/pengguna.h"
#include "Pengguna/tabPengguna.h"
#include "Kicauan/tabKicauan.h"
#include "Utas/tabUtas.h"
#include "Teman/teman.h"
#include "Utas/commandUtas.h"

extern Pengguna penggunaSekarang;
extern TabPengguna dataPengguna;
extern TabUtas dataUtas;
extern TabKicauan dataKicauan;
extern AdjacencyMatrix matrixTeman;
extern boolean statusLogin;
extern boolean statusProgram;

#endif