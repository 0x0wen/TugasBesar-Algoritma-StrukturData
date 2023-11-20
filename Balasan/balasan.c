#include <stdio.h>
#include "balasan.h"
#include "kicauan.h"

#include <stdio.h>
#include "tree.h"

addressTree createBalasan(int data)
{
    addressTree node = (addressTree)malloc(sizeof(Node));
    if (node != NULL)
    {
        Data(node) = data;
        FirstChild(node) = NULL;
        NextSibling(node) = NULL;
        Parent(node) = NULL;
    }
    return node;
}

void addBalasan(tree *parent, tree *child)
{

    if (*parent != NULL && *child != NULL)
    {
        if (FirstChild(*parent) == NULL)
        {
            FirstChild(*parent) = *child;
        }
        else
        {
            tree sibling = FirstChild(*parent);
            int x = 0;
            while (NextSibling(sibling) != NULL)
            {
                x++;
                sibling = NextSibling(sibling);
            }
            NextSibling(sibling) = *child;
        }
        Parent(*child) = *parent;
    }
}

void removeBalasan(tree *node)
{
    if (Parent(*node) == NULL)
    {
        *node = NULL;
        free(*node);
    }
    else
    {
        tree parent = Parent(*node);
        tree sibling = FirstChild(parent);
        if (sibling == *node)
        {
            FirstChild(parent) = NextSibling(sibling);
            *node = NULL;
            free(*node);
        }
        else
        {
            while (NextSibling(sibling) != *node)
            {
                ;
                sibling = NextSibling(sibling);
            }
            if (NextSibling(*node) != NULL)
            {
                NextSibling(sibling) = NextSibling(*node);
            }
            else
            {
                NextSibling(sibling) = NULL;
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
        printf("%*s%d\n", depth * 2, "", Data(root));
        tree child = FirstChild(root);
        while (child != NULL)
        {
            printTree(child, depth + 1);
            child = NextSibling(child);
        }
    }
}

addressTree searchBalasan(tree root, int val)
{
    addressTree p = ADDRESS(root);
    if (Data(p) == val)
    {
        return p;
    }
    else
    {
        p = FirstChild(p);
        int cek = 0;
        while (p != ADDRESS(root) && cek == 0)
        {
            while ((p) != NULL && cek == 0)
            {
                if (Data((p)) == val)
                {
                    cek = 1;
                }
                else
                {
                    p = FirstChild(p);
                }
            }
            if (cek == 0)
            {
                p = Parent(p);
                if (NextSibling(p) == NULL)
                {
                    p = Parent(p);
                }
                else
                {
                    p = NextSibling(p);
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
