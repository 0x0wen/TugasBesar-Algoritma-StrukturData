#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "sentenceMachine.h"

/* State Mesin Word */
boolean EndWord;
Word currentWord;

void startSentence()
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


void printSentence(Sentence w)
{
    int i;
    for (i = 0; i < w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
    }
}

void InputSentence(Sentence *inputWord)
{
    startSentence();
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

boolean IsSentenceEqual(Sentence w1, Sentence w2)
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
boolean isSentenceOnlyBlank(Sentence w)
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

int LengthStr(const char *str)
{
    int length = 0;

    // Loop hingga karakter null ditemukan
    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}

