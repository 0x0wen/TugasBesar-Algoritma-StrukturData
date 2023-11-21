#include "commandPermintaanTeman.h"


void TAMBAH_TEMAN(Pengguna p) {
    if (IsEmpty_PrioQueue(p.permintaan_teman)){
        printf("Masukkan nama pengguna:\n");
        STARTWORD();
        Word name = currentWord ;
        Pengguna A ;
        for (int i = 0; i < len(dataPengguna); i++){
            if(IsWordEqual(name, SelectPengguna(dataPengguna, i).nama)){
                A = SelectPengguna(dataPengguna, i) ;
            }
        }
        if (IdPengguna(A) == IDX_UNDEF){
            printf("Pengguna bernama ") ;
            printWord(name) ;
            printf(" tidak ditemukan.") ;
        }else{
            MakeEmpty(&p.permintaan_teman, 20) ;
            printf("\nPermintaan pertemanan kepada ");
            printWord(name);
            printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
            infotype req = {JUMLAH_TEMAN(name) , name};
            Enqueue(&p.permintaan_teman, req);
        }
    }else{
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
}

void DAFTAR_PERMINTAAN_PERTEMANAN(Pengguna p) {
    PrintPrioQueueChar(p.permintaan_teman);
}

void SETUJUI_PERTEMANAN(Pengguna p) {
    printf("Permintaan pertemanan teratas dari ");
    printWord(InfoHead(p.permintaan_teman));
    printf("| ");
    printWord(InfoHead(p.permintaan_teman));
    printf("| Jumlah teman: %d\n", Prio(Elmt(p.permintaan_teman, Head(p.permintaan_teman) )) );

    printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
    STARTWORD();
    Word pilihan = currentWord ;
    Word YA = {"YA", 2};
    Word TIDAK = {"TIDAK", 5};
    Pengguna Y = InfoHead(p.permintaan_teman) ; //Pengguna yang request pertemanan ke Pengguna p
    infotype Z ;

    if(IsWordEqual(pilihan, YA)){
        addFriend(IdPengguna(p), IdPengguna(Y));
        printf("Permintaan pertemanan dari ");
        printWord(InfoHead(p.permintaan_teman));
        printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
        printWord(InfoHead(p.permintaan_teman));
        printf(".\n") ;
        Dequeue(&p.permintaan_teman, &Z) ;
    }else{
        printf("Permintaan pertemanan dari ");
        printWord(InfoHead(p.permintaan_teman));
        printf(" telah ditolak.\n") ;
        Dequeue(&p.permintaan_teman, &Z) ;
    }
}