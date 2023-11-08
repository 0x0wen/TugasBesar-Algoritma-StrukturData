#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "wordmachine.h"

/* State Mesin Word */
boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK && currentChar != MARK)
    {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD()
{
    START(); //
    IgnoreBlanks();

    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        EndWord = false;
    }
}
void STARTWORD_BLANK()
{
    START();

    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        EndWord = false;
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord()
{
    int i = 0;

    while (currentChar != MARK)
    {
        if (i < NMax)
        {
            currentWord.TabWord[i] = currentChar;
        }
        i++;
        currentWord.Length = i;
        ADV();
    }

    if (i > NMax)
    {
        currentWord.Length = NMax;
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void writeWord(Word *writeWord, char input[], int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        writeWord->TabWord[i] = input[i];
    }
    writeWord->TabWord[length] = '\0';
    writeWord->Length = length;
}

void InputWord(Word *inputWord)
{
    STARTWORD();
    if (EOP)
    {
        writeWord(inputWord, currentWord.TabWord, currentWord.Length);
    }
    else
    {
        writeWord(inputWord, "", 0);
        while (!EOP)
        {
            ADVWORD();
        }
    }
}

void InputWordWithBlank(Word *inputWord)
{
    STARTWORD_BLANK();
    if (EOP)
    {
        writeWord(inputWord, currentWord.TabWord, currentWord.Length);
    }
    else
    {
        writeWord(inputWord, "", 0);
        while (!EOP)
        {
            ADVWORD();
        }
    }
}

boolean IsWordEqual(Word w1, Word w2)
{
    if (w1.Length != w2.Length)
    {
        return false;
    }
    else
    {
        int n = w1.Length;
        boolean IsEqual = true;
        int i = 0;
        while (IsEqual && (i < n))
        {
            if ((w1.TabWord[i] != w2.TabWord[i]))
            {
                IsEqual = false;
            }
            else
            {
                i += 1;
            }
        }
        return IsEqual;
    }
}

boolean IsWordNotEqual(Word w1, Word w2)
{
    if (w1.Length == w2.Length)
    {
        return false;
    }
    else
    {
        int n = w1.Length;
        boolean IsNotEqual = true;
        int i = 0;
        while (IsNotEqual && (i < n))
        {
            if ((w1.TabWord[i] == w2.TabWord[i]))
            {
                IsNotEqual = false;
            }
            else
            {
                i += 1;
            }
        }
        return IsNotEqual;
    }
}

boolean isOnlyBlank(Word w)
{

    boolean onlyBlank = true;
    int i = 0;

    while (i < w.Length && onlyBlank)
    {
        if (w.TabWord[i] != BLANK)
        {
            onlyBlank = false;
        }
        i++;
    }

    return onlyBlank;
}