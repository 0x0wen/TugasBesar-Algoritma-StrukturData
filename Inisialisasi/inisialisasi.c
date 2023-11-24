#include <stdio.h>
#include "../General/wordmachinefile.h"
#include "../Pengguna/pengguna.h"
#include "../General/sentenceMachine.h"
#include "../global.h"
#include "../muatsimpan/simpan.h"
#include "../muatsimpan/newMuat.h"


void inisialisasi(TabPengguna* datauser, AdjacencyMatrix* matrikstemen, TabKicauan* tabkicauan, TabUtas* datautas)
{
    printf("/$$$$$$$                      /$$       /$$           ");
    printf("| $$__  $$                    | $$      |__/          ");
    printf("| $$  \ $$ /$$   /$$  /$$$$$$ | $$$$$$$  /$$  /$$$$$$ ");
    printf("| $$$$$$$ | $$  | $$ /$$__  $$| $$__  $$| $$ /$$__  $$");
    printf("| $$__  $$| $$  | $$| $$  \__/| $$  \ $$| $$| $$  \__/");
    printf("| $$  \ $$| $$  | $$| $$      | $$  | $$| $$| $$      ");
    printf("| $$$$$$$/|  $$$$$$/| $$      | $$$$$$$/| $$| $$      ");
    printf("|_______/  \______/ |__/      |_______/ |__/|__/      ");
    printf("\n");
    printf("Selamat datang di BurBir.\n");
    printf("\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode\n");
    printf("(pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
    printf("\n");
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");

    Word config,locFile;
    writeWord(&locFile,"muatsimpan/Data/", 16);
    InputWord(&config);
    Word inputFolder = writefilename(locFile,config);
    writeWord(&locFile,"/pengguna.config", 16);
    Word inputFile = writefilename(inputFolder,locFile);
    FILE* tempFile = fopen(inputFile.TabWord, "r");
    if (tempFile == NULL)
    {
        printf("Name file tidak ada.\n");
    }
    else
    {
        printf("Name file ada.\n");
        muatPenggunaNew(inputFile, datauser,matrikstemen);

        writeWord(&locFile,"/kicauan.config", 15);
        inputFile = writefilename(inputFolder,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        muatKicauanNew(inputFile,tabkicauan);

        printf("Mohon tunggu...\n");

        writeWord(&locFile,"/balasan.config", 15);
        inputFile = writefilename(inputFolder,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        muatBalasanNew(inputFile,*datauser);

        printf("1...\n");

        writeWord(&locFile,"/draf.config", 12);
        inputFile = writefilename(inputFolder,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        muatDrafNew(inputFile,*datauser);

        printf("2...\n");

        writeWord(&locFile,"/utas.config", 12);
        inputFile = writefilename(inputFolder,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        muatUtasNew(inputFile,datautas);

        printf("3...\n");
        printf("Pemuatan selesai!\n");

        printf("\n");
        printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
    }

    statusProgram = true;
}