#include <stdio.h>
#include "inisialisasi.c"
#include "../General/listDinamis.c"

int main(){
    ListDinPengguna pengguna;
    CreateListDin(&pengguna,20);
    inisialisasi(&pengguna);
}