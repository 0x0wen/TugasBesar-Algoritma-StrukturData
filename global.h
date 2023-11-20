#ifndef GLOBAL_H
#define GLOBAL_H

#include "./Pengguna/TabPengguna.h"
#include "./Kicauan/kicauan.h"
#include "./Utas/TabUtas.h"
#include "./Balasan/TabBalasan.h"
#include "./Teman/tabTeman.h"

extern Pengguna penggunaSekarang;
extern TabPengguna dataPengguna;
extern TabKicauan dataKicauan;
extern TabUtas dataUtas;
extern TabTeman dataTeman;

extern boolean statusLogin;
extern boolean statusProgram;

#endif
