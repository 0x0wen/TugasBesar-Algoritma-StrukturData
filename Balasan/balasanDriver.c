
#include <stdio.h>
#include "balasan.h"
#include "kicauan.h"

int main()
{
    Kicauan K1;
    Balasan B1, B2, B3;
    TreeBalasan T1;
    createBalasan(B1);
    addBalasan(&K1, &B1);
    addBalasan(&K1, &B2);
    addBalasan(&K1, &B3);
    removeNode(&K1);
    searchBalasan(&K1, &B2);
    displayAllBalasan(T1, 1);

    return 0;
}