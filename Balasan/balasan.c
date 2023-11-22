#include <stdio.h>
#include "balasan.h"
#include <stdio.h>

addressTree createBalasan(Balasan data)
{
    addressTree node = (addressTree)malloc(sizeof(NodeBalasan));
    if (node != NULL)
    {
        DataNodeBalasan(node) = data;
        FirstChildBalasan(node) = NULL;
        NextSiblingBalasan(node) = NULL;
        ParentBalasan(node) = NULL;
    }
    return node;
}

void addBalasan(tree *parent, tree *child)
{

    if (*parent != NULL && *child != NULL)
    {
        if (FirstChildBalasan(*parent) == NULL)
        {
            FirstChildBalasan(*parent) = *child;
        }
        else
        {
            tree sibling = FirstChildBalasan(*parent);
            int x = 0;
            while (NextSiblingBalasan(sibling) != NULL)
            {
                x++;
                sibling = NextSiblingBalasan(sibling);
            }
            NextSiblingBalasan(sibling) = *child;
        }
        ParentBalasan(*child) = *parent;
    }
}

void removeBalasan(tree *node)
{
    if (ParentBalasan(*node) == NULL)
    {
        *node = NULL;
        free(*node);
    }
    else
    {
        tree parent = ParentBalasan(*node);
        tree sibling = FirstChildBalasan(parent);
        if (sibling == *node)
        {
            FirstChildBalasan(parent) = NextSiblingBalasan(sibling);
            *node = NULL;
            free(*node);
        }
        else
        {
            while (NextSiblingBalasan(sibling) != *node)
            {
                ;
                sibling = NextSiblingBalasan(sibling);
            }
            if (NextSiblingBalasan(*node) != NULL)
            {
                NextSiblingBalasan(sibling) = NextSiblingBalasan(*node);
            }
            else
            {
                NextSiblingBalasan(sibling) = NULL;
            }
            *node = NULL;
            free(*node);
        }
    }
}

void displayAllBalasan(tree root, int depth)
{
    if (root != NULL)
    {
        printf("%*s%d\n", depth * 2, "", DataNodeBalasan(root));
        tree child = FirstChildBalasan(root);
        while (child != NULL)
        {
            printTree(child, depth + 1);
            child = NextSiblingBalasan(child);
        }
    }
}

addressTree searchBalasan(tree root, int IDBalasan)
{
    addressTree p = ADDRESS(root);
    if (ID_BALASAN(DataNodeBalasan(p)) == IDBalasan)
    {
        return p;
    }
    else
    {
        p = FirstChildBalasan(p);
        int cek = 0;
        while (p != ADDRESS(root) && cek == 0)
        {
            while ((p) != NULL && cek == 0)
            {
                if (ID_BALASAN(DataNodeBalasan(p)) == IDBalasan)
                {
                    cek = 1;
                }
                else
                {
                    p = FirstChildBalasan(p);
                }
            }
            if (cek == 0)
            {
                p = ParentBalasan(p);
                if (NextSiblingBalasan(p) == NULL)
                {
                    p = ParentBalasan(p);
                }
                else
                {
                    p = NextSiblingBalasan(p);
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
}
