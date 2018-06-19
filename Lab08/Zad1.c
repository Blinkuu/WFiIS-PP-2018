#include <stdlib.h>
#include <stdio.h>

struct Wektor SumaWektorow(struct Wektor w1, struct Wektor w2);
void IloczynSkalarnyWektorow(struct Wektor *w1, struct Wektor *w2, float *iloczynSkalarny);
void IloczynWektorowy(struct Wektor w1, struct Wektor w2, struct Wektor *iloczynW);

struct Wektor{
	float x,y,z;
};

int main (void){
	
	struct Wektor wektor1;
	struct Wektor wektor2;
	struct Wektor sumaW;
	struct Wektor iloczynW;
	scanf("%f %f %f",&wektor1.x,&wektor1.y,&wektor1.z);
	scanf("%f %f %f",&wektor2.x,&wektor2.y,&wektor2.z);

	printf("w1 = [%.2f,%.2f,%.2f] \t w2 = [%.2f,%.2f,%.2f]\n",wektor1.x,wektor1.y,wektor1.z,wektor2.x,wektor2.y,wektor2.z);
	
	sumaW = SumaWektorow(wektor1,wektor2);
	printf("Suma Wektorow = [%.2f,%.2f,%.2f]\n",sumaW.x,sumaW.y,sumaW.z);
	float iloczynSkalarny;
	IloczynSkalarnyWektorow(&wektor1,&wektor2,&iloczynSkalarny);
	printf("Iloczyn Skalarny = %f\n",iloczynSkalarny);
	IloczynWektorowy(wektor1,wektor2,&iloczynW);
	printf("Iloczyn Wektorowy = [%.2f, %.2f, %.2f]\n",iloczynW.x,iloczynW.y,iloczynW.z);
	return 0;
}

struct Wektor SumaWektorow(struct Wektor w1, struct Wektor w2){
	
	struct Wektor sumaW;
	sumaW.x = w1.x+w2.x;
	sumaW.y = w1.y+w2.y;
	sumaW.z = w1.z+w2.z;
	
	return sumaW;
}

void IloczynSkalarnyWektorow(struct Wektor *w1, struct Wektor *w2, float *iloczynSkalarny){
	
	*iloczynSkalarny = (*w1).x * (*w2).x + (*w1).y * (*w2).y + (*w1).z * (*w2).z;
}	

void IloczynWektorowy(struct Wektor w1, struct Wektor w2, struct Wektor *iloczynW){

	(*iloczynW).x = w1.x * w2.z - w2.y * w1.z;
	(*iloczynW).y = w2.x * w1.z - w1.x*w1.z;
	(*iloczynW).z = w1.x * w2.y - w2.x * w1.y;

}
