#include <stdio.h>
#include "utas.h"
#include "sentenceMachine.h"

Address newNode(ElType val)
{

    Address NODE = (Address)malloc(sizeof(Node));

    if (NODE != NULL)
    {
        INFO(NODE) = val;
        NEXT(NODE) = NULL;
    }

    return NODE;
}

void CreateList(TabKicauanSambungan *T)
{
    FIRST(*T) = NULL;
}

boolean isEmpty(TabKicauanSambungan T)
{

    return FIRST(T) == NULL;
}

int indexOf(TabKicauanSambungan T, ElType val)
{

    Address NODE = FIRST(T);

    int IDX = 0;
    boolean FOUND = false;

    while (NODE != NULL && !FOUND)
    {
        if (INFO(NODE) == val)
        {
            FOUND = true;
        }
        else
        {
            IDX++;
            NODE = NEXT(NODE);
        }
    }

    if (FOUND)
    {
        return IDX;
    }
    else
    {
        return IDX_UNDEF;
    }
}

void insertFirst(TabKicauanSambungan *T, ElType val)
{

    Address NEWNODE = newNode(val);

    if (NEWNODE != NULL)
    {
        NEXT(NEWNODE) = FIRST(*T);
        FIRST(*T) = NEWNODE;
    }
}

void insertLast(TabKicauanSambungan *T, ElType val)
{

    if (isEmpty(*T))
    {
        insertFirst(l, val);
    }
    else
    {

        Address NODE = FIRST(*T);

        while (NEXT(NODE) != NULL)
        {
            NODE = NEXT(NODE);
        }

        Address NEWNODE = newNode(val);

        if (NEWNODE != NULL)
        {
            NEXT(NODE) = NEWNODE;
        }
    }
}

void insertAt(TabKicauanSambungan *T, ElType val, int idx)
{

    if (idx == 0)
    {
        insertFirst(l, val);
    }
    else
    {

        Address NEWNODE = newNode(val);

        if (NEWNODE != NULL)
        {
            Address NODE = FIRST(*T);

            int i;
            for (i = 0; i < idx - 1; i++)
            {
                NODE = NEXT(NODE);
            }
            NEXT(NEWNODE) = NEXT(NODE);
            NEXT(NODE) = NEWNODE;
        }
    }
}
void deleteFirst(TabKicauanSambungan *T, ElType *val)
{

    Address NODE = FIRST(*T);
    *val = INFO(NODE);

    FIRST(*T) = NEXT(NODE);
    free(NODE);
}
void deleteLast(TabKicauanSambungan *T, ElType *val)
{

    Address NODE = NULL;
    Address LAST = FIRST(*T);

    while (NEXT(LAST) != NULL)
    {
        NODE = LAST;
        LAST = NEXT(LAST);
    }

    if (NODE == NULL)
    {
        FIRST(*T) = NULL;
    }
    else
    {
        NEXT(NODE) = NULL;
    }

    *val = INFO(LAST);
    free(LAST);
}
void deleteAt(TabKicauanSambungan *T, int idx, ElType *val)
{

    if (idx == 0)
    {
        deleteFirst(l, val);
    }
    else
    {
        Address NODE = FIRST(*T);

        int i;

        for (i = 0; i < idx - 1; i++)
        {
            NODE = NEXT(NODE);
        }

        Address DELETE = NEXT(NODE);

        *val = INFO(DELETE);

        NEXT(NODE) = NEXT(DELETE);
        free(DELETE);
    }
}
void displayList(TabKicauanSambungan T)
{

    printf("[");

    if (!isEmpty(T))
    {
        Address NODE = FIRST(T);

        while (NEXT(NODE) != NULL)
        {
            printf("%d,", INFO(NODE));
            NODE = NEXT(NODE);
        }
        printf("%d", INFO(NODE));
    }

    printf("]");
}

int length(TabKicauanSambungan T)
{

    if (isEmpty(T))
    {
        return 0;
    }

    int len = 1;
    Address NODE = FIRST(T);

    while (NEXT(NODE) != NULL)
    {
        NODE = NEXT(NODE);
        len++;
    }

    return len;
}

void Create_Utas(int IDKicau)
{
    if (IDKicau bukan punya user)
    {
        printf("Utas ini bukan milik anda!");
    }
    else if (Kicauan sudah menjadi kicauan utama utas lain)
    {
    }
    else if (IDKicau not found)
    {
        printf("Kicauan tidak ditemukan\n");
    }
    else
    {

        printf("Utas berhasil dibuat!\n");
        do
        {
            printf("Masukkan kicauan: \n");
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)");
        } while (kata == "YA");
        printf("Utas selesai!\n");
    }
}
void Sambung_Utas(int IDUtas, int index)
{
    if (index lewat batas)
    {
        printf("Index terlalu tinggi!\n");
    }
    else if (IDUtas not found)
    {
        printf("Utas tidak ditemukan!\n");
    }
    else if (Utas not owned by user)
    {
        printf("Anda tidak bisa menyambung utas ini!");
    }
};
void Hapus_Utas(int IDUtas, int index)
{
    if (utas not found)
    {
        printf("Utas tidak ditemukan!");
    }
    else if (index not found)
    {
        printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!", index);
    }
    else if (index == 0)
    {
        printf("Anda tidak bisa menghapus kicauan utama!");
    }
    else if (utas is not owned by user)
    {
        printf("Anda tidak bisa menghapus kicauan dalam utas ini!");
    }
    else
    {
        printf("Kicauan sambungan berhasil dihapus!");
        // algoritma hapus
        // ...
    }
}
void Cetak_Utas(int IDUtas)
{
    if (utas not found)
    {
        printf("Utas tidak ditemukan!");
    }
    else if (utas owner is private)
    {
        printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!");
    }
    else
    {
        int i;
        printf("| ID = %d", IDUtas);
        printf("| %s");
        printf("| %s");
        printf("| ");
        PrintSentence();
        for (i = 0; i < length; i++)
        {
            printf("\t| INDEX = %d");
            printf("\t| %s");
            printf("\t| %s");
            printf("\t| ");
            PrintSentence();
            printf("\n");
        }
    }
};
