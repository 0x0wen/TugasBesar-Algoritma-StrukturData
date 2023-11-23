#include <stdio.h>
#include "newMuat.c"
#include "simpan.c"

int main(){
    TabPengguna dataPengguna;
    TabKicauan dataKicau;
    TabUtas tabutas;
    printf("Masukkan nama folder yang hendak dimuat.\n");
    Word config,locFile;
    writeWord(&locFile,"muatsimpan/Data/", 16);
    InputWord(&config);
    Word tes;
    Word inputFolder = writefilename(locFile,config);
    writeWord(&locFile,"/pengguna.config", 16);
    Word inputFile = writefilename(inputFolder,locFile);
    FILE* tempFile = fopen(inputFile.TabWord, "r");
    if(tempFile==NULL){
        printf("tes");
    }
    muatPenggunaNew(inputFile,&dataPengguna);

    // writeWord(&locFile,"/kicauan.config", 15);
    // inputFile = writefilename(inputFolder,locFile);
    // tempFile = fopen(inputFile.TabWord, "r");
    // //muatKicauanNew(inputFile,&dataKicau);

    // writeWord(&locFile,"/balasan.config", 15);
    // inputFile = writefilename(inputFolder,locFile);
    // tempFile = fopen(inputFile.TabWord, "r");
    // //muatBalasanNew(inputFile,dataPengguna);

    // writeWord(&locFile,"/draf.config", 12);
    // inputFile = writefilename(inputFolder,locFile);
    // tempFile = fopen(inputFile.TabWord, "r");
    // muatDrafNew(inputFile, dataPengguna);
}