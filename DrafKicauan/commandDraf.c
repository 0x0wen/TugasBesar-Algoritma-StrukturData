#include "draf.h"
#include "../global.h"

void BUAT_DRAF(){

    printf("\nMasukkan draf:\n");
    Sentence text; InputSentence(&text);
    int id = -1;
    Sentence author = NAMA_PENGGUNA(penggunaSekarang);
    Kicauan draf_kicau = createKicauan(id, text, author);

    // HAPUS; SIMPAN; TERBIT; ?
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?");
    Word action; InputWord(&action);

    Word Hapus = {"HAPUS", 5};
    Word Simpan = {"SIMPAN", 6};
    Word Terbit = {"TERBIT", 6};

    if (IsWordEqual(action, Hapus)){
        printf("\nDraf telah berhasil dihapus!");
    }
    else if (IsWordEqual(action, Simpan)){
        pushDraf(&penggunaSekarang.drafKicauan, draf_kicau);
        printf("\nDraf telah berhasil disimpan!");
    }
    else /* isWordEqual(action, Terbit)*/{
        draf_kicau.IDKicau = MAXID_TAB_KICAUAN(dataKicauan)+1;
        addKicauanToTab(&dataKicauan, draf_kicau);
        printf("Selamat! draf kicauan telah diterbitkan!\n");
        printf("Detil kicauan:");
        printKicauan(draf_kicau);
    }
}

void LIHAT_DRAF(){

    if (isEmptyDraf(penggunaSekarang.drafKicauan)){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D");

    } else {

        Kicauan draf_kicau;
        popDraf(&penggunaSekarang.drafKicauan, &draf_kicau);

        printf("Ini draf terakhir anda:");
        printf("| "); TulisDATETIME(draf_kicau.DateTime); printf("\n");
        printf("| "); printSentence(draf_kicau.Text); printf("\n");

        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)");
        Word action; InputWordWithBlank(&action);

        Word Ubah = {"UBAH", 6};
        Word Hapus = {"HAPUS", 5};
        Word Terbit = {"TERBIT", 6};
        Word Kembali = {"KEMBALI", 7};

        if (IsWordEqual(action, Ubah)){
            printf("\nMasukkan draf yang baru:\n");

            Sentence new_text; InputSentence(&new_text);
            DATETIME new_time = getDATETIME();

            draf_kicau.Text = new_text;
            draf_kicau.DateTime = new_time;

            // HAPUS; SIMPAN; TERBIT; ?
            printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?");
            action; InputWordWithBlank(&action);

            Word Simpan = {"SIMPAN", 6};

            if (IsWordEqual(action, Hapus)){
                printf("\nDraf telah berhasil dihapus!");
            }
            else if (IsWordEqual(action, Simpan)){
                pushDraf(&penggunaSekarang.drafKicauan, draf_kicau);
                printf("\nDraf telah berhasil disimpan!");
            }
            else if (isWordEqual(action, Terbit)){
                draf_kicau.IDKicau = MAXID_TAB_KICAUAN(dataKicauan)+1;
                addKicauanToTab(&dataKicauan, draf_kicau);
                printf("Selamat! draf kicauan telah diterbitkan!\n");
                printf("Detil kicauan:");
                printDetilKicau(draf_kicau);
            }
        }
        else if (IsWordEqual(action, Hapus)){
            printf("\nDraf telah berhasil dihapus!");
        }
        else if(isWordEqual(action, Terbit)){
            draf_kicau.IDKicau = MAXID_TAB_KICAUAN(dataKicauan)+1;
            addKicauanToTab(&dataKicauan, draf_kicau);
            printf("Selamat! draf kicauan telah diterbitkan!\n");
            printf("Detil kicauan:");
            printKicauan(draf_kicau);
        }
    }
}
