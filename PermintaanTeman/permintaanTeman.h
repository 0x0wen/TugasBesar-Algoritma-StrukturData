#ifndef PERMINTAAN_TEMAN_H
#define PERMINTAAN_TEMAN_H

#include "../General/boolean.h"
#include "../General/wordmachine.h"
#include "../General/charmachine.h"

#define IDX_UNDEF -1
#define MaxPermintaan 20

/* Tipe data pengirim permintaan teman */
typedef struct {
    int prio;  /* popularitas pengguna */
    int id_requester;           /* id pengguna */
} Requester;

/* PrioQueue list dinamis */
/* list untuk simpan friend request milik tiap user */
typedef struct{
    Requester buffer[MaxPermintaan];
    int idxHead;
    int idxTail;
} PrioQueueRequest;

#define ELMT_PQR(l, i) (l).buffer[(i)]
#define INFO_HEAD_PQR(l) (l).buffer[l.idxHead]
#define PRIO(q) (q).prio

Requester create_Requester(int priority, int val);
void create_PQR(PrioQueueRequest *Q);

boolean IsEmpty_PQR(PrioQueueRequest Q);
boolean IsFull_PQR(PrioQueueRequest Q);
int nEff_PQR(PrioQueueRequest Q);

boolean isExists_PQR(PrioQueueRequest Q, int id_requester);

void enqueue_PQR(PrioQueueRequest *Q, Requester R);
void dequeue_PQR(PrioQueueRequest *Q);

void display_PQR(PrioQueueRequest Q);

#endif