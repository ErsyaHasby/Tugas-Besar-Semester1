// nama program: ticket.h
// deskripsi: Header file untuk mendefinisikan struktur dan fungsi terkait tiket.
// pembuat: Varian Abidarma Syuhada & Ersya Hasby Satria

#ifndef TICKET_H
#define TICKET_H

#include "date.h"

// Struktur kategori tiket
typedef struct
{
    char name[50];
    int price;
} TicketCategory;

// Struktur pertandingan
typedef struct
{
    char team1[50];
    char team2[50];
    Date matchDate;
} Match;

// Struktur tiket
typedef struct
{
    char buyerName[50];
    char email[30];
    char nomertelepon[30];
    Match match;
    TicketCategory category;
    int ticketCount;
    float totalPrice;
    Date purchaseDate;
} Ticket;

// Prototipe fungsi
void InitializeCategories(TicketCategory categories[]);
void InitializeMatches(Match matches[]);
void InputTicket(Ticket *ticket, Match matches[], TicketCategory categories[]);
void ShowPurchases();
void ShowRemainingCapacity();

#endif
