#include <stdio.h>
#include "prioqueue.h"
#include "tabTeman.h"

int main(){
    Pengguna user ;
    TAMBAH_TEMAN(user);
    
    DAFTAR_PERMINTAAN_PERTEMANAN(user);
    SETUJUI_PERTEMANAN(user);
}