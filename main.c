#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"
#include "wordmachine.c"
#include "pengguna.h"
#include "kicauan.h"
#include "utas.h"
#include "balasan.h"

Pengguna penggunaSekarang;
TabPengguna dataPengguna;
TabKicauan dataKicauan;
TabUtas dataUtas;

int main()
{
  /* ===== INISIALISASI ===== */
  inisialisasi();

  // Setelah inisialisasi, status program akan true

  /* ===== MASUK APLIKASI ===== */
  STARTWORD();
  if (IsWordEqual(currentWord, 'DAFTAR'))
    DAFTAR();
  if (IsWordEqual(currentWord, 'MASUK'))
    MASUK();

  // Setelah pengguna masuk, status login akan true

  /* ===== APLIKASI =====*/
  while (/* ID Pengguna valid, ID != -1 (Pengguna belum keluar), dan login true */)
  {
    printf(">> ");
    STARTWORD();

    /* ========== KELUAR ========== */
    if (IsWordEqual(currentWord, 'KELUAR'))
      KELUAR(); // Fungsi keluar ini akan membuat ID Pengguna yang ada menjadi -1

    /* =========== PROFIL =========== */
    if (IsWordEqual(currentWord, 'GANTI_PROFIL'))
      GANTI_PROFIL();
    if (IsWordEqual(currentWord, 'LIHAT_PROFIL'))
      LIHAT_PROFIL();
    if (IsWordEqual(currentWord, 'ATUR_JENIS_AKUN'))
      ATUR_JENIS_AKUN();
    if (IsWordEqual(currentWord, 'UBAH_FOTO_PROFIL'))
      UBAH_FOTO_PROFIL();

    /* ========== TEMAN =========*/
    if (IsWordEqual(currentWord, 'DAFTAR_TEMAN'))
      DAFTAR_TEMAN();
    if (IsWordEqual(currentWord, 'HAPUS_TEMAN'))
      HAPUS_TEMAN();

    /* ========== PERMINTAAN PERTEMANAN =========*/
    if (IsWordEqual(currentWord, 'TAMBAH_TEMAN'))
      TAMBAH_TEMAN();
    if (IsWordEqual(currentWord, 'DAFTAR_PERMINTAAN_PERTEMANAN'))
      DAFTAR_PERMINTAAN_PERTEMAN();
    if (IsWordEqual(currentWord, 'SETUJUI_PERTEMANAN'))
      SETUJUI_PERTEMANAN();

    /* ========== KICUAN =========*/
    if (IsWordEqual(currentWord, 'KICAU'))
      KICAU();
    if (IsWordEqual(currentWord, 'KICAUAN'))
      KICAU();
    if (IsWordEqual(currentWord, 'SUKA_KICAUAN'))
      SUKA_KICAU();
    if (IsWordEqual(currentWord, 'UBAH_KICAUAN'))
      UBAH_KICAUAN();

    /* ========== BALASAN =========*/
    if (IsWordEqual(currentWord, 'BALAS'))
      BALAS();
    if (IsWordEqual(currentWord, 'BALASAN'))
      BALASAN();
    if (IsWordEqual(currentWord, 'HAPUS_BALASAN'))
      HAPUS_BALASAN();

    /* ========== DRAF =========*/
    if (IsWordEqual(currentWord, 'BUAT_DRAF'))
      BUAT_DRAF();
    if (IsWordEqual(currentWord, 'LIHAT_DRAF'))
      LIHAT_DRAF();

    /* ========== UTAS =========*/
    if (IsWordEqual(currentWord, 'UTAS'))
      UTAS();
    if (IsWordEqual(currentWord, 'SAMBUNG_UTAS'))
      SAMBUNG_UTAS();
    if (IsWordEqual(currentWord, 'HAPUS_UTAS'))
      HAPUS_UTAS();
    if (IsWordEqual(currentWord, 'CETAK_UTAS'))
      CETAK_UTAS();

    /* ========== SIMPAN DAN MUAT =========*/
    if (IsWordEqual(currentWord, 'SIMPAN'))
      SIMPAN();
    if (IsWordEqual(currentWord, 'MUAT'))
      MUAT();
  }

  /* ===== TUTUP_PROGRAM ===== */
  if (/* Login true (Pengguna sudah masuk)*/)
  {
    if (IsWordEqual(currentWord, 'TUTUP_PROGRAM'))
      TUTUP_PROGRAM();
  }

  return 0;
}
