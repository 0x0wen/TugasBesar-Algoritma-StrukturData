#include <stdio.h>
#include "../General/wordmachinefile.c"
#include "../Pengguna/pengguna.h"
#include "../General/sentenceMachine.h"
#include "../global.h"

Word writefilename(Word input1, Word input2)
{
    Word output;
    int i;
    for (i = 0; i < input1.Length; i++)
    {
        output.TabWord[i] = input1.TabWord[i];
    }
    for (i = 0; i < input2.Length; i++)
    {
        output.TabWord[input1.Length + i] = input2.TabWord[i];
    }
    output.TabWord[input1.Length + input2.Length] = '\0';
    output.Length = input1.Length + input2.Length;

    return output;
}

int compareCharArrays(const char *array1, const char *array2)
{
    int result = strcmp(array1, array2);
    return result;
}
#include "Alstrukdat\Tubes\Alstrokedat\ADT\sentenceMachine.h"
#include "Alstrukdat\Tubes\Alstrokedat\global.h"
#include "Alstrukdat\Tubes\Alstrokedat\muatsimpan\muat.c"

void inisialisasi()
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

    Word config, locFile;
    writeWord(&locFile, "/pengguna.config", 16);
    InputWord(&config);
    Word inputFile = writefilename(config, locFile);

    FILE *tempFile = fopen(inputFile.TabWord, "r");
    if (tempFile == NULL)
    {
        printf("Name file tidak ada.\n");
    }
    else
    {
        printf("Name file ada.\n");
        // Baca pengguna config
        int jmlUser = muatPengguna(inputFile);

        // Baca konfig kicauan
        writeWord(&locFile, "/kicauan.config", 15);
        inputFile = writefilename(config, locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        int jmlKicau = muatKicauan(inputFile);

        // Baca konfig balasan
        writeWord(&locFile, "/balasan.config", 15);
        inputFile = writefilename(config, locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        muatBalasan(inputFile,jmlKicau);

        writeWord(&locFile, "/draf.config", 12);
        inputFile = writefilename(config, locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        muatDraf(inputFile, jmlKicau);

        writeWord(&locFile, "/utas.config", 12);
        inputFile = writefilename(config, locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        muatUtas(inputFile,jmlKicau);

        printf("\n");
        printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
    }

    statusProgram = true;
}