#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void TwoMax(int *arr_a);

int main (int argc, char *argv[]){


	char arr[80];
	char txt;
	int j = 0;
	int line_c = 0;
	int word_c = 0;
	int arr_a[26] = {0};

	while(scanf("%c",&txt))
	{
		if(isalpha(txt)){
			if(isupper(txt)){
				arr_a[txt - 'A']++;
			} 
			if(islower(txt)){
				arr_a[txt - 'a']++;
			}
		}		
		
		if(txt == '\n')
			line_c++;	
		word_c++;

		if(feof(stdin))
			break;
		
	}

	printf("Liczba linii = %d\n", line_c);
	printf("Liczba znakow = %d\n", word_c);

	TwoMax(arr_a);

	return 0;
}

void TwoMax(int *arr_a){
	int max1 = 26;
	int max2 = 26;

	for(int i = 26; i >= 0; i--){
		if(arr_a[i] > arr_a[max1]){
			max2 = max1;		
			max1 = i;
		}
	}

	printf("Najczesciej wystepujaec litery to: %c = %d oraz %c = %d\n",max2+'A',arr_a[max2],max1+'A',arr_a[max1]);
}

