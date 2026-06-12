#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "biblioteka.h"

void zapiszDoPliku(Ksiazka baza[], int liczba ) {
	FILE* plik = fopen(PLIK_BAZY, "wb"); //otwieranie pliku

	if (plik == NULL) {
		printf("Nie mozna otwrozyc pliku do zapisu.\n");
		return;
	}

	fwrite(&liczba, sizeof(int), 1, plik); //zapis liczby książęk
	fwrite(baza, sizeof(Ksiazka), liczba, plik);

	fclose(plik);
	printf("Dane zapisano do pliku\n");
}

void wczytajZPliku(Ksiazka baza[], int *liczba) {
	FILE* plik = fopen(PLIK_BAZY, "rb");

	if (plik == NULL) {
		printf("plik nie istnieje. \n");
		utworzPrzykladowaBaze(baza, liczba);
		return;
	}

	fread(liczba, sizeof(int), 1, plik);

	fread(baza, sizeof(Ksiazka), *liczba, plik);

	fclose(plik);

	printf("Dane wczytano z pliku\n");

}

void utworzPrzykladowaBaze(Ksiazka baza[], int *liczba) {
	*liczba = 20;

	strcpy(baza[0].autor, "J.R.R Tolkien");
	strcpy(baza[0].tytul, "Hobbit");
	baza[0].rok_wydania = 1937;
	strcpy(baza[0].isbn, "9780261103344");
	baza[0].liczba_stron = 310;
	strcpy(baza[0].gatunek, "Fantastyka");
	strcpy(baza[0].okladka, "Miekka");

	strcpy(baza[1].autor, "George Orwell");
	strcpy(baza[1].tytul, "Rok 1984");
	baza[1].rok_wydania = 1949;
	strcpy(baza[1].isbn, "9780451524935");
	baza[1].liczba_stron = 328;
	strcpy(baza[1].gatunek, "Dystopia");
	strcpy(baza[1].okladka, "Miekka");

	strcpy(baza[2].autor, "Boleslaw Prus");
	strcpy(baza[2].tytul, "Lalka");
	baza[2].rok_wydania = 1890;
	strcpy(baza[2].isbn, "9788308049804");
	baza[2].liczba_stron = 676;
	strcpy(baza[2].gatunek, "Powiesc");
	strcpy(baza[2].okladka, "Twarda");

	strcpy(baza[3].autor, "Adam Mickiewicz");
	strcpy(baza[3].tytul, "Pan Tadeusz");
	baza[3].rok_wydania = 1834;
	strcpy(baza[3].isbn, "9788377910610");
	baza[3].liczba_stron = 376;
	strcpy(baza[3].gatunek, "Epos");
	strcpy(baza[3].okladka, "Twarda");

	strcpy(baza[4].autor, "J.K. Rowling");
	strcpy(baza[4].tytul, "Harry Potter i Kamien Filozoficzny");
	baza[4].rok_wydania = 1997;
	strcpy(baza[4].isbn, "9780747532699");
	baza[4].liczba_stron = 320;
	strcpy(baza[4].gatunek, "Fantastyka");
	strcpy(baza[4].okladka, "Twarda");

	strcpy(baza[5].autor, "Henryk Sienkiewicz");
	strcpy(baza[5].tytul, "Quo Vadis");
	baza[5].rok_wydania = 1896;
	strcpy(baza[5].isbn, "9788373271890");
	baza[5].liczba_stron = 512;
	strcpy(baza[5].gatunek, "Historyczna");
	strcpy(baza[5].okladka, "Twarda");

	strcpy(baza[6].autor, "Andrzej Sapkowski");
	strcpy(baza[6].tytul, "Ostatnie Zyczenie");
	baza[6].rok_wydania = 1993;
	strcpy(baza[6].isbn, "9788375780635");
	baza[6].liczba_stron = 288;
	strcpy(baza[6].gatunek, "Fantastyka");
	strcpy(baza[6].okladka, "Miekka");

	strcpy(baza[7].autor, "Stephen King");
	strcpy(baza[7].tytul, "Lsnienie");
	baza[7].rok_wydania = 1977;
	strcpy(baza[7].isbn, "9780307743657");
	baza[7].liczba_stron = 688;
	strcpy(baza[7].gatunek, "Horror");
	strcpy(baza[7].okladka, "Miekka");

	strcpy(baza[8].autor, "Antoine de Saint-Exupery");
	strcpy(baza[8].tytul, "Maly Ksiaze");
	baza[8].rok_wydania = 1943;
	strcpy(baza[8].isbn, "9788372780003");
	baza[8].liczba_stron = 96;
	strcpy(baza[8].gatunek, "Bajka");
	strcpy(baza[8].okladka, "Twarda");

	strcpy(baza[9].autor, "Frank Herbert");
	strcpy(baza[9].tytul, "Diuna");
	baza[9].rok_wydania = 1965;
	strcpy(baza[9].isbn, "9780441172719");
	baza[9].liczba_stron = 688;
	strcpy(baza[9].gatunek, "Science Fiction");
	strcpy(baza[9].okladka, "Twarda");

	strcpy(baza[10].autor, "Fiodor Dostojewski");
	strcpy(baza[10].tytul, "Zbrodnia i Kara");
	baza[10].rok_wydania = 1866;
	strcpy(baza[10].isbn, "9788373272118");
	baza[10].liczba_stron = 672;
	strcpy(baza[10].gatunek, "Powiesc");
	strcpy(baza[10].okladka, "Miekka");

	strcpy(baza[11].autor, "Harper Lee");
	strcpy(baza[11].tytul, "Zabic drozda");
	baza[11].rok_wydania = 1960;
	strcpy(baza[11].isbn, "9780061120084");
	baza[11].liczba_stron = 336;
	strcpy(baza[11].gatunek, "Powiesc");
	strcpy(baza[11].okladka, "Miekka");

	strcpy(baza[12].autor, "Dan Brown");
	strcpy(baza[12].tytul, "Kod Leonarda da Vinci");
	baza[12].rok_wydania = 2003;
	strcpy(baza[12].isbn, "9780307474278");
	baza[12].liczba_stron = 592;
	strcpy(baza[12].gatunek, "Thriller");
	strcpy(baza[12].okladka, "Miekka");

	strcpy(baza[13].autor, "Paulo Coelho");
	strcpy(baza[13].tytul, "Alchemik");
	baza[13].rok_wydania = 1988;
	strcpy(baza[13].isbn, "9780061122415");
	baza[13].liczba_stron = 208;
	strcpy(baza[13].gatunek, "Przygodowa");
	strcpy(baza[13].okladka, "Miekka");

	strcpy(baza[14].autor, "Suzanne Collins");
	strcpy(baza[14].tytul, "Igrzyska Smierci");
	baza[14].rok_wydania = 2008;
	strcpy(baza[14].isbn, "9780439023481");
	baza[14].liczba_stron = 384;
	strcpy(baza[14].gatunek, "Dystopia");
	strcpy(baza[14].okladka, "Miekka");

	strcpy(baza[15].autor, "Ernest Hemingway");
	strcpy(baza[15].tytul, "Stary czlowiek i morze");
	baza[15].rok_wydania = 1952;
	strcpy(baza[15].isbn, "9780684801223");
	baza[15].liczba_stron = 132;
	strcpy(baza[15].gatunek, "Powiesc");
	strcpy(baza[15].okladka, "Miekka");

	strcpy(baza[16].autor, "Aldous Huxley");
	strcpy(baza[16].tytul, "Nowy wspanialy swiat");
	baza[16].rok_wydania = 1932;
	strcpy(baza[16].isbn, "9780060850524");
	baza[16].liczba_stron = 288;
	strcpy(baza[16].gatunek, "Dystopia");
	strcpy(baza[16].okladka, "Miekka");

	strcpy(baza[17].autor, "Bram Stoker");
	strcpy(baza[17].tytul, "Dracula");
	baza[17].rok_wydania = 1897;
	strcpy(baza[17].isbn, "9780141439846");
	baza[17].liczba_stron = 418;
	strcpy(baza[17].gatunek, "Horror");
	strcpy(baza[17].okladka, "Twarda");

	strcpy(baza[18].autor, "George Orwell");
	strcpy(baza[18].tytul, "Folwark Zwierzecy");
	baza[18].rok_wydania = 1945;
	strcpy(baza[18].isbn, "9780451526342");
	baza[18].liczba_stron = 144;
	strcpy(baza[18].gatunek, "Satyra");
	strcpy(baza[18].okladka, "Miekka");

	strcpy(baza[19].autor, "J.R.R. Tolkien");
	strcpy(baza[19].tytul, "Wladca Pierscieni");
	baza[19].rok_wydania = 1954;
	strcpy(baza[19].isbn, "9780261103252");
	baza[19].liczba_stron = 1216;
	strcpy(baza[19].gatunek, "Fantastyka");
	strcpy(baza[19].okladka, "Twarda");
	
	zapiszDoPliku(baza, *liczba);
	printf("Utworzono przykladowa baze %d ksiazek. \n", *liczba);
}