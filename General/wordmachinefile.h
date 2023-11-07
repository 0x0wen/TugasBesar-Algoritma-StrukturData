#ifndef __WORDMACHINEFILE_H__
#define __WORDMACHINEFILE_H__

#include "boolean.h"
#include "charmachinefile.h"
#include "wordmachine.h"

extern boolean endWordFile;
extern Word currentWordFile;

void IgnoreBlanksFile();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARWORDFILE(char namaFile[]);
/* I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK;
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDFILE();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.
   Proses : Akuisisi kata menggunakan procedure copyWord */

void CopyWordFile();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

Word CopyWordFile2();

void StopWordFile();
/* Memberhentikan pembacaan Mesin Kata. Pita tidak bisa lagi dibaca
   I.S. : Mesin Kata sedang dijalankan
   F.S. : Mesin Kata berhenti */

#endif