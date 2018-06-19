#include <stdlib.h>
#include <stdio.h>
#include <string.h>



struct Student{
	char imie[256];
	char nazwisko[256];
	int wiek;
	char nr_indeksu[256];
};

void WriteToFile(struct Student s);
void ReadFile();
void ReadFileDeleted();
void SearchStudent(char *imie, char *nr_indeksu);
void Delete(int which_to_delete);
void FileLength();

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

	struct Student *student = malloc(sizeof(struct Student));

	if(walidacja){
		char c;
		int licznik = 0;
		printf("Dostep uzyskany! Podaj swoje dane!\n");
		while(1){
			
			
			printf("Podaj dane %d studenta:\n",++licznik);
			
			printf("Imie: ");
			scanf("%s",student[licznik-1].imie);
			printf("Nazwisko: ");
			scanf("%s",student[licznik-1].nazwisko);
			printf("Wiek: ");
			scanf("%d",&student[licznik-1].wiek);
			printf("Nr indeksu: ");
			scanf("%s",student[licznik-1].nr_indeksu);

			printf("Czy chcesz dodac kolejnego studenta? (T/N):\n");
			scanf("%s",&c);
			if(c == 'T'){
				student = realloc(student,(licznik+1)*sizeof(struct Student));
				
			} else {
				for(int i = 0; i < licznik; i++){
					WriteToFile(student[i]);
				}
				printf("Cala baza danych:\n");
				ReadFile();
				printf("Szukanie studenta:\n");
				SearchStudent("Gut","299852");
				printf("Rozmiar pliku:\n");
				FileLength();

				printf("\nUsuwanie rekordu:\n");
				Delete(1);
				
				ReadFileDeleted();
				printf("\nZakanczam program!\n");
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
	fptr = fopen("Baza_Studentow.bin","ab");
	if(fptr == NULL){
		printf("Error!");
		return;
	}

	fwrite(&s,sizeof(struct Student),1,fptr);

	fclose(fptr);
}

void ReadFile(){
	FILE *fptr;
	fptr = fopen("Baza_Studentow.bin","rb");
	if(fptr == NULL){
		printf("Error!");
		return;
	}
	
	
	fseek(fptr, 0, SEEK_END);
	int sz=ftell(fptr);
	int n = sz/sizeof(struct Student);
		
	struct Student s;
	fseek(fptr, 0, SEEK_SET);
	for(int i = 0; i < n; i++){
		fread(&s, sizeof(struct Student), 1, fptr);
		printf("%s %s %d %s\n",s.imie,s.nazwisko,s.wiek,s.nr_indeksu);
	}
	fclose(fptr);
}

void ReadFileDeleted(){
	FILE *fptr;
	fptr = fopen("Baza_Studentow_Usuniete.bin","rb");
	if(fptr == NULL){
		printf("Error!");
		return;
	}
	
	
	fseek(fptr, 0, SEEK_END);
	int sz=ftell(fptr);
	int n = sz/sizeof(struct Student);
		
	struct Student s;
	fseek(fptr, 0, SEEK_SET);
	for(int i = 0; i < n; i++){
		fread(&s, sizeof(struct Student), 1, fptr);
		printf("%s %s %d %s\n",s.imie,s.nazwisko,s.wiek,s.nr_indeksu);
	}
	fclose(fptr);
}

void SearchStudent(char *nazwisko, char *nr_indeksu){
	FILE *fptr;
	fptr = fopen("Baza_Studentow.bin","rb");
	if(fptr == NULL){
		printf("Error!");
		return;
	}
	
	
	fseek(fptr, 0, SEEK_END);
	int sz=ftell(fptr);
	int n = sz/sizeof(struct Student);
		
	struct Student s;
	fseek(fptr, 0, SEEK_SET);
	for(int i = 0; i < n; i++){
		fread(&s, sizeof(struct Student), 1, fptr);
		if(!strcmp(nazwisko,s.nazwisko) && !strcmp(nr_indeksu,s.nr_indeksu)){
			printf("%s %s %d %s\n",s.imie,s.nazwisko,s.wiek,s.nr_indeksu);
		}
		
	}
	fclose(fptr);
}

void Delete(int which_to_delete){
	FILE *fptr;
	fptr = fopen("Baza_Studentow.bin","rb");
	if(fptr == NULL){
		printf("Error!");
		return;
	}

	fseek(fptr, 0, SEEK_END);
	int sz=ftell(fptr);
	int n = sz/sizeof(struct Student);

	struct Student k[n];
	fseek(fptr, 0, SEEK_SET);
	for(int i = 0; i < n; i++){
		fread(&k, sizeof(struct Student), 1, fptr);
		//printf("%s %s %d %s\n",k[i].imie,k[i].nazwisko,k[i].wiek,k[i].nr_indeksu);
	}
	fclose(fptr);

	fptr = fopen("Baza_Studentow_Usuniete.bin","wb");
	for(int i = 0; i < n; i++){
		if(i!=which_to_delete){
			fwrite(&k[i],sizeof(struct Student),1,fptr);
		}
	}
	fclose(fptr);
}


void FileLength(){
	FILE *fptr;
	fptr = fopen("Baza_Studentow.bin","rb");
	if(fptr == NULL){
		printf("Error!");
		return;
	}
	fseek(fptr, 0, SEEK_END);
	int sz=ftell(fptr);
	printf("%d",sz);
	fclose(fptr);
}





