#ifndef GLOBAL_H
#define GLOBAL_H

#include "Pengguna/pengguna.h"
#include "Pengguna/TabPengguna.h"
#include "Kicauan/kicauan.h"
#include "Utas/TabUtas.h"
#include "Balasan/TabBalasan.h"
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
