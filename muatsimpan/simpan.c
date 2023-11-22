#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "..\General\wordmachinefile.c"
#include "..\General\wordmachine.c"
#include <sys/stat.h>
// #include "..\global.h"


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

void createFile(char *fullPath,char *filename){
    char fullpath[100]; 
    snprintf(fullpath, sizeof(fullpath), "%s/%s", fullPath, filename);
    FILE *fptr;
    fptr = fopen(fullpath, "w");
    fclose(fptr);
}

void simpanPengguna(int jumlahUser,Word inputfile){
    FILE *file;
    file = fopen(inputfile.TabWord, "w");
    fprintf(file, "%d\n",jumlahUser);//jumlah user
    for(int i=0; i < jumlahUser; i++){
        fprintf(file, "%s\n",inputfile);//nama
        fprintf(file, "%s\n",inputfile);//password
        fprintf(file, "%s\n",inputfile);//bio
        fprintf(file, "%s\n",inputfile);//no hp
        fprintf(file, "%s\n",inputfile);//weton
        fprintf(file, "%s\n",inputfile);//jenis akun

        for(int j = 0; j < 5; j++){
            for(int k = 0;k < 10;k++){
                fprintf(file, "%c",inputfile.TabWord[0]);//foto profil
            }
            fprintf(file,"\n");
        }
    }

    for(int i = 0; i < jumlahUser; i++){
        fprintf(file, "%c ",inputfile.TabWord[0]);//matriks pertemanan
        fprintf(file, "%c ",inputfile.TabWord[0]);
        fprintf(file, "%c\n",inputfile.TabWord[0]);

    }

    fprintf(file, "%d\n",jumlahUser);//banyakpermintaan pertemanan
    for(int i = 0;i < jumlahUser;i++){
        fprintf(file, "%c ",inputfile.TabWord[0]);// matriks req teman
        fprintf(file, "%c ",inputfile.TabWord[0]);
        fprintf(file, "%c\n",inputfile.TabWord[0]);
    }
    fclose(file);
}

void simpanKicauan(int jumlahKicauan,Word inputfile){
    FILE *file;
    file = fopen(inputfile.TabWord, "w");
    fprintf(file, "%d\n",jumlahKicauan);//jumlah kicauan
    for(int i = 0; i < jumlahKicauan; i++){
        fprintf(file, "%d\n",jumlahKicauan);//id kicauan
        fprintf(file, "%s\n",inputfile);//teks
        fprintf(file, "%d\n",jumlahKicauan);//like
        fprintf(file, "%s\n",inputfile);//author
        fprintf(file, "%s\n",inputfile);//datetime
    }
}

void simpanBalasan(int jumlahKicauan,Word inputfile){
    FILE *file;
    file = fopen(inputfile.TabWord, "w");
    fprintf(file, "%d\n",jumlahKicauan); // banyak kicauan yang memiliki balasan
    for(int i = 0; i < jumlahKicauan;i++){
        fprintf(file, "%d\n",jumlahKicauan);// id kicauan
        int jumlahbalasan = 4;
        fprintf(file, "%d\n",jumlahbalasan);// jumlah balasan
        for(int j = 0; j < jumlahbalasan; j++){
            fprintf(file, "%d ",jumlahKicauan);//id parent
            fprintf(file, "%d\n",jumlahbalasan);//id balasan
            fprintf(file, "%s\n",inputfile);//teks
            fprintf(file, "%s\n",inputfile);//penulis
            fprintf(file, "%s\n",inputfile);//datetime
        }
    }
}

void simpanDraf(int jumlahUser,Word inputfile){
    FILE *file;
    file = fopen(inputfile.TabWord, "w");
    fprintf(file, "%d\n",jumlahUser);//Banyak pengguna punya draf
    for(int i = 0; i < jumlahUser; i++){
        fprintf(file, "%s",inputfile);//username
        fprintf(file, " ",inputfile);
        int banyakDraf = 3;
        fprintf(file, "%d\n",banyakDraf);//Banyak draf
        for(int j = 0; j < banyakDraf; j++){
            fprintf(file, "%s\n",inputfile);//isi draf
            fprintf(file, "%s\n",inputfile);//datetime
        }
    }
}

void simpanUtas(int jumlahKicauan, Word inputfile){
    FILE *file;
    file = fopen(inputfile.TabWord, "w");
    fprintf(file, "%d\n",jumlahKicauan);//Banyak kicauan yang punya utas
    for(int i = 0; i < jumlahKicauan; i++){
        fprintf(file, "%d\n",jumlahKicauan);//id kicauan
        int banyakUtas = 3;
        fprintf(file, "%d\n",banyakUtas);//banyak utas
        for(int j = 0; j < banyakUtas; j++){
            fprintf(file, "%s\n",inputfile);//teks
            fprintf(file, "%s\n",inputfile);//penulis
            fprintf(file, "%s\n",inputfile);//datetime
        }
    }
}

void simpan(){
    printf("Masukkan nama folder penyimpanan.\n");
    Word config,locFile;
    writeWord(&locFile,"Data/", 5);
    InputWord(&config);
    Word inputFolder = writefilename(locFile,config);
    writeWord(&locFile,"/pengguna.config", 16);
    Word inputFile = writefilename(inputFolder,locFile);
    char foldername[100];
    for(int i = 0; i < config.Length;i++){
        foldername[i]=config.TabWord[i];
    }
    FILE* tempFile = fopen(inputFile.TabWord, "r");
    if (tempFile == NULL) {
        printf("Belum terdapat %s Akan dilakukan pembuatan Folder1 terlebih dahulu.\n",foldername);
        printf("Mohon tunggu...\n");
        char fullPath[300];  
        char fullpath[300];
        char folderpath[100] = "./Data";
        snprintf(fullPath, sizeof(fullPath), "%s/%s", folderpath, foldername);
        int result = mkdir(fullPath);
        char filename[] = "pengguna.config";
        createFile(fullPath,filename);
        char filename1[] = "kicauan.config";
        createFile(fullPath,filename1);
        char filename2[] = "balasan.config";
        createFile(fullPath,filename2);
        char filename3[] = "draf.config";
        createFile(fullPath,filename3);
        char filename4[] = "utas.config";
        createFile(fullPath,filename4);
        writeWord(&locFile,"Data/", 5);
        inputFolder = writefilename(locFile,config);
        writeWord(&locFile,"/pengguna.config", 16);
        inputFile = writefilename(inputFolder,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        printf("1...\n");
        printf("2...\n");
        printf("3...\n");
        printf("%s sudah berhasil dibuat.\n",foldername);
    }else{
        printf("Anda akan melakukan pemuatan dari %s.\n",foldername);
    }

    int jumlahUser = 3;
    simpanPengguna(jumlahUser,inputFile);

    int jumlahKicauan = 2;
    writeWord(&locFile,"/kicauan.config", 15);
    inputFile = writefilename(inputFolder,locFile);
    simpanKicauan(jumlahKicauan,inputFile);

    jumlahKicauan = 1;
    writeWord(&locFile,"/balasan.config", 15);
    inputFile = writefilename(inputFolder,locFile);
    simpanBalasan(jumlahKicauan,inputFile);

    jumlahUser=2;
    writeWord(&locFile,"/draf.config", 12);
    inputFile = writefilename(inputFolder,locFile);
    simpanDraf(jumlahUser,inputFile);

    jumlahKicauan = 2;
    writeWord(&locFile,"/utas.config", 12);
    inputFile = writefilename(inputFolder,locFile);
    simpanUtas(jumlahKicauan,inputFile);
}