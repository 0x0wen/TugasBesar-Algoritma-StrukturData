#include "../global.h"

Balasan createBalasan(Sentence konten, Sentence author, int IDPengguna, int IDBalasan)
{
    Balasan newBalasan;

    newBalasan.IDBalasan = IDBalasan;
    newBalasan.konten = konten;
    newBalasan.author = author;
    newBalasan.IDPengguna = IDPengguna;
    newBalasan.waktu = getDATETIME();

    return newBalasan;
}
TreeBalasan createBalasanNode(Balasan data)
{
    TreeBalasan node = (TreeBalasan)malloc(sizeof(NodeBalasan));
    if (node != NULL)
    {
        DATA_NODE_BALASAN(node) = data;
        FIRST_CHILD_BALASAN(node) = NULL;
        NEXT_SIBLING_BALASAN(node) = NULL;
        PARENT_BALASAN(node) = NULL;
    }
    return node;
}

void insertFirstTreeBalasan(TreeBalasan *TB, Balasan balasan)
{
    TreeBalasan p = createBalasanNode(balasan);
    if (p != NULL)
    {
        FIRST_CHILD_BALASAN(p) = *TB;
        *TB = p;
    }
}

void addBalasan(TreeBalasan *parent, Balasan child)
{
    TreeBalasan p = createBalasanNode(child);
    if (*parent != NULL && p != NULL)
    {
        if (FIRST_CHILD_BALASAN(*parent) == NULL)
        {
            FIRST_CHILD_BALASAN(*parent) = p;
        }
        else
        {
            TreeBalasan sibling = FIRST_CHILD_BALASAN(*parent);
            int x = 0;
            while (NEXT_SIBLING_BALASAN(sibling) != NULL)
            {
                x++;
                sibling = NEXT_SIBLING_BALASAN(sibling);
            }
            NEXT_SIBLING_BALASAN(sibling) = p;
        }
        PARENT_BALASAN(p) = *parent;
    }
}

void removeBalasan(TreeBalasan *node)
{
    if (PARENT_BALASAN(*node) == NULL)
    {
        *node = NULL;
        free(*node);
    }
    else
    {
        TreeBalasan parent = PARENT_BALASAN(*node);
        TreeBalasan sibling = FIRST_CHILD_BALASAN(parent);
        if (sibling == *node)
        {
            FIRST_CHILD_BALASAN(parent) = NEXT_SIBLING_BALASAN(sibling);
            *node = NULL;
            free(*node);
        }
        else
        {
            while (NEXT_SIBLING_BALASAN(sibling) != *node)
            {
                ;
                sibling = NEXT_SIBLING_BALASAN(sibling);
            }
            if (NEXT_SIBLING_BALASAN(*node) != NULL)
            {
                NEXT_SIBLING_BALASAN(sibling) = NEXT_SIBLING_BALASAN(*node);
            }
            else
            {
                NEXT_SIBLING_BALASAN(sibling) = NULL;
            }
            *node = NULL;
            free(*node);
        }
    }
}

void printTreeBalasan(TreeBalasan root, int depth)
{
    if (root != NULL)
    {
        printf("%*s| ID = %d", depth * 5, "", ID_BALASAN(DATA_NODE_BALASAN(root)));
        printf("\n%*s| ", depth * 5, "");
        printSentence(AUTHOR_BALASAN(DATA_NODE_BALASAN(root)));
        printf("\n%*s| ", depth * 5, "");
        TulisDATETIME(WAKTU_BALASAN(DATA_NODE_BALASAN(root)));
        printf("\n%*s| ", depth * 5, "");
        printSentence(KONTEN_BALASAN(DATA_NODE_BALASAN(root)));
        printf("\n\n");
        TreeBalasan child = FIRST_CHILD_BALASAN(root);
        while (child != NULL)
        {
            printTreeBalasan(child, depth + 1);
            child = NEXT_SIBLING_BALASAN(child);
        }
    }
}

TreeBalasan searchBalasan(TreeBalasan root, int IDBalasan)
{
    TreeBalasan p = root;
    if (ID_BALASAN(DATA_NODE_BALASAN(p)) == IDBalasan)
    {
        return p;
    }
    else
    {
        int cek = 0;
        if (FIRST_CHILD_BALASAN(p) != NULL)
        {
            p = FIRST_CHILD_BALASAN(p);
            while (p != root && cek == 0)
            {
                while (p != NULL && cek == 0)
                {
                    if (ID_BALASAN(DATA_NODE_BALASAN(p)) == IDBalasan)
                    {
                        cek = 1;
                        if (p != NULL)
                        {
                            return p;
                        }
                    }
                    else
                    {
                        p = FIRST_CHILD_BALASAN(p);
                    }
                }
                if (cek == 0)
                {
                    p = PARENT_BALASAN(p);
                    if (NEXT_SIBLING_BALASAN(p) == NULL)
                    {
                        p = PARENT_BALASAN(p);
                    }
                    else
                    {
                        p = NEXT_SIBLING_BALASAN(p);
                    }
                }
            }
            if (cek == 1)
            {
                return p;
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            return NULL;
        }
    }
}
