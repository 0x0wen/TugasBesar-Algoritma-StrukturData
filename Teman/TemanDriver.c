#include <stdio.h>
#include "tabTeman.h"
#include "pengguna.h"
#include "tabPengguna.h"

int main(){
    STARTWORD();
    Word user1 = currentWord;
    STARTWORD();
    Word user2 = currentWord;

    IsFriendWord(user1, user2) ;
    JUMLAH_TEMAN(user1);
    JUMLAH_TEMAN(user2);

    Pengguna user;
    DAFTAR_TEMAN(user);
    HAPUS_TEMAN(user);



}