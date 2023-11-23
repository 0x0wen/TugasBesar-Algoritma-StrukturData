#include "commandPermintaanTeman.h"
#include "../Teman/teman.h"

void TAMBAH_TEMAN(){

    Pengguna current_user = penggunaSekarang;

    if (IsEmpty_PQR(current_user.daftarPermintaanTeman))
    {
        printf("Masukkan nama pengguna:\n");
        Sentence input_name; InputSentence(&input_name);
        Pengguna send_to; int userid;

        int i;
        for (i = 0; i < dataPengguna.length; i++)
        {
            if (IsSentenceEqual(input_name, SELECT_PENGGUNA(dataPengguna, i).nama))
            {
                send_to = SELECT_PENGGUNA(dataPengguna, i);
            }
        }
        if (ID_PENGGUNA(send_to) == IDX_UNDEF)
        {
            printf("Pengguna bernama ");
            printSentence(input_name);
            printf(" tidak ditemukan.");
        }
        else
        {   
            // harus diinisialisasi saat config / create user, bkn disini
            // MakeEmpty(&p.permintaan_teman, 20);
            printf("\nPermintaan pertemanan kepada ");
            printSentence(input_name);
    
            Requester send_val = {countFriend(matrixTeman, ID_PENGGUNA(penggunaSekarang)), ID_PENGGUNA(current_user)};
            enqueue_PQR(&(send_to.daftarPermintaanTeman), send_val);

            printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
        }
    }
    else
    {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
}

void DAFTAR_PERMINTAAN_PERTEMANAN()
{   
    PrioQueueRequest current = penggunaSekarang.daftarPermintaanTeman;

    if (IsEmpty_PQR(current)){
        printf("\nTidak ada permintaan pertemanan untuk Anda.\n");
    } else {

        printf("\nTerdapat %d permintaan pertemanan untuk Anda.\n", nEff_PQR(current));
        int i,j;
        for(i = 0; i < nEff_PQR(current); i++){

            Pengguna sender;
            for (j = 0; j < dataPengguna.length; j++){
                if (ID_PENGGUNA(SELECT_PENGGUNA(dataPengguna, j)) == ELMT_PQR(current, i).id_requester){
                    sender = SELECT_PENGGUNA(dataPengguna, j); 
                    break;
                }
            }
            printf("| "); printSentence(NAMA_PENGGUNA(sender));
            printf("| Jumlah teman: %d\n", PRIO(ELMT_PQR(current, i)));
        }
    }
}

void SETUJUI_PERTEMANAN()
{   
    Pengguna current_user = penggunaSekarang;
    if (IsEmpty_PQR(current_user.daftarPermintaanTeman)){
        printf("Permintaan pertemanan Anda kosong!");
    }
    else {
    
        Requester req_val = INFO_HEAD_PQR(current_user.daftarPermintaanTeman);
        Pengguna sender;

        int i;
        for (i = 0; i < dataPengguna.length; i++)
        {
            if (INFO_HEAD_PQR(current_user.daftarPermintaanTeman).id_requester == ID_PENGGUNA(SELECT_PENGGUNA(dataPengguna, i))){
                sender = SELECT_PENGGUNA(dataPengguna, i);
            }
        }

        printf("Permintaan pertemanan teratas dari "); printSentence(NAMA_PENGGUNA(sender));
        printf("\n");
        printf("| "); printSentence(NAMA_PENGGUNA(sender));
        printf("| Jumlah teman: %d\n", PRIO(req_val));

        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
        Word pilihan; InputWord(&pilihan);

        Word YA = {"YA", 2};
        Word TIDAK = {"TIDAK", 5};

        if (IsWordEqual(pilihan, YA)){
            addFriend(&matrixTeman, ID_PENGGUNA(current_user), ID_PENGGUNA(sender));

            printf("Permintaan pertemanan dari "); printSentence(NAMA_PENGGUNA(sender));
            printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
            printSentence(NAMA_PENGGUNA(sender));
            printf(".\n");

            dequeue_PQR(&(current_user.daftarPermintaanTeman));

        } else if (IsWordEqual(pilihan, TIDAK)){
            printf("Permintaan pertemanan dari "); printSentence(NAMA_PENGGUNA(sender));
            printf(" telah ditolak.\n");

            dequeue_PQR(&(current_user.daftarPermintaanTeman));
        }
    }
}