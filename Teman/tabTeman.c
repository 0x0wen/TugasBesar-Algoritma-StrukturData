#include <stdio.h>
#include "tabTeman.h"
#include "global.h"
// membuat graf dengan n simpul
TabTeman createTabTeman(int simpul)
{
    TabTeman *tab = (TabTeman *)malloc(sizeof(TabTeman));
    DIMENSI(*tab) = simpul;
    for (int i = 0; i < simpul; i++)
    {
        for (int j = 0; j < simpul; j++)
        {
            HUBUNGAN(*tab, i, j) = 0;
        }
    }
    return *tab;
}

// untuk menambah sisi antar dua simpul
void addFriend(int simpul1, int simpul2)
{
    HUBUNGAN(dataTeman, simpul1 - 1, simpul2 - 1) = 1;
    HUBUNGAN(dataTeman, simpul2 - 1, simpul1 - 1) = 1;
}

void removeFriend(int simpul1, int simpul2)
{
    HUBUNGAN(dataTeman, simpul1 - 1, simpul2 - 1) = 0;
    HUBUNGAN(dataTeman, simpul2 - 1, simpul1 - 1) = 0;
}

// unruk mengecek apakah dua simpul saling terhubung
boolean isFriend(int simpul1, int simpul2)
{
    if (HUBUNGAN(dataTeman, simpul1, simpul2) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}