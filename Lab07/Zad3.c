#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define N 20

int qcompare(const void* a, const void *b);
int dcompare(const void* a, const void *b);
int icompare(const void* a, const void *b);
struct Liczba *Wypisz(struct Liczba *a);

struct Liczba{
	char znak;
	union Data{
		int i;
		double d;
	}data;
}liczba[N];

int main (void){
	
	srand(time(NULL));

	int p;
	int i_counter = 0;;
	int d_counter = 0;

	for(int i = 0; i < N; i++){
		p = rand()%2;
		if(p){
			liczba[i].data.i = rand()%10;
			liczba[i].znak = 'i';
			i_counter++;
		} else {
			liczba[i].data.d = (float)rand()/(float)(RAND_MAX)*10;
			liczba[i].znak = 'd';
			d_counter++;
		}
	}

	qsort(liczba,N,sizeof(liczba[0]),qcompare);
	
	qsort(liczba,d_counter,sizeof(liczba[0]),dcompare);

	qsort(&liczba[d_counter],i_counter,sizeof(liczba[0]),icompare);
	Wypisz(liczba);

	return 0;
}

struct Liczba *Wypisz(struct Liczba *a){
	for(int i = 0; i < N; i++){
		if(a[i].znak == 'i'){
			printf("%d \t int\n",a[i].data.i);
		} else {
			printf("%.2f \t double\n",a[i].data.d);
		}
	}
}

int qcompare(const void* a, const void *b){
	struct Liczba znakA = *(struct Liczba*)a;
	struct Liczba znakB = *(struct Liczba*)b;

	return znakA.znak - znakB.znak;
}

int dcompare(const void* a, const void *b){
	struct Liczba liczbaA = *(struct Liczba*)a;
	struct Liczba liczbaB = *(struct Liczba*)b;
	if(liczbaA.data.d < liczbaB.data.d) return -1;
	else return 1;
}

int icompare(const void* a, const void *b){
	struct Liczba liczbaA = *(struct Liczba*)a;
	struct Liczba liczbaB = *(struct Liczba*)b;

	return liczbaA.data.i - liczbaB.data.i;
}








