#include <stdio.h>
#include "../General/wordmachinefile.c"
#include "../Pengguna/pengguna.h"
#include "../General/sentenceMachine.h"
#include "../global.h"

Word writefilename(Word input1, Word input2)
{
    Word output;
    int i;
    for (i = 0; i < input1.Length; i++)
    {
        output.TabWord[i] = input1.TabWord[i];
    }
    for (i = 0; i < input2.Length; i++)
    {
        output.TabWord[input1.Length + i] = input2.TabWord[i];
    }
    output.TabWord[input1.Length + input2.Length] = '\0';
    output.Length = input1.Length + input2.Length;

    return output;
}

int compareCharArrays(const char *array1, const char *array2)
{
    int result = strcmp(array1, array2);
    return result;
}

void inisialisasi()
{
    printf("/$$$$$$$                      /$$       /$$           ");
    printf("| $$__  $$                    | $$      |__/          ");
    printf("| $$  \ $$ /$$   /$$  /$$$$$$ | $$$$$$$  /$$  /$$$$$$ ");
    printf("| $$$$$$$ | $$  | $$ /$$__  $$| $$__  $$| $$ /$$__  $$");
    printf("| $$__  $$| $$  | $$| $$  \__/| $$  \ $$| $$| $$  \__/");
    printf("| $$  \ $$| $$  | $$| $$      | $$  | $$| $$| $$      ");
    printf("| $$$$$$$/|  $$$$$$/| $$      | $$$$$$$/| $$| $$      ");
    printf("|_______/  \______/ |__/      |_______/ |__/|__/      ");
    printf("\n");
    printf("Selamat datang di BurBir.\n");
    printf("\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode\n");
    printf("(pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
    printf("\n");
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");

    Word config, locFile;
    writeWord(&locFile, "/pengguna.config", 16);
    InputWord(&config);
    Word inputFile = writefilename(config, locFile);

    FILE *tempFile = fopen(inputFile.TabWord, "r");
    if (tempFile == NULL)
    {
        printf("Name file tidak ada.\n");
    }
    else
    {
        printf("Name file ada.\n");
        // Baca pengguna config
        STARWORDFILE(inputFile.TabWord);
        int jumlahUser = atoi(currentWordFile.TabWord);
        if (jumlahUser != 0)
        {
            // Baca user config
            for (int i = 0; i < jumlahUser; i++)
            {
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
                if (temp.TabWord == "Privat")
                {
                    pengguna.jenisAkun = false;
                }
                else
                {
                    pengguna.jenisAkun = true;
                }
                ADVFILE();
                Matrix tempM;
                createMatrix(5, 10, &tempM);
                for (int p = 0; p < 5; p++)
                {
                    for (int q = 0; q < 10; q++)
                    {
                        tempM.mem[p][q] = currentCharFile;
                        ADVFILE();
                    }
                    ADVFILE();
                }
                pengguna.foto = tempM;
                insertLastTabPengguna(pengguna);
            }
            ADVFILE();
            // Baca pertemanan
            dataTeman = createTabTeman(jumlahUser);
            for (int i = 0; i < jumlahUser; i++)
            {
                int j = 0;
                int z = 0;
                while (currentCharFile != MARK_FILE)
                {
                    if (currentCharFile != BLANK)
                    {
                        int temp = atoi(&currentCharFile);
                        if (temp == 1)
                        {
                            addFriend(j, z);
                        }
                        // printf("%d",temp);
                        z++;
                    }
                    ADVFILE();
                    j++;
                }
                ADVFILE();
                printf("\n");
            }
            CopyWordFile();
            int reqPertemanan = atoi(currentWordFile.TabWord);
            printf("%d\n", reqPertemanan);
            ADVFILE();
            PrioQueueChar(reqTeman);
            MakeEmpty(&reqTeman, jumlahUser);
            for (int i = 0; i < reqPertemanan; i++)
            {
                int temp = atoi(&currentCharFile);
                for (int j = 0; j < jumlahUser; j++)
                {
                    printf("id minta %d ", temp);
                    Pengguna pengguna = dataPengguna.contents[j];
                    if (pengguna.id == temp)
                    {
                        ADVFILE();
                        ADVFILE();
                        temp = atoi(&currentCharFile);
                        printf("id diminta %d ", temp);
                        ADVFILE();
                        ADVFILE();
                        Enque(pengguna.permintaan_teman, temp);
                        temp = atoi(&currentCharFile);
                        printf("teman %d \n", temp);
                        ADVFILE();
                        ADVFILE();
                    }
                }
            }
        }
        StopWordFile(inputFile.TabWord);

        // Baca konfig kicauan
        writeWord(&locFile, "/kicauan.config", 15);
        inputFile = writefilename(config, locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        STARWORDFILE(inputFile.TabWord);
        int jumlahKicauan = atoi(currentWordFile.TabWord);
        createTabKicauan(&dataKicauan, jumlahKicauan);
        if (jumlahKicauan != 0)
        {
            for (int i = 0; i < jumlahKicauan; i++)
            {
                Kicauan temp;
                for (int j = 0; j < 3; j++)
                {
                    ADVFILE();
                    CopyWordFile();
                    for (int i = 0; i < currentWordFile.Length; i++)
                    {
                        printf("%c", currentWordFile.TabWord[i]);
                    }
                    printf("\n");
                }
                ADVFILE();
                CopyWordFile();
                int id = atoi(currentWordFile.TabWord);
                temp.IDKicau = id;
                ADVFILE();
                Word tempp = CopyWordFile2();
                temp.Text = tempp;
                ADVFILE();
                CopyWordFile();
                int like = atoi(currentWordFile.TabWord);
                temp.Like = like;
                ADVFILE();
                CopyWordFile();
                tempp = CopyWordFile2();
                Sentence author;
                author.TabWord[0] = tempp;
                author.Length = 1;
                temp.Author = author;
                ADVFILE();
                int day = atoi(currentCharFile);
                ADVFILE();
                day = atoi(currentCharFile) + (10 * day);
                ADVFILE();
                printf("%c", currentCharFile);
                ADVFILE();
                int month = atoi(currentCharFile);
                ADVFILE();
                month = atoi(currentCharFile) + (10 * month);
                ADVFILE();
                printf("%c", currentCharFile);
                ADVFILE();
                int year = atoi(currentCharFile) * 1000;
                ADVFILE();
                year = (atoi(currentCharFile) * 100) + year;
                ADVFILE();
                year = (atoi(currentCharFile) * 10) + year;
                ADVFILE();
                year = (atoi(currentCharFile)) + year;
                ADVFILE();
                printf("%c", currentCharFile);
                ADVFILE();
                int hh = atoi(currentCharFile) * 10;
                ADVFILE();
                hh = atoi(currentCharFile) + hh;
                ADVFILE();
                printf("%c", currentCharFile);
                ADVFILE();
                int mm = atoi(currentCharFile) * 10;
                ADVFILE();
                mm = atoi(currentCharFile) + mm;
                ADVFILE();
                printf("%c", currentCharFile);
                ADVFILE();
                int ss = atoi(currentCharFile) * 10;
                ADVFILE();
                ss = atoi(currentCharFile) + ss;
                ADVFILE();
                DATETIME date;
                CreateDATETIME(&date, day, month, year, hh, mm, ss);
                temp.DateTime = date;
                addKicauanToTab(&dataKicauan, temp);
            }
        }
        StopWordFile(inputFile.TabWord);

        // Baca konfig balasan
        writeWord(&locFile, "/balasan.config", 15);
        inputFile = writefilename(config, locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        STARWORDFILE(inputFile.TabWord);
        jumlahKicauan = atoi(currentWordFile.TabWord);
        printf("%d\n", jumlahKicauan);
        if (jumlahKicauan != 0)
        {
            for (int i = 0; i < jumlahKicauan; i++)
            {
                TabBalasan tabbalasan;
                ADVFILE();
                CopyWordFile();
                int id = atoi(currentWordFile.TabWord);
                Kicauan kicau;
                for (int a = 0; a < jumlahKicauan; a++)
                {
                    Kicauan temp = dataPengguna.contents[a];
                    if (id == temp.IDKicau)
                    {
                        kicau = temp;
                    }
                }
                ADVFILE();
                CopyWordFile();
                int jumlahBalasan = atoi(currentWordFile.TabWord);
                createTabBalasan(jumlahBalasan);
                for (int j = 0; j < jumlahBalasan; j++)
                {
                    Balasan balas;
                    ADVFILE();
                    printf("%c", currentCharFile);
                    if (currentCharFile == '-')
                    {
                        ADVFILE();
                        int idparent = atoi(currentCharFile);
                        balas.IDParent = kicau.IDKicau;
                    }
                    else
                    {
                        int idparent = atoi(currentCharFile);
                        for (int b = 0; b < jumlahBalasan; b++)
                        {
                            Balasan temp = tabbalasan.buffer[b];
                            if (idparent == temp.IDBalasan)
                            {
                                balas.IDParent = kicau.IDKicau;
                            }
                        }
                    }
                    ADVFILE();
                    ADVFILE();
                    int idbalas = atoi(currentCharFile);
                    balas.IDBalasan = idbalas;
                    ADVFILE();
                    ADVFILE();
                    Word temptext = CopyWordFile2();
                    Sentence text;
                    text.TabWord[0] = temptext;
                    text.Length = 1;
                    balas.konten = text;
                    ADVFILE();
                    Word nama = CopyWordFile2();
                    text.TabWord[0] = temptext;
                    text.Length = 1;
                    balas.author = text;
                    ADVFILE();
                    int day = atoi(currentCharFile);
                    ADVFILE();
                    day = atoi(currentCharFile) + (10 * day);
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int month = atoi(currentCharFile);
                    ADVFILE();
                    month = atoi(currentCharFile) + (10 * month);
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int year = atoi(currentCharFile) * 1000;
                    ADVFILE();
                    year = (atoi(currentCharFile) * 100) + year;
                    ADVFILE();
                    year = (atoi(currentCharFile) * 10) + year;
                    ADVFILE();
                    year = (atoi(currentCharFile)) + year;
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int hh = atoi(currentCharFile) * 10;
                    ADVFILE();
                    hh = atoi(currentCharFile) + hh;
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int mm = atoi(currentCharFile) * 10;
                    ADVFILE();
                    mm = atoi(currentCharFile) + mm;
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int ss = atoi(currentCharFile) * 10;
                    ADVFILE();
                    ss = atoi(currentCharFile) + ss;
                    ADVFILE();
                    DATETIME date;
                    CreateDATETIME(&date, day, month, year, hh, mm, ss);
                    balas.waktu = date;
                }
            }
        }
        StopWordFile(inputFile.TabWord);

        writeWord(&locFile, "/draf.config", 12);
        inputFile = writefilename(config, locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        STARWORDFILE(inputFile.TabWord);
        int jumlahPengguna = atoi(currentWordFile.TabWord);
        printf("\n%d\n", jumlahPengguna);
        if (jumlahPengguna != 0)
        {
            for (int i = 0; i < jumlahPengguna; i++)
            {
                Draf draf;
                CreateDraf(&draf);
                ADVFILE();
                int j, k;
                j = 0;
                k = 0;
                Word temp[10];
                temp[k].Length = 0;
                while (currentCharFile != MARK_FILE)
                {
                    if (i < NMax)
                    {
                        temp[k].TabWord[j] = currentCharFile;
                        temp[k].Length++;
                    }
                    if (currentCharFile == BLANK)
                    {
                        k++;
                        j = 0;
                        temp[k].Length = 0;
                    }
                    else
                    {
                        j++;
                    }
                    ADVFILE();
                }
                Word username;
                username.Length = 0;
                int t = 0;
                for (int p = 0; p < k; p++)
                {
                    for (j = 0; j < temp[p].Length; j++)
                    {
                        if (!(j == temp[p].Length - 1 && p == k - 1))
                        {
                            username.TabWord[t] = temp[p].TabWord[j];
                            username.Length++;
                            t++;
                        }
                    }
                }
                for (int j = 0; j < username.Length; j++)
                {
                    printf("%c", username.TabWord[j]);
                }
                int jumlahdraf = atoi(temp[k].TabWord);
                printf(" %d\n", jumlahdraf);
                for (int c = 0; c < jumlahUser; c++)
                {
                    Pengguna temp = dataPengguna.contents[i];
                    Sentence tempnama;
                    tempnama = temp.nama;
                    Word temppp = tempnama.TabWord[0];
                    if (compareCharArrays(&temppp.TabWord, &username.TabWord))
                    {
                        temp.drafkicauan = draf;
                    }
                }
                Node tempnode;
                Address addressnode;
                addressnode = createNode(&tempnode);
                draf.addrTop = addressnode;
                for (int l = 0; l < jumlahdraf; l++)
                {
                    Kicauan kicau;
                    ADVFILE();
                    Word temptext = CopyWordFile2();
                    kicau.Text = temptext;
                    ADVFILE();
                    int day = atoi(currentCharFile);
                    ADVFILE();
                    day = atoi(currentCharFile) + (10 * day);
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int month = atoi(currentCharFile);
                    ADVFILE();
                    month = atoi(currentCharFile) + (10 * month);
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int year = atoi(currentCharFile) * 1000;
                    ADVFILE();
                    year = (atoi(currentCharFile) * 100) + year;
                    ADVFILE();
                    year = (atoi(currentCharFile) * 10) + year;
                    ADVFILE();
                    year = (atoi(currentCharFile)) + year;
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int hh = atoi(currentCharFile) * 10;
                    ADVFILE();
                    hh = atoi(currentCharFile) + hh;
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int mm = atoi(currentCharFile) * 10;
                    ADVFILE();
                    mm = atoi(currentCharFile) + mm;
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int ss = atoi(currentCharFile) * 10;
                    ADVFILE();
                    ss = atoi(currentCharFile) + ss;
                    ADVFILE();
                    DATETIME date;
                    CreateDATETIME(&date, day, month, year, hh, mm, ss);
                    kicau.DateTime = date;
                    tempnode.info = kicau;
                    addressnode = createNode(&temp);
                }
            }
        }
        StopWordFile(inputFile.TabWord);

        writeWord(&locFile, "/utas.config", 12);
        inputFile = writefilename(config, locFile);
        tempFile = fopen(inputFile.TabWord, "r");
        STARWORDFILE(inputFile.TabWord);
        jumlahKicauan = atoi(currentWordFile.TabWord);
        createTabUtas(jumlahKicauan);
        if (jumlahKicauan != 0)
        {
            for (int k = 0; k < jumlahKicauan; k++)
            {
                Utas utas;
                ADVFILE();
                CopyWordFile();
                int id = atoi(currentWordFile.TabWord);
                Create_Utas(id);
                printf("%d\n", id);
                ADVFILE();
                Word tempS = CopyWordFile2();
                int banyakUtas = atoi(tempS.TabWord);
                TabKicauanSambungan tabkicauansambungan;
                createTabKicauanSambungan(&tabkicauansambungan);
                printf("%d\n", banyakUtas);
                for (int j = 0; j < banyakUtas; j++)
                {
                    KicauanSambungan kicauansambungan;
                    ADVFILE();
                    Word temptext = CopyWordFile2();
                    Sentence text;
                    text.TabWord[0] = temptext;
                    text.Length = 1;
                    kicauansambungan.pesan[0] = text;
                    printf("\n");
                    ADVFILE();
                    Word temptext2 = CopyWordFile2();
                    Sentence text2;
                    text2.TabWord[0] = temptext2;
                    text2.Length = 1;
                    kicauansambungan.author = text2;
                    printf("\n");
                    ADVFILE();
                    int day = atoi(currentCharFile);
                    ADVFILE();
                    day = atoi(currentCharFile) + (10 * day);
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int month = atoi(currentCharFile);
                    ADVFILE();
                    month = atoi(currentCharFile) + (10 * month);
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int year = atoi(currentCharFile) * 1000;
                    ADVFILE();
                    year = (atoi(currentCharFile) * 100) + year;
                    ADVFILE();
                    year = (atoi(currentCharFile) * 10) + year;
                    ADVFILE();
                    year = (atoi(currentCharFile)) + year;
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int hh = atoi(currentCharFile) * 10;
                    ADVFILE();
                    hh = atoi(currentCharFile) + hh;
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int mm = atoi(currentCharFile) * 10;
                    ADVFILE();
                    mm = atoi(currentCharFile) + mm;
                    ADVFILE();
                    printf("%c", currentCharFile);
                    ADVFILE();
                    int ss = atoi(currentCharFile) * 10;
                    ADVFILE();
                    ss = atoi(currentCharFile) + ss;
                    ADVFILE();
                    DATETIME date;
                    CreateDATETIME(&date, day, month, year, hh, mm, ss);
                    kicauansambungan.waktu = date;
                    insertLastTabKicauanSambungan(&tabkicauansambungan, kicauansambungan);
                }
            }
        }
        StopWordFile(inputFile.TabWord);

        printf("\n");
        printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
    }

    statusProgram = true;
}