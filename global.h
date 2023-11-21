#ifndef GLOBAL_H
#define GLOBAL_H

#include "Pengguna/TabPengguna.h"
#include "Pengguna/pengguna.h"
#include "Kicauan/kicauan.h"
#include "Utas/TabUtas.h"
#include "Balasan/TabBalasan.h"
#include "Teman/tabTeman.h"
#include "Utas/commandUtas.h"

extern Pengguna penggunaSekarang;
extern TabPengguna dataPengguna;
extern TabKicauan dataKicauan;
// TabKicauan dataKicauan;
// createTabKicauan(&dataKicauan, 100);
extern TabUtas dataUtas;
extern TabTeman dataTeman;

extern boolean statusLogin;
extern boolean statusProgram;

#endif