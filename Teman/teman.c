#include <stdio.h>
#include "teman.h"
#include "tabTeman.h"
#include "pengguna.h"
#include "tabPengguna.h"

boolean IsFriendWord(Word user1, Word user2) {
    int idx1 = idPengguna(user1);
    int idx2 = idPengguna(user2);

    return (HUBUNGAN(dataTeman, idx1, idx2) == 1);
}

