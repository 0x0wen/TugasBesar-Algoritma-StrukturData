#include "../global.h"

KicauanSambungan createKicauanSambungan(Sentence konten, Sentence author, int IDPengguna, int IDKicauanSambungan)
{
    KicauanSambungan newKicauanSambungan;
    newKicauanSambungan.IDKicauanSambungan = IDKicauanSambungan;
    newKicauanSambungan.konten = konten;
    newKicauanSambungan.author = author;
    newKicauanSambungan.IDPengguna = IDPengguna;
    newKicauanSambungan.waktu = getDATETIME();
    return newKicauanSambungan;
}

Address newKicauanSambunganNode(KicauanSambungan val)
{
    Address Node = (Address)malloc(sizeof(NodeKicauanSambungan));
    if (Node != NULL)
    {
        INFO_UTAS(Node) = val;
        NEXT_UTAS(Node) = NULL;
    }
    return Node;
}

Utas createUtas(Sentence author, int IDUtas, int IDKicau, Sentence konten, DATETIME waktu)
{
    Utas newUtas;
    AUTHOR_UTAS(newUtas) = author;
    ID_UTAS(newUtas) = IDUtas;
    ID_KICAU_UTAS(newUtas) = IDKicau;
    KONTEN_UTAS(newUtas) = konten;
    createTabKicauanSambungan(&KICAUAN_SAMBUNGAN(newUtas));
    return newUtas;
}

void printUtas(Utas U)
{
    printf("%*s| ID = %d", 1, "", ID_UTAS(U));
    printf("\n%*s| ", 1, "");
    printSentence(AUTHOR_UTAS(U));
    printf("\n%*s| ", 1, "");
    TulisDATETIME(WAKTU_UTAS(U));
    printf("\n%*s| ", 1, "");
    printSentence(KONTEN_UTAS(U));
    TabKicauanSambungan T = KICAUAN_SAMBUNGAN(U);
    if (!isTabKicauanSambunganEmpty(T))
    {
        Address NodeKicauanSambungan = FIRST_UTAS(T);
        while (NEXT_UTAS(NodeKicauanSambungan) != NULL)
        {
            printf("%*s| INDEX = %d", 5, "", ID_UTAS(INFO_UTAS(NodeKicauanSambungan)));
            printf("\n%*s| ", 5, "");
            printSentence(AUTHOR_KICAUAN_SAMBUNGAN(INFO_UTAS(NodeKicauanSambungan)));
            printf("\n%*s| ", 5, "");
            TulisDATETIME(WAKTU_KICAUAN_SAMBUNGAN(INFO_UTAS(NodeKicauanSambungan)));
            printf("\n%*s| ", 5, "");
            printSentence(KONTEN_KICAUAN_SAMBUNGAN(INFO_UTAS(NodeKicauanSambungan)));
            printf("\n");
            NodeKicauanSambungan = NEXT_UTAS(NodeKicauanSambungan);
        }
    }
}
void createTabKicauanSambungan(TabKicauanSambungan *T)
{
    FIRST_UTAS(*T) = NULL;
}

boolean isTabKicauanSambunganEmpty(TabKicauanSambungan T)
{

    return FIRST_UTAS(T) == NULL;
}

void insertFirstTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val)
{

    Address NodeKicauanSambungan = newKicauanSambunganNode(val);

    if (NodeKicauanSambungan != NULL)
    {
        NEXT_UTAS(NodeKicauanSambungan) = FIRST_UTAS(*T);
        FIRST_UTAS(*T) = NodeKicauanSambungan;
    }
}

void insertLastTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val)
{

    if (isTabKicauanSambunganEmpty(*T))
    {
        insertFirstTabKicauanSambungan(T, val);
    }
    else
    {

        Address NodeKicauanSambungan = FIRST_UTAS(*T);

        while (NEXT_UTAS(NodeKicauanSambungan) != NULL)
        {
            NodeKicauanSambungan = NEXT_UTAS(NodeKicauanSambungan);
        }

        Address NodeKicauanSambunganNew = newKicauanSambunganNode(val);

        if (NodeKicauanSambunganNew != NULL)
        {
            NEXT_UTAS(NodeKicauanSambungan) = NodeKicauanSambunganNew;
        }
    }
}

void insertAtTabKicauanSambungan(TabKicauanSambungan *T, KicauanSambungan val, int idx)
{

    if (idx == 0)
    {
        insertFirstTabKicauanSambungan(T, val);
    }
    else
    {

        Address NodeKicauanSambunganNew = newKicauanSambunganNode(val);

        if (NodeKicauanSambunganNew != NULL)
        {
            Address NodeKicauanSambungan = FIRST_UTAS(*T);

            int i;
            for (i = 0; i < idx - 1; i++)
            {
                NodeKicauanSambungan = NEXT_UTAS(NodeKicauanSambungan);
            }
            NEXT_UTAS(NodeKicauanSambunganNew) = NEXT_UTAS(NodeKicauanSambungan);
            NEXT_UTAS(NodeKicauanSambungan) = NodeKicauanSambunganNew;
        }
    }
}
void deleteFirstTabKicauanSambungan(TabKicauanSambungan *T)
{

    Address NodeKicauanSambungan = FIRST_UTAS(*T);

    FIRST_UTAS(*T) = NEXT_UTAS(NodeKicauanSambungan);
    free(NodeKicauanSambungan);
}
void deleteLastTabKicauanSambungan(TabKicauanSambungan *T)
{

    Address NodeKicauanSambungan = NULL;
    Address LAST = FIRST_UTAS(*T);

    while (NEXT_UTAS(LAST) != NULL)
    {
        NodeKicauanSambungan = LAST;
        LAST = NEXT_UTAS(LAST);
    }

    if (NodeKicauanSambungan == NULL)
    {
        FIRST_UTAS(*T) = NULL;
    }
    else
    {
        NEXT_UTAS(NodeKicauanSambungan) = NULL;
    }

    free(LAST);
}
void deleteAtTabKicauanSambungan(TabKicauanSambungan *T, int idx)
{

    if (idx == 0)
    {
        deleteFirstTabKicauanSambungan(T);
    }
    else
    {
        Address NodeKicauanSambungan = FIRST_UTAS(*T);
        int i;
        for (i = 0; i < idx - 1; i++)
        {
            NodeKicauanSambungan = NEXT_UTAS(NodeKicauanSambungan);
        }
        Address DELETE = NEXT_UTAS(NodeKicauanSambungan);
        NEXT_UTAS(NodeKicauanSambungan) = NEXT_UTAS(DELETE);
        free(DELETE);
    }
}
void displayTabKicauanSambungan(TabKicauanSambungan T)
{
    if (!isTabKicauanSambunganEmpty(T))
    {
        Address NodeKicauanSambungan = FIRST_UTAS(T);
        while (NEXT_UTAS(NodeKicauanSambungan) != NULL)
        {
            printf("%*s| ID = %d", 2, "", ID_UTAS(INFO_UTAS(NodeKicauanSambungan)));
            printf("%*s| ", 2, "");
            printSentence(AUTHOR_KICAUAN_SAMBUNGAN(INFO_UTAS(NodeKicauanSambungan)));
            printf("%*s| ", 2, "");
            TulisDATETIME(WAKTU_KICAUAN_SAMBUNGAN(INFO_UTAS(NodeKicauanSambungan)));
            printf("%*s| ", 2, "");
            printSentence(KONTEN_KICAUAN_SAMBUNGAN(INFO_UTAS(NodeKicauanSambungan)));
            NodeKicauanSambungan = NEXT_UTAS(NodeKicauanSambungan);
        }
    }
}

int lengthTabKicauanSambungan(TabKicauanSambungan T)
{

    if (isTabKicauanSambunganEmpty(T))
    {
        return 0;
    }

    int len = 1;
    Address NodeKicauanSambungan = FIRST_UTAS(T);

    while (NEXT_UTAS(NodeKicauanSambungan) != NULL)
    {
        NodeKicauanSambungan = NEXT_UTAS(NodeKicauanSambungan);
        len++;
    }

    return len;
}
