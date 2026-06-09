#define _CRT_SECURE_NO_WARNINGS //  Visual Studio blokuje mi zwyklego "scanf" jako niebezpiecznego

#include <stdio.h>
#include <string.h>
#include "biblioteka.h"

void dodajKsiazke(Ksiazka baza[], int* liczba) {
    if (*liczba >= MAX_KSIAZEK) {
        printf("Baza jest pelna! Nie mozna dodac wiecej ksiazek.\n");
        return;
    }

    Ksiazka nowa;

    printf("\n--- DODAWANIE KSIAZKI ---\n");

    printf("Autor: ");
    scanf(" %[^\n]", nowa.autor);

    printf("Tytul: ");
    scanf(" %[^\n]", nowa.tytul);

    printf("Rok wydania: ");
    scanf(" %d", &nowa.rok_wydania);

    printf("ISBN: ");
    scanf(" %[^\n]", nowa.isbn);

    printf("Liczba stron: ");
    scanf(" %d", &nowa.liczba_stron);

    printf("Gatunek (np. dramat, komedia, fantasy): ");
    scanf(" %[^\n]", nowa.gatunek);

    printf("Rodzaj okladki (miekka/twarda): ");
    scanf(" %[^\n]", nowa.okladka);

    baza[*liczba] = nowa;
    (*liczba)++;

    printf("Ksiazka zostala dodana!\n");
}

void wyszukajKsiazke(Ksiazka baza[], int liczba) {
    if (liczba == 0) {
        printf("Baza jest pusta!\n");
        return;
    }

    int wybor;
    char fraza[100];
    int znaleziono = 0;

    printf("\n--- WYSZUKIWANIE ---\n");
    printf("1. Wyszukaj po autorze\n");
    printf("2. Wyszukaj po tytule\n");
    printf("Wybor: ");
    scanf(" %d", &wybor);

    if (wybor == 1) {
        printf("Podaj nazwe autora (lub fragment): ");
        scanf(" %[^\n]", fraza);
        printf("\n%-30s %-40s %-6s %-20s\n", "Autor", "Tytul", "Rok", "ISBN");
        printf("--------------------------------------------------------------------------------\n");
        for (int i = 0; i < liczba; i++) {
            if (strstr(baza[i].autor, fraza) != NULL) {
                printf("%-30s %-40s %-6d %-20s\n",
                    baza[i].autor, baza[i].tytul,
                    baza[i].rok_wydania, baza[i].isbn);
                znaleziono++;
            }
        }
    }
    else if (wybor == 2) {
        printf("Podaj tytul (lub fragment): ");
        scanf(" %[^\n]", fraza);
        printf("\n%-30s %-40s %-6s %-20s\n", "Autor", "Tytul", "Rok", "ISBN");
        printf("--------------------------------------------------------------------------------\n");
        for (int i = 0; i < liczba; i++) {
            if (strstr(baza[i].tytul, fraza) != NULL) {
                printf("%-30s %-40s %-6d %-20s\n",
                    baza[i].autor, baza[i].tytul,
                    baza[i].rok_wydania, baza[i].isbn);
                znaleziono++;
            }
        }
    }
    else {
        printf("Nieprawidlowy wybor.\n");
        return;
    }

    if (znaleziono == 0) {
        printf("Nie znaleziono zadnych ksiazek.\n");
    }
    else {
        printf("\nZnaleziono: %d ksiazek.\n", znaleziono);
    }
}

void usunKsiazke(Ksiazka baza[], int* liczba) {
    if (*liczba == 0) {
        printf("Baza jest pusta!\n");
        return;
    }

    char fraza[100];
    int indeks = -1;

    printf("\n--- USUWANIE KSIAZKI ---\n");
    printf("Podaj tytul ksiazki do usuniecia: ");
    scanf(" %[^\n]", fraza);

    for (int i = 0; i < *liczba; i++) {
        if (strstr(baza[i].tytul, fraza) != NULL) {
            indeks = i;
            printf("\nZnaleziono: \"%s\" - %s (%d)\n",
                baza[i].tytul, baza[i].autor, baza[i].rok_wydania);
            break;
        }
    }

    if (indeks == -1) {
        printf("Nie znaleziono ksiazki o takim tytule.\n");
        return;
    }

    char potwierdzenie;
    printf("Czy na pewno chcesz usunac te ksiazke? (t/n): ");
    scanf(" %c", &potwierdzenie);

    if (potwierdzenie == 't' || potwierdzenie == 'T') {
        for (int i = indeks; i < *liczba - 1; i++) {
            baza[i] = baza[i + 1];
        }
        (*liczba)--;
        printf("Ksiazka zostala usunieta.\n");
    }
    else {
        printf("Anulowano usuwanie.\n");
    }
}