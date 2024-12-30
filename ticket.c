// nama program: ticket.c
// deskripsi: Implementasi fungsi terkait tiket, kategori, dan kapasitas.
// pembuat: Varian Abidarma Syuhada & Ersya Hasby Satria

#include "ticket.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Kapasitas tribun awal
int kapasitasTribun[5] = {6000, 6000, 10000, 3500, 2500};

// Kapasitas awal tribun
static int utaraCapacity = 6000;
static int selatanCapacity = 6000;
static int timurCapacity = 10000;
static int vipCapacity = 3500;
static int premiumCapacity = 2500;

void ShowRemainingCapacity()
{
    printf("\n=====================================================\n");
    printf("|                SISA KAPASITAS TRIBUN              |\n");
    printf("=====================================================\n");
    printf("Tribun Utara   : %d\n", utaraCapacity);
    printf("Tribun Selatan : %d\n", selatanCapacity);
    printf("Tribun Timur   : %d\n", timurCapacity);
    printf("Tribun VIP     : %d\n", vipCapacity);
    printf("Tribun Premium : %d\n", premiumCapacity);
    printf("=====================================================\n");
}

// Pastikan kapasitas dikurangi di bagian pembelian tiket
void UpdateCapacity(const char *categoryName, int ticketCount)
{
    if (strcmp(categoryName, "Utara") == 0)
    {
        utaraCapacity -= ticketCount;
    }
    else if (strcmp(categoryName, "Selatan") == 0)
    {
        selatanCapacity -= ticketCount;
    }
    else if (strcmp(categoryName, "Timur") == 0)
    {
        timurCapacity -= ticketCount;
    }
    else if (strcmp(categoryName, "VIP") == 0)
    {
        vipCapacity -= ticketCount;
    }
    else if (strcmp(categoryName, "Premium") == 0)
    {
        premiumCapacity -= ticketCount;
    }
}
void InitializeCategories(TicketCategory categories[])
{
    strcpy(categories[0].name, "UTARA");
    categories[0].price = 100000;

    strcpy(categories[1].name, "SELATAN");
    categories[1].price = 120000;

    strcpy(categories[2].name, "TIMUR");
    categories[2].price = 200000;

    strcpy(categories[3].name, "VIP");
    categories[3].price = 300000;

    strcpy(categories[4].name, "PREMIUM");
    categories[4].price = 400000;
}

void InitializeMatches(Match matches[])
{
    strcpy(matches[0].team1, "PSKC Cimahi");
    strcpy(matches[0].team2, "Real Madrid");
    matches[0].matchDate.day = 13;
    matches[0].matchDate.month = 11;
    matches[0].matchDate.year = 2024;
    matches[0].matchDate.hour = 15;
    matches[0].matchDate.minute = 30;

    strcpy(matches[1].team1, "Semen Padang");
    strcpy(matches[1].team2, "Manchester United");
    matches[1].matchDate.day = 13;
    matches[1].matchDate.month = 11;
    matches[1].matchDate.year = 2024;
    matches[1].matchDate.hour = 19;
    matches[1].matchDate.minute = 30;

    strcpy(matches[2].team1, "Persiraja Banda Aceh");
    strcpy(matches[2].team2, "AC Milan");
    matches[2].matchDate.day = 14;
    matches[2].matchDate.month = 11;
    matches[2].matchDate.year = 2024;
    matches[2].matchDate.hour = 15;
    matches[2].matchDate.minute = 30;

    strcpy(matches[3].team1, "Persib Bandung");
    strcpy(matches[3].team2, "FC Barcelona");
    matches[3].matchDate.day = 14;
    matches[3].matchDate.month = 11;
    matches[3].matchDate.year = 2024;
    matches[3].matchDate.hour = 19;
    matches[3].matchDate.minute = 30;

    strcpy(matches[4].team1, "Lampung FC");
    strcpy(matches[4].team2, "FC Bayern Munchen");
    matches[4].matchDate.day = 15;
    matches[4].matchDate.month = 11;
    matches[4].matchDate.year = 2024;
    matches[4].matchDate.hour = 15;
    matches[4].matchDate.minute = 30;
}

void InputTicket(Ticket *ticket, Match matches[], TicketCategory categories[])
{
    int matchChoice, categoryChoice;

    printf("\n=====================================================\n");
    printf("|                PENJUALAN TIKET SEPAKBOLA          |\n");
    printf("=====================================================\n");
    printf(" Daftar Pertandingan:                                 \n");
    for (int i = 0; i < 5; i++)
    {
        printf(" %d. %s vs %s\n", i + 1, matches[i].team1, matches[i].team2);
    }
    printf("-----------------------------------------------------\n");
    printf(" Pilih pertandingan (1-5): ");
    scanf("%d", &matchChoice);
    ticket->match = matches[matchChoice - 1];

    printf("\n=====================================================\n");
    printf(" Kategori Tiket:                                    \n");
    for (int i = 0; i < 5; i++)
    {
        printf(" %d. %s - Rp %d (Sisa: %d)\n", i + 1, categories[i].name, categories[i].price, kapasitasTribun[i]);
    }
    printf("-----------------------------------------------------\n");
    printf(" Pilih kategori tiket (1-5): ");
    scanf("%d", &categoryChoice);

    if (kapasitasTribun[categoryChoice - 1] == 0)
    {
        printf("Maaf, kapasitas tribun %s sudah penuh!\n", categories[categoryChoice - 1].name);
        return;
    }

    ticket->category = categories[categoryChoice - 1];

    printf("-----------------------------------------------------\n");
    printf("| Masukkan nama pembeli: ");
    scanf(" %[^\n]", ticket->buyerName);
    printf("| Masukkan email: ");
    scanf(" %[^\n]", ticket->email);
    printf("| Masukkan nomer whatsapp: ");
    scanf(" %[^\n]", ticket->nomertelepon);

    do
    {
        printf("| Masukkan jumlah tiket: ");
        scanf("%d", &ticket->ticketCount);
        if (ticket->ticketCount > kapasitasTribun[categoryChoice - 1])
        {
            printf("Jumlah tiket melebihi sisa kapasitas tribun. Silakan coba lagi.\n");
        }
    } while (ticket->ticketCount > kapasitasTribun[categoryChoice - 1]);

    // Hitung total harga
    ticket->totalPrice = ticket->ticketCount * ticket->category.price;

    // Set tanggal pembelian
    SetDate(&ticket->purchaseDate);

    // Kurangi kapasitas tribun
    kapasitasTribun[categoryChoice - 1] -= ticket->ticketCount;

    printf("\n=====================================================\n");
    printf("|                PENJUALAN TIKET SEPAKBOLA          |\n");
    printf("=====================================================\n");
    printf("| Ringkasan Pembelian                                |\n");
    printf("|----------------------------------------------------\n");
    printf("| Nama Pembeli    : %s\n", ticket->buyerName);
    printf("| Alamat Email    : %s\n", ticket->email);
    printf("| Nomer Telepon   : %s\n", ticket->nomertelepon);
    printf("| Pertandingan    : %s vs %s\n", ticket->match.team1, ticket->match.team2);
    printf("| Kategori Tiket  : %s\n", ticket->category.name);
    printf("| Jumlah Tiket    : %d\n", ticket->ticketCount);
    printf("| Total Harga     : Rp %.2f\n", ticket->totalPrice);
    printf("| Tanggal Beli    : %02d-%02d-%04d %02d:%02d\n", ticket->purchaseDate.day, ticket->purchaseDate.month, ticket->purchaseDate.year, ticket->purchaseDate.hour, ticket->purchaseDate.minute);
    printf("=====================================================\n");

    UpdateCapacity(ticket->category.name, ticket->ticketCount);
}

void ShowPurchases()
{
    FILE *file = fopen("data_pembelian.txt", "r");

    if (file == NULL)
    {
        printf("Gagal membuka file data_pembelian.txt.\n");
        return;
    }

    printf("\n======================= DATA PEMBELIAN TIKET =======================\n");

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line); // Cetak setiap baris dari file
    }

    printf("===================================================================\n");

    fclose(file);
}
