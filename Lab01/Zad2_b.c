#include <stdio.h>
#include <math.h>
int main (void){
	int liczba;
	scanf ("%d",&liczba);
	int suma = 0;
	int counter = 0;
	printf("Reprezentacja binarna: ");
	while (liczba){
		suma += (liczba%2)*(pow(10,counter));
		liczba = liczba >> 1;
		counter++;
	}

	printf("%d", suma);
}
