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

    // Word config, locFile;
    // writeWord(&locFile, "/pengguna.config", 16);
    // InputWord(&config);
    // Word inputFile = writefilename(config, locFile);

    // FILE *tempFile = fopen(inputFile.TabWord, "r");
    // if (tempFile == NULL)
    // {
    //     printf("Name file tidak ada.\n");
    // }
    // else
    // {
    //     printf("Name file ada.\n");
    //     muatPenggunaNew(inputFile,&dataPengguna);

    //     writeWord(&locFile,"/kicauan.config", 15);
    //     inputFile = writefilename(inputFolder,locFile);
    //     tempFile = fopen(inputFile.TabWord, "r");
    //     muatKicauanNew(inputFile,&dataKicau);

    //     writeWord(&locFile,"/balasan.config", 15);
    //     inputFile = writefilename(inputFolder,locFile);
    //     tempFile = fopen(inputFile.TabWord, "r");
    //     muatBalasanNew(inputFile,dataPengguna);

    //     printf("\n");
    //     printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
    // }

    statusProgram = true;
}