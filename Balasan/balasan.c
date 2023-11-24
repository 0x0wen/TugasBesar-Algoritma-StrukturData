#include "../global.h"

addressTree createBalasan(Balasan data)
{
    addressTree node = (addressTree)malloc(sizeof(NodeBalasan));
    if (node != NULL)
    {
        DATA_NODE_BALASAN(node) = data;
        FIRST_CHILD_BALASAN(node) = NULL;
        NEXT_SIBLING_BALASAN(node) = NULL;
        PARENT_BALASAN(node) = NULL;
    }
    return node;
}

void addBalasan(TreeBalasan *parent, TreeBalasan *child)
{
    if (*parent != NULL && *child != NULL)
    {
        if (FIRST_CHILD_BALASAN(*parent) == NULL)
        {
            FIRST_CHILD_BALASAN(*parent) = *child;
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
            NEXT_SIBLING_BALASAN(sibling) = *child;
        }
        PARENT_BALASAN(*child) = *parent;
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
        printf("%*s| ID = %d", depth * 2, "", ID_BALASAN(DATA_NODE_BALASAN(root)));
        printf("%*s\n| ", depth * 2, "");
        printSentence(AUTHOR_BALASAN(DATA_NODE_BALASAN(root)));
        printf("%*s\n| ", depth * 2, "");
        TulisDATETIME(WAKTU_BALASAN(DATA_NODE_BALASAN(root)));
        printf("%*s\n| ", depth * 2, "");
        printSentence(KONTEN_BALASAN(DATA_NODE_BALASAN(root)));
        printf("/n");
        TreeBalasan child = FIRST_CHILD_BALASAN(root);
        while (child != NULL)
        {
            printTreeBalasan(child, depth + 1);
            child = NEXT_SIBLING_BALASAN(child);
        }
    }
}

Balasan *searchBalasan(TreeBalasan root, int IDBalasan)
{
    addressTree p = ADDRESS_BALASAN(root);
    if (ID_BALASAN(DATA_NODE_BALASAN(p)) == IDBalasan)
    {
        return &DATA_NODE_BALASAN(p);
    }
    else
    {
        p = FIRST_CHILD_BALASAN(p);
        int cek = 0;
        while (p != ADDRESS_BALASAN(root) && cek == 0)
        {
            while ((p) != NULL && cek == 0)
            {
                if (ID_BALASAN(DATA_NODE_BALASAN(p)) == IDBalasan)
                {
                    cek = 1;
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
            return &DATA_NODE_BALASAN(p);
        }
        else
        {
            return NULL;
        }
    }
}
