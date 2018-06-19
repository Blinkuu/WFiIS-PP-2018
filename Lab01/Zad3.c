#include <stdio.h>
int main(void){
	float x;
	float *px;
	float *py;
	printf("Adres zmiennej x: %p\n",&x);
	printf("Adres zmiennej px: %p\n",&px);
	printf("Adres zmiennej py: %p\n",&py);

	printf("Wartosc zmiennej x: %f\n",x);
	printf("Wartosc zmiennej px: %p\n",px);
	printf("Wartosc zmiennej py: %p\n",py);
	
	if(px){
		printf("Wartosc px jest rozna od NULL\n");
	}

	if(py){
		printf("Wartosc py jest rozna od NULL\n");
	}


		scanf("%f",&x);
		printf("\n");


	printf("Adres zmiennej x: %p\n",&x);
	printf("Adres zmiennej px: %p\n",&px);
	printf("Adres zmiennej py: %p\n",&py);

	printf("Wartosc zmiennej x: %f\n",x);
	printf("Wartosc zmiennej px: %p\n",px);
	printf("Wartosc zmiennej py: %p\n",py);
	
	if(px){
		printf("Wartosc px jest rozna od NULL\n");
	}

	if(py){
		printf("Wartosc py jest rozna od NULL\n");
	}

		px = &x;
		printf("\n");
	
	printf("Adres zmiennej x: %p\n",&x);
	printf("Adres zmiennej px: %p\n",&px);
	printf("Adres zmiennej py: %p\n",&py);

	printf("Wartosc zmiennej x: %f\n",x);
	printf("Wartosc zmiennej px: %p\n",px);
	printf("Wartosc zmiennej py: %p\n",py);
	
	if(px){
		printf("Wartosc px jest rozna od NULL\n");
	}

	if(py){
		printf("Wartosc py jest rozna od NULL\n");
	}

		py = px;
		printf("\n");

	printf("Adres zmiennej x: %p\n",&x);
	printf("Adres zmiennej px: %p\n",&px);
	printf("Adres zmiennej py: %p\n",&py);

	printf("Wartosc zmiennej x: %f\n",x);
	printf("Wartosc zmiennej px: %p\n",px);
	printf("Wartosc zmiennej py: %p\n",py);
	
	if(px){
		printf("Wartosc px jest rozna od NULL\n");
	}

	if(py){
		printf("Wartosc py jest rozna od NULL\n");
	}

		x = *py;
}
