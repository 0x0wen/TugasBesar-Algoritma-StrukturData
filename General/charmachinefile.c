#include <stdio.h>
#include "charmachinefile.h"

char currentCharFile;
boolean eotFile;

static FILE *tapeFile;
static int retvalFile;

void STARFILE(char namaFile[]){
  tapeFile = fopen(namaFile, "r");
  ADVFILE();
}

void ADVFILE(){
  retvalFile = fscanf(tapeFile, "%c", &currentCharFile);
  eotFile = (currentCharFile == MARK_FILE);
}

void ENDFILE(){
  fclose(tapeFile);
}