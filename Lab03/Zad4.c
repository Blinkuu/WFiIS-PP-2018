#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 8
#define K 4
#define N 8

void Mnoz(float tab1[][N], float tab2[][N], float scoreTab[][N], int Ile_wierszy, int Ile_kolumn);
void Mnoz_Uniwersalne(float tab1[][K], float tab2[][N], float scoreTab[][N], int m, int k, int n);

int main(void)
{
    srand(time(NULL));

    float tab1[N][N];
    float tab2[N][N];
    float scoreTab[N][N] = {0};

    float tab3[M][K];
    float tab4[K][N];
    float scoreTab2[M][N] = {0};

    int min = 125;
    int max = 440;

//Wypelnianie tab1 i tab2
/*
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tab1[i][j] = (float)(rand()%(max-min+1)+min)/10.0;
            tab2[i][j] = (float)(rand()%(max-min+1)+min)/10.0;
        }
    }
*/

//Wypelnianie tab3 i tab4
    for(int i = 0; i < M; i++)
        for(int j = 0; j < K; j++)
            tab3[i][j] = (float)(rand()%(max-min+1)+min)/10.0;

    for(int i = 0; i < K; i++)
        for(int j = 0; j < N; j++)
            tab4[i][j] = (float)(rand()%(max-min+1)+min)/10.0;

    //Wyswietlanie tab1 i tab2
    /*for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%.2f ",tab1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%.2f ",tab2[i][j]);
        }
        printf("\n");
    }*/

    //Wyswietlanie tab3 i tab4
	printf("I macierz o rozmiarze %d x %d:\n",M,K);
    for(int i = 0; i < M; i++){
        for(int j = 0; j < K; j++)
            printf("%.2f ",tab3[i][j]);
        printf("\n");
    }

    printf("\n");
	printf("II macierz o rozmiarze %d x %d:\n",K,N);
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++)
            printf("%.2f ",tab4[i][j]);
        printf("\n");
    }

    printf("\n");

//Mnozenie tablic o wymiarach NxN
/*    Mnoz(tab1,tab2,scoreTab,N,N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%.2f ",scoreTab[i][j]);
        }
        printf("\n");
    }
*/

    Mnoz_Uniwersalne(tab3,tab4,scoreTab2,M,K,N);

	printf("Wynik mnozenia macierzy I oraz macierzy II:\n");
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++)
            printf("%.2f ",scoreTab2[i][j]);
        printf("\n");
    }

    return 0;
}

void Mnoz(float tab1[][N], float tab2[][N], float scoreTab[][N], int Ile_wierszy, int Ile_kolumn){
    float mnoznik;
    for(int i = 0; i < Ile_kolumn; i++){
        mnoznik = 0;
        for(int j = 0; j < Ile_wierszy; j++){
            for(int k = 0; k < N; k++) mnoznik += tab1[i][k] * tab2[k][j];
            scoreTab[i][j] = mnoznik;
        }
        printf("\n");
    }
}

void Mnoz_Uniwersalne(float tab1[][K], float tab2[][N], float scoreTab[][N], int m, int k, int n){
    float mnoznik;
    for(int i = 0; i < m; i++){

        for(int j = 0; j < n; j++){
            mnoznik = 0;
            for(int g = 0; g < n; g++) mnoznik += tab1[i][g] * tab2[g][j];
            scoreTab[i][j] = mnoznik;
        }
        printf("\n");
    }
}
