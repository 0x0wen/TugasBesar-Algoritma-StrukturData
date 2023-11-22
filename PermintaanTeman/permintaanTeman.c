#include "permintaanTeman.h"

#include <stdio.h>
#include <stdlib.h>
#include "tabTeman.h"

/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsPermintaanTemanEmpty(PermintaanTeman Q)
{
    return NBElmt(Q) == 0;
}

/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
boolean IsPermintaanTemanFull(PermintaanTeman Q)
{
    return NBElmt(Q) == MaxPermintaan;
}

/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
int BanyakPermintaanTeman(PermintaanTeman Q)
{

    if (Head(Q) == Nil)
    {
        return 0;
    }
    else if (Head(Q) <= Tail(Q))
    {
        return Tail(Q) - Head(Q) + 1;
    }
    else
    {
        return MaxPermintaan - (Head(Q) - Tail(Q) - 1);
    }
}

/* *** Kreator *** */

/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
void CreatePermintaanTeman(PermintaanTeman *Q, int Max)
{

    (*Q).T = (AnggotaTeman *)malloc((Max) * sizeof(AnggotaTeman));
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Destruktor *** */

/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
void DealokasiPermintaanTeman(PermintaanTeman *Q)
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */

/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void EnqueuePermintaanTeman(PermintaanTeman *Q, AnggotaTeman X)
{

    if (NBElmt(*Q) == 0)
    {

        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoHead(*Q) = X;
    }
    else
    {
        AnggotaTeman temp[100];
        int i;

        for (i = 0; i < NBElmt(*Q); i++)
        {
            temp[i] = Elmt(*Q, (Head(*Q) + i) % MaxPermintaan);
        }

        int idxPlace = 0;
        while (temp[idxPlace].prio <= Prio(X) && idxPlace < NBElmt(*Q))
        {
            idxPlace++;
        }

        int idxMove = NBElmt(*Q) - 1;

        while (idxMove >= idxPlace)
        {
            temp[idxMove + 1] = temp[idxMove];
            idxMove--;
        }

        temp[idxPlace] = X;

        Tail(*Q) = (Tail(*Q) + 1) % MaxPermintaan;

        for (i = 0; i < NBElmt(*Q); i++)
        {

            Elmt(*Q, (Head(*Q) + i) % MaxPermintaan) = temp[i];
        }
    }
}

/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
void DequeuePermintaanTeman(PermintaanTeman *Q, AnggotaTeman *X)
{
    int len = NBElmt(*Q);

    *X = InfoHead(*Q);
    Head(*Q) = (Head(*Q) + 1) % MaxPermintaan;

    if (len == 1)
    {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
}

/* Operasi Tambahan */

/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
void CetakPermintaanTeman(PermintaanTeman Q)
{

    int i;
    AnggotaTeman current;

    for (i = 0; i < NBElmt(Q); i++)
    {

        current = Elmt(Q, (Head(Q) + i) % MaxPermintaan);
        printf("%d %c\n", Prio(current), Info(current));
    }
    printf("#\n");
}
