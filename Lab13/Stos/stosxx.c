#include "stos.h"

int main(int argc, char *argv[]){
	node *top=NULL;

	printf("Wstawiam elementy na stos.\n");
	top=PUSH(top, 8);
	top=PUSH(top, 23);
	top=PUSH(top, 123);
	printf("Wypisuje zawartosc stosu.\n");
	print_list(top);
	printf("Usuwam elementy ze stosu.\n");
	printf("Usuwam element ze stosu. %d\n",pop(&top));
	printf("Wypisuje zawartosc stosu.\n");
	print_list(top);
	printf("Usuwam elementy ze stosu.\n");
	printf("Usuwam element ze stosu. %d\n",pop(&top));
	printf("Wypisuje zawartosc stosu.\n");
	print_list(top);
	top=PUSH(top, 1223);
	top=PUSH(top, 12);
	top=PUSH(top, 787);
	printf("Wypisuje zawartosc stosu.\n");
	print_list(top);
	
}
