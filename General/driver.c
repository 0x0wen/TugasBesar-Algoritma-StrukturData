#include "sentenceMachine.h"
#include "sentenceMachine.c"
#include "wordMachine.c"
#include "charMachine.c"


int main() {
  Sentence Input;
  Sentence Input2;

  printf("WORD1 :");
  InputSentence(&Input);
  printf("WORD1 :");
  printSentence(Input);

  printf("\nWORD2 :");
  InputSentence(&Input2);
  printf("WORD2 :");
  printSentence(Input2);

  if (IsSentenceEqual(Input, Input2)) {
    printf("\nSama\n");
  } else {
    printf("\nTidak Sama\n");
  }

  Sentence Input3;

  InputSentence(&Input3);

  if (isSentenceOnlyBlank(Input3)) {
    printf("Hanya Blank\n");
  }

  printf("Panjang sentence: %d\n", Input.Length);

  return 0;
}