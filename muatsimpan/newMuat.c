#include "../global.h"

DATETIME muatDateTime(){
    ADVFILE();
    int day= atoi(&currentCharFile);
    ADVFILE();
    day= atoi(&currentCharFile)+(10*day);
    ADVFILE();
    ADVFILE();
    int month=atoi(&currentCharFile);
    ADVFILE();
    month=atoi(&currentCharFile)+(10*month);
    ADVFILE();
    ADVFILE();
    int year = atoi(&currentCharFile)*1000;
    ADVFILE();
    year = (atoi(&currentCharFile)*100)+year;
    ADVFILE();
    year = (atoi(&currentCharFile)*10)+year;
    ADVFILE();
    year = (atoi(&currentCharFile))+year;
    ADVFILE();
    ADVFILE();
    int hh = atoi(&currentCharFile)*10;
    ADVFILE();
    hh = atoi(&currentCharFile)+hh;
    ADVFILE();
    ADVFILE();
    int mm = atoi(&currentCharFile)*10;
    ADVFILE();
    mm = atoi(&currentCharFile)+mm;
    ADVFILE();
    ADVFILE();
    int ss = atoi(&currentCharFile)*10;
    ADVFILE();
    ss = atoi(&currentCharFile)+ss;
    ADVFILE();
    DATETIME date;
    CreateDATETIME(&date,day,month,year,hh,mm,ss);
    return date;
}

void muatPenggunaNew(Word inputFile,TabPengguna dataPengguna,AdjacencyMatrix mteman){
    STARWORDFILE(inputFile.TabWord);
    int jumlahUser = atoi(currentWordFile.TabWord); //jumlah user
    if(jumlahUser!=0){

        for(int i = 0; i < jumlahUser; i++){
            Pengguna pengguna;
            pengguna.id = i;

            Sentence username = CopySentenceFile();
            pengguna.nama = username;

            ADVFILE();
            Sentence password = CopySentenceFile();
            pengguna.kataSandi = password;

            ADVFILE();
            Sentence bio = CopySentenceFile();
            pengguna.bio = bio;

            ADVFILE();
            Word nomorHp = CopyWordFile2();
            pengguna.noHP = nomorHp;

            ADVFILE();
            Word weton = CopyWordFile2();
            pengguna.weton = weton;

            ADVFILE();
            Word akun = CopyWordFile2();
            Word temp;
            writeWord(&temp,"Privat",6);
            boolean privat = IsWordEqual(akun,temp);
            pengguna.privat = privat;

            FotoProfil foto;
            createFotoProfil(5,10,&foto);
            ADVFILE();
            for(int j = 0; j < 5; j++){
                for(int k = 0; k < 10; k++){
                    ELMT(foto,j,k) = currentCharFile;
                    ADVFILE();
                    ADVFILE();
                }
            }
            pengguna.foto = foto;
            PrioQueueRequest req;
            create_PQR(&req);
            pengguna.daftarPermintaanTeman = req;
            

            insertLastTabPengguna(&dataPengguna,pengguna);
            
            // (*dataPengguna).contents[i] = pengguna;
            //(*dataPengguna).length++;
        }
        createMatrixTeman(&mteman);
        int j = 0;
        int z = 0;
        for(int i = 0; i < jumlahUser; i++){
            while (currentCharFile != MARK_FILE) {
                if(currentCharFile!=BLANK){
                    int temp = atoi(&currentCharFile);
                    if(temp==1){
                        addFriend(&mteman,j,z);
                    }
                    z++;
                }
                ADVFILE();
                j++;
            }
            ADVFILE();
        }
        int temp = atoi(&currentCharFile);
        for(int i = 0; i < temp; i++){
            Requester request;
            ADVFILE();
            ADVFILE();
            int idminta = atoi(&currentCharFile);
            ADVFILE();
            ADVFILE();
            int iddiminta = atoi(&currentCharFile);
            ADVFILE();
            ADVFILE();
            int banyakfoll = atoi(&currentCharFile);

            request.id_requester = idminta;
            request.prio = banyakfoll;

            for(int j = 0; j < jumlahUser; j++){
                if(dataPengguna.contents[j].id==iddiminta){
                    enqueue_PQR(&dataPengguna.contents[j].daftarPermintaanTeman,request);
                }

            }
        }
    }
    StopWordFile(inputFile.TabWord);
}

void muatKicauanNew(Word inputFile,TabKicauan *tabkicau){
    STARWORDFILE(inputFile.TabWord);
    int jumlahKicauan = atoi(currentWordFile.TabWord);
    createTabKicauan(tabkicau,jumlahKicauan);
    if(jumlahKicauan!=0){
        for(int i = 0; i < jumlahKicauan; i++){
            Kicauan kicau;
            ADVFILE();
            CopyWordFile();
            int id= atoi(currentWordFile.TabWord);
            kicau.IDKicau = id;
            
            ADVFILE();
            Sentence text = CopySentenceFile();
            kicau.Text = text;

            ADVFILE();
            CopyWordFile();
            int like= atoi(currentWordFile.TabWord);
            kicau.Like = like;

            ADVFILE();
            Sentence author = CopySentenceFile();
            kicau.Author = author;

            DATETIME dateTime = muatDateTime();
            kicau.DateTime=dateTime;
            addKicauanToTab(tabkicau,kicau);
        }    
    }
    StopWordFile(inputFile.TabWord);
}

void muatBalasanNew(Word inputFile,TabPengguna *tabuser){
    printf("tesss");
    STARWORDFILE(inputFile.TabWord);
    int jumlahKicauan = atoi(currentWordFile.TabWord);
    if(jumlahKicauan!=0){
        ADVFILE();
        CopyWordFile();
        int id= atoi(currentWordFile.TabWord);

        ADVFILE();
        CopyWordFile();
        int banyakBalasan = atoi(currentWordFile.TabWord);

        for(int i = 0; i < banyakBalasan; i++){
            Balasan data;
            addressTree balas = createBalasan(data);
            
            ADVFILE();
            CopyWordFile3();
            int idparent = atoi(currentWordFile.TabWord);
            if(idparent>=0){
                balas->data.IDParent = idparent;
            }else{
                balas->data.IDParent = id;
            }

            ADVFILE();
            CopyWordFile3();
            int idbalas = atoi(currentWordFile.TabWord);
            balas->data.IDBalasan = idbalas;

            ADVFILE();
            Sentence teks = CopySentenceFile();
            balas->data.konten = teks;
            
            ADVFILE();
            Sentence author = CopySentenceFile();
            balas->data.author = author;

            Pengguna *temp = searchPenggunaByName(tabuser,author);
            balas->data.IDPengguna = (temp)->id;
            
            DATETIME dateTime = muatDateTime();
            balas->data.waktu = dateTime;
        }
    }
    StopWordFile(inputFile.TabWord);
}

void muatDrafNew(Word inputFile,TabPengguna *tabuser){
    printf("debug");
    STARWORDFILE(inputFile.TabWord);
    int jumlahPengguna= atoi(currentWordFile.TabWord);
    for(int i = 0; i < jumlahPengguna; i++){
        printf("debug");
        Draf draf;
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
        Sentence username;
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
        int jumlahdraf= atoi(temp[k].TabWord);
        for(int j = 0; j < jumlahdraf;j++){
            Kicauan kicau;
            ADVFILE();
            Sentence isi = CopySentenceFile();
            kicau.Text = isi;
            DATETIME dateTime = muatDateTime();
            kicau.DateTime = dateTime;
            pushDraf(&draf,kicau);
        }
        Pengguna *pengguna = searchPenggunaByName(tabuser,username);
        (pengguna)->drafKicauan = draf;
    }
    StopWordFile(inputFile.TabWord);
}

void muatUtasNew(Word inputFile, TabUtas *dataUtas){
    STARWORDFILE(inputFile.TabWord);
    int jumlahKicauan= atoi(currentWordFile.TabWord);
    if(jumlahKicauan!=0){
        for(int k = 0; k < jumlahKicauan;k++){
            Utas utas;
            TabKicauanSambungan tabsambungan;
            ADVFILE();
            CopyWordFile();
            int id= atoi(currentWordFile.TabWord);
            utas.IDKicau = id;

            ADVFILE();
            CopyWordFile();
            int banyakUtas = atoi(currentWordFile.TabWord);

            for(int i = 0; i < banyakUtas; i++){
                KicauanSambungan sambungan;
                Address kicauannew= newKicauanSambungan(sambungan);
                ADVFILE();
                Sentence teks = CopySentenceFile();
                kicauannew->info.pesan = teks;

                ADVFILE();
                Sentence author = CopySentenceFile();
                kicauannew->info.author = author;

                DATETIME dateTime = muatDateTime();
                kicauannew->info.waktu = dateTime;
                insertLastTabKicauanSambungan(&tabsambungan,kicauannew->info);
            }
            utas.dataKicauanSambungan = tabsambungan;
            utas.IDUtas = k;
            insertLastTabUtas(dataUtas,utas);
        }
    }
    StopWordFile(inputFile.TabWord);
}

void muat(TabPengguna* datauser, AdjacencyMatrix* matrikstemen, TabKicauan* tabkicauan, TabUtas* datautas){
    printf("Masukkan nama folder yang hendak dimuat.\n");
    Word config,locFile;
    writeWord(&locFile,"muatsimpan/Data/", 16);
    InputWord(&config);
    Word inputFolder = writefilename(locFile,config);
    writeWord(&locFile,"/pengguna.config", 16);
    Word inputFile = writefilename(inputFolder,locFile);
    FILE* tempFile = fopen(inputFile.TabWord, "r");
    if (tempFile == NULL) {
        printf("Tidak ada folder yang dimaksud!\n");
    }else{
        printf("Anda akan melakukan pemuatan dari Folder2.\n");

        muatPenggunaNew(inputFile, *datauser,*matrikstemen);

        writeWord(&locFile,"/kicauan.config", 15);
        inputFile = writefilename(inputFolder,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        muatKicauanNew(inputFile,tabkicauan);

        printf("Mohon tunggu...\n");

        writeWord(&locFile,"/balasan.config", 15);
        inputFile = writefilename(inputFolder,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        muatBalasanNew(inputFile,datauser);

        printf("1...\n");

        writeWord(&locFile,"/draf.config", 12);
        inputFile = writefilename(inputFolder,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        muatDrafNew(inputFile,datauser);

        printf("2...\n");

        writeWord(&locFile,"/utas.config", 12);
        inputFile = writefilename(inputFolder,locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        muatUtasNew(inputFile,datautas);

        printf("3...\n");
        printf("Pemuatan selesai!\n");
    }
}