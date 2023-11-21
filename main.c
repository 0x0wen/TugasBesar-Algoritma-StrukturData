#include <stdio.h>
#include "General/wordmachine.h"
#include "General/wordmachine.c"
#include "Pengguna/pengguna.h"
#include "Kicauan/kicauan.h"
#include "Utas/utas.h"
#include "Balasan/balasan.h"
#include "Utas/commandUtas.h"
#include "Balasan/commandBalasan.h"
#include "PermintaanTeman/commandPermintaanTeman.h"
#include "global.h"

Pengguna penggunaSekarang;
TabPengguna dataPengguna;
TabKicauan dataKicauan;
TabUtas dataUtas;
TabTeman dataTeman;

int main()
{
  inisialisasi();

  while (!statusLogin)
  {
    printf(">> ");
    STARTWORD();

    if (IsWordEqualStr(&currentWord, 'DAFTAR'))
      DAFTAR();
    if (IsWordEqualStr(&currentWord, 'MASUK'))
      MASUK();
  }

  while (statusLogin && statusProgram)
  {
    printf(">> ");
    STARTWORD();

    if (isWordEqualStr(&currentWord, "KELUAR"))
      KELUAR();

    if (isWordEqualStr(&currentWord, "GANTI_PROFIL"))
      GANTI_PROFIL();
    if (isWordEqualStr(&currentWord, "LIHAT_PROFIL"))
      LIHAT_PROFIL();
    if (isWordEqualStr(&currentWord, "ATUR_JENIS_AKUN"))
      ATUR_JENIS_AKUN();
    if (isWordEqualStr(&currentWord, "UBAH_FOTO_PROFIL"))
      UBAH_FOTO_PROFIL();

    if (isWordEqualStr(&currentWord, "DAFTAR_TEMAN"))
      DAFTAR_TEMAN();
    if (isWordEqualStr(&currentWord, "HAPUS_TEMAN"))
      HAPUS_TEMAN();

    if (isWordEqualStr(&currentWord, "TAMBAH_TEMAN"))
      TAMBAH_TEMAN();
    if (isWordEqualStr(&currentWord, "DAFTAR_PERMINTAAN_PERTEMANAN"))
      DAFTAR_PERMINTAAN_PERTEMAN();
    if (isWordEqualStr(&currentWord, "SETUJUI_PERTEMANAN"))
      SETUJUI_PERTEMANAN();

    if (isWordEqualStr(&currentWord, "KICAU"))
      KICAU();
    if (isWordEqualStr(&currentWord, "KICAUAN"))
      KICAU();
    if (isWordEqualStr(&currentWord, "SUKA_KICAUAN"))
      SUKA_KICAU();
    if (isWordEqualStr(&currentWord, "UBAH_KICAUAN"))
      UBAH_KICAUAN(NULL);
    if (isWordEqualStr(&currentWord, "KICAU")) KICAU();
    if (isWordEqualStr(&currentWord, "KICAUAN")) KICAU();
    if (isWordEqualStr(&currentWord, "SUKA_KICAUAN")) SUKA_KICAUAN(NULL);
    if (isWordEqualStr(&currentWord, "UBAH_KICAUAN")) UBAH_KICAUAN(NULL);

    if (isWordEqualStr(&currentWord, "BALAS"))
      BALAS();
    if (isWordEqualStr(&currentWord, "BALASAN"))
      CETAK_BALASAN();
    if (isWordEqualStr(&currentWord, "HAPUS_BALASAN"))
      HAPUS_BALASAN();

    if (isWordEqualStr(&currentWord, "BUAT_DRAF"))
      BUAT_DRAF(NULL);
    if (isWordEqualStr(&currentWord, "LIHAT_DRAF"))
      LIHAT_DRAF(NULL);

    if (isWordEqualStr(&currentWord, "UTAS"))
      CREATE_UTAS();
    if (isWordEqualStr(&currentWord, "SAMBUNG_UTAS"))
      SAMBUNG_UTAS();
    if (isWordEqualStr(&currentWord, "HAPUS_UTAS"))
      HAPUS_UTAS();
    if (isWordEqualStr(&currentWord, "CETAK_UTAS"))
      CETAK_UTAS();

    if (isWordEqualStr(&currentWord, "SIMPAN"))
      SIMPAN();
    if (isWordEqualStr(&currentWord, "MUAT"))
      MUAT();
  }

  if (statusProgram)
  {
    if (IsWordEqualStr(&currentWord, 'TUTUP_PROGRAM'))
      TUTUP_PROGRAM();
  }

  return 0;
}