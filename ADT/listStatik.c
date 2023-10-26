#include "liststatik.h"
#include <stdio.h>

void CreateListStatik(ListStatik *l) {
    for (IdxType i = IDX_MIN; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l) {
    IdxType i = IDX_MIN;
    while (i < CAPACITY && ELMT(l, i) != MARK) {
        i++;
    }
    return i;
}

IdxType getFirstIdx(ListStatik l) {
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l) {
    IdxType i = listLength(l);
    return (i > 0) ? i - 1 : IDX_UNDEF;
}

boolean isIdxValid(ListStatik l, IdxType i) {
    return (i >= IDX_MIN) && (i < CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i) {
    return (i >= IDX_MIN) && (i <= getLastIdx(l));
}

boolean isEmpty(ListStatik l) {
    return listLength(l) == 0;
}

boolean isFull(ListStatik l) {
    return listLength(l) == CAPACITY;
}

void readList(ListStatik *l) {
    int n;
    printf("Masukkan banyak elemen: ");
    scanf("%d", &n);

    if (n >= 0 && n <= CAPACITY) {
        for (int i = 0; i < n; i++) {
            printf("Masukkan elemen ke-%d: ", i + 1);
            scanf("%d", &ELMT(*l, i));
        }

        for (int i = n; i < CAPACITY; i++) {
            ELMT(*l, i) = MARK;
        }
    } else {
        printf("Banyak elemen tidak valid.\n");
    }
}

void printList(ListStatik l) {
    printf("[");
    IdxType i = getFirstIdx(l);
    while (i <= getLastIdx(l)) {
        printf("%d", ELMT(l, i));
        if (i < getLastIdx(l)) {
            printf(",");
        }
        i++;
    }
    printf("]\n");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    ListStatik result;
    CreateListStatik(&result);
    IdxType i = getFirstIdx(l1);
    IdxType j = getFirstIdx(l2);
    IdxType k = getFirstIdx(result);

    while (i <= getLastIdx(l1) && j <= getLastIdx(l2)) {
        if (plus) {
            ELMT(result, k) = ELMT(l1, i) + ELMT(l2, j);
        } else {
            ELMT(result, k) = ELMT(l1, i) - ELMT(l2, j);
        }
        i++;
        j++;
        k++;
    }

    return result;
}

boolean isListEqual(ListStatik l1, ListStatik l2) {
    IdxType i = getFirstIdx(l1);
    IdxType j = getFirstIdx(l2);

    while (i <= getLastIdx(l1) && j <= getLastIdx(l2)) {
        if (ELMT(l1, i) != ELMT(l2, j)) {
            return false;
        }
        i++;
        j++;
    }

    // Pastikan kedua list memiliki panjang yang sama
    if (i <= getLastIdx(l1) || j <= getLastIdx(l2)) {
        return false;
    }

    return true;
}

int indexOf(ListStatik l, ElType val) {
    IdxType i = getFirstIdx(l);
    while (i <= getLastIdx(l)) {
        if (ELMT(l, i) == val) {
            return i;
        }
        i++;
    }
    return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min) {
    IdxType i = getFirstIdx(l);
    *max = *min = ELMT(l, i);

    while (i <= getLastIdx(l)) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
        i++;
    }
}

void insertFirst(ListStatik *l, ElType val) {
    if (!isFull(*l)) {
        IdxType last = getLastIdx(*l);
        for (IdxType i = last; i >= getFirstIdx(*l); i--) {
            ELMT(*l, i + 1) = ELMT(*l, i);
        }
        ELMT(*l, getFirstIdx(*l)) = val;
    }
}

void insertAt(ListStatik *l, ElType val, IdxType idx) {
    if (!isFull(*l) && isIdxEff(*l, idx)) {
        IdxType last = getLastIdx(*l);
        for (IdxType i = last; i >= idx; i--) {
            ELMT(*l, i + 1) = ELMT(*l, i);
        }
        ELMT(*l, idx) = val;
    }
}

void insertLast(ListStatik *l, ElType val) {
    if (!isFull(*l)) {
        IdxType last = getLastIdx(*l);
        ELMT(*l, last + 1) = val;
    }
}

void deleteFirst(ListStatik *l, ElType *val) {
    if (!isEmpty(*l)) {
        *val = ELMT(*l, getFirstIdx(*l));
        IdxType last = getLastIdx(*l);
        for (IdxType i = getFirstIdx(*l); i < last; i++) {
            ELMT(*l, i) = ELMT(*l, i + 1);
        }
        ELMT(*l, last) = MARK;
    }
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    if (!isEmpty(*l) && isIdxEff(*l, idx)) {
        *val = ELMT(*l, idx);
        IdxType last = getLastIdx(*l);
        for (IdxType i = idx; i < last; i++) {
            ELMT(*l, i) = ELMT(*l, i + 1);
        }
        ELMT(*l, last) = MARK;
    }
}

void deleteLast(ListStatik *l, ElType *val) {
    if (!isEmpty(*l)) {
        IdxType last = getLastIdx(*l);
        *val = ELMT(*l, last);
        ELMT(*l, last) = MARK;
    }
}

void sortList(ListStatik *l, boolean asc) {
    if (!isEmpty(*l)) {
        IdxType n = listLength(*l);
        ElType temp;

        for (IdxType i = 0; i < n - 1; i++) {
            for (IdxType j = 0; j < n - i - 1; j++) {
                if ((asc && ELMT(*l, j) > ELMT(*l, j + 1)) ||
                    (!asc && ELMT(*l, j) < ELMT(*l, j + 1))) {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                }
            }
        }
    }
}