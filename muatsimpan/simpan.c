#include "../global.h"
#include <sys/types.h>
#include <sys/stat.h>


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
    char fullpath[300]; 
    snprintf(fullpath, sizeof(fullpath), "%s/%s", fullPath, filename);
    FILE *fptr;
    fptr = fopen(fullpath, "w");
    fclose(fptr);
}

void simpanPengguna(TabPengguna datapengguna, Word inputfile, AdjacencyMatrix mteman){
    FILE *file;
    file = fopen(inputfile.TabWord, "w");
    fprintf(file, "%d\n",datapengguna.length);//jumlah user
    for(int i=0; i < datapengguna.length; i++){
        fprintf(file, "%s\n",datapengguna.contents[i].nama.TabWord);//nama
        fprintf(file, "%s\n",datapengguna.contents[i].kataSandi.TabWord);//password
        fprintf(file, "%s\n",datapengguna.contents[i].bio.TabWord);//bio
        fprintf(file, "%s\n",datapengguna.contents[i].noHP.TabWord);//no hp
        fprintf(file, "%s\n",datapengguna.contents[i].weton.TabWord);//weton
        if(datapengguna.contents[i].privat == 1){
            fprintf(file,"Privat\n");
        }else{
            fprintf(file,"Publik\n");
        }

        for(int j = 0; j < 5; j++){
            for(int k = 0;k < 10;k++){
                fprintf(file, "%c",datapengguna.contents[i].foto.mem[j][k]);//foto profil
            }
            fprintf(file,"\n");
        }
    }

    for(int i = 0; i < datapengguna.length; i++){
        for(int j = 0; j < datapengguna.length; j++){
            if(j==datapengguna.length-1){
                fprintf(file,"%d",mteman.matrix[i][j]);
            }else{
                fprintf(file,"%d ",mteman.matrix[i][j]);
            }
        }
    }
    int req=0;
    for(int i = 0; i < datapengguna.length;i++){
        if(datapengguna.contents[i].daftarPermintaanTeman.idxHead!=IDX_UNDEF){
            int temp = datapengguna.contents[i].daftarPermintaanTeman.idxTail-datapengguna.contents[i].daftarPermintaanTeman.idxHead+1;
            req=req+temp;
        }
    }
    fprintf(file, "%d\n",req);//banyakpermintaan pertemanan
    for(int i = 0; i < datapengguna.length;i++){
        if(datapengguna.contents[i].daftarPermintaanTeman.idxHead!=IDX_UNDEF){
            int temp = datapengguna.contents[i].daftarPermintaanTeman.idxTail-datapengguna.contents[i].daftarPermintaanTeman.idxHead+1;
            for(int j = 0; j < temp; j++){
                fprintf(file, "%d ",datapengguna.contents[i].daftarPermintaanTeman.buffer[j].id_requester);// matriks req teman
                fprintf(file, "%d ",datapengguna.contents[i].id);
                fprintf(file, "%d\n",datapengguna.contents[i].daftarPermintaanTeman.buffer[j].prio);
            }
        }
    }
    fclose(file);
}

void simpanKicauan(Word inputfile,TabKicauan tabkicau){
    FILE *file;
    file = fopen(inputfile.TabWord, "w");
    fprintf(file, "%d\n",tabkicau.nEff);//jumlah kicauan
    for(int i = 0; i < tabkicau.nEff; i++){
        fprintf(file, "%d\n",tabkicau.buffer[i].IDKicau);//id kicauan
        fprintf(file, "%s\n",tabkicau.buffer[i].Text.TabWord);//teks
        fprintf(file, "%d\n",tabkicau.buffer[i].Like);//like
        fprintf(file, "%s\n",tabkicau.buffer[i].Author.TabWord);//author
        DATETIME time = tabkicau.buffer[i].DateTime;
        TIME jam = time.T;
        fprintf(file,"%02d/%02d/%04d %02d:%02d:%02d\n", Day(time), Month(time), Year(time),Hour(jam), Minute(jam), Second(jam));
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
            fprintf(file, "%s\n",inputfile.TabWord);//teks
            fprintf(file, "%s\n",inputfile.TabWord);//penulis
            fprintf(file, "%s\n",inputfile.TabWord);//datetime
        }
    }
}

void simpanDraf(Word inputfile,TabPengguna datapengguna){
    FILE *file;
    file = fopen(inputfile.TabWord, "w");
    int user=0;
    for(int i = 0; i < datapengguna.length;i++){
        user = user + lengthDraf(datapengguna.contents[i].drafKicauan);
    }
    fprintf(file, "%d\n",user);//Banyak pengguna punya draf
    int banyakdraf=0;
    for(int i = 0; i < datapengguna.length; i++){
        banyakdraf = lengthDraf(datapengguna.contents[i].drafKicauan);
        if(banyakdraf!=0){
            fprintf(file, "%s ",datapengguna.contents[i].nama.TabWord);//username
            fprintf(file, "%d\n",banyakdraf);//Banyak draf
            Address_draf p = datapengguna.contents[i].drafKicauan.addrTop;
            for(int j = 0; j < banyakdraf; j++){
                fprintf(file, "%s\n",p->info.Text.TabWord);//isi draf
                DATETIME time = p->info.DateTime;
                TIME jam = time.T;
                fprintf(file,"%02d/%02d/%04d %02d:%02d:%02d\n", Day(time), Month(time), Year(time),Hour(jam), Minute(jam), Second(jam));
                p = p->next;
            }
        }
    }
}

void simpanUtas(Word inputfile,TabUtas datautas){
    FILE *file;
    file = fopen(inputfile.TabWord, "w");
    fprintf(file, "%d\n",datautas.nEff);//Banyak kicauan yang punya utas
    for(int i = 0; i < datautas.nEff; i++){
        fprintf(file, "%d\n",datautas.buffer[i].IDKicau);//id kicauan
        int banyakUtas = lengthTabKicauanSambungan(datautas.buffer[i].dataKicauanSambungan);
        fprintf(file, "%d\n",banyakUtas);//banyak utas
        for(int j = 0; j < banyakUtas; j++){
            fprintf(file, "%s\n",datautas.buffer[i].dataKicauanSambungan->info.konten.TabWord);//teks
            fprintf(file, "%s\n",datautas.buffer[i].dataKicauanSambungan->info.author.TabWord);//penulis
            DATETIME time = datautas.buffer[i].dataKicauanSambungan->info.waktu;
            TIME jam = time.T;
            fprintf(file,"%02d/%02d/%04d %02d:%02d:%02d\n", Day(time), Month(time), Year(time),Hour(jam), Minute(jam), Second(jam));
            datautas.buffer[i].dataKicauanSambungan = datautas.buffer[i].dataKicauanSambungan->next;
        }
    }
}

void simpan(TabPengguna tabuser,AdjacencyMatrix matriksteman, TabKicauan tabkicau, TabUtas tabutas){
    printf("Masukkan nama folder penyimpanan.\n");
    Word config,locFile;
    writeWord(&locFile,"muatsimpan/Data/", 16);
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
        mkdir(foldername, 0777);
        char fullPath[200] = "";
        char folderpath[100] = "/muatsimpan/Data";
        snprintf(fullPath, sizeof(fullPath), "%s/%s", folderpath, foldername);
        char filenames[300];
        snprintf(filenames, sizeof(filenames), "%s/%s", fullPath, "pengguna.config");
        printf("%s\n",filenames);
        FILE *fptr;
        fptr = fopen("muatsimpan/Data/halo/pengguna.config", "w");
        fclose(fptr);
        printf("debug1\n");
        char filename1[14] = "kicauan.config";
        createFile(fullPath,filename1);
        char filename2[14] = "balasan.config";
        createFile(fullPath,filename2);
        char filename3[11] = "draf.config";
        createFile(fullPath,filename3);
        char filename4[11] = "utas.config";
        createFile(fullPath,filename4);
        writeWord(&locFile,"muatsimpan/Data/", 16);
        inputFolder = writefilename(locFile,config);
        writeWord(&locFile,"/pengguna.config", 16);
        inputFile = writefilename(inputFolder,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        printf("1...\n");
        printf("2...\n");
        printf("3...\n");
        printf("%s sudah berhasil dibuat.\n",foldername);
    }else{
        printf("Anda akan melakukan penyimpanan dari %s.\n",foldername);
    }

    simpanPengguna(tabuser,inputFile,matriksteman);

    writeWord(&locFile,"/kicauan.config", 15);
    inputFile = writefilename(inputFolder,locFile);
    simpanKicauan(inputFile, tabkicau);

    writeWord(&locFile,"/balasan.config", 15);
    inputFile = writefilename(inputFolder,locFile);
    simpanBalasan(0,inputFile);

    writeWord(&locFile,"/draf.config", 12);
    inputFile = writefilename(inputFolder,locFile);
    simpanDraf(inputFile,tabuser);

    writeWord(&locFile,"/utas.config", 12);
    inputFile = writefilename(inputFolder,locFile);
    simpanUtas(inputFile,tabutas);
}