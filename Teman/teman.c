#include "../global.h"

void createMatrixTeman(AdjacencyMatrix *matrix_teman)
{
    int i, j;
    for (i = 0; i < MAX_SIMPUL; i++)
    {
        for (j = 0; j < MAX_SIMPUL; j++)
        {
            ELMT_TEMAN(*matrix_teman, i, j) = 0;
        }
    }
}

void addFriend(AdjacencyMatrix *matrix_teman, int id_user1, int id_user2)
{   
    ELMT_TEMAN(*matrix_teman, id_user1, id_user2) = 1;
    ELMT_TEMAN(*matrix_teman, id_user2, id_user1) = 1;
}

void deleteFriend(AdjacencyMatrix *matrix_teman, int id_user1, int id_user2)
{
    ELMT_TEMAN(*matrix_teman, id_user1, id_user2) = 0;
    ELMT_TEMAN(*matrix_teman, id_user2, id_user1) = 0;
}

boolean isFriend(AdjacencyMatrix matrix_teman, int id_user1, int id_user2)
{
    return ELMT_TEMAN(matrix_teman, id_user1, id_user2) == 1;
}

int countFriend(AdjacencyMatrix matrix_teman, int id_user)
{

    int i, count = 0;
    for (i = 0; i < MAX_SIMPUL; i++)
    {
        count += ELMT_TEMAN(matrix_teman, id_user, i);
    }

    return count;
}

// #include "tabTeman.h"
// #include "pengguna.h"
// #include "tabPengguna.h"

// boolean IsFriendWord(Word user1, Word user2) {
//     int idx1 = idPengguna(user1);
//     int idx2 = idPengguna(user2);

//     return (HUBUNGAN(dataTeman, idx1, idx2) == 1);
// }

// #include <stdio.h>
// #include "tabTeman.h"
// #include "global.h"
// membuat graf dengan n simpul
// TabTeman createTabTeman(int simpul)
// {
//     TabTeman *tab = (TabTeman *)malloc(sizeof(TabTeman));
//     DIMENSI(*tab) = simpul;
//     for (int i = 0; i < simpul; i++)
//     {
//         for (int j = 0; j < simpul; j++)
//         {
//             HUBUNGAN(*tab, i, j) = 0;
//         }
//     }
//     return *tab;
// }

// // untuk menambah sisi antar dua simpul
// void addFriend(int simpul1, int simpul2)
// {
//     HUBUNGAN(dataTeman, simpul1 - 1, simpul2 - 1) = 1;
//     HUBUNGAN(dataTeman, simpul2 - 1, simpul1 - 1) = 1;
// }

// void removeFriend(int simpul1, int simpul2)
// {
//     HUBUNGAN(dataTeman, simpul1 - 1, simpul2 - 1) = 0;
//     HUBUNGAN(dataTeman, simpul2 - 1, simpul1 - 1) = 0;
// }

// // unruk mengecek apakah dua simpul saling terhubung
// boolean isFriend(int simpul1, int simpul2)
// {
//     if (HUBUNGAN(dataTeman, simpul1, simpul2) == 1)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }