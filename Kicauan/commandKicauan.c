#include "commandKicauan.h"
#include "../global.h"

/*** Prosedur Kicauan yang berkaitan dengan spek ***/
void KICAU(){

    printf("\nMasukkan kicauan:\n");
    Sentence text; InputSentence(&text);

    if (isSentenceOnlyBlank(text)){
        printf("\nKicauan tidak boleh hanya berisi spasi!\n");
    } else {
        int id = MAXID_TAB_KICAUAN(dataKicauan) + 1;
        Sentence author = NAMA_PENGGUNA(penggunaSekarang);

        Kicauan newKicau = createKicauan(id, text, author);
        addKicauanToTab(&dataKicauan, newKicau);

        printf("Selamat! kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        printDetilKicauan(newKicau);
    }
}

void KICAUAN(){

    int i;
    for (i = 0; i < NEFF_TAB_KICAUAN(dataKicauan); i++){
        if (IsSentenceEqual(SELECT_KICAUAN(dataKicauan, i).Author, NAMA_PENGGUNA(penggunaSekarang))){
            printf("\n");
            printKicauan(SELECT_KICAUAN(dataKicauan, i));
        } 
    }
}

void SUKA_KICAUAN(int id){

    if (isKicauanInTab(&dataKicauan, id)){

        int i, idx = getKicauanIdx(dataKicauan, id);
        Sentence author_name = SELECT_KICAUAN(dataKicauan, idx).Author;
        Pengguna author;

        for (i = 0; i < dataPengguna.length; i++){
            if (IsSentenceEqual(SELECT_PENGGUNA(dataPengguna, i), author_name)){
                author = SELECT_PENGGUNA(dataPengguna, i);
            }
        }
   
        if (IsSentenceEqual(SELECT_KICAUAN(dataKicauan, i).Author, NAMA_PENGGUNA(penggunaSekarang)) || 
            !author.privat || 
            isFriend(ID_PENGGUNA(penggunaSekarang), ID_PENGGUNA(author))){
            
            SELECT_KICAUAN(dataKicauan, idx).Like++;
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detil kicauan:");
            printKicauan( SELECT_KICAUAN(dataKicauan, idx));
            
        } else {
            printf("\nWah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya");
        }

    } else {
        printf("Tidak ditemukan kicauan dengan ID = %d;", id);
    }
}

void UBAH_KICAUAN(int id){

    if (isKicauanInTab(&dataKicauan, id)){

        int i, idx = getKicauanIdx(dataKicauan, id);

        if (!IsSentenceEqual(SELECT_KICAUAN(dataKicauan, idx).Author, NAMA_PENGGUNA(penggunaSekarang))){
            printf("\nKicauan dengan ID = %d bukan milikmu!", id);
        } else {
            printf("\nMasukkan kicauan baru: \n");
            Sentence text; InputSentence(&text);
            SELECT_KICAUAN(dataKicauan, idx).Text = text;
            printf("\nSelamat! kicauan telah diterbitkan!");
            printKicauan(SELECT_KICAUAN(dataKicauan, idx));
        }
    } else {
        printf("\nTidak ditemukan kicauan dengan ID = %d!;", id);
    }
}
