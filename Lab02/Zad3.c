#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int guess(int los, int max, int min);

int main()
{
    srand(time(NULL));
    int max = 100;
    int min = 0;
    float suma = 0;
    for(int i = 0; i < 1000; i++){
        int los = rand()%(max-min+1) + min;
        printf("Los = %d\n", los);
        suma+=guess(los, max, min);
    }

    float average = suma/1000.0;
    printf("\n\nSrednia = %f",average);
    return 0;
}

int guess(int los, int max, int min){
    int licznik = 0;
    while(1){
        int tryout = rand()%(max-min+1) + min;
        if(tryout == los){
            printf("Znalezione za %d razem!\n",licznik);
            return licznik;
        }
        else if (tryout < los) {
            min = tryout;
            licznik++;
        }
        else {
            max = tryout;
            licznik++;
        }

    }
}
