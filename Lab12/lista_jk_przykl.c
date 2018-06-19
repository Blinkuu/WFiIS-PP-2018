#include <stdio.h>
#include <stdlib.h>
#define N 3

/* lista jednokierunkowa - przyklad  */

typedef struct pt number;

struct pt {
   int x;
   number *next; /* wskaznik do nastepnej struktury */
};

number* smem() {
   number *pt;
   if((pt=(number *)malloc(sizeof(number)))==NULL){
      fprintf(stderr,"can not allocate memory\n");
      exit(1);
   }
   return pt;
}

int main() {
  number *p,*root;
  int i,n=5;
 
  /*  przydzielamy pamiec, dla trzech kolejnych struktur, jednoczesnie tworzac
   *  N-elementowa liste jednokierunkowa, oraz inicjujac warosci kolejnych
   *  elementow: */
  p=root=smem(); /* poczatek listy */
  p->x=n++;  /* inicjujemy pierwszy element */
  for(i=1;i<N;i++){
     p->next=smem();
     p=p->next;
     p->x=n++;
  }
  p->next=NULL; /* koniec listy */
  

  /* przegladamy liste: */
  p=root;
  while(p!=NULL){
     printf("%d\n",p->x);
     p=p->next;
  }
   
   return 0;
}
