#include <stdio.h>
#define BINSIZE 8
int main (void){
 int liczba;
 scanf ("%d",&liczba);
 char tab[BINSIZE] = "\0";

 printf("Reprezentacja binarnia:");
 int licznik=7;
 while(liczba){
 	tab[licznik] += (liczba%2) + '0';
	printf("%c", tab[licznik]);
 	liczba = liczba >> 1;
	licznik--;
 }
}
