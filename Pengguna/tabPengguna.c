#include "tabPengguna.h"
#include <stdio.h>

void createTabPengguna(TabPengguna *T)
{
    for (int i = IDX_MIN; i < CAPACITYPENGGUNA; i++)
    {
        ID_PENGGUNA(SELECT_PENGGUNA(dataPengguna, i)) = IDX_UNDEF_TAB_PENGGUNA;
    }
}

int lengthTabPengguna(TabPengguna T)
{
    int i = IDX_MIN;
    while (i < CAPACITYPENGGUNA && ID_PENGGUNA(SELECT_PENGGUNA(T, i)) != IDX_UNDEF_TAB_PENGGUNA)
    {
        i++;
    }
    return i;
}

boolean isIdxEffTabPengguna(int i)
{
    return (i >= IDX_MIN) && (i <= getLastIdxTabPengguna(dataPengguna));
}

boolean isTabPenggunaEmpty()
{
    return lengthTabPengguna(dataPengguna) == 0;
}

boolean isTabPenggunaFull()
{
    return lengthTabPengguna(dataPengguna) == CAPACITYPENGGUNA;
}

void printTabPengguna()
{
    printf("[");
    int i = getFirstIdxTabPengguna(dataPengguna);
    while (i <= getLastIdxTabPengguna(dataPengguna))
    {
        printf("%d", SELECT_PENGGUNA(dataPengguna, i));
        if (i < getLastIdxTabPengguna(dataPengguna))
        {
            printf(",");
        }
        i++;
    }
    printf("]\n");
}

int indexOfTabPengguna(Pengguna val)
{
    int i = getFirstIdxTabPengguna(dataPengguna);
    while (i <= getLastIdxTabPengguna(dataPengguna))
    {
        if (SELECT_PENGGUNA(dataPengguna, i) == val)
        {
            return i;
        }
        i++;
    }
    return IDX_UNDEF_TAB_PENGGUNA;
}

void insertFirstTabPengguna(Pengguna val)
{
    if (!isFull(dataPengguna))
    {
        int last = getLastIdxTabPengguna(dataPengguna);
        for (int i = last; i >= getFirstIdxTabPengguna(dataPengguna); i--)
        {
            SELECT_PENGGUNA(dataPengguna, i + 1) = SELECT_PENGGUNA(dataPengguna, i);
        }
        SELECT_PENGGUNA(dataPengguna, getFirstIdxTabPengguna(dataPengguna)) = val;
    }
}

void insertAtTabPengguna(Pengguna val, int idx)
{
    if (!isFull(dataPengguna) && isIdxEffTabPengguna(idx))
    {
        int last = getLastIdxTabPengguna(dataPengguna);
        for (int i = last; i >= idx; i--)
        {
            SELECT_PENGGUNA(dataPengguna, i + 1) = SELECT_PENGGUNA(dataPengguna, i);
        }
        SELECT_PENGGUNA(dataPengguna, idx) = val;
    }
}

void insertLastTabPengguna(Pengguna val)
{
    if (!isFull(dataPengguna))
    {
        int last = getLastIdxTabPengguna(dataPengguna);
        SELECT_PENGGUNA(dataPengguna, last + 1) = val;
    }
}

void deleteFirstTabPengguna(Pengguna *val)
{
    if (!isTabPenggunaEmpty(dataPengguna))
    {
        *val = SELECT_PENGGUNA(dataPengguna, getFirstIdxTabPengguna(dataPengguna));
        int last = getLastIdxTabPengguna(dataPengguna);
        for (int i = getFirstIdxTabPengguna(dataPengguna); i < last; i++)
        {
            SELECT_PENGGUNA(dataPengguna, i) = SELECT_PENGGUNA(dataPengguna, i + 1);
        }
        SELECT_PENGGUNA(dataPengguna, last) = MARK;
    }
}

void deleteAtTabPengguna(Pengguna *val, int idx)
{
    if (!isTabPenggunaEmpty(dataPengguna) && isIdxEffTabPengguna(dataPengguna, idx))
    {
        *val = SELECT_PENGGUNA(dataPengguna, idx);
        int last = getLastIdxTabPengguna(dataPengguna);
        for (int i = idx; i < last; i++)
        {
            SELECT_PENGGUNA(dataPengguna, i) = SELECT_PENGGUNA(dataPengguna, i + 1);
        }
        SELECT_PENGGUNA(dataPengguna, last) = MARK;
    }
}

void deleteLastTabPengguna(TabPengguna *T, Pengguna *val)
{
    if (!isTabPenggunaEmpty(*T))
    {
        int last = getLastIdxTabPengguna(*T);
        *val = SELECT_PENGGUNA(*T, last);
        ID_PENGGUNA(SELECT_PENGGUNA(*T, last)) = IDX_UNDEF_TAB_PENGGUNA;
    }
}

boolean checkUsernameExist(TabPengguna T, Sentence username, int numUsers)
{
    // Mengecek apakah pengguna ada dalam array TabPengguna

    boolean found = false;

    for (int i = 0; i < numUsers; ++i)
    {
        // Misalnya, anggaplah username disimpan dalam atribut tertentu dari Pengguna
        // Gantilah dengan atribut sebenarnya yang menyimpan username di dalam Pengguna
        if (IsSentenceEqual(NAMA_PENGGUNA(SELECT_PENGGUNA(T, i)), username))
        {
            found = true;
            break;
        }
    }

    return found;
}
boolean checkPassword(TabPengguna T, Sentence password, int numUsers)
{
    // Mengecek apakah password ada dalam array contents

    boolean found = false;

    for (int i = 0; i < numUsers; ++i)
    {
        // Misalnya, anggaplah password disimpan dalam atribut tertentu dari Pengguna
        // Gantilah dengan atribut sebenarnya yang menyimpan password di dalam Pengguna
        if (IsSentenceEqual(PASSWORD_PENGGUNA(SELECT_PENGGUNA(T, i)), password))
        {
            found = true;
            break;
        }
    }

    return found;
}