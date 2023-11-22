#ifndef GLOBAL_H
#define GLOBAL_H

#include "Pengguna/tabPengguna.h"
#include "Pengguna/pengguna.h"
#include "Kicauan/tabKicauan.h"
#include "Utas/tabUtas.h"
#include "Balasan/tabBalasan.h"
#include "Teman/tabTeman.h"
#include "Utas/commandUtas.h"

extern Pengguna penggunaSekarang;
extern TabPengguna dataPengguna;
extern TabUtas dataUtas;
extern TabKicauan dataKicauan;
extern TabTeman dataTeman;
extern boolean statusLogin;
extern boolean statusProgram;

#endif