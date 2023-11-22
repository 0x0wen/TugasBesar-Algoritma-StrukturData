#include <stdio.h>
#include "..\General\wordmachinefile.c"
#include "..\General\wordmachine.c"

Word writefilename(Word input1, Word input2){
    Word output;
    int i;
    for (i = 0; i < input1.Length; i++) {
        output.TabWord[i] = input1.TabWord[i];
    }
    for (i = 0; i < input2.Length; i++) {
        output.TabWord[input1.Length + i] = input2.TabWord[i];
    }
    output.TabWord[input1.Length + input2.Length] = '\0';
    output.Length = input1.Length + input2.Length;

    return output;
}

void muatPengguna(Word inputFile){
    STARWORDFILE(inputFile.TabWord);
    int jumlahUser = atoi(currentWordFile.TabWord); //jumlah user
    printf("%d",jumlahUser);
    if(jumlahUser!=0){
        for(int i = 0; i < jumlahUser; i++){
            ADVFILE();
            Word temp[10];
            temp = CopyWordFile3();// Nama
        }
    }
}