#ifndef GRAF
#define GRAF

#include "boolean.h"
#define MAX_SIMPUL 20

typedef struct {
    int simpul;
    int matrix[MAX_SIMPUL][MAX_SIMPUL];
} Graf;

#define SIMPUL(p) (p).simpul
#define MATRIX(p,i,j) (p).matrix[i][j]

// membuat graf dengan n simpul
Graf* createGraf(int simpul);

// untuk menambah sisi antar dua simpul
void addSisi(Graf *graph, int simpul1, int simpul2);

// unruk mengecek apakah dua simpul saling terhubung
boolean simpulTerhubung(Graf *graph, int simpul1, int simpul2);

#endif