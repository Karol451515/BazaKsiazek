 // Bazaksiazek.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
 
// trzeba poprawić wyłapywanie błędów błędów

#define _CRT_SECURE_NO_WARNINGS //  Visual Studio blokuje mi zwyklego "scanf" jako niebezpiecznego
#include <stdio.h>
#include "biblioteka.h"

int main()
{
    Ksiazka baza[100];
    int liczba_ksiazek = 0;

    int wybor;

    //wczytajZPliku(baza, &liczba_ksiazek);
    
    do {
        printf("\n DOMOWA BIBLIOTEKA\n");
        printf("1. Wyswietl ksiazki\n");
        printf("2. Dodaj ksiazke\n");
        printf("3. Wyszukaj ksiazke\n");         
        printf("4. Usun ksiazke\n");             
        printf("5. Sortuj ksiazki\n");           
        printf("6. Wygeneruj baze testowa\n"); 
        printf("7. Wczytaj baze z pliku\n");
        printf("0. Zapisz i Wyjscie\n");         

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

        case 3:
            wyszukajKsiazke(baza, liczba_ksiazek); 
            break;

        case 4:
            usunKsiazke(baza, &liczba_ksiazek);   
            break;

        case 5:
            sortujKsiazki(baza, liczba_ksiazek);
            wyswietlKsiazki(baza, liczba_ksiazek);
            break;

        case 6:
            utworzPrzykladowaBaza(baza, &liczba_ksiazek); 
            break;*/

        case 0:
            zapiszDoPliku(baza, liczba_ksiazek);  
            printf("Zapisano dane. Do widzenia!\n");
            break;

        default:
            printf("Nieznana opcja. Sprobuj ponownie.\n");
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

        printf("| %-20.20s | %-30.30s | %-11d | %-20s |\n",
            baza[i].autor,
            baza[i].tytul,
            baza[i].rok_wydania,
            baza[i].isbn);
    }

    printf("+----------------------+--------------------------------+-------------+----------------------+\n");
}

