#include <stdio.h>
#include "sentenceMachine.h"
/* File: charmachine.c */
/* Implementasi Mesin Karakter */

Sentence sentence;

void AcquireBlanks()
{
    int i = 0;
    currentWord.Length = 0;
    while (currentChar == BLANK)
    {
        currentWord.TabWord[i] = currentChar;
        currentWord.Length++;
        ADV();
        i++;
    }
}
/*  Membaca blank spaces
    I.S :   currentChar adalah blank pertama
    F.S :   currentWord adalah kumpulan blank
            currentChar adalah sebuah character atau MARK
    */

void AcquireSentence()
{
    currentWord.Length = 0;
    int i = 0;
    while (currentChar != MARK)
    {
        if (currentChar == BLANK)
        {
            AcquireBlanks();
        }
        else
        {
            CopyWord();
        }
        sentence.TabSentence[i] = currentWord;
        ADV();
        i++;
    }
};
/* Membaca seluruh pita dan mengakuisisi kalimat
   I.S. : currentChar adalah karakter pertama dari pita
   F.S. : sentence berisi kalimat yang sudah diakuisisi dengan format array of words.
          Contoh: "Saya suka     babi" akan disimpan dengan format ["Saya", " ", "suka", "     ", "babi"]
          currentChar = MARK; */
