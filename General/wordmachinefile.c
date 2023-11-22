#include <stdio.h>
#include "wordmachinefile.h"

boolean endWordFile;
Word currentWordFile;

void IgnoreBlanksFile(){
    if(currentCharFile == BLANK && currentCharFile!=MARK_FILE){    
        while (currentCharFile == BLANK && currentCharFile != MARK_FILE) {
            ADVFILE();
        }
    }
}

void STARWORDFILE(char namaFile[]){
    STARFILE(namaFile);
    IgnoreBlanksFile();

    if (currentCharFile == MARK_FILE || atoi(&currentCharFile)==0) {
        currentWordFile.TabWord[0] = currentCharFile;
        endWordFile = true;
        ADVFILE();
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
    
    while (currentCharFile != MARK_FILE) {
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

Word CopyWordFile2(){
    int i;
    i = 0;
    Word string;
    while (currentCharFile != MARK_FILE && currentCharFile!=BLANK) {
        if (i < NMax) {
            currentWordFile.TabWord[i] = currentCharFile;
            string.TabWord[i]=currentCharFile;
        }
        ADVFILE();
        i++;
    }
    if (i < NMax) {
        currentWordFile.Length = i;
        string.Length = i;
        
    } else {
        currentWordFile.Length = NMax;
        string.Length=NMax;
    }
    return string;
}

Word *CopyWordFile3(){
    Word kata[100];
    int i = 0;
    while(currentCharFile!=MARK_FILE){
        if(currentCharFile==BLANK){
            kata[i].TabWord[0]=BLANK;
            ADVFILE();
        }else{
            kata[i]=CopyWordFile2();
        }
        i++;
    }
    return kata;
};

void StopWordFile(){
    ENDFILE();
}