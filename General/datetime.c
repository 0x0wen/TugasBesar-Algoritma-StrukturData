#include "../global.h"

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
{
    TIME T;
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    CreateTime(&T, hh, mm, ss);
    Time(*D) = T;
}

void TulisDATETIME(DATETIME D)
{
    printf("%02d/%02d/%04d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}


DATETIME getDATETIME(){

    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);

    DATETIME d;

    CreateDATETIME(&d, (*ptr).tm_mday, 
                       (*ptr).tm_mon+1, 
                       (*ptr).tm_year+1900, 
                       (*ptr).tm_hour, 
                       (*ptr).tm_min, 
                       (*ptr).tm_sec);

    return d;
}