#ifndef BALASAN_H
#define BALASAN_H

#define CAPACITY 100
/* Kapasitas penyimpanan */

/* Definisi Type Data */
typedef struct treeNode *addressTree;
typedef struct treeNode
{
    int data;
    addressTree firstChild;
    addressTree nextSibling;
    addressTree parent;
} Node;

#define Data(P) (P)->data
#define FirstChild(P) (P)->firstChild
#define NextSibling(P) (P)->nextSibling
#define Parent(P) (P)->parent
#define ADDRESS(P) (P)

typedef addressTree tree;

addressTree createNode(int data);

void addChild(tree *parent, tree *child);

void printTree(tree root, int depth);

addressTree searchTree(tree root, int val);

#include "sentenceMachine.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "sentenceMachine.h"
#include "datetime.h"
#include "pengguna.h"
#include "kicauan.h"

typedef struct
{
    int idBalasan;
    Sentence teks;
    int IDPengguna;
    DATETIME waktu;
    address root;
} Balasan;

#define Id(P) (P).id;
#define Teks(P) (P).teks;
#define Writer(P) (P).penulis;
#define Time(P) (P).dateTime;
#define DaftarBalasan(P) (P).daftarBalasan;

void Balas(int IDKicau, int IDBalasan);

void Show_Balasan(int IDKicau);

void Hapus_Balasan(int IDKicau, int IDBalasan);

#endif