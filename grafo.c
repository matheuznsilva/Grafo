#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct grafo{
	int eh_ponderado;
	int nro_vert;
	int Gmax;
	int** arestas;
	float** pesos;
	int* grau;
};

GRAFO* criar_Grafo(int nro_vert, int Gmax, int eh_ponderado){
	GRAFO* gr = (GRAFO*) malloc(sizeof(struct grafo));
	if(gr != NULL){
		int i;
		gr->nro_vert = nro_vert;
		gr->Gmax = Gmax;
		gr->eh_ponderado = (eh_ponderado != 0)?1:0;
		gr->grau = (int*)calloc(nro_vert,sizeof(int));

		gr->arestas = (int**)malloc(nro_vert*sizeof(int*));
		for (i = 0; i < nro_vert; ++i){
			gr->arestas[i] = (int*)malloc(Gmax * sizeof(int));
		}

		if(gr->eh_ponderado){
			gr->pesos = (float**)malloc(nro_vert*sizeof(float*));
			for (i = 0; i < nro_vert; ++i){
				gr->pesos[i] = (float*)malloc(Gmax*sizeof(float)); 
			}
		}
	}
	return gr;
}

void libera_Grafo(GRAFO* gr){
	if(gr != NULL){
		int i;
		for (i = 0; i < gr->nro_vert; ++i){
			free(gr->arestas[i]);
		}
		free(gr->arestas);
		
		if(gr->eh_ponderado){
			for (i = 0; i < gr->nro_vert; ++i){
				free(gr->pesos[i]);	
			}
			free(gr->pesos);
		}
		free(gr->grau);
		free(gr);		
	}
}

int insereAresta(GRAFO* gr, int orig, int dest, int digrafo, float peso){
	if(gr == NULL){
		return 0;
	}
	if(orig < 0 || orig >= gr->nro_vert){
		return 0;
	}
	if(dest < 0 || dest >= gr->nro_vert){
		return 0;
	}

	gr->arestas[orig][gr->grau[orig]] = dest;
	if(gr->eh_ponderado){
		gr->pesos[orig][gr->grau[orig]] = peso;
	}
	gr->grau[orig]++;

	if(digrafo == 0){
		insereAresta(gr, dest, orig, 1, peso);
	}
	return 1;
}

int removeAresta(GRAFO* gr, int orig, int dest, int eh_digrafo){
	if(gr == NULL){
		return 0;
	}
	if(orig < 0 || orig >= gr->nro_vert){
		return 0;
	}
	if(dest < 0 || dest >= gr->nro_vert){
		return 0;
	}

	int i = 0;	
	while(i < gr->grau[orig] && gr->arestas[orig][i] != dest){
		i++;
	}
	if(i == gr->grau[orig]){
		return 0;
	}
	gr->grau[orig]--;
	gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
	if(gr->eh_ponderado){
		gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
	}
	if(eh_digrafo == 0){
		removeAresta(gr, dest, orig, 1);
	}
	return 1;
}
