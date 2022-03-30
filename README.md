# Wprowadzenie do wskaźników.
Wskaźnik to zmienna przechowująca adres pamięci. Posiada ona swój typ. Typy zmiennych wskaźnikowych są takie same jak zwykłe typy zmiennych, jednak, aby zadeklarować zmienną wskaźnikową należy po typie zmiennej użyć operatora \*. 

*Przykład (12.0) deklaracja zmiennych wskaźnikowych*
```
int* wsk_int;
char* wsk_char;
struct node* wsk_node;
```

## **Wskaźniki na zmienne, referencja i dereferencja**
Wskaźnik taki można następnie przypisać do istniejącej zmiennej za pomocą operatora referencji `&`. Z operatorem tym spotkaliśmy się już na samym początku przy omawianiu funkcji `scanf`. 

*Przykład (12.1) Stworzenie wskaźnika na zmienną*
```
int zmienna;
int* wsk_int= &zmienna;
/*----------------------- lub w inny sposób --------------------*/
int zmienna;
int* wsk_int;
wsk_int = &zmienna;

```

Ponieważ `wsk_int` w przykładzie (12.1) jest wskaźnikiem na zmienną o nazwie zmienna, to za jego pomocą możemy modyfikować wartość zmiennej. Operacje takie wykonuje się przy wtkorzystaniu operatora dereferencji `*`użytego przed wskaźnikiem. Trafnie obrazuje to schemat poniżej (12.0) . 

Język ANSI C. Programowanie B.W Kernighan D.M. Rithie.

*Schemat (12.0) wskaźniki na zmienne*

![wskaznikiopng](https://user-images.githubusercontent.com/71324202/160777339-4b090071-38cc-4909-80c8-5009f72b48d6.png)


Wskaźnik na zmienną może wskazywać wiele różnych zmiennych w toku działania programu, ale tylko na jedną w dowolnym momencie. 

## **Arytmetyka wskaźników**
Wskaźniki są specyficznym typem zmiennych. Można wykonywać operacje odejmowania dwóch wskaźników lub dodawania i odejmowania liczby całkowitej. W pierwszym wypadku odjąć można od siebie dwa wskaźniki tego samego typu. Wynikiem takiej operacji będzie liczba całkowita, określająca różnicę względną wskaźników czyli ilość zmiennych swojego typu która zmieściłaby się pomiędzy jednym a drugim. W przypadku dodawania lub odejmowania liczb całkowitych, wartość wskaźnika ulegnie zmianie tak, że za każdą jedność w liczbie odejmowanej wskaźnik zostanie przeniesiony o rozmiar zmiennej swojego typu. Własności te są bardzo przydatne w przypadku poruszania się po tablicy. Poruszając się po tablicy możemy bowiem przemieszczać się po niej za pomocą wskaźników. Dodatkowo własnością tablicy jest to, że jej nazwa jest wskaźnikiem na jej pierwszy element. 

*Przykład (12.2.1) poruszanie się po tablicy za pomocą wskaźników.*
```
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 6   

int main()
{
	
	int array[ARRAY_SIZE] = {1,2,3,4,5,6};
	int *ptrArray;
	
	for(ptrArray = array; ptrArray-array < ARRAY_SIZE; ptrArray++)
	{
		printf("%d ", *ptrArray);
	}
	return 0;
}
```

*Przykład (12.2.2) poruszanie się po tablicy za pomocą wskaźników.*
```
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 6   

int main()
{
	
	int array[ARRAY_SIZE] = {1,2,3,4,5,6};
	int *ptrArray = array;
	int i;
	for( i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", *(ptrArray+i));
	}
	return 0;
}
```

*Wynik działania programów:*

> 1 2 3 4 5 6 

Przeanalizujmy przykład (12.2). Pierwszym wyrażeniem zawartym w pętli for, jest przypisanie do wskaźnika ptrArray wartości wskaźnika na pierwszego elementu tablicy array. W warunku wykonywania mamy dokonane odejmowanie dwóch wskaźników ptrArray i array. Jego wynikiem jest odległość pomiędzy pierwszym elementem tablicy a aktualnie wskazywanym przez ptrArray. Ostatnie wyrażenie, definiujące krok iteracyjny jest wykonanie inkrementacji wskaźnika ptrArray. W wyniku tej operacji, wskaźnik ptrArray zacznie wskazywać kolejny element tablicy. Wynika to z dwóch własności – pierwsza to własność tablicy, mówiąca, że tablica jest spójnym blokiem pamięci, a druga jest własność operacji na wskaźniku, czyli że dodanie 1 do wskaźnika skutkuje przeniesieniem go o rozmiar jaki zajmuje jego typ zmiennej (czyli de facto trafiamy właśnie w miejsce gdzie przechowywany jest kolejny element tablicy. Wewnątrz printf użyty został operator dereferencji, aby uzyskać dostęp do zmiennej na którą wskaźnik wskazuje a nie do wartości wskaźnika.

Ważnym zagadnieniem do omówienia, które stwarza wiele problemów, jest podejście do operacji na tablicy wymiarowej przy pomocy wskaźnika. Aby wykonać operacje na tablicy wielowymiarowej, należy wykorzystać własność, że tablica jest spójnym blokiem pamięci. Można więc dostać się do poszczególnych elementów tablicy w sposób przedstawiony w poniższym przykładzie (12.3).

*Przykład (12.3) poruszanie się po tablicy wielowymiarowej za pomocą wskaźnika*

```
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 3

int main() 
{
	
	int array[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
	int* ptr;
	
	for(ptr=array; ptr <= &array[ARRAY_SIZE-1][ARRAY_SIZE-1]; ptr++)
	{
		printf(" %d", *ptr);
	}
	return 0;
}
```
*Wynik działania programu:*

> 1 2 3 4 5 6 7 8 9

## **Wskaźnik na wskaźnik**
Wskaźniki mogą również wskazywać inne wskaźniki. Taki efekt uzyskamy poprzez dodanie kolejnego operatora \* po nazwie typu.

*Przykład (12.4) wskaźnik na wskaźnik na wskaźnik …*
```
#include <stdio.h>
#include <stdlib.h>


int main() 
{
	
	int  liczba=20;
	int* wsk_int;
	int** wsk_wsk_int;
	int*** wsk_wsk_wsk_int;
	
	wsk_int = &liczba;
	wsk_wsk_int = &wsk_int;
	wsk_wsk_wsk_int = &wsk_wsk_int;

	printf(" liczba= %8d ; ",liczba);
	printf(" *wsk_int= %8d ; ", *wsk_int);
	printf(" **wsk_wsk_int= %8d ; ",**wsk_wsk_int);
	printf(" ***wsk_wsk_wsk_int= %8d \n", ***wsk_wsk_wsk_int);
	
	liczba++;
	
	printf(" liczba= %8d ; ",liczba);
	printf(" *wsk_int= %8d ; ", *wsk_int);
	printf(" **wsk_wsk_int= %8d ; ",**wsk_wsk_int);
	printf(" ***wsk_wsk_wsk_int= %8d \n", ***wsk_wsk_wsk_int);
	
	printf("&liczba= %8x ; ",&liczba);
	printf("  wsk_int= %8x ; ", wsk_int);
	printf("  *wsk_wsk_int= %8x ; ",*wsk_wsk_int);
	printf("  **wsk_wsk_wsk_int= %8x \n", **wsk_wsk_wsk_int);
	
	printf("                  ; ");
	printf(" &wsk_int= %8x ; ", &wsk_int);
	printf("   wsk_wsk_int= %8x ; ",wsk_wsk_int);
	printf("   *wsk_wsk_wsk_int= %8x \n", *wsk_wsk_wsk_int);
	
	printf("                  ; ");
	printf("                    ; ");
	printf("  &wsk_wsk_int= %8x ; ", &wsk_wsk_int);
	printf("    wsk_wsk_wsk_int= %8x \n", wsk_wsk_wsk_int);
	return 0;
}

```

Działanie programu z przykładu (12.4), obrazuje wartości poszczególnych zmiennych wskaźnikowych oraz ich referencji i dereferencji. Wskaźniki na wskaźniki są niezbędne przy dynamicznym alokowaniu tablic wielowymiarowych, co jest opisane w rozdziale 14.


## Zadania do samodzielnego wykonania:

Wprowadzenie do wskaźników jest rozdziałem teoretycznym, nie da się zrobić na tym etapie wielu zadań praktycznych, jednak ta wiedza jest niezwykle istotna do zrozumienia kolejnych rozdziałów.

1. Wykonaj następujące kroki:
   1. zadeklaruj zmienną oraz wskaźnik typu int;
   1. następnie zainicjalizuj zmienną wybraną przez siebie wartością oraz przypisz wskaźnikowi adres tej zmiennej;
   1. wyświetl kolejno wartość zmiennej, jej adres, potem adres na który wskazuje wskaźnik;
   1. zmień wartość zmiennej operacją przypisania i wykonaj ponownie punkt iii; 
   1. zmień wartość zmiennej operacją przypisania przy pomocy dereferencji przez wskaźnik i wykonaj ponownie punkt iii.

1. Wykonaj następujące kroki:
   1. zadeklaruj i zainicjalizuj tablice o rozmiarze 10 elementów oraz wskaźnik na tą tablicę
   1. wyświetl kolejno elementy tablicy przy pomocy wskaźnika
   1. zmień dwa wybrane przez siebie elementy tablicy przy pomocy wskaźnika i operacji na nim


***
[Poprzednia część]() | [Spis treści](https://github.com/CyberMALab/Wprowadzenie-do-programowania-w-j-zyku-ANSI-C.git) | [Następna część](https://github.com/CyberMALab/Comming-Soon.git)
***
&copy; Cyberspace Modelling and Analysis Laboratory
