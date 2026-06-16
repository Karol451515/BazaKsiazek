#pragma once

#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H
#define MAX_KSIAZEK 100
#define PLIK_BAZY "baza.bin"

typedef struct {
    char autor[100];
    char tytul[50];
    int rok_wydania;
    char isbn[20];
    int liczba_stron;
    char gatunek[30];  
    char okladka[10]; 
} Ksiazka;

/*operacje na ksiazkach*/
void wyswietlKsiazki(Ksiazka baza[], int liczba_ksiazek);
void dodajKsiazke(Ksiazka baza[], int* liczba);
void wyszukajKsiazke(Ksiazka baza[], int liczba);
void usunKsiazke(Ksiazka baza[], int* liczba);
void sortujKsiazki(Ksiazka baza[], int liczba);

/*operacje na plikach*/
void zapiszDoPliku(Ksiazka baza[], int liczba);
void wczytajZPliku(Ksiazka baza[], int* liczba);
void utworzPrzykladowaBaze(Ksiazka baza[], int* liczba);

#endif
