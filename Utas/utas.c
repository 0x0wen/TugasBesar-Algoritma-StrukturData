#include <stdio.h>
#include "utas.h"
#include "sentenceMachine.h"

Address newKicauanSambungan(KicauanSambungan val)
{

    Address NODE = (Address)malloc(sizeof(Node));

    if (NODE != NULL)
    {
        INFO(NODE) = val;
        NEXT(NODE) = NULL;
    }

    return NODE;
}

void createTabKicauanSambungan(TabKicauanSambungan *T)
{
    FIRST(*T) = NULL;
}

boolean isTabKicauanSambunganEmpty(TabKicauanSambungan T)
{

    return FIRST(T) == NULL;
}

int indexOfTabKicauanSambungan(TabKicauanSambungan T, KicauanSambungan val)
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

void insertFirstTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val)
{

    Address NEWNODE = newNode(val);

    if (NEWNODE != NULL)
    {
        NEXT(NEWNODE) = FIRST(*T);
        FIRST(*T) = NEWNODE;
    }
}

void insertLastTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val)
{

    if (isKicauanSambunganEmpty(*T))
    {
        insertFirstTabKicauanSambungan(T, val);
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

void insertAtTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val, int idx)
{

    if (idx == 0)
    {
        insertFirstTabicauanSambungan(T, val);
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
void deleteFirstTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan *val)
{

    Address NODE = FIRST(*T);
    *val = INFO(NODE);

    FIRST(*T) = NEXT(NODE);
    free(NODE);
}
void deleteLastTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan *val)
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
void deleteAtTabKicauanSambungan(TabKicauanSambungan *T, int idx, KicauanSambungan *val)
{

    if (idx == 0)
    {
        deleteFirstTabKicauanSambungan(T, val);
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
void displayTabKicauanSambungan(TabKicauanSambungan T)
{

    printf("[");

    if (!isTabKicauanSambunganEmpty(T))
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

int lengthTabKicauanSambungan(TabKicauanSambungan T)
{

    if (isTabKicauanSambunganEmpty(T))
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
