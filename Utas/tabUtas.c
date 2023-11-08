#include <stdio.h>
#include "tabUtas.h"
void createTabUtas(int capacity)
{
    CAPACITY(dataUtas) = capacity;
    NEFF(dataUtas) = 0;
    BUFFER(dataUtas) = (ElType *)malloc(capacity * sizeof(ElType));
};

void deallocateTabUtas()
{
    free(BUFFER(dataUtas));
    CAPACITY(dataUtas) = 0;
    NEFF(dataUtas) = 0;
};

int lengthTabUtas()
{
    return NEFF(dataUtas);
};

boolean isIdxTabUtasValid(IdxType i)
{
    return (i < (CAPACITY(dataUtas)) && i >= IDX_MIN);
};

boolean isIdxTabUtasEff(IdxType i)
{
    return (i < (NEFF(dataUtas)) && i >= IDX_MIN);
};

boolean isTabUtasEmpty()
{
    return (NEFF(dataUtas) == 0);
};

boolean isTabUtasFull()
{
    return (NEFF(dataUtas) == CAPACITY(dataUtas));
};

IdxType indexOfTabUtas(ElType utas)
{
    int i;
    for (i = IDX_MIN; i < NEFF(dataUtas); i++)
    {
        if (ELMT(dataUtas, i).IDKicau == utas.IDKicau)
        {
            return i;
        }
    }
    return IDX_UNDEF;
};

void insertLastTabUtas(ElType val)
{
    ELMT(dataUtas, NEFF(dataUtas)) = val;
    NEFF(dataUtas) += 1;
};

void deleteLastTabUtas(ElType *val)
{
    *val = ELMT(dataUtas, NEFF(dataUtas) - 1);
    NEFF(dataUtas) -= 1;
};

void copyTabUtas(TabUtas lIn, TabUtas *lOut)
{
    int i;
    createTabUtas(lOut, CAPACITY(lIn));
    for (i = 0; i < NEFF(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
};

void expandTabUtas(int num)
{
    ListDinUtas L;
    int cap1, nEff1, i;

    copyTabUtas(dataUtas, &L);
    cap1 = CAPACITY(dataUtas) + num;
    nEff1 = NEFF(dataUtas);

    deallocateTabUtas(dataUtas);

    createTabUtas(&dataUtas, cap1);
    NEFF(dataUtas) = nEff1;

    for (i = 0; i < lengthTabUtas(dataUtas); i++)
    {
        ELMT(dataUtas, i) = ELMT(L, i);
    }
    deallocateTabUtas(&L);
};
