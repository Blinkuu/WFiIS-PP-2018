#include <stdlib.h>
#include <stdio.h>
#include <string.h>



struct Student{
	char imie[256];
	char nazwisko[256];
	int wiek;
	char nr_indeksu[256];
}student;

void WriteToFile(struct Student s);

int main (void){
	
	char *haslo = "1234";
	char haslo_uzytkownik[256];
	int proby = 0;
	int walidacja = 0;
	
	do{
		printf("Podaj haslo (haslo = 1234):");
		scanf("%s",haslo_uzytkownik);
		if(!strcmp(haslo_uzytkownik,haslo)){
			walidacja = 1;
			break;
		}
		printf("Podales zle haslo. Zostaly ci %d proby!\n",2-proby);
		proby++;
	}while(proby < 3);

	if(walidacja){
		char c;
		int licznik = 0;
		printf("Dostep uzyskany! Podaj swoje dane!\n");
		while(1){
			printf("Podaj dane %d studenta:\n",++licznik);

			printf("Imie: ");
			scanf("%s",student.imie);
			printf("Nazwisko: ");
			scanf("%s",student.nazwisko);
			printf("Wiek: ");
			scanf("%d",&student.wiek);
			printf("Nr indeksu: ");
			scanf("%s",student.nr_indeksu);
			WriteToFile(student);

			printf("Czy chcesz zakonczyc program? (T/N):\n");
			scanf("%s",&c);
			if(c == 'T'){
				printf("Zakanczam program!\n");
				exit(0);
			}
		}

	} else{
		printf("Podales 3-krotnie zle haslo. Zakanczam program!\n");
		exit(0);
	}
	return 0;
}

void WriteToFile(struct Student s){
	FILE *fptr;
	fptr = fopen("Baza_Studentow.txt","a");
	if(fptr == NULL){
		printf("Error!");
		return;
	}
	
	fprintf(fptr,"Imie: %s\n",s.imie);
	fprintf(fptr,"Nazwisko: %s\n",s.nazwisko);
	fprintf(fptr,"Wiek: %d\n",s.wiek);
	fprintf(fptr,"Nr indeksu: %s\n",s.nr_indeksu);

	fclose(fptr);
}
