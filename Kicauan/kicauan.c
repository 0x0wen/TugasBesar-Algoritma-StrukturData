#include "kicauan.h"
#include <stdio.h>
#include <stdlib.h>

/*** Kreator/Deletor Tab Kicauan ***/
void createTabKicauan(TabKicauan *t, int capacity)
{

    TAB(*t) = (Kicauan *)malloc(capacity * sizeof(Kicauan));

    /* Kalau malloc berhasil capacity(t) = capacity
       kalau gagal capacity = 0;*/
    if (TAB(*t) != NULL)
    {
        CAPACITY(*t) = capacity;
    }
    else
    {
        CAPACITY(*t) = 0;
    }

    NEFF(*t) = 0;
}

void deleteTabKicauan(TabKicauan *t)
{

    free(TAB(*t));
    CAPACITY(*t) = 0;
    NEFF(*t) = 0;
}

/*** Add/Delete Kicauan from Tab ***/
void addKicauanToTab(TabKicauan *t, Kicauan k)
{

    if (NEFF(*t) < CAPACITY(*t))
    {
        // do nothing
    }
    else
    {
        // expand dulu list nya by 1P
        expandList(t, 1);
    }
    // assign k ke indeks ke-neff di t
    ELMT(*t, NEFF(*t)) = k;
    NEFF(*t)
    ++;
}
// Owen : nambahin fungsi buat ngecek ada kicauan dengan id tertentu di tab atau tidak
boolean isKicauanInTab(TabKicauan *t, int id)
{
    int i;
    boolean found;
    found = false;
    for (i = 0; i < NEFF(*t); i++)
    {
        if ((ELMT(*t, i)).IDKicau == id)
        {
            found = true;
            break;
        }
    }
    return found;
}
void deleteKicauanFromTab(TabKicauan *t, Kicauan *k, int id)
{

    int idxStart, i;
    boolean found = false;

    for (i = 0; i < NEFF(*t); i++)
    {

        if (found)
        { // geser elemen ke-i mundur ke-(i-1)
            ELMT(*t, i - 1) = ELMT(*t, i);
        }
        if ((ELMT(*t, i)).IDKicau == id)
        {
            *k = ELMT(*t, i);
            found = true;
        }
    }
    if (found)
    {
        NEFF(*t)
        --;
    }
}

/*** Mengubah Ukuran Tab ***/
void expandList(TabKicauan *t, int num);
void shrinkList(TabKicauan *t, int num);
void compressList(TabKicauan *t);

/*** Prosedur Kicauan ***/

/** Membuat kicauan baru kemudian memasukkannya ke list **/
void createKicauan(TabKicauan *t)
{

    // inisialisasi
    Kicauan newKicau;

    // id kicauan baru adalah id kicauan terakhir pada list ditambah 1
    int newID = ID(ELMT(*t, NEFF(*t) - 1)) + 1;

    // ini gtw napa kalo make selektor
    // ID(newKicau) = newID;
    // TEXT(newKicau) = "kicauan baru";
    // LIKE(newKicau) = 0;
    // AUTHOR(newKicau) = "rafi";
    // TIME(newKicau) = "otw";

    addKicauanToTab(t, newKicau);
}

void printKicauan(Kicauan k)
{

    // printf();
}