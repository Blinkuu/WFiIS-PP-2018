#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int suma(int *tab, int a, int b);

int main()
{
    srand(time(NULL));
    int tab[N];
    int *p = NULL;
    for(p=tab;p<tab+N;p++){
        *p=rand()%(35-7+1)+7;
        printf("p[%d]=%d\n",p-tab,*p);
    }
    printf("\n");

    int sum = suma(tab,1,5);
    printf("su = %d",sum);
    return 0;
}

int suma(int *tab, int a, int b){
    int x = 0;
    for(int *i = tab+a; i <= tab+b; i++){
        x+=*(i);
    }
    return x;
}
