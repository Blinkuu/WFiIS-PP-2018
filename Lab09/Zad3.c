#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define N 100

void ReadBinary();
void WriteToFile(float *arr);
void WriteToBinaryFile(float *arr);
void OpenBinaryAndCheck(float *arr);

int main(void){
	float arr[N];
	
	for(int i = 0; i < 100; i++){
		arr[i] = (float)rand()/(float)(RAND_MAX/N);
		//printf("%.2f\n", arr[i]);
	}
	WriteToFile(arr);
	WriteToBinaryFile(arr);
	OpenBinaryAndCheck(arr);
	ReadBinary();
	

	return 0;
}

void ReadBinary(){
	FILE *fptr;
	fptr = fopen("Tekstowy.bin","rb");

	if(fptr == NULL){
		printf("Error!");
		exit(1);
	}
	float x = 0;
	for(int i = 0; i < N; i++){
		fread(&x,sizeof(float),1,fptr);
		printf("%f\n",x);
	}
	fclose(fptr);
}

void OpenBinaryAndCheck(float *arr){
	FILE *fptr;
	fptr = fopen("Tekstowy.bin","rb+");

	if(fptr == NULL){
		printf("Error opening file!");
		exit(1);
	}
	float zero = 0;

	for(int i = 0; i < N/5; i++){
		fseek(fptr,4*sizeof(float),SEEK_CUR);
		fwrite(&zero,sizeof(float),1,fptr);
	}
	fclose(fptr);
}

void WriteToFile(float *arr){
	FILE *fptr;
	fptr = fopen("Tekstowy.txt","w");

	if(fptr == NULL){
		printf("Error!");
		exit(1);
	}
	
	for(int i = 0; i < N; i++){
		fwrite(&arr[i],sizeof(float),1,fptr);
	}
	
	fclose(fptr);
}

void WriteToBinaryFile(float *arr){
	FILE *fptr;
	fptr = fopen("Tekstowy.bin","wb");

	if(fptr == NULL){
		printf("Error!");
		exit(1);
	}

	for(int i = 0; i < N; i++){
		fwrite(&arr[i],sizeof(float),1,fptr);
	}

	fclose(fptr);
}
