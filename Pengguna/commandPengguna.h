#ifndef COMMAND_PENGGUNA_H
#define COMMAND_PENGGUNA_H

#include "../General/boolean.h"
#include "../FotoProfil/fotoProfil.h"
#include "pengguna.h"
#include "tabPengguna.h"
#include "global.h"

/* PROFIL */
void GANTI_PROFIL();
void LIHAT_PROFIL();
void ATUR_JENIS_AKUN();
void UBAH_FOTO_PROFIL();
void DISPLAY_FOTO_PROFIL(Pengguna p);
void DISPLAY_PROFIL(Pengguna user);

#endif