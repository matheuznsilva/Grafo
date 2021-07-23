typedef struct grafo GRAFO;

GRAFO* criar_Grafo(int nro_vert, int Gmax, int eh_ponderado);

void libera_Grafo(GRAFO* gr);

int insereAresta(GRAFO* gr, int orig, int dest, int digrafo, float peso);

int removeAresta(GRAFO* gr, int orig, int dest, int digrafo);
