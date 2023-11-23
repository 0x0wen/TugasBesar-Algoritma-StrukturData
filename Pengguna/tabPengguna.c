#include "tabPengguna.h"
#include <stdio.h>

void createTabPengguna(TabPengguna *T)
{
    for (int i = IDX_MIN; i < CAPACITYPENGGUNA; i++)
    {
        ID_PENGGUNA(SELECT_PENGGUNA(*T, i)) = IDX_UNDEF_TAB_PENGGUNA;
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

boolean isIdxEffTabPengguna(TabPengguna T, int i)
{
    return (i >= IDX_MIN) && (i <= getLastIdxTabPengguna(T));
}

boolean isTabPenggunaEmpty(TabPengguna T)
{
    return lengthTabPengguna(T) == 0;
}

boolean isTabPenggunaFull(TabPengguna T)
{
    return lengthTabPengguna(T) == CAPACITYPENGGUNA;
}

void printTabPengguna(TabPengguna T)
{
    printf("[");
    int i = getFirstIdxTabPengguna(T);
    while (i <= getLastIdxTabPengguna(T))
    {
        printf("%d", SELECT_PENGGUNA(T, i));
        if (i < getLastIdxTabPengguna(T))
        {
            printf(",");
        }
        i++;
    }
    printf("]\n");
}

int indexOfTabPengguna(TabPengguna T, Pengguna val)
{
    int i = getFirstIdxTabPengguna(T);
    while (i <= getLastIdxTabPengguna(T))
    {
        if (ID_PENGGUNA(SELECT_PENGGUNA(T, i)) == ID_PENGGUNA(val))
        {
            return i;
        }
        i++;
    }
    return IDX_UNDEF_TAB_PENGGUNA;
}

void insertFirstTabPengguna(TabPengguna *T, Pengguna val)
{
    if (!isTabPenggunaFull(*T))
    {
        int last = getLastIdxTabPengguna(*T);
        for (int i = last; i >= getFirstIdxTabPengguna(*T); i--)
        {
            SELECT_PENGGUNA(*T, i + 1) = SELECT_PENGGUNA(*T, i);
        }
        SELECT_PENGGUNA(*T, getFirstIdxTabPengguna(*T)) = val;
    }
}

void insertAtTabPengguna(TabPengguna *T, Pengguna val, int idx)
{
    if (!isTabPenggunaFull(*T) && isIdxEffTabPengguna(*T, idx))
    {
        int last = getLastIdxTabPengguna(*T);
        for (int i = last; i >= idx; i--)
        {
            SELECT_PENGGUNA(*T, i + 1) = SELECT_PENGGUNA(*T, i);
        }
        SELECT_PENGGUNA(*T, idx) = val;
    }
}

void insertLastTabPengguna(TabPengguna *T, Pengguna val)
{
    if (!isTabPenggunaFull(*T))
    {
        int last = getLastIdxTabPengguna(*T);
        SELECT_PENGGUNA(*T, last + 1) = val;
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

Pengguna *searchPenggunaByName(TabPengguna T, Sentence username)
{
    int i = 0;
    while (i < CAPACITYPENGGUNA && !IsSentenceEqual(NAMA_PENGGUNA(SELECT_PENGGUNA(T, i)), username))
    {
        i++;
    }
    if (i == CAPACITYPENGGUNA)
    {
        return NULL;
    }
    else
    {
        return &SELECT_PENGGUNA(T, i);
    }
};
Pengguna *searchPengguna(TabPengguna T, int IDPengguna)
{
    int i = 0;
    while (i < CAPACITYPENGGUNA && ID_PENGGUNA(SELECT_PENGGUNA(T, i)) != IDPengguna)
    {
        i++;
    }
    if (i == CAPACITYPENGGUNA)
    {
        return NULL;
    }
    else
    {
        return &SELECT_PENGGUNA(T, i);
    }
};