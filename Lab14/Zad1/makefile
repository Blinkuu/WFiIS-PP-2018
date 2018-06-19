tree.exe: main.o drzewo.o
	gcc -o tree.exe  drzewo.o main.o -Wall
drzewo.o: drzewo.c drzewo.h
	gcc -c drzewo.c -Wall
main.o: main.c drzewo.h
	gcc -c main.c -Wall
