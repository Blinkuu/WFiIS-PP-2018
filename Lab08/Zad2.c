#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>	



struct zxy{
	char znak;
	struct zxy *wsk;
}a,b,c;

void SwapChar(struct zxy *x);

int main (void){
	
	a.wsk = &b;
	b.wsk = &c;
	c.wsk = &a;

	a.znak = '+';
	(*(a.wsk)).znak = '+';
	(*(*(a.wsk)).wsk).znak = '-';

	printf("znak a = %c , znak b = %c , znak c = %c\n",a.znak,b.znak,c.znak);	

	b.znak = 'b';
	b.wsk -> znak = 'c';
	b.wsk -> wsk -> znak = 'a';
	
printf("znak a = %c , znak b = %c , znak c = %c\n",a.znak,b.znak,c.znak);	

	SwapChar(&c);
	SwapChar(c.wsk);
	SwapChar((c.wsk)->wsk);

printf("znak a = %c , znak b = %c , znak c = %c\n",a.znak,b.znak,c.znak);	

	return 0;
}

void SwapChar(struct zxy *x){
	if(islower((*x).znak)){
		(*x).znak -= 32;
	} else {
		(*x).znak += 32;
	}
}
