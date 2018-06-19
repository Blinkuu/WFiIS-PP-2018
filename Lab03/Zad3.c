#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void Srednie(int *tab, int n, float *sw);
void SredniaKolumny(int tab[][5], int n, float sk[]);
void Transpozycja(int tab[][5],int transposeTab[][5], int n1, int n2);
void Transpozycja_Jedna_Tablica(int tab[][5], int n1, int n2);
void Wypisz(int tab[][5], int n1, int n2);
int suma(int tab[][5], int n);
void Swap(int *a, int *b);

int main()
{
    srand(time(NULL));
    int tab[N][N];
    int transposeTab[N][N];
    float sw[N], sk[N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            *(*(tab+i)+j) = rand()%(30-20+1) + 10;
            printf("%d ",*(*(tab+i)+j));
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++){
        Srednie(tab[i],N,&sw[i]);
    }

    for(int i = 0; i < N; i++){
        printf("Srednia %d wiersza = %.2f\n",i,sw[i]);
    }

    //Transpozycja(tab,transposeTab,N,N);
    //Wypisz(transposeTab,N,N);

	Transpozycja_Jedna_Tablica(tab,N,N);
	Wypisz(tab,N,N);

    SredniaKolumny(tab,N,sk);
    for(int i = 0; i < N; i++){
        printf("Srednia %d kolumny = %.2f\n",i,sk[i]);
    }

    printf("\n");

    if(suma(tab,N))
        printf("Tak, suma elementow we wszystkich wierszach jest rowna sumie elementow we wszystkich kolumnach.\n");

    return 0;
}

void Srednie(int *tab, int n, float *sw){
    int suma = 0;
    float srednia;
    for(int i = 0; i < n; i++){
        suma += tab[i];
    }
    srednia = (float)suma/n;
    *sw = srednia;
}

void SredniaKolumny(int tab[][5], int n, float sk[]){
    int suma = 0;
    float srednia;
    for(int i = 0; i < n; i++){
        suma = 0;
        for(int j = 0; j < n; j++){
            suma+=tab[j][i];
        }
        sk[i] = (float)suma/n;
    }
}
void Transpozycja(int tab[][5], int transposeTab[][5], int n1, int n2){
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            transposeTab[j][i] = tab[i][j];
        }
    }
}

void Transpozycja_Jedna_Tablica(int tab[][5], int n1, int n2){
	for(int i = 0; i < n1; i++){
		for(int j = i; j < n2; j++){
			Swap(&tab[j][i],&tab[i][j]);
		}
	}
}

void Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Wypisz(int tab[][5], int n1, int n2){
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}

int suma(int tab[][5], int n){
    int sumaK = 0, sumaW = 0, sumaA = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sumaW += tab[j][i];
            sumaK += tab[i][j];
        }
    }
    if(sumaW==sumaK)
        return 1;
    return 0;
}
