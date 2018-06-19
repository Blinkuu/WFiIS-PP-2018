#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int T[4][2];
	int mnoznik = 1;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 2; j++){
			T[i][j] = 2*mnoznik;
			mnoznik++;
		}
	}

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 2; j++){
			printf("T[%d][%d] = %d &T[%d][%d] = %p ",i,j,T[i][j],i,j,&T[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	printf("*T[0] = %d, T[0] = %p \n*T[0]+1 = %d, T[0]+1 = %p\n\n",*T[0],T[0],*(T[0]+1),T[0]+1);

	printf("*T = %p, T = %p \n*T+1 = %p, T+1 = %p\n\n",*T,T,*(T+1),T+1);
	
	printf("**T = %d, *T = %p\n**T+1 = %d, *T+1 = %p\n**(T+1) = %d, *(T+1) = %p\n\n",**T,T,**T+1,T+1,**(T+1),*(T+1));
	
	printf("\n");

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 2; j++){
			printf("T[%d][%d] = %d &T[%d][%d] = %p ",i,j,T[i][j],i,j,&T[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 2; j++){
			printf("*(*(T+%d)+%d) = %d  (T+%d)+%d= %p ",i,j,*(*(T+i)+j),i,j,&T[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	int (*wsk2d)[2] = T;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 2; j++){
			printf("T[%d][%d] = %d &T[%d][%d] = %p ",i,j,T[i][j],i,j,&T[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
