#include <stdio.h>

int main(void){
	char tekst[] = "Ile i które z samoglosek znajdziesz w tym zdaniu ?";
	int len = sizeof(tekst)/sizeof(char);
	int i = 0;
	int sam_c[6] = {0};
	int sum_spolgloski = 0;
	int sum_samogloski = 0;
	int sum_wyrazy = 0;

	while(i < len){
		switch(tekst[i]){
			case 'a':
			case 'A':
				sam_c[0]++;
				break;			
			case 'e':
			case 'E':
				sam_c[1]++;
				break;			
			case 'i':
			case 'I':
				sam_c[2]++;
				break;			
			case 'o':
			case 'O':
				sam_c[3]++;
				break;			
			case 'u':
			case 'U':
				sam_c[4]++;
				break;			
			case 'y':
			case 'Y':
				sam_c[5]++;
				break;			
			case ' ':
				sum_wyrazy++;
				break;
			default:
				if((tekst[i] <= 'Z' && tekst[i] >= 'A') || (tekst[i] <= 'z' && tekst[i] >= 'a'))
				sum_spolgloski++;
				break;
		}
		i++;
	}

	printf("Samogloska 'a' wystapila %d razy\n",sam_c[0]);
	printf("Samogloska 'e' wystapila %d razy\n",sam_c[1]);
	printf("Samogloska 'i' wystapila %d razy\n",sam_c[2]);
	printf("Samogloska 'o' wystapila %d razy\n",sam_c[3]);
	printf("Samogloska 'u' wystapila %d razy\n",sam_c[4]);
	printf("Samogloska 'y' wystapila %d razy\n",sam_c[5]);

	for(int j = 0; j < 6; j++){
		sum_samogloski+=sam_c[j];
	}
	printf("Samogloski -> %d razy\n",sum_samogloski);
	printf("Spolgloski -> %d razy\n",sum_spolgloski);
	printf("Wyrazy -> %d razy\n",sum_wyrazy);
}
