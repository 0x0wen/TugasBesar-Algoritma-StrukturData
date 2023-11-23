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

void printWord(Word w) {
    int i;
    for (i = 0; i < w.Length; i++) {
        printf("%c", w.TabWord[i]);
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

// int LengthStr(const char *str) {
//     int length = 0;

//     // Loop hingga karakter null ditemukan
//     while (str[length] != '\0') {
//         length++;
//     }

//     return length;
// }

// boolean isWordEqualStr(Word *w, char *str) {
//     int n = w->Length;
//     int strLength = LengthStr(str);

//     // Jika panjang Word tidak sama dengan panjang String, return false
//     if (n != strLength) {
//         return false;
//     }

//     // Bandingkan setiap karakter
//     for (int i = 0; i < n; ++i) {
//         if (w->TabWord[i] != str[i]) {
//             return false;
//         }
//     }

//     return true;
// }

// int wordToInteger(Word *word) {
//     // Check if the Word is empty
//     if (word->Length == 0) {
//         printf("Error: Empty Word\n");
//         return 0;  // You may want to handle this differently based on your requirements
//     }

//     // Convert the character array to an integer using strtol function
//     char *endptr;
//     long result = strtol(word->TabWord, &endptr, 10);

//     // Check if the conversion was successful
//     if (*endptr != '\0') {
//         printf("Error: Non-integer characters found in Word\n");
//         return 0;  // You may want to handle this differently based on your requirements
//     }

//     return (int)result;
// }