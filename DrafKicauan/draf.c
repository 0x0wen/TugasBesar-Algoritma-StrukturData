#include "draf.h"
#include <stdio.h>

/* Prototype manajemen memori */
Address newNode(Kicauan x){
    Address p = (Address) malloc (sizeof(Node));
    if (p != NULL){
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   

/* ********* PROTOTYPE REPRESENTASI LOJIK Draf ***************/
boolean isEmpty(Draf s){
    return ADDR_TOP(s) == NIL;
}
/* Mengirim true jika Draf kosong: TOP(s) = NIL */

int length(Draf s){
    if (isEmpty(s)){
        return 0;
    } else {
        int len = 0;
        Address p = ADDR_TOP(s);
        while(p != NIL){
            len++;
            p = NEXT(p);
        }
        return len;
    }
}
/* Mengirimkan banyaknya elemen Draf. Mengirimkan 0 jika Draf s kosong */

void CreateDraf(Draf *s){
    ADDR_TOP(*s) = NIL;
}
/* I.S. sembarang */ 
/* F.S. Membuat sebuah Draf s yang kosong */

void DisplayDraf(Draf s){
    printf("[");
    if (!isEmpty(s)){
        Address p = ADDR_TOP(s);
        while (NEXT(p) != NIL){
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d", INFO(p));
    }
    printf("]");
}
/* Proses : Menuliskan isi Draf, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1 (TOP), 20, 30 akan dicetak: [1,20,30] */
/* Jika Draf kosong : menulis [] */

void push(Draf *s, Kicauan x){
    Address p = newNode(x);
    if (p != NULL){
        if (isEmpty(*s)){
            ADDR_TOP(*s) = p;
        } else {
            NEXT(p) = ADDR_TOP(*s);
            ADDR_TOP(*s) = p;
        } 
    }
}
/* Menambahkan x sebagai elemen Draf s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void pop(Draf *s, Kicauan *x){
    *x = INFO(ADDR_TOP(*s));
    if (length(*s) == 1){
        ADDR_TOP(*s) = NULL;
    } else {
        ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    }
}
/* Menghapus Top dari Draf s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */

// #endif

void BUAT_DRAF(Draf *s){

    printf("\nMasukkan draf:\n");
    Kicauan draf = createKicauan();

    // HAPUS; SIMPAN; TERBIT; ?
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?");
    Word action; InputWordWithBlank(&action);

    Word Hapus = {"HAPUS", 5};
    Word Simpan = {"SIMPAN", 6};
    Word Terbit = {"TERBIT", 6};

    if (IsWordEqual(action, Hapus)){
        printf("\nDraf telah berhasil dihapus!");
    }
    else if (IsWordEqual(action, Simpan)){
        push(s, draf);
        printf("\nDraf telah berhasil disimpan!");
    }
    else /* isWordEqual(action, Terbit)*/{
        addKicauanToTab(&dataKicauan, draf);
        printf("Selamat! draf kicauan telah diterbitkan!\n");
        printf("Detil kicauan:");
        printKicauan(draf);
    }

}
void LIHAT_DRAF(Draf *s){

    if (isEmpty(*s)){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D");

    } else {

        Kicauan draf;
        pop(s, &draf);

        printf("Ini draf terakhir anda:");
        printf("| "); printTime(draf.DateTime); printf("\n");
        printf("| "); printWord(draf.Text); printf("\n");

        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)");
        Word action; InputWordWithBlank(&action);

        Word Ubah = {"UBAH", 6};
        Word Hapus = {"HAPUS", 5};
        Word Terbit = {"TERBIT", 6};
        Word Kembali = {"KEMBALI", 7};

        if (IsWordEqual(action, Ubah)){
            printf("\nMasukkan draf yang baru:\n");
            Kicauan newdraf = createKicauan();

            // HAPUS; SIMPAN; TERBIT; ?
            printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?");
            action; InputWordWithBlank(&action);

            Word Simpan = {"SIMPAN", 6};

            if (IsWordEqual(action, Hapus)){
                printf("\nDraf telah berhasil dihapus!");
            }
            else if (IsWordEqual(action, Simpan)){
                push(s, newdraf);
                printf("\nDraf telah berhasil disimpan!");
            }
            else /* isWordEqual(action, Terbit)*/{
                addKicauanToTab(&dataKicauan, newdraf);
                printf("Selamat! draf kicauan telah diterbitkan!\n");
                printf("Detil kicauan:");
                newdraf.IDKicau = dataKicauan.maxID;
                printKicauan(newdraf);
            }
        }
        else if (IsWordEqual(action, Hapus)){
            printf("\nDraf telah berhasil dihapus!");
        }
        else /* isWordEqual(action, Terbit)*/{
            addKicauanToTab(&dataKicauan, draf);
            printf("Selamat! draf kicauan telah diterbitkan!\n");
            printf("Detil kicauan:");
            draf.IDKicau = dataKicauan.maxID;
            printKicauan(draf);
        }
    }
}
