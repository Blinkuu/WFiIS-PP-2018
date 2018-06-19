#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N1 10
#define N2 5

void BubbleSort(float *tab, int n);
void swap(float  *tab, int a, int b);
void swap_two(float *tab1, float  *tab2, int a);
void exchange(float  *tab, int n);
void exchange_ptr(float  *tab, int n);
void exchange_array(float  *tab1, float  *tab2, int n);
void exchange_array_ptr(float  *tab1, float  *tab2, int n);
void merge(float *tab1, float *tab2, float *sortedTab, int a, int b);

int main()
{
    srand(time(NULL));

    float tab1[N1];
    float tab2[N2];

    float tab3[N1];

    float sortedTab[N1+N2];

    for(int i = 0; i < N1; i++){
        if(i < N2){
            tab2[i] = (rand()%100)/100.0;
        }
        tab1[i] = (rand()%100)/100.0;
        tab3[i] = (rand()%100)/100.0;
    }

    for(int i = 0; i < N1; i++)
        printf("%.2f\n",tab1[i]);

    printf("Posortowana tab1: \n");
    BubbleSort(tab1,N1);
    for(int i = 0; i < N1; i++)
        printf("%.2f\n",tab1[i]);
    printf("Posortowana tab2: \n");
    BubbleSort(tab2,N2);
    for(int i = 0; i < N2; i++)
        printf("%.2f\n",tab2[i]);

    printf("Zamiana elementow tablicy:\n");
    exchange_ptr(tab1,N1);
    for(int i = 0; i < N1; i++)
        printf("%.2f\n",tab1[i]);

    printf("\n\nTab1 przed zamiana z Tab3\n");
    for(int i = 0; i < N1; i++){
        printf("tab1 = %.2f\n",tab1[i]);
    }
    printf("Tab3 przed zamiana z Tab1\n");
    for(int i = 0; i < N1; i++){
        printf("tab3 = %.2f\n",tab3[i]);
    }
    exchange_array_ptr(tab1,tab3,N1);
    printf("Tab1 po zamianie z Tab3\n");
    for(int i = 0; i < N1; i++){
        printf("tab1 = %.2f\n",tab1[i]);
    }
    printf("Tab3 po zamianie z Tab1\n");
    for(int i = 0; i < N1; i++){
        printf("tab3 = %.2f\n",tab3[i]);
    }

    printf("Scalanie: \n");
    merge(tab1,tab2,sortedTab,N1,N2);
    for(int i = 0; i < N1+N2; i++){
        printf("sortedTab = %.2f\n",sortedTab[i]);
    }

    return 0;
}

void BubbleSort(float *tab, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(tab[j+1] < tab[j]){
                swap(tab,j+1,j);
            }
        }
    }
}

void swap(float *tab, int a, int b){
    float temp = *(tab+a);
    *(tab+a) = *(tab+b);
    *(tab+b) = temp;
}

void swap_two(float *tab1, float *tab2, int a){
    float temp = *(tab1+a);
    *(tab1+a) = *(tab2+a);
    *(tab2+a) = temp;
}

void exchange(float *tab, int n){
    for(int i = 0; i < n/2; i++){
        swap(tab,i,n-i-1);
    }
}

void exchange_ptr(float *tab, int n){
	float *i = NULL;
	for(i = tab; i < tab+(n/2); i++){
		swap(tab,i-tab,tab-i+n-1);
	}
}

void exchange_array(float *tab1, float *tab2, int n){
    for(int i = 0; i < n; i++){
        swap_two(tab1,tab2,i);
    }
}

void exchange_array_ptr(float *tab1, float *tab2, int n){
	float *i = NULL;
    for(i = tab1; i < tab1 + n; i++){
        swap_two(tab1,tab2,i-tab1);
    }
}

void merge_janusz(float *tab1, float *tab2, float *sortedTab, int a, int b){
    for(int i = 0; i < a; i++){
        sortedTab[i] = tab1[i];
    }
    for(int j = 0; j+a < a+b; j++){
        sortedTab[j+a] = tab2[j];
    }
    BubbleSort(sortedTab,a+b);
}

void merge_ptr_janusz(float *tab1, float *tab2, float *sortedTab, int a, int b){
	float *i = NULL;
    for(i = tab1; i < tab1+a; i++){
        *(sortedTab+(i-tab1)) = *(tab1+(i-tab1));
    }
	float *j = NULL;
    for(j = tab2; j+a < tab2+a+b; j++){
        *(sortedTab+(j-tab2+a)) = *(tab2+(j-tab2));
    }
    BubbleSort(sortedTab,a+b);
}

void merge(float *tab1, float *tab2, float *sortedTab, int a, int b){
	int k = 0;
	int i = 0;
	int j = 0;
	BubbleSort(tab1,a);
	BubbleSort(tab2,b);
	while(i < a && j < b){
		if(tab1[i] < tab2[j]){
			sortedTab[k] = tab1[i];
			i++;
		} else {
			sortedTab[k] = tab2[j];
			j++;
		}
	k++;
	}
	printf("\ni = %d\n",i);
	printf("j = %d\n",j);
	
	if(tab1[i] > tab2[j]) {
		for(k; k<a+b;k++){
			sortedTab[k] = tab1[i];
			i++;
		}
	} else {
		for(k; k<a+b;k++){
			sortedTab[k] = tab2[j];
			j++;
		}
	}
}
