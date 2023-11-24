#include "../global.h"

void CreateTime(TIME *T, int HH, int MM, int SS)
{
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

void TulisTIME(TIME T)
{
    printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}