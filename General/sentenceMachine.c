#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "sentenceMachine.h"

/* State Mesin Word */
boolean EndWord;
Sentence currentSentence;

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
void AcquireSentence()
{
    int i = 0;
    while (currentChar != MARK)
    {
        if (i < NMax)
        {
            currentSentence.TabWord[i] = currentChar;
        }
        i++;
        currentSentence.Length = i;
        ADV();
    }

    if (i > NMax)
    {
        currentSentence.Length = NMax;
    }
}


void printSentence(Sentence w)
{
    int i;
    for (i = 0; i < w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
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

