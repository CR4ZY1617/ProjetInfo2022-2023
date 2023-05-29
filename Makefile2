all:exec

main.o: main.c
	gcc -c main.c -o main.o

fonction.o: fonction.c header.h
	gcc -c fonction.c -o fonction.o
  
exec: main.o fonction.o
	gcc fonction.o main.o -o exec
