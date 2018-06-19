#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int losuj (int a, int b);
float fun(float *t, int n, float *sum, float *min, float *max, float *average);
float fun_ptr(float *t, int n, float *sum, float *min, float *max, float *average);
void sort(int *tab, int n);
void sort_ptr(int *tab, int n);

int main(void){
  srand(time(NULL));

  int tab[10];
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);

  printf("\n");
  printf("A:\n");
  printf("------------\n");
  for(int i = 0; i < 10; i++){
    tab[i] = losuj(a,b);
    printf("%d\n",tab[i]);
  }

  printf("\n");
  printf("B:\n");
  printf("------------\n\n");

  float t[5] = {1.1,2.2,3.3,4.4,5.5};
  float sum;
  float min;
  float max;
  float average;
  fun(t,5,&sum,&min,&max,&average);
  //fun_ptr(t,5,sum,min,max,average);

  printf("\n");
  printf("C:\n");
  printf("------------\n\n");
  printf("\n");
  sort(tab,10);
  //sort_ptr(tab,10);
  for(int i = 0; i < 10; i++){
    printf("%d\n",tab[i]);
  }
  printf("\n");

  return 0;
}

int losuj (int a, int b){
  return rand()%(b-a+1) + a;
}

float fun(float *t, int n, float *sum, float *min, float *max, float *average){
  *sum = 0;
  min = t;
  max = t;

  for(int i = 0; i < n; i++){
    *sum+=t[i];
    if(t[i] < *min)
      min = &t[i];
    if(t[i] > *max)
      max = &t[i];
  }

  *average = *sum/n;
  float wariacja = 0;

  for(int i = 0; i < n; i++){
    wariacja += pow(t[i]-(*average),2)/(*average);
  }
  float odchylenieStandardowe = sqrt(wariacja);

  printf("Suma = %f\n",*sum);
  printf("Min = %f\n",*min);
  printf("Max = %f\n",*max);
  printf("Average = %f\n",*average);
  printf("Odchylenie Standardowe = %f\n",odchylenieStandardowe);
  return *sum;
}

float fun_ptr(float *t, int n, float *sum, float *min, float *max, float *average){
  float *start = t;
  float *end = t+n;
  float *start_1 = t;
  float *end_1 = t+n;

  *sum = 0;
  min = start;
  max = start;

  while(start < end){
    *sum += *start;
    if(*start < *min)
      min = start;
    if(*start > *max)
      max = start;
    start++;
  }

  *average = *sum/n;
  float wariacja = 0;

  while(start_1 < end_1){
    wariacja += pow(((*start_1) - (*average)),2)/(*average);
    start_1++;
  }
  float odchylenieStandardowe = sqrt(wariacja);

  printf("Suma = %f\n",*sum);
  printf("Min = %f\n",*min);
  printf("Max = %f\n",*max);
  printf("Average = %f\n",*average);
  printf("Odchylenie Standardowe = %f\n",odchylenieStandardowe);
  return *sum;
}

void sort(int *tab, int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n-1; j++){
      if(tab[j+1] < tab[j]){
        int temp = tab[j];
        tab[j] = tab[j+1];
        tab[j+1] = temp;
      }
    }
  }
}

void sort_ptr(int *tab, int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n-1; j++){
      if(*(tab+j+1)<*(tab+j)){
        int temp = *(tab+j);
        tab[j] = *(tab+j+1);
        *(tab+j+1) = temp;
      }
    }
  }
}
