#include <stdio.h>
#include <stdarg.h>

struct pair {
	float x;
	char z;
};

char max_chr_flt(int n, ...){
	va_list ap;
	va_start(ap,n);
	struct pair Pair[n];
	double max = 0.0;
	char c;
	for(int i = 0; i < n; i = i+2){
			Pair[i].x = va_arg(ap,double);
			Pair[i].z = va_arg(ap,int);
			if(Pair[i].x > max){
				max = Pair[i].x;
				c = Pair[i].z;
			}
	}
	
	va_end(ap);
	return c;
}

int main (void) {
	
	char znak = max_chr_flt(8,10.34,'a',122.0,'f',100.12,'x',1.67,'d');
	printf("%c\n",znak);
	return 0;
}
