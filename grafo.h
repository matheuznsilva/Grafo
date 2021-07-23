typedef struct grafo GRAFO;

GRAFO* criar_Grafo(int nro_vert, int Gmax, int eh_ponderado);

void libera_Grafo(GRAFO* gr);

int insereAresta(GRAFO* gr, int orig, int dest, int digrafo, float peso);

int removeAresta(GRAFO* gr, int orig, int dest, int digrafo);

void buscaProfundidade(GRAFO* gr, int ini, int *visitado, int cont);

void buscaProfundidade_Grafo(GRAFO* gr, int ini, int *visitado);

void buscaLargura_Grafo(GRAFO *gr, int ini, int *visitado);

