#include <stdio.h>
#include "../General/wordmachinefile.c"
#include "../Pengguna/pengguna.h"
#include "Alstrukdat\Tubes\Alstrokedat\ADT\sentenceMachine.h"

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

void inisialisasi(TabPengguna* dataPengguna){
    printf(".______    __    __  .______      .______    __  .______\n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\\n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |\n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /\n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n");
    printf("\n");
    printf("Selamat datang di BurBir.\n");
    printf("\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode\n");
    printf("(pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
    printf("\n");
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");

    Word config,locFile;
    writeWord(&locFile,"/pengguna.config", 16);
    InputWord(&config);
    Word inputFile = writefilename(config,locFile);

    FILE* tempFile = fopen(inputFile.TabWord, "r");
    if (tempFile == NULL) {
        printf("Name file tidak ada.\n");
    }
    else {
        printf("Name file ada.\n");
        // Baca pengguna config
        STARWORDFILE(inputFile.TabWord);
        int jumlahUser = atoi(currentWordFile.TabWord);
        if(jumlahUser!=0){
            // Baca user config
            for(int i = 0; i < jumlahUser; i++){
                Pengguna pengguna;
                ADVFILE();
                Word temp = CopyWordFile2();
                Sentence temp2;
                temp2.TabWord[0] = temp;
                pengguna.nama = temp2;
                ADVFILE();
                Word temp = CopyWordFile2();
                Sentence temp2;
                temp2.TabWord[0] = temp;
                temp2.Length = 1;
                pengguna.kataSandi = temp2;
                ADVFILE();
                Word temp = CopyWordFile2();
                Sentence temp2;
                temp2.TabWord[0] = temp;
                temp2.Length = 1;
                pengguna.bio = temp2;
                ADVFILE();
                Word temp = CopyWordFile2();
                pengguna.weton = temp;
                ADVFILE();
                Word temp = CopyWordFile2();
                if(temp.TabWord=="Privat"){
                    pengguna.jenisAkun = false;
                }else{
                    pengguna.jenisAkun = true;
                }
                ADVFILE();
                Matrix tempM;
                createMatrix(5,10,&tempM);
                for(int p = 0; p < 5; p++){
                    for(int q = 0; q < 10; q++){
                        tempM.mem[p][q]=currentCharFile;
                        ADVFILE();
                    }
                    ADVFILE();
                }
                pengguna.foto=tempM;
                insertLastTabPengguna(pengguna);
            }
            ADVFILE();
            //Baca pertemanan
            for(int i = 0; i < jumlahUser; i++){
                while (currentCharFile != MARK_FILE) {
                    if(currentCharFile!=BLANK){
                        int temp = atoi(&currentCharFile);
                        printf("%d",temp);
                    }
                    ADVFILE();
                }
                ADVFILE();
                printf("\n");
            }
            CopyWordFile();
            int reqPertemanan = atoi(currentWordFile.TabWord);
            printf("%d\n",reqPertemanan);

            ADVFILE();
            for(int i = 0; i < reqPertemanan; i++){
                int temp = atoi(&currentCharFile);
                printf("id minta %d ",temp);
                ADVFILE();
                ADVFILE();
                temp = atoi(&currentCharFile);
                printf("id diminta %d ",temp);
                ADVFILE();
                ADVFILE();
                temp = atoi(&currentCharFile);
                printf("teman %d \n",temp);
                ADVFILE();
                ADVFILE();
            }
        }
        StopWordFile(inputFile.TabWord);

        //Baca konfig balasan
        writeWord(&locFile,"/balasan.config", 15);
        inputFile = writefilename(config,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        STARWORDFILE(inputFile.TabWord);
        int jumlahKicauan= atoi(currentWordFile.TabWord);
        printf("%d\n",jumlahKicauan);
        if(jumlahKicauan!=0){
            for(int i = 0; i < jumlahKicauan; i++){
                ADVFILE();
                CopyWordFile();
                int id= atoi(currentWordFile.TabWord);
                printf("%d\n",id);
                ADVFILE();
                CopyWordFile();
                int jumlahBalasan = atoi(currentWordFile.TabWord);
                for(int j = 0; j < jumlahBalasan; j++){
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    ADVFILE();
                    printf("%c\n",currentCharFile);
                    ADVFILE();
                    ADVFILE();
                    CopyWordFile();
                    for(int i = 0; i<currentWordFile.Length;i++){
                        printf("%c",currentWordFile.TabWord[i]);
                    }
                    printf("\n");
                    ADVFILE();
                    CopyWordFile();
                    for(int i = 0; i<currentWordFile.Length;i++){
                        printf("%c",currentWordFile.TabWord[i]);
                    }
                    printf("\n");
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("\n");
                }
            }
        }
        StopWordFile(inputFile.TabWord);
        //Baca konfig kicauan
        writeWord(&locFile,"/kicauan.config", 15);
        inputFile = writefilename(config,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        STARWORDFILE(inputFile.TabWord);
        jumlahKicauan= atoi(currentWordFile.TabWord);
        if(jumlahKicauan!=0){
            for(int i = 0; i < jumlahKicauan; i++){
                for(int j = 0; j < 4; j++){
                    ADVFILE();
                    CopyWordFile();
                    for(int i = 0; i<currentWordFile.Length;i++){
                        printf("%c",currentWordFile.TabWord[i]);
                    }
                    printf("\n");
                }
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
                printf("%c",currentCharFile);
                ADVFILE();
            }
        }
        StopWordFile(inputFile.TabWord);

        writeWord(&locFile,"/draf.config", 12);
        inputFile = writefilename(config,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        STARWORDFILE(inputFile.TabWord);
        int jumlahPengguna= atoi(currentWordFile.TabWord);
        printf("\n%d\n",jumlahPengguna);
        if(jumlahPengguna!=0){
            for(int i = 0; i < jumlahPengguna; i++){
                ADVFILE();
                int j,k;
                j = 0;
                k = 0;
                Word temp[10];
                temp[k].Length=0;
                while (currentCharFile != MARK_FILE) {
                    if (i < NMax) {
                        temp[k].TabWord[j]=currentCharFile;
                        temp[k].Length++;
                    }
                    if(currentCharFile == BLANK){
                        k++;
                        j=0;
                        temp[k].Length=0;
                    }else{
                        j++;
                    }
                    ADVFILE();
                }
                Word username;
                username.Length=0;
                int t = 0;
                for(int p = 0; p<k;p++){
                    for(j = 0; j<temp[p].Length; j++){
                        if(!(j==temp[p].Length-1 && p==k-1)){ 
                            username.TabWord[t]=temp[p].TabWord[j];
                            username.Length++;
                            t++;
                        }
                    }
                }
                for(int j = 0; j< username.Length;j++){
                    printf("%c",username.TabWord[j]);
                }
                int jumlahdraf= atoi(temp[k].TabWord);
                printf(" %d\n",jumlahdraf);
                for(int l = 0; l < jumlahdraf; l++){
                    ADVFILE();
                    CopyWordFile();
                    for(int j = 0; j< currentWordFile.Length;j++){
                        printf("%c",currentWordFile.TabWord[j]);
                    }
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c\n",currentCharFile);
                    ADVFILE();
                }
            }
        }
        StopWordFile(inputFile.TabWord);

        writeWord(&locFile,"/utas.config", 12);
        inputFile = writefilename(config,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        STARWORDFILE(inputFile.TabWord);
        jumlahKicauan= atoi(currentWordFile.TabWord);
        printf("\n%d\n",jumlahKicauan);
        if(jumlahKicauan!=0){
            for(int k = 0; k < jumlahKicauan;k++){
                ADVFILE();
                CopyWordFile();
                int id = atoi(currentWordFile.TabWord);
                printf("%d\n",id);
                ADVFILE();
                Word tempS = CopyWordFile2();
                int banyakUtas = atoi(tempS.TabWord);
                printf("%d\n",banyakUtas);
                for(int j = 0; j < banyakUtas; j++){
                    ADVFILE();
                    CopyWordFile();
                    for(int i = 0; i < currentWordFile.Length;i++){
                        printf("%c",currentWordFile.TabWord[i]);
                    }
                    printf("\n");
                    ADVFILE();
                    CopyWordFile();
                    for(int i = 0; i < currentWordFile.Length;i++){
                        printf("%c",currentWordFile.TabWord[i]);
                    }
                    printf("\n");
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c",currentCharFile);
                    ADVFILE();
                    printf("%c\n",currentCharFile);
                    ADVFILE();
                }
            }
        }
        StopWordFile(inputFile.TabWord);

        printf("\n");
        printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
        printf("Aku kangen sama kamu saaaaaaaaa\n");
    }

    statusProgram = true;
}