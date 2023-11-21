#include "fotoProfil.h"
#include <stdio.h>
#include <stdlib.h>


/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

#include <stdio.h>
#include "pcolor.h"

void print_red(char c)
{
    printf("%s%c", RED, c);
    printf("%s", NORMAL);
}

void print_green(char c)
{
    printf("%s%c", GREEN, c);
    printf("%s", NORMAL);
}

void print_blue(char c)
{
    printf("%s%c", BLUE, c);
    printf("%s", NORMAL);
}

void createFotoProfil(int nRows, int nCols, FotoProfil *m)
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isFotoProfilIdxValid(int i, int j)
{
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

int getLastIdxRow(FotoProfil m)
{
    return (ROW_EFF(m) - 1);
}

int getLastIdxCol(FotoProfil m)
{
    return (COL_EFF(m) - 1);
}

boolean isIdxEff(FotoProfil m, int i, int j)
{
    return (i >= 0 && i <= ROW_EFF(m) - 1 && j >= 0 && j <= COL_EFF(m) - 1);
}

ElType getElmtDiagonal(FotoProfil m, int i)
{
    return (ELMT(m, i, i));
}

void copyFotoProfil(FotoProfil mIn, FotoProfil *mOut)
{
    int i, j;
    createFotoProfil(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for (i = 0; i < ROW_EFF(mIn); i++)
    {
        for (j = 0; j < COL_EFF(mIn); j++)
        {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

void readFotoProfil(FotoProfil *m, int nRow, int nCol)
{
    int i, j;
    createFotoProfil(nRow, nCol, m);
    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayFotoProfil(FotoProfil m)
{
    int nRow = ROW_EFF(m);
    int nCol = COL_EFF(m);
    int i, j;

    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol - 1; j++)
        {
            printf("%d ", ELMT(m, i, j));
        }
        printf("%d", ELMT(m, i, nCol - 1));
        printf("\n");
    }
}

FotoProfil addFotoProfil(FotoProfil m1, FotoProfil m2)
{
    FotoProfil m;
    createFotoProfil(ROW_EFF(m1), COL_EFF(m1), &m);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            ELMT(m, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m;
}

FotoProfil subtractFotoProfil(FotoProfil m1, FotoProfil m2)
{
    FotoProfil m;
    createFotoProfil(ROW_EFF(m1), COL_EFF(m1), &m);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            ELMT(m, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m;
}

FotoProfil multiplyFotoProfil(FotoProfil m1, FotoProfil m2)
{
    FotoProfil m;
    int i, j, k;
    createFotoProfil(ROW_EFF(m1), COL_EFF(m2), &m);
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m2); j++)
        {
            ELMT(m, i, j) = 0;
            for (k = 0; k < COL_EFF(m1); k++)
            {
                ELMT(m, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return m;
}

FotoProfil multiplyFotoProfilWithMod(FotoProfil m1, FotoProfil m2, int mod)
{
    FotoProfil m;
    int i, j, k;
    createFotoProfil(ROW_EFF(m1), COL_EFF(m2), &m);
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m2); j++)
        {
            ELMT(m, i, j) = 0;
            for (k = 0; k < COL_EFF(m1); k++)
            {
                ELMT(m, i, j) += (ELMT(m1, i, k) * ELMT(m2, k, j));
                ELMT(m, i, j) %= mod;
            }
        }
    }
    return m;
}

FotoProfil multiplyByConst(FotoProfil m, ElType x)
{
    FotoProfil m1;
    int i, j;
    createFotoProfil(ROW_EFF(m), COL_EFF(m), &m1);
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            ELMT(m1, i, j) = ELMT(m, i, j) * x;
        }
    }
    return m1;
}

void pMultiplyByConst(FotoProfil *m, ElType k)
{
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(*m, i, j) = ELMT(*m, i, j) * k;
        }
    }
}

boolean isFotoProfilEqual(FotoProfil m1, FotoProfil m2)
{
    if (!isFotoProfilSizeEqual(m1, m2) || countElmt(m1) != countElmt(m2))
    {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            if (ELMT(m1, i, j) != ELMT(m2, i, j))
            {
                return false;
            }
        }
    }
    return true;
}

boolean isFotoProfilNotEqual(FotoProfil m1, FotoProfil m2)
{
    return (!isFotoProfilEqual(m1, m2));
}

boolean isFotoProfilSizeEqual(FotoProfil m1, FotoProfil m2)
{
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

int countElmt(FotoProfil m)
{
    return (ROW_EFF(m) * COL_EFF(m));
}

boolean isSquare(FotoProfil m)
{
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(FotoProfil m)
{
    if (!isSquare(m))
    {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != ELMT(m, j, i))
            {
                return false;
            }
        }
    }
    return true;
}

boolean isIdentity(FotoProfil m)
{
    if (!isSquare(m))
    {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (i == j)
            {
                if (ELMT(m, i, j) != 1)
                {
                    return false;
                }
            }
            else
            {
                if (ELMT(m, i, j) != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

boolean isSparse(FotoProfil m)
{
    int i, j, count = 0;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                count++;
            }
        }
    }
    return (count <= (0.05 * countElmt(m)));
}

FotoProfil negation(FotoProfil m)
{
    return multiplyByConst(m, (-1));
}

void pNegation(FotoProfil *m)
{
    pMultiplyByConst(m, -1);
}

float determinant(FotoProfil m)
{
    int i, j, k, p, var = 1;
    FotoProfil mFac;
    float det;
    if (countElmt(m) == 1)
    {
        det = (float)ELMT(m, 0, 0);
    }
    else if (countElmt(m) == 4)
    {
        det = (ELMT(m, 0, 0) * ELMT(m, 1, 1)) - (ELMT(m, 1, 0) * ELMT(m, 0, 1));
        det = (float)(det);
    }
    else
    {
        createFotoProfil(ROW_EFF(m) - 1, COL_EFF(m) - 1, &mFac);
        det = 0;
        for (i = 0; i < ROW_EFF(m); i++)
        {
            for (j = 1; j < ROW_EFF(m); j++)
            {
                for (k = 0; k < COL_EFF(m); k++)
                {
                    if (k == i)
                    {
                        continue;
                    }
                    else if (k < i)
                    {
                        p = k;
                    }
                    else
                    {
                        p = k - 1;
                    }
                    ELMT(mFac, j - 1, p) = ELMT(m, j, k);
                }
            }
            det += var * ELMT(m, 0, i) * determinant(mFac);
            var *= -1;
        }
    }
    return det;
}

FotoProfil transpose(FotoProfil m)
{
    FotoProfil m1;
    int i, j;
    createFotoProfil(ROW_EFF(m), COL_EFF(m), &m1);
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            ELMT(m1, i, j) = ELMT(m, j, i);
        }
    }
    return m1;
}

void pTranspose(FotoProfil *m)
{
    FotoProfil m1;
    m1 = transpose(*m);
    copyFotoProfil(m1, m);
}