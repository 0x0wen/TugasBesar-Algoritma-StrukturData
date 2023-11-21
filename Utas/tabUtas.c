#include <stdio.h>
#include "tabUtas.h"
void createTabUtas(int capacity)
{
    CAPACITY_UTAS(dataUtas) = capacity;
    NEFF_UTAS(dataUtas) = 0;
    BUFFER_UTAS(dataUtas) = (Utas *)malloc(capacity * sizeof(Utas));
};

void deallocateTabUtas()
{
    free(BUFFER_UTAS(dataUtas));
    CAPACITY_UTAS(dataUtas) = 0;
    NEFF_UTAS(dataUtas) = 0;
};

int lengthTabUtas()
{
    return NEFF_UTAS(dataUtas);
};

boolean isIdxTabUtasValid(IdxType i)
{
    return (i < (CAPACITY_UTAS(dataUtas)) && i >= IDX_MIN);
};

boolean isIdxTabUtasEff(IdxType i)
{
    return (i < (NEFF_UTAS(dataUtas)) && i >= IDX_MIN);
};

boolean isTabUtasEmpty()
{
    return (NEFF_UTAS(dataUtas) == 0);
};

boolean isTabUtasFull()
{
    return (NEFF_UTAS(dataUtas) == CAPACITY_UTAS(dataUtas));
};

IdxType indexOfTabUtas(Utas utas)
{
    int i;
    for (i = IDX_MIN; i < NEFF_UTAS(dataUtas); i++)
    {
        if (SELECT_UTAS(dataUtas, i).IDKicau == utas.IDKicau)
        {
            return i;
        }
    }
    return IDX_UNDEF;
};

void insertLastTabUtas(Utas val)
{
    SELECT_UTAS(dataUtas, NEFF_UTAS(dataUtas)) = val;
    NEFF_UTAS(dataUtas) += 1;
};

void deleteLastTabUtas(Utas *val)
{
    *val = SELECT_UTAS(dataUtas, NEFF_UTAS(dataUtas) - 1);
    NEFF_UTAS(dataUtas) -= 1;
};

void copyTabUtas(TabUtas lIn, TabUtas *lOut)
{
    int i;
    createTabUtas(lOut, CAPACITY(lIn));
    for (i = 0; i < NEFF(lIn); i++)
    {
        SELECT_UTAS(*lOut, i) = SELECT_UTAS(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
};

Utas cariUtas(int IDUtas)
{
    int i;
    Utas utas;
    for (i = 0; i < lengthTabUtas(dataUtas); i++)
    {
        if (ID_UTAS(SELECT_UTAS(dataUtas, i)) == IDUtas)
        {
            utas = SELECT_UTAS(dataUtas, i);
            break;
        }
    }
    return utas;
};

void expandTabUtas(int num)
{
    ListDinUtas L;
    int cap1, nEff1, i;

    copyTabUtas(dataUtas, &L);
    cap1 = CAPACITY_UTAS(dataUtas) + num;
    nEff1 = NEFF_UTAS(dataUtas);

    deallocateTabUtas(dataUtas);

    createTabUtas(&dataUtas, cap1);
    NEFF_UTAS(dataUtas) = nEff1;

    for (i = 0; i < lengthTabUtas(dataUtas); i++)
    {
        SELECT_UTAS(dataUtas, i) = SELECT_UTAS(L, i);
    }
    deallocateTabUtas(&L);
};
