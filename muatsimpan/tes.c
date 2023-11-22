#include <stdio.h>
#include "newMuat.c"

int main(){
    printf("Masukkan nama folder yang hendak dimuat.\n");
    Word config,locFile;
    writeWord(&locFile,"Data/", 5);
    InputWord(&config);
    Word inputFolder = writefilename(locFile,config);
    writeWord(&locFile,"/pengguna.config", 16);
    Word inputFile = writefilename(inputFolder,locFile);
    FILE* tempFile = fopen(inputFile.TabWord, "r");
    muatPengguna(inputFile);
}