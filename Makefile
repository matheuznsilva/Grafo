main:	main.o	grafo.o
	gcc main.o grafo.o -o main

main.o:	main.c
	gcc -c main.c

grafo.o:	grafo.c	grafo.h
	gcc -c grafo.c

clean:
	rm *.o
