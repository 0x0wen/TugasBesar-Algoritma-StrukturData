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

int main() {
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

    if (isWordEqualStr(&currentWord, "KELUAR")) KELUAR();
    if (isWordEqualStr(&currentWord, "GANTI_PROFIL")) GANTI_PROFIL();
    if (isWordEqualStr(&currentWord, "ATUR_JENIS_AKUN")) ATUR_JENIS_AKUN();
    if (isWordEqualStr(&currentWord, "UBAH_FOTO_PROFIL")) UBAH_FOTO_PROFIL();
    if (isWordEqualStr(&currentWord, "DAFTAR_TEMAN")) DAFTAR_TEMAN();
    if (isWordEqualStr(&currentWord, "HAPUS_TEMAN")) HAPUS_TEMAN();
    if (isWordEqualStr(&currentWord, "TAMBAH_TEMAN")) TAMBAH_TEMAN();
    if (isWordEqualStr(&currentWord, "DAFTAR_PERMINTAAN_PERTEMANAN")) DAFTAR_PERMINTAAN_PERTEMAN();
    if (isWordEqualStr(&currentWord, "SETUJUI_PERTEMANAN")) SETUJUI_PERTEMANAN();
    if (isWordEqualStr(&currentWord, "KICAU")) KICAU();
    if (isWordEqualStr(&currentWord, "KICAUAN")) KICAU();
    if (isWordEqualStr(&currentWord, "KICAU")) KICAU();
    if (isWordEqualStr(&currentWord, "KICAUAN")) KICAU();
    if (isWordEqualStr(&currentWord, "SUKA_KICAUAN")) SUKA_KICAUAN(NULL);
    if (isWordEqualStr(&currentWord, "UBAH_KICAUAN")) UBAH_KICAUAN(NULL);
    if (isWordEqualStr(&currentWord, "BUAT_DRAF")) BUAT_DRAF(NULL);
    if (isWordEqualStr(&currentWord, "LIHAT_DRAF")) LIHAT_DRAF(NULL);
    if (isWordEqualStr(&currentWord, "SIMPAN")) SIMPAN();
    if (isWordEqualStr(&currentWord, "MUAT")) MUAT();

    if (&currentWord == 'LIHAT_PROFIL') {
      ADV();
      Word NAMA = currentWord;
      LIHAT_PROFIL(NAMA);
    }

    if (&currentWord == 'SUKA_KICAUAN') {
      ADV();
      int IDKicau = wordToInteger(&currentWord);
      SUKA_KICAUAN(IDKicau);
    }

    if (&currentWord == 'UBAH_KICAUAN') {
      ADV();
      int IDKicau = wordToInteger(&currentWord);
      UBAH_KICAUAN(IDKicau);
    }

    if (&currentWord == 'BALAS') {
      ADV();
      int IDKicau = wordToInteger(&currentWord);
      ADV();
      int IDBalasan = wordToInteger(&currentWord);
      BALAS(IDKicau, IDBalasan);
    }

    if (&currentWord == 'BALASAN') {
      ADV();
      int IDKicau = wordToInteger(&currentWord);
      BALASAN(IDKicau);
    }

    if (&currentWord == 'HAPUS_BALASAN') {
      ADV();
      int IDKicau = wordToInteger(&currentWord);
      ADV();
      int IDBalasan = wordToInteger(&currentWord);
      HAPUS_BALASAN(IDKicau, IDBalasan);
    }

    if (&currentWord == 'UTAS') {
      ADV();
      int IDKicau = wordToInteger(&currentWord);
      UTAS(IDKicau);
    }

    if (&currentWord == 'SAMBUNG_UTAS') {
      ADV();
      int IDUtas = wordToInteger(&currentWord);
      ADV();
      int Index = wordToInteger(&currentWord);
      SAMBUNG_UTAS(IDUtas, Index);
    }

    if (&currentWord == 'HAPUS_UTAS') {
      ADV();
      int IDUtas = wordToInteger(&currentWord);
      ADV();
      int Index = wordToInteger(&currentWord);
      HAPUS_UTAS(IDUtas, Index);
    }

    if (&currentWord == 'CETAK_UTAS') {
      ADV();
      int IDUtas = wordToInteger(&currentWord);
      CETAK_UTAS(IDUtas);
    }
  }

  if (statusProgram)
  {
    if (IsWordEqualStr(&currentWord, 'TUTUP_PROGRAM'))
      TUTUP_PROGRAM();
  }

  return 0;
}