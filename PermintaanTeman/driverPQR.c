#include "permintaanTeman.c"

int main(){

    Requester r1 = create_Requester(3,301);
    Requester r2 = create_Requester(1,123);
    Requester r3 = create_Requester(7,432);
    Requester r4 = create_Requester(5,754);
    Requester r5 = create_Requester(1,226);

    PrioQueueRequest PQR; create_PQR(&PQR);

    display_PQR(PQR);
    
    enqueue_PQR(&PQR, r1);
    display_PQR(PQR);

    enqueue_PQR(&PQR, r2);
    display_PQR(PQR);

    enqueue_PQR(&PQR, r3);
    display_PQR(PQR);

    enqueue_PQR(&PQR, r4);
    display_PQR(PQR);

    enqueue_PQR(&PQR, r5);
    display_PQR(PQR);
    

    return 0;
}