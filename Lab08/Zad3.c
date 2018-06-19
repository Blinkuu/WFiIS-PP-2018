#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
int main (void){
	srand(time(NULL));
	float arr[N];

	for(int i = 0; i < N; i++){
		arr[i] = (float)rand()/(float)(RAND_MAX/100.0);
	}







	FILE *fptr;
	long size;
	fptr = fopen("WynikiZad3.txt","w");
	if(fptr == NULL){
		printf("Error!");
		exit(1);
	} else {
		for(int i = 0; i < N; i++){
			fprintf(fptr,"%.2f\n",arr[i]);
		}
		fseek(fptr,0,SEEK_END);
		size=ftell(fptr);
		printf("Dlugosc pliku txt = %lu\n",size);
	}

	fclose(fptr);









	fptr = fopen("WynikiZad3.bin","wb");
	if(fptr == NULL){
		printf("Error!");
		exit(1);
	} else {
		fwrite(arr,sizeof(float),N,fptr);
		fseek(fptr,0,SEEK_END);
		size=ftell(fptr);
		printf("Dlugosc pliku bin = %lu\n",size);
	}

	fclose(fptr);
	

	return 0;
}
