#include "../global.h"
void createTabUtas(TabUtas *TU, int capacity)
{
    CAPACITY_UTAS(*TU) = capacity;
    NEFF_UTAS(*TU) = 0;
    BUFFER_UTAS(*TU) = (Utas *)malloc(capacity * sizeof(Utas));
}

void deallocateTabUtas(TabUtas *TU)
{
    free(BUFFER_UTAS(*TU));
    CAPACITY_UTAS(*TU) = 0;
    NEFF_UTAS(*TU) = 0;
}

int lengthTabUtas(TabUtas TU)
{
    return NEFF_UTAS(TU);
}

boolean isIdxTabUtasValid(TabUtas TU, int i)
{
    return (i < (CAPACITY_UTAS(TU)) && i >= IDX_MIN_TAB_UTAS);
}

boolean isIdxTabUtasEff(TabUtas TU, int i)
{
    return (i < (NEFF_UTAS(TU)) && i >= IDX_MIN_TAB_UTAS);
}

boolean isTabUtasEmpty(TabUtas TU)
{
    return (NEFF_UTAS(TU) == 0);
}

boolean isTabUtasFull(TabUtas TU)
{
    return (NEFF_UTAS(TU) == CAPACITY_UTAS(TU));
}

int indexOfTabUtas(TabUtas TU, Utas utas)
{
    int i;
    for (i = IDX_MIN_TAB_UTAS; i < NEFF_UTAS(TU); i++)
    {
        if (SELECT_UTAS(TU, i).IDKicau == ID_KICAU_UTAS(utas))
        {
            return i;
        }
    }
    return IDX_UNDEF_TAB_UTAS;
}
void insertLastTabUtas(TabUtas *TU, Utas val)
{
    SELECT_UTAS(*TU, NEFF_UTAS(*TU)) = val;
    NEFF_UTAS(*TU) += 1;
}

void deleteLastTabUtas(TabUtas *TU)
{
    NEFF_UTAS(*TU) -= 1;
}

void copyTabUtas(TabUtas lIn, TabUtas *lOut)
{
    int i;
    createTabUtas(lOut, CAPACITY_UTAS(lIn));
    for (i = 0; i < NEFF_UTAS(lIn); i++)
    {
        SELECT_UTAS(*lOut, i) = SELECT_UTAS(lIn, i);
    }
    NEFF_UTAS(*lOut) = NEFF_UTAS(lIn);
}

Utas *searchUtas(TabUtas TU, int IDUtas)
{
    int i;
    for (i = 0; i < lengthTabUtas(TU); i++)
    {
        if (ID_UTAS(SELECT_UTAS(TU, i)) == IDUtas)
        {
            return &SELECT_UTAS(TU, i);
        }
    }
    return NULL;
}

void expandTabUtas(TabUtas *TU, int num)
{
    TabUtas L;
    int cap1, nEff1, i;

    copyTabUtas(*TU, &L);
    cap1 = CAPACITY_UTAS(*TU) + num;
    nEff1 = NEFF_UTAS(*TU);

    deallocateTabUtas(TU);

    createTabUtas(TU, cap1);
    NEFF_UTAS(*TU) = nEff1;

    for (i = 0; i < lengthTabUtas(*TU); i++)
    {
        SELECT_UTAS(*TU, i) = SELECT_UTAS(L, i);
    }
    deallocateTabUtas(&L);
}
