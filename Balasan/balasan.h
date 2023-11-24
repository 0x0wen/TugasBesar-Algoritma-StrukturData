#ifndef BALASAN_H
#define BALASAN_H

#define CAPACITY_BALASAN 100
#include "../General/sentenceMachine.h"
#include "../General/wordmachine.h"
#include "../General/charmachine.h"
#include "../General/sentenceMachine.h"
#include "../General/datetime.h"

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
#define AUTHOR_BALASAN(P) (P).author
#define PENULIS_BALASAN(P) (P).IDPengguna
#define WAKTU_BALASAN(P) (P).waktu

typedef struct treeNode *addressTree;
typedef struct treeNode
{
    Balasan data;
    addressTree firstChild;
    addressTree nextSibling;
    addressTree parent;
} NodeBalasan;

#define DATA_NODE_BALASAN(P) (P)->data
#define FIRST_CHILD_BALASAN(P) (P)->firstChild
#define NEXT_SIBLING_BALASAN(P) (P)->nextSibling
#define PARENT_BALASAN(P) (P)->parent
#define ADDRESS_BALASAN(P) (P)

typedef addressTree TreeBalasan;

Balasan createBalasan(Sentence konten, Sentence author, int IDPengguna, int IDBalasan);
TreeBalasan createBalasanNode(Balasan data);
void addBalasan(TreeBalasan *parent, Balasan child);
void removeBalasan(TreeBalasan *parent);
void printTreeBalasan(TreeBalasan root, int depth);
void insertFirstTreeBalasan(TreeBalasan *TB, Balasan balasan);
TreeBalasan searchBalasan(TreeBalasan root, int val);

#endif