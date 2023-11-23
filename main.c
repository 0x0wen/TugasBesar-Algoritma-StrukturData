#include <stdio.h>
#include "Inisialisasi/inisialisasi.h"
#include "General/wordmachine.h"
#include "Pengguna/pengguna.h"
#include "Pengguna/commandPengguna.h"
#include "Pengguna/tabPengguna.h"
#include "Kicauan/kicauan.h"
#include "Kicauan/commandKicauan.h"
#include "Kicauan/tabKicauan.h"
#include "Utas/utas.h"
#include "Utas/commandUtas.h"
#include "Utas/tabUtas.h"
#include "Teman/teman.h"
#include "Teman/commandTeman.h"
#include "Teman/teman.h"
#include "PermintaanTeman/permintaanTeman.h"
#include "PermintaanTeman/commandPermintaanTeman.h"
#include "FotoProfil/fotoProfil.h"
#include "DrafKicauan/draf.h"
#include "DrafKicauan/commandDraf.h"
#include "Balasan/balasan.h"
#include "Balasan/commandBalasan.h"
#include "Balasan/tabBalasan.h"
#include "global.h"

Pengguna penggunaSekarang;
TabPengguna dataPengguna;
TabKicauan dataKicauan;
TabUtas dataUtas;
AdjacencyMatrix matrixTeman;

int main()
{
  inisialisasi();

  while (!statusLogin)
  {
    printf(">> ");
    STARTWORD();

    if (isWordEqualStr(&currentWord, "DAFTAR"))
      DAFTAR();
    if (isWordEqualStr(&currentWord, "MASUK"))
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
    if (isWordEqualStr(&currentWord, "ATUR_JENIS_AKUN"))
      ATUR_JENIS_AKUN();
    if (isWordEqualStr(&currentWord, "UBAH_FOTO_PROFIL"))
      UBAH_FOTO_PROFIL();
    if (isWordEqualStr(&currentWord, "KICAU"))
      KICAU();
    if (isWordEqualStr(&currentWord, "KICAUAN"))
      KICAU();
    if (isWordEqualStr(&currentWord, "BUAT_DRAF"))
      BUAT_DRAF(NULL);
    if (isWordEqualStr(&currentWord, "LIHAT_DRAF"))
      LIHAT_DRAF(NULL);
    if (isWordEqualStr(&currentWord, "DAFTAR_TEMAN"))
      DAFTAR_TEMAN();
    if (isWordEqualStr(&currentWord, "HAPUS_TEMAN"))
      HAPUS_TEMAN();
    if (isWordEqualStr(&currentWord, "TAMBAH_TEMAN"))
      TAMBAH_TEMAN();
    if (isWordEqualStr(&currentWord, "DAFTAR_PERMINTAAN_PERTEMANAN"))
      DAFTAR_PERMINTAAN_PERTEMANAN();
    if (isWordEqualStr(&currentWord, "SETUJUI_PERTEMANAN"))
      SETUJUI_PERTEMANAN();

    if (isWordEqualStr(&currentWord, "LIHAT_PROFIL")) {
      ADV();
      Word Nama = currentWord;
      LIHAT_PROFIL(Nama);
    }

    if (isWordEqualStr(&currentWord, "SUKA_KICAUAN"))
    {
      ADV();
      int IDKicau = wordToInteger(&currentWord);
      SUKA_KICAUAN(IDKicau);
    }

    if (isWordEqualStr(&currentWord, "UBAH_KICAUAN"))
    {
      ADV();
      int IDKicau = wordToInteger(&currentWord);
      UBAH_KICAUAN(IDKicau);
    }

    if (isWordEqualStr(&currentWord, "BALAS"))
    {
      ADV();
      int IDKicau = wordToInteger(&currentWord);
      ADV();
      int IDBalasan = wordToInteger(&currentWord);
      BALAS(IDKicau, IDBalasan);
    }

    if (isWordEqualStr(&currentWord, "BALASAN"))
    {
      ADV();
      int IDKicau = wordToInteger(&currentWord);
      CETAK_BALASAN(IDKicau);
    }

    if (isWordEqualStr(&currentWord, "HAPUS_BALASAN"))
    {
      ADV();
      int IDKicau = wordToInteger(&currentWord);
      ADV();
      int IDBalasan = wordToInteger(&currentWord);
      HAPUS_BALASAN(IDKicau, IDBalasan);
    }

    if (isWordEqualStr(&currentWord, "UTAS"))
    {
      ADV();
      int IDKicau = wordToInteger(&currentWord);
      CREATE_UTAS(IDKicau);
    }

    if (isWordEqualStr(&currentWord, "SAMBUNG_UTAS"))
    {
      ADV();
      int IDUtas = wordToInteger(&currentWord);
      ADV();
      int Index = wordToInteger(&currentWord);
      SAMBUNG_UTAS(IDUtas, Index);
    }

    if (isWordEqualStr(&currentWord, "HAPUS_UTAS"))
    {
      ADV();
      int IDUtas = wordToInteger(&currentWord);
      ADV();
      int Index = wordToInteger(&currentWord);
      HAPUS_UTAS(IDUtas, Index);
    }

    if (isWordEqualStr(&currentWord, "CETAK_UTAS"))
    {
      ADV();
      int IDUtas = wordToInteger(&currentWord);
      CETAK_UTAS(IDUtas);
    }

    // if (isWordEqualStr(&currentWord, "SIMPAN")) SIMPAN();
    // if (isWordEqualStr(&currentWord, "MUAT")) MUAT();
  }

  if (statusProgram)
  {
    if (isWordEqualStr(&currentWord, "TUTUP_PROGRAM"))
      TUTUP_PROGRAM();
  }

  return 0;
}