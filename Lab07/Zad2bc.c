#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define N 10

struct abc *DlugoscWektora(struct abc *abc);
int bcompare(const void *key, const void *elem);
int qcompare(const void *a, const void *b);

struct abc{
	struct Wektor{
		int x,y,z;
	}wektor;
	float dl_wektora;
}abc[N];



int main (void){
	srand(time(NULL));
	
	for(int i = 0; i < N; i++){
		abc[i].wektor.x = rand()%10;
		abc[i].wektor.y = rand()%10;
		abc[i].wektor.z = rand()%10;
	}
	
	for(int i = 0; i < N; i++){
		printf("x=%d y=%d z=%d\n",abc[i].wektor.x,abc[i].wektor.y,abc[i].wektor.z);
	}

	DlugoscWektora(abc);
	abc[9].dl_wektora = 1.0;
	qsort(abc,10,sizeof(abc[0]),qcompare);

	for(int i = 0; i < N; i++){
		printf("dl_wektora = %f\n",abc[i].dl_wektora);
	}

	float key = 1.0;
	int *p = bsearch(&key,abc,N,sizeof(abc[0]),bcompare);

	if(p){
		int licznik = 0;
		for(int i = 0; i < N; i++){
			float offset = abc[i].dl_wektora/100;
			if(key <= abc[i].dl_wektora + offset && key >= abc[i].dl_wektora - offset) licznik++;
		}
		printf("Key (%f) exists in an array! Number = %d\n",key,licznik);
	} else {
		printf("Key doesn't exist in an array!\n");
	}

	return 0;
}

struct abc *DlugoscWektora(struct abc *abc){
	for(int i = 0; i < N; i++){
		abc[i].dl_wektora = sqrt(pow(abc[i].wektor.x,2) + pow(abc[i].wektor.y,2) + pow(abc[i].wektor.z,2));
	}
}

int qcompare(const void *a, const void *b){
	struct abc elemA = *(struct abc*)a;
	struct abc elemB = *(struct abc*)b;

	return elemA.dl_wektora - elemB.dl_wektora;
}

int bcompare(const void *key, const void *elem){
	struct abc elemS = *(struct abc*)elem;
	float offset = elemS.dl_wektora/100;
	
	if(*(float*)key <= elemS.dl_wektora + offset && *(float*)key >= elemS.dl_wektora - offset) return 0;
	if(*(float*)key < elemS.dl_wektora - offset) return -1;
	if(*(float*)key > elemS.dl_wektora + offset) return 1;
}








