#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"
#include "wordmachine.c"
#include "pengguna.h"
#include "kicauan.h"
#include "utas.h"
#include "balasan.h"
#include "global.h"

Pengguna penggunaSekarang;
TabPengguna dataPengguna;
TabKicauan dataKicauan;
TabUtas dataUtas;
TabTeman dataTeman;

int main()
{
  /* INISIALISASI */
  inisialisasi();

  /* MASUK APLIKASI */
  STARTWORD();
  if (IsWordEqualStr(currentWord, 'DAFTAR')) DAFTAR();
  if (IsWordEqualStr(currentWord, 'MASUK')) MASUK();

  /* APLIKASI */
  while (statusLogin && statusProgram)
  {
    printf(">> ");
    STARTWORD();

    /* KELUAR */
    if (isWordEqualStr(&currentWord, "KELUAR")) KELUAR();
    /* PROFIL */
    if (isWordEqualStr(&currentWord, "GANTI_PROFIL")) GANTI_PROFIL();
    if (isWordEqualStr(&currentWord, "LIHAT_PROFIL")) LIHAT_PROFIL();
    if (isWordEqualStr(&currentWord, "ATUR_JENIS_AKUN")) ATUR_JENIS_AKUN();
    if (isWordEqualStr(&currentWord, "UBAH_FOTO_PROFIL")) UBAH_FOTO_PROFIL();
    /* TEMAN */
    if (isWordEqualStr(&currentWord, "DAFTAR_TEMAN")) DAFTAR_TEMAN();
    if (isWordEqualStr(&currentWord, "HAPUS_TEMAN")) HAPUS_TEMAN();
    /* PERMINTAAN PERTEMANAN */
    if (isWordEqualStr(&currentWord, "TAMBAH_TEMAN")) TAMBAH_TEMAN();
    if (isWordEqualStr(&currentWord, "DAFTAR_PERMINTAAN_PERTEMANAN")) DAFTAR_PERMINTAAN_PERTEMAN();
    if (isWordEqualStr(&currentWord, "SETUJUI_PERTEMANAN")) SETUJUI_PERTEMANAN();
    /* KICUAN */
    if (isWordEqualStr(&currentWord, "KICAU")) KICAU();
    if (isWordEqualStr(&currentWord, "KICAUAN")) KICAU();
    if (isWordEqualStr(&currentWord, "SUKA_KICAUAN")) SUKA_KICAU();
    if (isWordEqualStr(&currentWord, "UBAH_KICAUAN")) UBAH_KICAUAN(NULL);
    /* BALASAN */
    if (isWordEqualStr(&currentWord, "BALAS")) BALAS();
    if (isWordEqualStr(&currentWord, "BALASAN")) BALASAN();
    if (isWordEqualStr(&currentWord, "HAPUS_BALASAN")) HAPUS_BALASAN();
    /* DRAF */
    if (isWordEqualStr(&currentWord, "BUAT_DRAF")) BUAT_DRAF(NULL);
    if (isWordEqualStr(&currentWord, "LIHAT_DRAF")) LIHAT_DRAF(NULL);
    /* UTAS */
    if (isWordEqualStr(&currentWord, "UTAS")) UTAS();
    if (isWordEqualStr(&currentWord, "SAMBUNG_UTAS")) SAMBUNG_UTAS();
    if (isWordEqualStr(&currentWord, "HAPUS_UTAS")) HAPUS_UTAS();
    if (isWordEqualStr(&currentWord, "CETAK_UTAS")) CETAK_UTAS();
    /* SIMPAN DAN MUAT */
    if (isWordEqualStr(&currentWord, "SIMPAN")) SIMPAN();
    if (isWordEqualStr(&currentWord, "MUAT")) MUAT();
  }

  /* TUTUP_PROGRAM */
  if (statusProgram)
  {
    if (IsWordEqualStr(&currentWord, 'TUTUP_PROGRAM'))
      TUTUP_PROGRAM();
  }

  return 0;
}
