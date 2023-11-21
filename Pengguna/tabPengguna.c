#include "tabPengguna.h"
#include <stdio.h>

TabPengguna anjay;
void createTabPengguna(TabPengguna *T)
{
    for (IdxType i = IDX_MIN; i < CAPACITY; i++)
    {
        SelectPengguna(dataPengguna, i) = MARK;
    }
}

int lengthTabPengguna()
{
    IdxType i = IDX_MIN;
    while (i < CAPACITY && SelectPengguna(dataPengguna, i) != MARK)
    {
        i++;
    }
    return i;
}

IdxType getFirstIdxTabPengguna()
{
    return IDX_MIN;
}

IdxType getLastIdxTabPengguna()
{
    IdxType i = listLength(dataPengguna);
    return (i > 0) ? i - 1 : IDX_UNDEF;
}

boolean isIdxValidTabPengguna(IdxType i)
{
    return (i >= IDX_MIN) && (i < CAPACITY);
}

boolean isIdxEffTabPengguna(IdxType i)
{
    return (i >= IDX_MIN) && (i <= getLastIdx(dataPengguna));
}

boolean isTabPenggunaEmpty()
{
    return listLength(dataPengguna) == 0;
}

boolean isTabPenggunaFull()
{
    return listLength(dataPengguna) == CAPACITY;
}

void printTabPengguna()
{
    printf("[");
    IdxType i = getFirstIdx(dataPengguna);
    while (i <= getLastIdx(dataPengguna))
    {
        printf("%d", SelectPengguna(dataPengguna, i));
        if (i < getLastIdx(dataPengguna))
        {
            printf(",");
        }
        i++;
    }
    printf("]\n");
}

int indexOfTabPengguna(Pengguna val)
{
    IdxType i = getFirstIdx(dataPengguna);
    while (i <= getLastIdx(dataPengguna))
    {
        if (SelectPengguna(dataPengguna, i) == val)
        {
            return i;
        }
        i++;
    }
    return IDX_UNDEF;
}

void insertFirstTabPengguna(Pengguna val)
{
    if (!isFull(dataPengguna))
    {
        IdxType last = getLastIdx(dataPengguna);
        for (IdxType i = last; i >= getFirstIdx(dataPengguna); i--)
        {
            SelectPengguna(dataPengguna, i + 1) = SelectPengguna(dataPengguna, i);
        }
        SelectPengguna(dataPengguna, getFirstIdx(dataPengguna)) = val;
    }
}

void insertAtTabPengguna(Pengguna val, IdxType idx)
{
    if (!isFull(dataPengguna) && isIdxEffTabPengguna(idx))
    {
        IdxType last = getLastIdx(dataPengguna);
        for (IdxType i = last; i >= idx; i--)
        {
            SelectPengguna(dataPengguna, i + 1) = SelectPengguna(dataPengguna, i);
        }
        SelectPengguna(dataPengguna, idx) = val;
    }
}

void insertLastTabPengguna(Pengguna val)
{
    if (!isFull(dataPengguna))
    {
        IdxType last = getLastIdx(dataPengguna);
        SelectPengguna(dataPengguna, last + 1) = val;
    }
}

void deleteFirstTabPengguna(Pengguna *val)
{
    if (!isEmpty(dataPengguna))
    {
        *val = SelectPengguna(dataPengguna, getFirstIdx(dataPengguna));
        IdxType last = getLastIdx(dataPengguna);
        for (IdxType i = getFirstIdx(dataPengguna); i < last; i++)
        {
            SelectPengguna(dataPengguna, i) = SelectPengguna(dataPengguna, i + 1);
        }
        SelectPengguna(dataPengguna, last) = MARK;
    }
}

void deleteAtTabPengguna(Pengguna *val, IdxType idx)
{
    if (!isEmpty(dataPengguna) && isIdxEffTabPengguna(dataPengguna, idx))
    {
        *val = SelectPengguna(dataPengguna, idx);
        IdxType last = getLastIdx(dataPengguna);
        for (IdxType i = idx; i < last; i++)
        {
            SelectPengguna(dataPengguna, i) = SelectPengguna(dataPengguna, i + 1);
        }
        SelectPengguna(dataPengguna, last) = MARK;
    }
}

void deleteLastTabPengguna(Pengguna *val)
{
    if (!isEmpty(dataPengguna))
    {
        IdxType last = getLastIdx(dataPengguna);
        *val = SelectPengguna(dataPengguna, last);
        SelectPengguna(dataPengguna, last) = MARK;
    }
}

void sortTabPengguna(boolean asc)
{
    if (!isEmpty(dataPengguna))
    {
        IdxType n = listLength(dataPengguna);
        Pengguna temp;

        for (IdxType i = 0; i < n - 1; i++)
        {
            for (IdxType j = 0; j < n - i - 1; j++)
            {
                if ((asc && SelectPengguna(dataPengguna, j) > SelectPengguna(dataPengguna, j + 1)) ||
                    (!asc && SelectPengguna(dataPengguna, i) < SelectPengguna(dataPengguna, j + 1)))
                {
                    temp = SelectPengguna(dataPengguna, j);
                    SelectPengguna(dataPengguna, j) = SelectPengguna(dataPengguna, j + 1);
                    SelectPengguna(dataPengguna, j + 1) = temp;
                }
            }
        }
    }
}