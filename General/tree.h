#ifndef TREE_H
#define TREE_H

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */

/* Definisi Type Data */
typedef struct treeNode *addressTree;
typedef struct treeNode {
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
void addChild(tree *parent,tree *child);
void printTree(tree root, int depth);
addressTree searchTree(tree root, int val);

#endif