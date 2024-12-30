// Nama Program: main.c
// Deskripsi   : Program untuk pemesanan tiket pertandingan sepak bola dengan fitur login, registrasi, dan penyimpanan data pembelian.
// Pembuat     : Varian Abidarma Syuhada & Ersya Hasby Satria

#include <stdio.h>
#include <conio.h>
#include "ticket.h"
#include "account.h"

int main()
{
    Ticket tickets[100];
    TicketCategory categories[5];
    Match matches[5];
    int ticketCount = 0;
    int loggedIn = 0;
    int option;

    // Menu login atau registrasi
    do
    {
        printf(" ====================================================\n");
        printf("|                   SELAMAT DATANG                  |\n");
        printf(" ====================================================\n");
        printf("1. Login\n");
        printf("2. Registrasi\n");
        printf("3. Jadwal Pertandingan\n");
        printf("4. Exit\n"); // Ganti opsi 4 dengan Exit
        printf("Pilih opsi (1/2/3/4): ");

        scanf("%d", &option);

        if (option == 1)
        {
            loggedIn = loginAccount();
        }
        else if (option == 2)
        {
            loggedIn = registerAccount();
            continue;
        }
        else if (option == 3)
        {
            // Menampilkan Jadwal Pertandingan
            printf("\n=====================================================\n");
            printf("|                JADWAL PERTANDINGAN                |\n");
            printf("=====================================================\n");

            // Inisialisasi kategori dan pertandingan
            InitializeCategories(categories);
            InitializeMatches(matches);

            // Menampilkan jadwal pertandingan
            for (int i = 0; i < 5; i++)
            {
                printf("\nPertandingan %d: %s vs %s\n", i + 1, matches[i].team1, matches[i].team2);
                printf("Tanggal: %02d-%02d-%04d %02d:%02d\n",
                       matches[i].matchDate.day, matches[i].matchDate.month, matches[i].matchDate.year,
                       matches[i].matchDate.hour, matches[i].matchDate.minute);
            }

            printf("\n=====================================================\n");
            continue;
        }
        else if (option == 4)
        {
            break; // Exit program
        }
        else
        {
            printf("Opsi tidak valid.\n");
            continue;
        }

        if (!loggedIn)
        {
            printf("Login gagal, program dihentikan.\n");
            continue;
        }

        // Inisialisasi kategori dan pertandingan
        InitializeCategories(categories);
        InitializeMatches(matches);

        FILE *file = fopen("data_pembelian.txt", "a");
        if (file == NULL)
        {
            printf("Gagal membuka file untuk menyimpan data.\n");
            return 1;
        }

        // Tambahkan header ke file jika kosong
        fseek(file, 0, SEEK_END);
        if (ftell(file) == 0)
        {
            fprintf(file, "===============================================================================================================================\n");
            fprintf(file, "| Nama Pembeli   |       Alamat Email       |    Nomer Telepon    |    Pertandingan    |   Kategori   | Jumlah | Tanggal Beli |\n");
            fprintf(file, "===============================================================================================================================\n");
        }

        // Input pembelian tiket
        InputTicket(&tickets[ticketCount], matches, categories);

        // Simpan data ke file dengan format tabel
        fprintf(file, "| %-14s | %-24s | %-19s | %-9s vs %-16s | %-12s | %-6d | %02d-%02d-%04d %02d:%02d |\n",
                tickets[ticketCount].buyerName,
                tickets[ticketCount].email,
                tickets[ticketCount].nomertelepon,
                tickets[ticketCount].match.team1,
                tickets[ticketCount].match.team2,
                tickets[ticketCount].category.name,
                tickets[ticketCount].ticketCount,
                tickets[ticketCount].purchaseDate.day,
                tickets[ticketCount].purchaseDate.month,
                tickets[ticketCount].purchaseDate.year,
                tickets[ticketCount].purchaseDate.hour,
                tickets[ticketCount].purchaseDate.minute);

        fclose(file);

        ticketCount++;

        printf("Tiket berhasil dipesan! Kembali ke menu utama.\n\n");

    } while (option != 4); // Keluar jika opsi 4 dipilih

    printf("\n=====================================================\n");
    printf("|       Terima kasih telah menggunakan layanan kami!   |\n");
    printf("=======================================================\n");

    getch();

    return 0;
}
