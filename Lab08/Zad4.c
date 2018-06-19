#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> 
#include <string.h>
#include <time.h>
#define N 200

int main (void){

	int arr1[N];
	int arr2[N];
	char help[N];

	FILE *fptr1;
	FILE *fptr2;
	fptr1 = fopen("liczba1","r");
	fptr2 = fopen("liczba2","r");
	if(fptr1 == NULL || fptr2 == NULL){
		printf("Error!");
		exit(1);
	} else {
		fscanf(fptr1,"%s",help);
		for(int i = 0; i < N; i++){
			arr1[i] = atoi(help+i);
			printf("%d",arr1[i]);
		}
		printf("\n");
		fscanf(fptr2,"%s",help);
		for(int i = 0; i < N; i++){
			arr2[i] = atoi(help+i);
			printf("%d",arr2[i]);
		}
		printf("\n");
	}

	
	return 0;
}

