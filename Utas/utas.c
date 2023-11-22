#include <stdio.h>
#include "utas.h"
#include "../General/sentenceMachine.h"

Address newKicauanSambungan(KicauanSambungan val)
{

    Address NodeKicauanSambungan = (Address)malloc(sizeof(NodeKicauanSambungan));

    if (NodeKicauanSambungan != NULL)
    {
        INFO(NodeKicauanSambungan) = val;
        NEXT(NodeKicauanSambungan) = NULL;
    }

    return NodeKicauanSambungan;
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

    Address NodeKicauanSambungan = FIRST(T);
    int IDX = 0;
    boolean FOUND = false;

    while (NodeKicauanSambungan != NULL && !FOUND)
    {
        if (INFO(NodeKicauanSambungan) == val)
        {
            FOUND = true;
        }
        else
        {
            IDX++;
            NodeKicauanSambungan = NEXT(NodeKicauanSambungan);
        }
    }

    if (FOUND)
    {
        return IDX;
    }
    else
    {
        return IDX_UNDEF_UTAS;
    }
}

void insertFirstTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val)
{

    Address NodeKicauanSambungan = newNode(val);

    if (NodeKicauanSambungan != NULL)
    {
        NEXT(NodeKicauanSambungan) = FIRST(*T);
        FIRST(*T) = NodeKicauanSambungan;
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

        Address NodeKicauanSambungan = FIRST(*T);

        while (NEXT(NodeKicauanSambungan) != NULL)
        {
            NodeKicauanSambungan = NEXT(NodeKicauanSambungan);
        }

        Address NodeKicauanSambunganNew = newNode(val);

        if (NodeKicauanSambunganNew != NULL)
        {
            NEXT(NodeKicauanSambungan) = NodeKicauanSambunganNew;
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

        Address NodeKicauanSambunganNew = newNode(val);

        if (NodeKicauanSambunganNew != NULL)
        {
            Address NodeKicauanSambungan = FIRST(*T);

            int i;
            for (i = 0; i < idx - 1; i++)
            {
                NodeKicauanSambungan = NEXT(NodeKicauanSambungan);
            }
            NEXT(NodeKicauanSambunganNew) = NEXT(NodeKicauanSambungan);
            NEXT(NodeKicauanSambungan) = NodeKicauanSambunganNew;
        }
    }
}
void deleteFirstTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan *val)
{

    Address NodeKicauanSambungan = FIRST(*T);
    *val = INFO(NodeKicauanSambungan);

    FIRST(*T) = NEXT(NodeKicauanSambungan);
    free(NodeKicauanSambungan);
}
void deleteLastTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan *val)
{

    Address NodeKicauanSambungan = NULL;
    Address LAST = FIRST(*T);

    while (NEXT(LAST) != NULL)
    {
        NodeKicauanSambungan = LAST;
        LAST = NEXT(LAST);
    }

    if (NodeKicauanSambungan == NULL)
    {
        FIRST(*T) = NULL;
    }
    else
    {
        NEXT(NodeKicauanSambungan) = NULL;
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
        Address NodeKicauanSambungan = FIRST(*T);

        int i;

        for (i = 0; i < idx - 1; i++)
        {
            NodeKicauanSambungan = NEXT(NodeKicauanSambungan);
        }

        Address DELETE = NEXT(NodeKicauanSambungan);

        *val = INFO(DELETE);

        NEXT(NodeKicauanSambungan) = NEXT(DELETE);
        free(DELETE);
    }
}
void displayTabKicauanSambungan(TabKicauanSambungan T)
{

    printf("[");

    if (!isTabKicauanSambunganEmpty(T))
    {
        Address NodeKicauanSambungan = FIRST(T);

        while (NEXT(NodeKicauanSambungan) != NULL)
        {
            printf("%d,", INFO(NodeKicauanSambungan));
            NodeKicauanSambungan = NEXT(NodeKicauanSambungan);
        }
        printf("%d", INFO(NodeKicauanSambungan));
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
    Address NodeKicauanSambungan = FIRST(T);

    while (NEXT(NodeKicauanSambungan) != NULL)
    {
        NodeKicauanSambungan = NEXT(NodeKicauanSambungan);
        len++;
    }

    return len;
}
