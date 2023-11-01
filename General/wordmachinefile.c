#include <stdio.h>
#include "wordmachinefile.h"

boolean endWordFile;
Word currentWordFile;

void IgnoreBlanksFile(){
    while (currentCharFile == BLANK && currentCharFile != MARK_FILE) {
        ADVFILE();
    }
}

void STARWORDFILE(char namaFile[]){
    STARFILE(namaFile);
    IgnoreBlanksFile();

    if (currentCharFile == MARK_FILE) {
        endWordFile = true;
    } else {
        endWordFile = false;
        CopyWordFile();
    }
}

void ADVWORDFILE(){
    IgnoreBlanksFile();
    
    if (currentCharFile == MARK_FILE) {
        endWordFile = true;
    } else {
        CopyWordFile();
    }
}

void CopyWordFile(){
    int i;
    i = 0;

    while (currentCharFile != MARK_FILE && currentCharFile != BLANK) {
        if (i < NMax) {
            currentWordFile.TabWord[i] = currentCharFile;
        }
        ADVFILE();
        i++;
    }

    if (i < NMax) {
        currentWordFile.Length = i;
    } else {
        currentWordFile.Length = NMax;
    }
}

void StopWordFile(){
    ENDFILE();
}