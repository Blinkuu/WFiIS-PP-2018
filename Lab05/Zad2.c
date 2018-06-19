#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

	for(int i = 0; i < argc; i++){
		printf("Argument[%d] = %s\n",i,argv[i]);
	}
	
	int i = atoi(argv[2]);
	float f = atof(argv[3]);

	printf("i = %d, f = %f\n", i, f);

	char arr[80];
	printf("Podaj lancuch znakow:\n");
	int j = 0;

	while(scanf("%c",&arr[j])){
		printf("%c",arr[j]);	
		if(arr[j++] == '\n')
			break;
	}

	printf("Podaj drugi lancuch znakow:\n");
	char txt[80], *h;
	gets(txt);
	printf("%s",txt);
	
	return 0;
}

