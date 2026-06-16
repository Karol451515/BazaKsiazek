#define _CRT_SECURE_NO_WARNINGS
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
    scanf(" %99[^\n]", nowa.autor);

    printf("Tytul: ");
    scanf(" %49[^\n]", nowa.tytul);

    //rok wydania + zabezpieczenia
    
    int poprawny_rok = 0;

    do {
        printf("Rok wydania (tylko liczba): ");

        if (scanf(" %d", &nowa.rok_wydania) == 1) {
            char nastepny_znak = getchar();

            if (nastepny_znak == '\n') {
                if (nowa.rok_wydania > 0 && nowa.rok_wydania <= 2026) {
                    poprawny_rok = 1;
                }
                else {
                    printf("Blad! Rok wydania musi byc liczba wieksza od 0 i nie z przyszlosci.\n");
                }
            }
            else {
                printf("Blad! Wpisz sama liczbe, bez zadnego tekstu.\n");
                while (getchar() != '\n');
            }
        }
        else {
            printf("Blad! To w ogole nie jest liczba.\n");
            while (getchar() != '\n');
        }
    } while (poprawny_rok == 0);



    printf("ISBN: ");
    scanf(" %19[^\n]", nowa.isbn);


    //liczba stron + zabezpieczenia
    int poprawna_liczba_stron = 0;

    do {
        printf("Liczba stron (tylko liczba): ");

        if (scanf(" %d", &nowa.liczba_stron) == 1) {
            char nastepny_znak = getchar();

            if (nastepny_znak == '\n') {
                if (nowa.liczba_stron > 0 && nowa.liczba_stron <= 10000) {
                    poprawna_liczba_stron = 1;
                }
                else {
                    printf("Blad! Liczba stron musi byc dodatnia i realna (np. 1 - 10000).\n");
                }
            }
            else {
                printf("Blad! Wpisz sama liczbe, bez zadnego tekstu.\n");
                while (getchar() != '\n');
            }
        }
        else {
            printf("Blad! To w ogole nie jest liczba.\n");
            while (getchar() != '\n');
        }
    } while (poprawna_liczba_stron == 0);


    printf("Gatunek (np. dramat, komedia, fantasy): ");
    scanf(" %29[^\n]", nowa.gatunek);


    //rodziaj okładki + zabezpieczenia
    int poprawna_okladka = 0;
    do {
        printf("Rodzaj okladki (miekka/twarda): ");
        scanf(" %9[^\n]", nowa.okladka);

        if (strcmp(nowa.okladka, "miekka") == 0 || strcmp(nowa.okladka, "twarda") == 0) {
            poprawna_okladka = 1;
        }
        else {
            printf("Blad! Wpisz dokladnie 'miekka' lub 'twarda'.\n");
        }
    } while (poprawna_okladka == 0);

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
    char fraza[100] = "";
    int znaleziono = 0;

    printf("\n--- WYSZUKIWANIE ---\n");
    printf("1. Wyszukaj po autorze\n");
    printf("2. Wyszukaj po tytule\n");
    printf("Wybor: ");
    scanf(" %d", &wybor);

    if (wybor == 1) {
        printf("Podaj nazwe autora (lub fragment): ");
        scanf(" %[^\n]", fraza);
        printf("\n%-30.30s %-40s %-6s %-20s\n", "Autor", "Tytul", "Rok", "ISBN");
        printf("--------------------------------------------------------------------------------\n");
        for (int i = 0; i < liczba; i++) {
            if (strstr(baza[i].autor, fraza) != NULL) {
                printf("%-30.30s %-40s %-6d %-20s\n",
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

    char fraza[100] = "";
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

int porownajAutor(const void* a, const void* b)
{
    Ksiazka* k1 = (Ksiazka*)a;
    Ksiazka* k2 = (Ksiazka*)b;

    int c = strcmp(k1->autor, k2->autor);
    return c != 0 ? c : strcmp(k1->tytul, k2->tytul);
}

int porownajTytul(const void* a, const void* b)
{
    Ksiazka* k1 = (Ksiazka*)a;
    Ksiazka* k2 = (Ksiazka*)b;

    int c = strcmp(k1->tytul, k2->tytul);
    return c != 0 ? c : strcmp(k1->autor, k2->autor);
}

int porownajRok(const void* a, const void* b)
{
    Ksiazka* k1 = (Ksiazka*)a;
    Ksiazka* k2 = (Ksiazka*)b;

    return k1->rok_wydania - k2->rok_wydania;
}

void sortujKsiazki(Ksiazka baza[], int liczba) {

    int wybor;
    
    if (liczba <= 0)
    {
        printf("Brak ksiazek do sortowania.\n");
        return;
    }

    printf("\nSortowanie wedlug:\n");
    printf("1. Autora\n");
    printf("2. Tytulu\n");
    printf("3. Roku wydania\n");
    printf("Wybor: ");
    scanf("%d", &wybor);

    switch (wybor) {
    case 1:
        qsort(baza, liczba, sizeof(Ksiazka), porownajAutor);
        printf("Posortowano ksiazki po autorze.\n");
        break;

    case 2:
        qsort(baza, liczba, sizeof(Ksiazka), porownajTytul);
        printf("Posortowano ksiazki po tytule.\n");
        break;

    case 3:
        qsort(baza, liczba, sizeof(Ksiazka), porownajRok);
        printf("Posortowano ksiazki po roku wydania.\n");
        break;

    default:
        printf("Niepoprawny wybor sortowania.\n");
        return;

    }
    printf("Posortowano ksiazki");
    zapiszDoPliku(baza, liczba);
}