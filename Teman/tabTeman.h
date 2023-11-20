#ifndef TAB__TEMAN__H
#define TAB__TEMAN__H

#include "boolean.h"
#define MAX_SIMPUL 20

typedef struct
{
    int dimensi;
    int matrix[MAX_SIMPUL][MAX_SIMPUL];
} TabTeman;

#define DIMENSI(p) (p).dimensi
#define HUBUNGAN(p, i, j) (p).matrix[i][j]

// membuat graf dengan n simpul
TabTeman createTabTeman(int simpul);

// untuk menambah teman
void addFriend(int simpul1, int simpul2);

// untuk menghapus teman
void removeFriend(int simpul1, int simpul2);

// unruk mengecek apakah dua simpul saling terhubung
boolean isFriend(int simpul1, int simpul2);

#endif