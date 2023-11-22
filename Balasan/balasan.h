#ifndef BALASAN_H
#define BALASAN_H

#define CAPACITY_BALASAN 100
#include "../General/sentenceMachine.h"
#include "../General/wordmachine.h"
#include "../General/charmachine.h"
#include "../General/sentenceMachine.h"
#include "../General/datetime.h"

typedef struct treeNode *addressTree;
typedef struct treeNode
{
    Balasan data;
    addressTree firstChild;
    addressTree nextSibling;
    addressTree parent;
} NodeBalasan;

#define DataNodeBalasan(P) (P)->data
#define FirstChildBalasan(P) (P)->firstChild
#define NextSiblingBalasan(P) (P)->nextSibling
#define ParentBalasan(P) (P)->parent
#define AdressBalasan(P) (P)

typedef addressTree tree;

addressTree createBalasan(Balasan data);
void addBalasan(tree *parent, tree *child);
void removeBalasan(tree *parent);
void displayAllBalasan(tree root, int depth);
addressTree searchBalasan(tree root, int val);

typedef struct
{
    int IDParent;
    int IDBalasan;
    Sentence konten;
    Sentence author;
    int IDPengguna;
    DATETIME waktu;
} Balasan;

#define ID_BALASAN(P) (P).IDBalasan
#define KONTEN_BALASAN(P) (P).konten
#define PENULIS_BALASAN(P) (P).IDPengguna
#define WAKTU_BALASAN(P) (P).waktu

#endif