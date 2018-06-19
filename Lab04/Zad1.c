#include <stdlib.h>
#include <stdio.h>

int main(void){

	int n;
	
	do{
	printf("Podaj N (N musi byc mniejsze od 1000000!): ");
	scanf("%d",&n);	
	}while(n>1000000);

	
	int *arr = malloc(n*sizeof(int));
	for(int i = 0; i < n; i++)
		arr[i] = 0;
	
	for(int i = 2; i*i < n; i++){
		for(int j = i*i; j < n; j+=i)
			if(!arr[j])
				arr[j] = 1;
	}

	for(int i = 2; i < n; i++)
		if(!arr[i])
			printf("%d\n",i);
	
	free(arr);	
	
	return 0;
}
