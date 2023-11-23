/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef SENTENCE_MACHINE_H
#define SENTENCE_MACHINE_H

#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

#define NMax 280
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Sentence;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void startSentence();
void ADVW0RD();
void CopyWord();
void writeWord(Word *writeWord, char input[], int length);
void printSentence(Sentence w);
void InputSentence(Sentence *inputWord);
boolean IsSentenceEqual(Sentence w1, Sentence w2);
boolean isSentenceOnlyBlank(Sentence w);
int LengthStr(const char *str);
void AcquireSentence();
// void InputWord(Word *inputWord);
// void printWord(Word w);
// void InputWordWithBlank(Word *inputWord);
// void printSentence(Sentence w)
// boolean IsSentenceEqual(Sentence w1, Sentence w2);
// boolean isOnlyBlank(Word w);
// int LengthStr(const char *str);
// boolean isWordEqualStr(const Word *w, const char *str);
#endif