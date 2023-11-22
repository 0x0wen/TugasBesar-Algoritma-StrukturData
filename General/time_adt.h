/* File: time.h */
/* Tanggal: 3 September 2022 */
/* Definisi ADT TIME */

#ifndef TIME_H
#define TIME_H

#include "boolean.h"

/* *** Definisi TYPE TIME <HH:MM:SS> *** */
typedef struct
{
    int HH; /* integer [0..23] */
    int MM; /* integer [0..59] */
    int SS; /* integer [0..59] */
} TIME;

/* *** Notasi Akses: selektor TIME *** */
#define Hour(T) (T).HH
#define Minute(T) (T).MM
#define Second(T) (T).SS

void CreateTime(TIME *T, int HH, int MM, int SS);
void TulisTIME(TIME T);

#endif