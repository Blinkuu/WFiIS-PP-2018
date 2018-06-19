#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define N 100

void MakeStrings(char **tab1);
void Wypisz(char **tab1);
void FreeAll(char **tab1);
int compare(const void *a, const void *b);
int alphacompare(const void *a, const void *b);

int main(void){
	srand(time(NULL));
	char *tab1[N];
	MakeStrings(tab1);
	
	//Wypisz(tab1);
	qsort(tab1,N,sizeof(tab1[0]),compare);
	Wypisz(tab1);
	printf("--------------------------------------------------------");
	for(int i = 0; i < N; i++){
		qsort(tab1[i],strlen(tab1[i]),sizeof(char),strcmp);
	}
	qsort(tab1,N,sizeof(tab1[0]),alphacompare);
	Wypisz(tab1);
	FreeAll(tab1);
	return 0;
}

void MakeStrings(char **tab1){
	for(int i = 0; i < N; i++){
		int length = rand()%10+1;
		char *tab2 = malloc((length+1)*sizeof(char));
		for(int j = 0; j < length; j++){
			tab2[j] = rand()%26+97;
		}
		tab2[length+1] = '\0';
		tab1[i] = tab2;
	}
}

void Wypisz(char **tab1){
	for(int i = 0; i < N; i++){
		printf("%s\n",tab1[i]);
	}
}

void FreeAll(char **tab1){
	for(int i = 0; i < N; i++){
		free(tab1[i]);
	}
}

int compare(const void *a, const void *b){
	const char *tab1 = *(const char**)a;
	const char *tab2 = *(const char**)b;
	
	return strlen(tab1) - strlen(tab2);
}

int alphacompare(const void *a, const void *b){
	const char *tab1 = *(const char**)a;
	const char *tab2 = *(const char**)b;
	
	return strcmp(tab1,tab2);
}
