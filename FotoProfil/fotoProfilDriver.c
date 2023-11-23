/**
Filename: pcolor_driver.c (driver of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

#include <stdio.h>
#include "fotoProfil.h"
#include "fotoProfil.c"

int main()
{
    print_red('R');
    print_green('G');
    print_blue('B');
    printf("\n");

    FotoProfil F;
    createFotoProfil(5, 10, &F);

    if (isFotoProfilIdxValid(5, 10))
        printf("Foto profil valid\n");
    else
        printf("Foto profil tidak valid\n");

    printf("LastIdxRow: %d\n", getLastIdxRow(F));
    printf("LastIdxCol: %d\n", getLastIdxCol(F));

    if (isIdxEff(F, 4, 9))
        printf("Index valid\n");
    else
        printf("Index tidak valid\n");

    printf("ElmtDiagonal: %d\n", getElmtDiagonal(F, 4));

    printf("\nMasukkan foto profil:\n");
    readFotoProfil(&F, 5, 10);

    printf("\nFoto profil:\n");
    displayFotoProfil(F);

    return 0;
}
