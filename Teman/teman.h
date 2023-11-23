#ifndef TEMAN_H
#define TEMAN_H
#include "../General/boolean.h"

// boolean IsFriendWord(Word user1, Word user2);
#define MAX_SIMPUL 20

typedef struct
{
    int matrix[MAX_SIMPUL][MAX_SIMPUL];
} AdjacencyMatrix;

#define ELMT_TEMAN(m, i, j) (m).matrix[i][j]


void createMatrixTeman(AdjacencyMatrix *matrix_teman);

void addFriend(AdjacencyMatrix *matrix_teman, int id_user1, int id_user2);

void deleteFriend(AdjacencyMatrix *matrix_teman, int id_user1, int id_user2);

boolean isFriend(AdjacencyMatrix matrix_teman, int id_user1, int id_user2);

int countFriend(AdjacencyMatrix matrix_teman, int id_user);
// #define DIMENSI(p) (p).dimensi
// #define HUBUNGAN(p, i, j) (p).matrix[i][j]

// // membuat graf dengan n simpul
// TabTeman createTabTeman(int simpul);

// // untuk menambah teman
// void addFriend(int simpul1, int simpul2);

// // untuk menghapus teman
// void removeFriend(int simpul1, int simpul2);

// // unruk mengecek apakah dua simpul saling terhubung
// boolean isFriend(int simpul1, int simpul2);
#endif