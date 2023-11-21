#include "commandKicauan.h"

/*** Prosedur Kicauan yang berkaitan dengan spek ***/
void KICAU(){

    printf("\nMasukkan kicauan:\n");
    Kicauan newKicau = createKicauan();

    // add newKicau ke tab
    addKicauanToTab(&dataKicauan, newKicau);

    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:");
    newKicau.IDKicau = MAXID(dataKicauan);

    printKicauan(newKicau);
}

void KICAUAN(){

    int i;
    for (i = 0; i < NEFF(dataKicauan); i++){
        if (ELMT(dataKicauan, i).Author == penggunaSekarang){
            printf("\n");
            printKicauan(ELMT(dataKicauan, i));
        } 
    }
}

void SUKA_KICAUAN(int id){


    if (isKicauanInTab(&dataKicauan, id)){

        int i, idx = getKicauanIdx(dataKicauan, id);

        Word Publik = {"Publik", 6};
   
        if (dataKicauan[idx].Author == penggunaSekarang || 
            IsWordEqual(dataKicauan[idx].Author.jenisAkun,Publik) /*|| 
            isFriend(penggunaSekarang, dataKicauan[idx].Author) */){
            
            dataKicauan[idx].Likes++;
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detil kicauan:");

            printKicauan(dataKicauan[idx]);
            
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

        if (dataKicauan[idx].Author != penggunaSekarang){
            printf("\nKicauan dengan ID = %d bukan milikmu!", id);
        } else {

            printf("\nMasukkan kicauan baru: \n");
            Word text; InputWordWithBlank(&text);
            dataKicauan[idx].Text = text;
            printf("\nSelamat! kicauan telah diterbitkan!");
            printKicauan(dataKicauan[idx]);
        }
    } else {
        printf("\nTidak ditemukan kicauan dengan ID = %d!;", id);
    }
}
