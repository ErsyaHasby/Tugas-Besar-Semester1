// Nama Program: account.c
// Deskripsi   : Program untuk melakukan registrasi dan login menggunakan file biner
// Pembuat     : Varian Abidarma Syuhada & Ersya Hasby Satria

#include <stdio.h>
#include <string.h>
#include "account.h"

// Fungsi untuk registrasi akun
int registerAccount()
{
    Account account;
    FILE *file = fopen("account.dat", "ab"); // Gunakan mode "ab" untuk menulis dalam format biner

    if (file == NULL)
    {
        printf("Gagal membuka file account.dat untuk menulis.\n");
        return 0;
    }

    printf("Masukkan username baru: ");
    scanf("%s", account.username);
    printf("Masukkan password baru: ");
    scanf("%s", account.password);

    fwrite(&account, sizeof(Account), 1, file); // Menulis struktur akun ke file biner
    fclose(file);

    printf("Registrasi berhasil! Silakan login.\n");
    return 1;
}

// Fungsi untuk login
int loginAccount()
{
    Account account, fileAccount;
    FILE *file = fopen("account.dat", "rb"); // Gunakan mode "rb" untuk membaca file biner

    if (file == NULL)
    {
        printf("Gagal membuka file account.dat untuk membaca.\n");
        return 0;
    }

    printf("Masukkan Username: ");
    scanf("%s", account.username);
    printf("Masukkan Password: ");
    scanf("%s", account.password);

    // Periksa apakah username dan password cocok
    while (fread(&fileAccount, sizeof(Account), 1, file))
    { // Membaca data akun dari file biner
        if (strcmp(account.username, fileAccount.username) == 0 && strcmp(account.password, fileAccount.password) == 0)
        {
            fclose(file);
            printf("Login berhasil!\n");
            return 1;
        }
    }

    fclose(file);
    printf("Username atau Password salah.\n");
    return 0;
}
