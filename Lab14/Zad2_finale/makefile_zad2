drzewo.exe: drzewo.o drzewo.o
	gcc -o drzewo.exe drzewo.o drzewo.o -L. -libdrzewo -Wall
libdrzewo.a: drzewo.o
		ar rcsv libdrzewo.a drzewo.o
drzewo.o: drzewo.c drzewo.h
	gcc -c drzewo.c -Wall
main.o: drzewo.c drzewo.h
	gcc -c drzewo.c -Wall
