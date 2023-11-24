#include "../global.h"

boolean endWordFile;
Word currentWordFile;

void IgnoreBlanksFile(){   
    while (currentCharFile == BLANK && currentCharFile != MARK_FILE) {
            ADVFILE();
    }
}

void STARWORDFILE(char namaFile[]){
    STARFILE(namaFile);
    if (currentCharFile == '\n') {
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

Word CopyWordFile2(){
    int i;
    i = 0;
    Word string;
    while (currentCharFile != MARK_FILE) {
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

Word CopyWordFile3(){
    int i;
    i = 0;
    Word string;
    while (currentCharFile != MARK_FILE && currentCharFile != BLANK) {
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

Sentence CopySentenceFile(){
    int i;
    i = 0;
    Sentence string;
    while (currentCharFile != MARK_FILE) {
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

void StopWordFile(){
    ENDFILE();
}