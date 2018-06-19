#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){


	char arr[80];
	char txt;
	int j = 0;
	int licznik = 0;

	while(scanf("%c",&txt))
	{
		arr[j] = txt;
		j++;
		
		if(txt == '\n')
		{
			arr[j+1] = '\0';

			if(strstr(arr,"wagon") || strstr(arr,"Wagon") )
			{
				printf("%s",arr);			
				licznik++;
			}
			
			for(int i = 0; i < 80; i++)
			{
				arr[i] = '\n';
			} 
			j=0;	
		}
		
		if(feof(stdin))
			break;
	}

	printf("Licznik wagonow = %d\n", licznik);

	return 0;
}

