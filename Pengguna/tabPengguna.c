#include "../global.h"

void createTabPengguna(TabPengguna *T)
{
    (*T).length = 0;
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

boolean isTabPenggunaEmpty(TabPengguna T)
{
    return lengthTabPengguna(T) == 0;
}

boolean isTabPenggunaFull(TabPengguna T)
{
    return lengthTabPengguna(T) == CAPACITYPENGGUNA;
}

int indexOfTabPengguna(TabPengguna T, Pengguna val)
{
    int i = 0;
    while (i < T.length)
    {
        if (ID_PENGGUNA(SELECT_PENGGUNA(T, i)) == ID_PENGGUNA(val))
        {
            return i;
        }
        i++;
    }
    return IDX_UNDEF_TAB_PENGGUNA;
}

void insertLastTabPengguna(TabPengguna *T, Pengguna val)
{
    int len = T->length;
    SELECT_PENGGUNA(*T, len) = val;
    (*T).length++;
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

Pengguna *searchPenggunaByName(TabPengguna *T, Sentence username)
{
    int i = 0;
    while (i < CAPACITYPENGGUNA && !IsSentenceEqual(NAMA_PENGGUNA(SELECT_PENGGUNA(*T, i)), username))
    {
        i++;
    }
    if (i == CAPACITYPENGGUNA)
    {
        return NULL;
    }
    else
    {
        return &SELECT_PENGGUNA(*T, i);
    }
};
Pengguna *searchPengguna(TabPengguna *T, int IDPengguna)
{
    int i = 0;
    while (i < CAPACITYPENGGUNA && ID_PENGGUNA(SELECT_PENGGUNA(*T, i)) != IDPengguna)
    {
        i++;
    }
    if (i == CAPACITYPENGGUNA)
    {
        return NULL;
    }
    else
    {
        return &SELECT_PENGGUNA(*T, i);
    }
};

int getIDPengguna(TabPengguna T, Sentence username)
{
    int id_teman = 0;
    int i;

    for (i = 0; i < BANYAK_PENGGUNA(T); i++)
    {
        if (IsSentenceEqual(SELECT_PENGGUNA(T, i).nama, username))
        {
            id_teman = SELECT_PENGGUNA(T, i).id;
            break;
        }
    }
    return id_teman;
}