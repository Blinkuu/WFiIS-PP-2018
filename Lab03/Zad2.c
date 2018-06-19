#include <stdio.h>
#include <stdlib.h>

void Sort(int a, int b, int c);

int main()
{

    int a,b,c;

    a = 1;
    b = 2;
    c = 3;
    Sort(a,b,c);

    printf("\n\n");

    a = 3;
    b = 2;
    c = 1;
    Sort(a,b,c);

    printf("\n\n");

    a = 2;
    b = 1;
    c = 3;
    Sort(a,b,c);

    printf("\n\n");

    a = 1;
    b = 3;
    c = 2;
    Sort(a,b,c);

    printf("\n\n");

    a = 3;
    b = 1;
    c = 2;
    Sort(a,b,c);

    printf("\n\n");

    a = 2;
    b = 3;
    c = 1;
    Sort(a,b,c);

    return 0;
}

void Sort(int a, int b, int c){
    printf("1. a = %d, b = %d, c = %d\n",a,b,c);
    if(b < a){
        int temp = a;
        a = b;
        b = temp;
        printf("2. a = %d, b = %d, c = %d\n",a,b,c);
    }
    if(c < b){
        int temp = b;
        b = c;
        c = temp;
        if(b < a){
            int temp = a;
            a = b;
            b = temp;
        }
    printf("3. a = %d, b = %d, c = %d\n",a,b,c);
    }else{
        printf("4. a = %d, b = %d, c = %d\n",a,b,c);
    }
}
