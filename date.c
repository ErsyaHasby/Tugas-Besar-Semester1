// Nama Program: date.c
// Deskripsi   : Implementasi fungsi untuk pengelolaan tanggal dan waktu.
// Pembuat     : Varian Abidarma Syuhada & Ersya Hasby Satria

#include "ticket.h"
#include <time.h>

void SetDate(Date *date)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    date->day = tm.tm_mday;
    date->month = tm.tm_mon + 1;
    date->year = tm.tm_year + 1900;
    date->hour = tm.tm_hour;
    date->minute = tm.tm_min;
}
