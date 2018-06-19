#include <stdio.h>
#include <stdlib.h>

void sumy(int **arr, int n1, int n2);

int main()
{

    int n = 5;
    int **arr = malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++)
        *(arr+i) = malloc(n*sizeof(int));

	int mnoznik = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			arr[i][j] = 2*mnoznik;
			mnoznik++;
		}
	}

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    sumy(arr,n,n);

    return 0;
}

void sumy(int **arr, int n1, int n2){
    //a
    int suma = 0;
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            suma+=arr[i][j];
        }
    }
    printf("Suma = %d\n",suma);

    //b
    int suma_p_p = 0;
    for(int i = 0; i < n1; i++){
        for(int j = i+1; j < n2; j++){
            suma_p_p+=arr[j][i];
        }
    }
    printf("Suma pod przekatna = %d\n",suma_p_p);

    //c
    int suma_n_p = 0;
    for(int i = n1-1; i >= 0; i--){
        for(int j = i-1; j >= 0; j--){
            suma_n_p+=arr[j][i];
        }
    }
    printf("Suma nad przekatna = %d\n",suma_n_p);

    //d
    int suma_p = 0;
    for(int i = 0; i < n1; i++){
        for(int j = i; j < n2; j+=n1){
            suma_p+=arr[i][j];
        }
    }
    printf("Suma na przekatnej = %d\n",suma_p);
}
