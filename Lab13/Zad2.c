#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Osoba{
	char *imie;
	char *nazwisko;
}Osoba;

typedef struct Student{
	Osoba dane;
	struct Student *next;
	struct Student *prev;
}Student;

Student *utworz_element();
void dodaj_na_poczatek(Student **head);
void print_list(Student *node);

int main(void){

	Student *head = utworz_element();
	dodaj_na_poczatek(&head);
	print_list(head);
	
	return 0;
}

Student *utworz_element(){
	Student *element;
	char bufor[30+1];
	char *imie, *nazwisko;

	printf("Podaj imie: ");
	gets(bufor);
	imie = malloc(strlen(bufor));
	strcpy(imie,bufor);

	printf("Podaj nazwisko: ");
	gets(bufor);
	nazwisko = malloc(strlen(bufor));
	strcpy(nazwisko,bufor);

	element = malloc(sizeof(Student));
	element->next = NULL;
	element->prev = NULL;
	element->dane.imie = imie;
	element->dane.nazwisko = nazwisko;

	return element;
}

void dodaj_na_poczatek(Student **head){
	if(!head){
		(*head)->next = utworz_element();
	} else {
		Student *temp = utworz_element();
		temp->next = *head;
		(*head)->prev = temp;
		*head = temp;
	}
}

void print_list(Student *node)
{
	Student *last;
	printf("Od przodu\n");
    while (node != NULL)
    {
        printf("%s %s\n", node->dane.imie, node->dane.nazwisko);
		last = node;
        node = node->next;
    }
	printf("Od tylu\n");
	while(last!=NULL){
		printf("%s %s\n", last->dane.imie, last->dane.nazwisko);
		last = last->prev;
	}
}
