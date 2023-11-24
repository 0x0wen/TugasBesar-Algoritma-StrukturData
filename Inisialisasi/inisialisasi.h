#ifndef INISIALISASI_HEADER_H
#define INISIALISASI_HEADER_H

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

#include "../muatsimpan/charmachinefile.h"
#include "../muatsimpan/newMuat.h"
#include "../muatsimpan/simpan.h"
#include "../muatsimpan/wordmachinefile.h"

void inisialisasi(TabPengguna* datauser, AdjacencyMatrix* matrikstemen, TabKicauan* tabkicauan, TabUtas* datautas);

#endif