#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m)
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j)
{
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m)
{
    return (ROW_EFF(m) - 1);
}

IdxType getLastIdxCol(Matrix m)
{
    return (COL_EFF(m) - 1);
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j)
{
    return (i >= 0 && i <= ROW_EFF(m) - 1 && j >= 0 && j <= COL_EFF(m) - 1);
}

ElType getElmtDiagonal(Matrix m, IdxType i)
{
    return (ELMT(m, i, i));
}

void copyMatrix(Matrix mIn, Matrix *mOut)
{
    int i, j;
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for (i = 0; i < ROW_EFF(mIn); i++)
    {
        for (j = 0; j < COL_EFF(mIn); j++)
        {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol)
{
    int i, j;
    createMatrix(nRow, nCol, m);
    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m)
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

Matrix addMatrix(Matrix m1, Matrix m2)
{
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m);
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

Matrix subtractMatrix(Matrix m1, Matrix m2)
{
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m);
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

Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
    Matrix m;
    int i, j, k;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
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

Matrix multiplyMatrixWithMod(Matrix m1, Matrix m2, int mod)
{
    Matrix m;
    int i, j, k;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
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

Matrix multiplyByConst(Matrix m, ElType x)
{
    Matrix m1;
    int i, j;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            ELMT(m1, i, j) = ELMT(m, i, j) * x;
        }
    }
    return m1;
}

void pMultiplyByConst(Matrix *m, ElType k)
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

boolean isMatrixEqual(Matrix m1, Matrix m2)
{
    if (!isMatrixSizeEqual(m1, m2) || countElmt(m1) != countElmt(m2))
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

boolean isMatrixNotEqual(Matrix m1, Matrix m2)
{
    return (!isMatrixEqual(m1, m2));
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

int countElmt(Matrix m)
{
    return (ROW_EFF(m) * COL_EFF(m));
}

boolean isSquare(Matrix m)
{
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(Matrix m)
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

boolean isIdentity(Matrix m)
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

boolean isSparse(Matrix m)
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

Matrix negation(Matrix m)
{
    return multiplyByConst(m, (-1));
}

void pNegation(Matrix *m)
{
    pMultiplyByConst(m, -1);
}

float determinant(Matrix m)
{
    int i, j, k, p, var = 1;
    Matrix mFac;
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
        createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &mFac);
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

Matrix transpose(Matrix m)
{
    Matrix m1;
    int i, j;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            ELMT(m1, i, j) = ELMT(m, j, i);
        }
    }
    return m1;
}

void pTranspose(Matrix *m)
{
    Matrix m1;
    m1 = transpose(*m);
    copyMatrix(m1, m);
}