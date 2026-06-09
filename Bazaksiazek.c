 // Bazaksiazek.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#define _CRT_SECURE_NO_WARNINGS //  Visual Studio blokuje mi zwyklego "scanf" jako niebezpiecznego
#include <stdio.h>
#include "biblioteka.h"

int main()
{
    Ksiazka baza[100];
    int liczba_ksiazek = 0;

    int wybor;
    
    do {
        printf("\n DOMOWA BIBLIOTEKA\n");
        printf("1. Wyswietl ksiazki\n");
        printf("2. Dodaj ksiazke\n");
        printf("0. Wyjscie\n");

        printf("Wybor: ");
        scanf_s("%d", &wybor);

        switch (wybor)
        {
            case 1:
                wyswietlKsiazki(baza, liczba_ksiazek);
                break;

            case 2:
                dodajKsiazke(baza, &liczba_ksiazek);
                break;
        }

    } while (wybor != 0);

    return 0;
}

void wyswietlKsiazki(Ksiazka baza[], int liczba_ksiazek)
{
    if (liczba_ksiazek == 0) {
        printf("Baza ksiazek jest pusta! Dodaj najpierw jakies pozycje. \n");
        return;
    }

    printf("\n+----------------------+--------------------------------+-------------+----------------------+\n");
    printf("| Autorzy              | Tytul                          | Rok wydania | ISBN                 |\n");
    printf("+----------------------+--------------------------------+-------------+----------------------+\n");

    for (int i = 0; i < liczba_ksiazek; ++i) {

        printf("| %-20s | %-30s | %-11d | %-20s |\n",
            baza[i].autor,
            baza[i].tytul,
            baza[i].rok_wydania,
            baza[i].isbn);
    }

    printf("+----------------------+--------------------------------+-------------+----------------------+\n");
}

