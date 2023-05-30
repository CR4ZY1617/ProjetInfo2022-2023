all:exec

main.o: main.c main.h
	gcc -c main.c -o main.o

allfonction.o: allfonction.c allfonction.h
	gcc -c allfonction.c -o allfonction.o
  
exec: main.o allfonction.o
	gcc allfonction.o main.o -o exec
