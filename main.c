#include "global.h"

// Pengguna penggunaSekarang;
// TabPengguna dataPengguna;
// TabKicauan dataKicauan;
// TabUtas dataUtas;
// AdjacencyMatrix matrixTeman;

int main()
{ 
  createTabPengguna(&dataPengguna);
  createTabUtas(&dataUtas, 100);
  createTabKicauan(&dataKicauan, 100);
  createMatrixTeman(&matrixTeman);

  statusLogin = false;
  statusProgram = false;

  inisialisasi(&dataPengguna,&matrixTeman,&dataKicauan,&dataUtas);

  while (statusProgram)
  {
    while (!statusLogin)
      {
        printf("\n𝑴𝒂𝒔𝒖𝒌/𝑫𝒂𝒇𝒕𝒂𝒓 𝒖𝒏𝒕𝒖𝒌 𝒎𝒆𝒍𝒂𝒏𝒋𝒖𝒕𝒌𝒂𝒏\n");
        printf("\n>> ");
        STARTWORD();

        // if (isWordEqualStr(currentWord, "MUAT")) 
        //   muat();
        // if (isWordEqualStr(currentWord, "SIMPAN")) 
        //   simpan();
        if (isWordEqualStr(currentWord, "DAFTAR"))
          DAFTAR();
        if (isWordEqualStr(currentWord, "MASUK"))
          MASUK();
      }
      
    printf("\n>> ");
    STARTWORD();
    
    // if (isWordEqualStr(currentWord, "SIMPAN")) 
    //   simpan();
    if (isWordEqualStr(currentWord, "KELUAR"))
      KELUAR();
    else if (isWordEqualStr(currentWord, "GANTI_PROFIL"))
      GANTI_PROFIL();
    else if (isWordEqualStr(currentWord, "ATUR_JENIS_AKUN"))
      ATUR_JENIS_AKUN();
    else if (isWordEqualStr(currentWord, "UBAH_FOTO_PROFIL"))
      UBAH_FOTO_PROFIL();
    else if (isWordEqualStr(currentWord, "KICAU"))
      KICAU();
    else if (isWordEqualStr(currentWord, "KICAUAN"))
      KICAUAN();
    else if (isWordEqualStr(currentWord, "BUAT_DRAF"))
      BUAT_DRAF();
    else if (isWordEqualStr(currentWord, "LIHAT_DRAF"))
      LIHAT_DRAF();
    else if (isWordEqualStr(currentWord, "DAFTAR_TEMAN"))
      DAFTAR_TEMAN();
    else if (isWordEqualStr(currentWord, "HAPUS_TEMAN"))
      HAPUS_TEMAN();
    else if (isWordEqualStr(currentWord, "TAMBAH_TEMAN"))
      TAMBAH_TEMAN();
    else if (isWordEqualStr(currentWord, "DAFTAR_PERMINTAAN_PERTEMANAN"))
      DAFTAR_PERMINTAAN_PERTEMANAN();
    else if (isWordEqualStr(currentWord, "SETUJUI_PERTEMANAN"))
      SETUJUI_PERTEMANAN();
    else if (isWordEqualStr(currentWord, "LIHAT_PROFIL")) {
      LIHAT_PROFIL();
    }

    else if (isWordEqualStr(currentWord, "SUKA_KICAUAN"))
    {
      ADVWORD();
      int IDKicau = wordToInteger(currentWord);
      SUKA_KICAUAN(IDKicau);
    }

    else if (isWordEqualStr(currentWord, "UBAH_KICAUAN"))
    {
      ADVWORD();
      int IDKicau = wordToInteger(currentWord);
      UBAH_KICAUAN(IDKicau);
    }

    else if (isWordEqualStr(currentWord, "BALAS"))
    {
      ADVWORD();
      int IDKicau = wordToInteger(currentWord);
      ADVWORD();
      int IDBalasan = wordToInteger(currentWord);
      BALAS(IDKicau, IDBalasan);
    }

    else if (isWordEqualStr(currentWord, "BALASAN"))
    {
      ADVWORD();
      int IDKicau = wordToInteger(currentWord);
      CETAK_BALASAN(IDKicau);
    }

    else if (isWordEqualStr(currentWord, "HAPUS_BALASAN"))
    {
      ADVWORD();
      int IDKicau = wordToInteger(currentWord);
      ADVWORD();
      int IDBalasan = wordToInteger(currentWord);
      HAPUS_BALASAN(IDKicau, IDBalasan);
    }

    else if (isWordEqualStr(currentWord, "UTAS"))
    {
      ADVWORD();
      int IDKicau = wordToInteger(currentWord);
      CREATE_UTAS(IDKicau);
    }

    else if (isWordEqualStr(currentWord, "SAMBUNG_UTAS"))
    {
      ADVWORD();
      int IDUtas = wordToInteger(currentWord);
      ADVWORD();
      int Index = wordToInteger(currentWord);
      SAMBUNG_UTAS(IDUtas, Index);
    }

    else if (isWordEqualStr(currentWord, "HAPUS_UTAS"))
    {
      ADVWORD();
      int IDUtas = wordToInteger(currentWord);
      ADVWORD();
      int Index = wordToInteger(currentWord);
      HAPUS_UTAS(IDUtas, Index);
    }

    else if (isWordEqualStr(currentWord, "CETAK_UTAS"))
    {
      ADVWORD();
      int IDUtas = wordToInteger(currentWord);
      CETAK_UTAS(IDUtas);
    }

    printf("\nTekan ; kemudian Enter untuk melanjutkan...\n");
    STARTWORD();
    system("clear");
  }

  if (statusProgram)
  {
    if (isWordEqualStr(currentWord, "TUTUP_PROGRAM"))
      TUTUP_PROGRAM();
  }

  return 0;
}