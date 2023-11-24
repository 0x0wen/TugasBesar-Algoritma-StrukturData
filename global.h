#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "Balasan/balasan.h"
#include "Balasan/commandBalasan.h"

#include "DrafKicauan/commandDraf.h"
#include "DrafKicauan/draf.h"

#include "FotoProfil/fotoProfil.h"

#include "General/boolean.h"
#include "General/charmachine.h"
#include "General/datetime.h"
#include "General/listDinamis.h"
#include "General/sentenceMachine.h"
#include "General/time_adt.h"
#include "General/wordmachine.h"

#include "Inisialisasi/inisialisasi.h"

#include "Kicauan/commandKicauan.h"
#include "Kicauan/kicauan.h"
#include "Kicauan/tabKicauan.h"

#include "Pengguna/commandPengguna.h"
#include "Pengguna/pengguna.h"
#include "Pengguna/tabPengguna.h"

#include "PermintaanTeman/commandPermintaanTeman.h"
#include "PermintaanTeman/permintaanTeman.h"

#include "Teman/commandTeman.h"
#include "Teman/teman.h"

#include "Utas/commandUtas.h"
#include "Utas/tabUtas.h"
#include "Utas/utas.h"

#include "muatsimpan/charmachinefile.h"
#include "muatsimpan/newMuat.h"
#include "muatsimpan/simpan.h"
#include "muatsimpan/wordmachinefile.h"


extern Pengguna penggunaSekarang;
extern TabPengguna dataPengguna;
extern TabUtas dataUtas;
extern TabKicauan dataKicauan;
extern AdjacencyMatrix matrixTeman;
extern boolean statusLogin;
extern boolean statusProgram;

#endif