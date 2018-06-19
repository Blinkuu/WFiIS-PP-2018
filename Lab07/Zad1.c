#include <stdio.h>
#include <string.h>

int compare (const void *a, const void *b);

struct Klient{
  char imie[20];
  char nazwisko[32];
  char kod_pocztowy[7];
  int wiek;
}klient[5];


int main (void){

  for(int i = 0; i < 5; i++){
    scanf("%s %s %s %d",klient[i].imie, klient[i].nazwisko, klient[i].kod_pocztowy, &klient[i].wiek);
  }

  qsort(klient,5,sizeof(klient[0]),compare);

  for(int i = 0; i < 5; i++){
    printf("%s %s %s %d\n",klient[i].imie, klient[i].nazwisko, klient[i].kod_pocztowy, klient[i].wiek);
  }

  return 0;
}

int compare(const void *a, const void *b){
  struct Klient clientA = *(struct Klient*)a;
  struct Klient clientB = *(struct Klient*)b;

  int cmp = strcmp(clientA.imie, clientB.imie);
  if(cmp == 0){
    return strcmp(clientA.nazwisko, clientB.nazwisko);
  }
  return cmp;
}
