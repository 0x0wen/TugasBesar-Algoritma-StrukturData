#include "../global.h"


void inisialisasi(TabPengguna* datauser, AdjacencyMatrix* matrikstemen, TabKicauan* tabkicauan, TabUtas* datautas)
{
    printf("/$$$$$$$                      /$$       /$$           \n");
    printf("| $$__  $$                    | $$      |__/          \n");
    printf("| $$  \\ $$ /$$   /$$  /$$$$$$ | $$$$$$$  /$$  /$$$$$$ \n");
    printf("| $$$$$$$ | $$  | $$ /$$__  $$| $$__  $$| $$ /$$__  $$\n");
    printf("| $$__  $$| $$  | $$| $$  \\__/| $$  \\ $$| $$| $$  \\__/\n");
    printf("| $$  \\ $$| $$  | $$| $$      | $$  | $$| $$| $$      \n");
    printf("| $$$$$$$/|  $$$$$$/| $$      | $$$$$$$/| $$| $$      \n");
    printf("|_______/  \\______/ |__/      |_______/ |__/|__/      \n");
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
        // muatPenggunaNew(inputFile, *datauser,*matrikstemen);
        printf("Maaf sedang ada masalah pada pemuatan.\n");


        simpan(*datauser,*matrikstemen,*tabkicauan,*datautas);
        // writeWord(&locFile,"/kicauan.config", 15);
        // inputFile = writefilename(inputFolder,locFile);
        // tempFile = fopen(inputFile.TabWord, "r");
        // muatKicauanNew(inputFile,tabkicauan);
        // printf("Name file ada.\n");

        // writeWord(&locFile,"/balasan.config", 15);
        // inputFile = writefilename(inputFolder,locFile);
        // tempFile = fopen(inputFile.TabWord, "r");
        // muatBalasanNew(inputFile,datauser);
        // printf("Name file ada.\n");

        // writeWord(&locFile,"/draf.config", 12);
        // inputFile = writefilename(inputFolder,locFile);
        // tempFile = fopen(inputFile.TabWord, "r");
        // muatDrafNew(inputFile,*datauser);
        // printf("Name file ada.\n");

        // writeWord(&locFile,"/utas.config", 12);
        // inputFile = writefilename(inputFolder,locFile);
        // tempFile = fopen(inputFile.TabWord, "r");
        // muatUtasNew(inputFile,datautas);
        // printf("Name file ada.\n");

        printf("\n");
        printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
    }

    statusProgram = true;
}