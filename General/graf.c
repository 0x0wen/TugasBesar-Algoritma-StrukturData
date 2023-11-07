#include <stdio.h>
#include "graf.h"

// membuat graf dengan n simpul
Graf* createGraf(int simpul){
    Graf* graph = (Graf*)malloc(sizeof(Graf));
    SIMPUL(*graph) = simpul;
    for (int i = 0; i < simpul; i++) {
        for (int j = 0; j < simpul; j++) {
            MATRIX(*graph,i,j) = 0;
        }
    }
    return graph; 
}

// untuk menambah sisi antar dua simpul
void addSisi(Graf *graph, int simpul1, int simpul2){
    MATRIX(*graph,simpul1-1,simpul2-1) = 1;
    MATRIX(*graph,simpul2-1,simpul1-1) = 1;
}

// unruk mengecek apakah dua simpul saling terhubung
boolean simpulTerhubung(Graf *graph, int simpul1, int simpul2){
    if(MATRIX(*graph,simpul1,simpul2)==1){
        return true;
    }else{
        return false;
    }
    
}