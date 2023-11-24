#include "../global.h"

Requester create_Requester(int priority, int id){
    Requester R;
    R.prio = priority;
    R.id_requester = id;

    return R;
}

void create_PQR(PrioQueueRequest *Q){
    (*Q).idxHead = IDX_UNDEF;
    (*Q).idxTail = IDX_UNDEF;
}

boolean IsEmpty_PQR(PrioQueueRequest Q){
    return Q.idxTail == -1;
}

/* harusnya gak bakal penuh sih */
boolean IsFull_PQR(PrioQueueRequest Q){
    return nEff_PQR(Q) == MaxPermintaan;
}

int nEff_PQR(PrioQueueRequest Q){
    return Q.idxTail+1;
}

boolean isExists_PQR(PrioQueueRequest Q, int id_requester){

    int i, len = nEff_PQR(Q);

    for (i = 0; i < len; i++){
        if (ELMT_PQR(Q, i).id_requester == id_requester){
            return true;
        }
    }  
    return false;
}

void enqueue_PQR(PrioQueueRequest *Q, Requester R){

    if (IsEmpty_PQR(*Q)) {
        ELMT_PQR(*Q, 0) = R;
        (*Q).idxHead = 0;
        (*Q).idxTail = 0;
    } else {
        int idxPlace = 0;
        while ((ELMT_PQR(*Q, idxPlace).prio >= R.prio) && (idxPlace < nEff_PQR(*Q))){
            idxPlace++;
        }
        int i;
        for (i = nEff_PQR(*Q)-1; i >= idxPlace; i--){
            ELMT_PQR(*Q, i+1) = ELMT_PQR(*Q, i);
        } 
        ELMT_PQR(*Q, idxPlace) = R;
        (*Q).idxTail++;
    }
}

void dequeue_PQR(PrioQueueRequest *Q){

    if (nEff_PQR(*Q) == 1){
        (*Q).idxHead = IDX_UNDEF;
        (*Q).idxTail = IDX_UNDEF;
    } else {
        int i;
        for (i = 0; i < nEff_PQR(*Q)-1; i++){
            ELMT_PQR(*Q, i) = ELMT_PQR(*Q, i+1);
        }
        (*Q).idxTail--;
    }
}

void display_PQR(PrioQueueRequest Q){
    int i;
    printf("\nQueue: \n");
    for (i = 0; i < nEff_PQR(Q); i++){
        Requester current = ELMT_PQR(Q,i);
        printf("[banyak teman: %d, id: %d]\n", current.prio, current.id_requester);
    }
    if (IsEmpty_PQR(Q)){
        printf("Kosong\n");
    }
}