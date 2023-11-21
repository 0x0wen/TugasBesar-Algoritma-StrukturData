/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __SENTENCEMACHINE_H__
#define __SENTENCEMACHINE_H__

#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

#define NMaxSentence 10
#define BLANK ' '

typedef struct
{
   Word TabSentence[280]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Sentence;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void AcquireBlanks();
void AcquireSentence();

#endif