#include <stdio.h>
#include "balasan.h"
#include "kicauan.h"

#include <stdio.h>
#include "tree.h"

addressTree createNode(int data)
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

void addChild(tree *parent, tree *child)
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

void removeNode(tree *node)
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

void printTree(tree root, int depth)
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

addressTree searchTree(tree root, int val)
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

// Command Balasan
void Balas(int IDKicau, int IDBalasan)
{
    if (!isKicauanInTab(IDKicau))
    {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!");
    }
    else if (IDBalasan != 1 && !isBalasanExistInKicauan(IDKicau, IDBalasan))
    {
        printf("Wah, tidak terdapat balasan yang ingin Anda balas!");
    }
    else if (!isFriend(a, b))
    {
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!");
    }
    else
    {
        if (idbalasan == -1)
            printf("Masukkan Balasan:\n");
        AcquireSentence();
        printf("Selamat! balasan telah diterbitkan!\n");
        printf("Detil balasan:\n");
        printf("| ID = %d", anjay);
        printf("\n| %d", anjay);
        printf("\n| ");
        printTime();
        printf("\n| ");
        printSentence();
        printf("/n");
    }
};

void Show_Balasan(int IDKicau)
{
    if (jumlahBalasan(IDKicau) == 0)
    {
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!");
    }
    else if (kicauan privat && user tidak berteman)
    {
        printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!");
    }
    else if (isKicauanInTab(IDKicau))
    {
        printf("Tidak terdapat kicauan dengan id tersebut!");
    }
    else
    {
        // anjay
    }
};

void Hapus_Balasan(int IDKicau, int IDBalasan)
{
    if (!isBalasanExistInKicauan(IDKicau, IDBalasan))
    {
        printf("Balasan tidak ditemukan")
    }
    else if (balasan punya orang lain)
    {
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!");
    }
    else
    {
        printf("Balasan berhasil dihapus");
    }
};
