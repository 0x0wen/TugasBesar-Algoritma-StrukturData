#include <stdio.h>

#include "wordmachine.h"
#include "charmachine.h"
#include "boolean.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK && currentChar != MARK)
    {
        ADV();
    }
}

void IgnoreEnters()
{
    while (currentChar == ENTER)
    {
        ADV();
    }
}

void STARTWORD()
{
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
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
    while (currentChar != MARK && currentChar != BLANK)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax)
    {
        i = NMax;
    }
    currentWord.Length = i;
}

void printWord(Word w)
{
    int i;
    for (i = 0; i < w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
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