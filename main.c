#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){

	GRAFO *gr;
	gr = criar_Grafo(10,7,0);

	insereAresta(gr, 0,1,0,0);
	insereAresta(gr, 1,3,0,0);

	removeAresta(gr, 0,1,0);

	libera_Grafo(gr);
	
	return 0;
}