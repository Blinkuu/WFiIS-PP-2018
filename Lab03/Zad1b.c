#include <stdio.h>
#include <stdlib.h>

int main (void){
	
	int n;
	do{
		printf("Podaj wysokosc trojkata (N<=100!): ");
		scanf("%d",&n);
	}while(n>=100);
	n++;

	int *tab = malloc(sizeof(int));



	for(int j = 0; j<n; j++){
		*tab = 1;
		*(tab+j) = 1;

		for(int i = j; i < n; i++){
			printf(" ");
		}
		

		for(int i = 0; i < j+1; i++){
			printf("%d ",*(tab+i));
		}

		for(int i = j; i > 0; i--){
			
			*(tab+i) += *(tab+i-1);
		}

		tab = realloc(tab,(j+2)*sizeof(int));
		printf("\n");
	}

	free(tab);

	return 0;
}
