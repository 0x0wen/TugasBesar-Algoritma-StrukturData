#ifndef BALASAN_H
#define BALASAN_H

#define CAPACITY 100
/* Kapasitas penyimpanan */
#include "../Kicauan/kicauan.h"

/* Definisi Type Data */
typedef struct treeNode *addressTree;
typedef struct treeNode
{
    Kicauan data;
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

addressTree createBalasan(Kicauan data);

void addBalasan(tree *parent, tree *child);
void removeBalasan(tree *parent, tree *child);
void displayAllBalasan(tree root, int depth);
addressTree searchBalasan(tree root, int val);

#include "sentenceMachine.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "sentenceMachine.h"
#include "datetime.h"
#include "pengguna.h"
#include "kicauan.h"

typedef struct
{
    int IDParent;
    int IDBalasan;
    Sentence konten;
    Sentence author;
    int IDPengguna;
    DATETIME waktu;
} Balasan;

#define ID_BALASAN(P) (P).IDBalasan;
#define KONTEN_BALASAN(P) (P).konten;
#define PENULIS_BALASAN(P) (P).IDPengguna;
#define WAKTU_BALASAN(P) (P).waktu;



#endif