#include <stdio.h>
#include "biblioteka.h"

void zapiszDoPliku(Ksiazka baza[], int liczba ) {
	FILE* plik = fopen(PLIK_BAZY, "wb"); //otwieranie pliku

	if (plik == NULL) {
		printf("Nie mozna otwrozyc pliku do zapisu.\n");
		return;
	}

	fwrite(&liczba, sizeof(int), 1, plik); //zapis liczby książęk
	fwirte(baza, sizeof(Ksiazka), liczba, plik);

	fclose(plik);
	printf("Dane zapisano do pliku\n");
}

void wczytajZPliku(Ksiazka baza[], int *liczba) {
	printf("Wczytywanie z pliku\n");
}

void utworzPrzykladowaBaze(Ksiazka baza[], int* liczba) {
	printf("Tworzenie przykladowej bazy\n");
}