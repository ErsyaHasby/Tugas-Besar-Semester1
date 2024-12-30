// Nama Program: date.h
// Deskripsi   : Deklarasi struktur dan fungsi untuk pengelolaan tanggal dan waktu.
// Pembuat     : Varian Abidarma Syuhada & Ersya Hasby Satria

#ifndef DATE_H
#define DATE_H

typedef struct
{
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Date;

// Prototipe fungsi
void SetDate(Date *date);

#endif
