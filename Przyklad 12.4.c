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
