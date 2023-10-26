#include <stdio.h>
#include <math.h>

#include "datetime.h"

int GetMaxDay(int M, int Y)
{
    boolean kabisat = false;
    int i;
    if ((Y % 400 == 0) || (Y % 400 != 0 && Y % 100 != 0 && Y % 4 == 0))
    {
        kabisat = true;
    }
    i = M;
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            return 31;
        }
        else if (kabisat == true && i == 2)
        {
            return 29;
        }
        else if (kabisat == false && i == 2)
        {
            return 28;
        }
        else
        {
            return 30;
        }
    }
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
{
    return ((D >= 1 && D <= 31) && (M >= 1 && M <= 12) && (Y >= 1900 && Y <= 2030) && (h >= 0 && h <= 23) && (m >= 0 && m <= 59) && (s >= 0 && s <= 59));
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
{
    TIME T;
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    CreateTime(&T, hh, mm, ss);
    Time(*D) = T;
}

void BacaDATETIME(DATETIME *D)
{
    int DD, M, Y, h, m, s;
    scanf("%d %d %d %d %d %d", &DD, &M, &Y, &h, &m, &s);
    while (!IsDATETIMEValid(DD, M, Y, h, m, s))
    {
        printf("DATETIME tidak valid\n");
        scanf("%d %d %d %d %d %d", &DD, &M, &Y, &h, &m, &s);
    }
    CreateDATETIME(D, DD, M, Y, h, m, s);
}

void TulisDATETIME(DATETIME D)
{
    printf("%02d/%02d/%04d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}

boolean DEQ(DATETIME D1, DATETIME D2)
{
    return ((Day(D1) == Day(D2)) && (Month(D1) == Month(D2)) && (Year(D1) == Year(D2)) && TEQ(Time(D1), Time(D2)));
}

boolean DNEQ(DATETIME D1, DATETIME D2)
{
    return (!DEQ(D1, D2));
}

boolean DLT(DATETIME D1, DATETIME D2)
{
    if (Year(D1) == Year(D2))
    {
        long total1 = ((Day(D1) + GetMaxDay(Month(D1), Year(D1))) * 86400) + TIMEToDetik(Time(D1));
        long total2 = ((Day(D2) + GetMaxDay(Month(D2), Year(D2))) * 86400) + TIMEToDetik(Time(D2));
        return (total1 < total2);
    }
    else
    {
        return (Year(D1) < Year(D2));
    }
}

boolean DGT(DATETIME D1, DATETIME D2)
{
    if (Year(D1) == Year(D2))
    {
        long total1 = ((Day(D1) + GetMaxDay(Month(D1), Year(D1))) * 86400) + TIMEToDetik(Time(D1));
        long total2 = ((Day(D2) + GetMaxDay(Month(D2), Year(D2))) * 86400) + TIMEToDetik(Time(D2));
        return (total1 > total2);
    }
    else
    {
        return (Year(D1) > Year(D2));
    }
}

DATETIME DATETIMENextNDetik(DATETIME D, int N)
{
    long detik = TIMEToDetik(Time(D));
    detik += N;
    if (detik >= 86400)
    {
        Day(D) += detik / 86400;
        detik %= 86400;
        if (Day(D) > 31)
        {
            Month(D) += Day(D) / 31;
            Day(D) %= 31;
            if (Month(D) > 12)
            {
                Month(D) %= 12;
                Year(D) += Month(D) / 12;
            }
        }
    }
    Time(D) = DetikToTIME(detik);
    return D;
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
{
    long detik = TIMEToDetik(Time(D));
    detik -= N;
    if (detik < 0)
    {
        Day(D) -= detik / 86400;
        detik %= 86400;
        if (Day(D) < 1)
        {
            Month(D) -= Day(D) / 31;
            Day(D) %= 31;
            if (Month(D) < 1)
            {
                Month(D) %= 12;
                Year(D) -= Month(D) / 12;
            }
        }
    }
    Time(D) = DetikToTIME(detik);
    return D;
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
{
    int i;
    long int total1 = ((Day(DAw) + GetMaxDay(Month(DAw), Year(DAw))) * 86400) + TIMEToDetik(Time(DAw));
    long int total2 = ((Day(DAkh) + GetMaxDay(Month(DAkh), Year(DAkh))) * 86400) + TIMEToDetik(Time(DAkh));
    for (i = 1900; i < Year(DAw); i++)
    {
        total1 += GetMaxDay(12, i);
    }
    for (i = 1900; i < Year(DAkh); i++)
    {
        total2 += GetMaxDay(12, i);
    }
    return (total2 - total1);
}