#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float suma(float **TAB, int i, int n);

int main (void){
	srand(time(NULL));
	float T_1[4],T_2[6],T_3[3],T_4[2],T_5[4];


	for(int i = 0; i < 4; i++){
		T_1[i] = rand()/(float)(RAND_MAX/10);
		T_5[i] = rand()/(float)(RAND_MAX/10);
	}

	for(int i = 0; i < 6; i++){
		T_2[i] = rand()/(float)(RAND_MAX/10);
	}
	
	for(int i = 0; i < 3; i++){
		T_3[i] = rand()/(float)(RAND_MAX/10);
	}

	for(int i = 0; i < 2; i++){
		T_4[i] = rand()/(float)(RAND_MAX/10);
	}

	float *TAB[5];
	TAB[0] = T_1;
	TAB[1] = T_2;
	TAB[2] = T_3;
	TAB[3] = T_4;
	TAB[4] = T_5;


	int tab_pom[5] = {4,6,3,2,4};

	for(int i = 0; i < 5; i++){
		float sum = suma(TAB,i,tab_pom[i]);
		printf("\nSuma T_%d = %f\n", i+1,sum);
	}
	

	
	return 0;
}

float suma(float **TAB, int i, int n){
	float s = 0;
	for(int k = 0; k < n; k++){
		s+=TAB[i][k];
	}
	return s;
}
