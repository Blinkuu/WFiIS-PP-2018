#include <stdio.h>
#include <stdarg.h>

float average(int counter, ...) {
	va_list ap;
	int next = 0, sum = 0, i = counter;
	
	if(counter == 0) {
		return 0.0;
	}

	va_start(ap,counter);
	while(i--) {
		next = va_arg(ap,int);
		sum += next;
	}
	va_end(ap);
	return (float)sum/counter;

}

void Wypisz(int counter, ...) {
	va_list ap;

	
	va_start(ap,counter);
	for(int i = 0; i < counter;i++) {
		if(i%3 == 0){ 
			int next = va_arg(ap,int);
			printf("char = %c\n",next);
		} else if(i%3 == 1) {
			int next = va_arg(ap,int);
			printf("int = %d\n",next);
		} else if(i%3 == 2){
			double next = va_arg(ap,double);
			printf("float = %f\n",next);
		}
	}
	va_end(ap);
	printf("\n");
}

int main (void) {
	float result = average(4,1,2,3,4);
	printf("%f\n\n",result);

	char a = 'a';
	int b = 1;
	float c = 2.5;
	Wypisz(7,a,b,c,a,b,c,a);
	return 0;
}
