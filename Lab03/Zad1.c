#include <stdio.h>
#include <stdlib.h>

int main (void){
	
	int n;
	do{
		printf("Podaj wysokosc trojkata (N<=100!): ");
		scanf("%d",&n);
	}while(n>=100);
	n++;
	int *tab1 = calloc(n+1,sizeof(int));
	int *tab2 = calloc(n+1,sizeof(int));


	*(tab1+1) = 1;
	for(int j = 0; j<n; j++){
		for(int i = 1; i <= n; i++){
			*(tab2+i) = *(tab1+i-1) + *(tab1+i);
		}
		
		for(int i = j; i < n; i++){
			printf(" ");
		}

		for(int i = 1; i <= n; i++){
			if(*(tab1+i) == 0){
				break;
			}
				
			printf("%d ",*(tab1+i));
		}

		for(int i = 0; i <= n; i++){
			*(tab1+i) = *(tab2+i);
		}
		printf("\n");
	}

	free(tab1);
	free(tab2);

	return 0;
}
