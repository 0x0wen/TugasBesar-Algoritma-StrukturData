
#include <stdio.h>
#include "utas.h"
#include "commandUtas.h"

TabUtas dataUtas;

int main()
{
    Utas U1;
    TabKicauanSambungan TKS1;
    KicauanSambungan KS1;
    createTabKicauanSambungan(&TKS1);
    isTabKicauanSambunganEmpty(TKS1);
    indexOfTabKicauanSambungan(TKS1, KS1);
    insertFirstTabKicauanSambungan(&TKS1, KS1);
    insertLastTabKicauanSambungan(&TKS1, KS1);
    insertAtTabKicauanSambungan(&TKS1, KS1, 1);
    insertAtTabKicauanSambungan(&TKS1, KS1, 2);
    insertAtTabKicauanSambungan(&TKS1, KS1, 3);
    deleteFirstTabKicauanSambungan(&TKS1, &KS1);
    deleteLastTabKicauanSambungan(&TKS1, &KS1);
    deleteAtTabKicauanSambungan(&TKS1, 2, &KS1);
    displayTabKicauanSambungan(TKS1);
    lengthTabKicauanSambungan(TKS1);
    Cetak_Utas(ID_UTAS(U1));
    return 0;
}