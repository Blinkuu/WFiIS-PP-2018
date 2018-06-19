#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int qcompare(const void *a, const void *b);
int bcompare(const void *key, const void *x);

int main (int argc, char *argv[]){
	srand(time(NULL));

	int arr[1000];
	for(int i = 0; i < 1000; i++){
		arr[i] = rand()%200 - 100;
	}

	qsort(arr,1000,sizeof(int),qcompare);
	
	for(int i = 0; i < 1000; i++){
		printf("%d\n",arr[i]);
	}
	
	printf("\n\n");

	for(int i = 1; i < argc; i++){
		int key = atoi(argv[i]);
		int *p;
		p = bsearch(&key, arr, 1000, sizeof(int), bcompare);
		
		int *a;
		int *b;
		
		if(p){
			for(int *start = p; start < arr + 1000; start++){
				if(*start != *p){
					b = start-1;
					break;
				}
			}

			for(int *start = p; start > arr; start--){
				if(*start != *p){
					a = start;
					break;
				}
			}

			printf("%d exists in an array! Number: %d\n",key,b-a);
		} else {
			printf("%d doesn't exist in an array!\n",key);
		}

	}

	return 0;
}

int qcompare(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int bcompare(const void *key, const void *x){
	return *(int*)key - *(int*)x;
}
