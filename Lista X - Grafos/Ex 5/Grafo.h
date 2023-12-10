//Arquivo Grafo.h

Grafo* cria_Grafo(int nos);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, float peso);
int removeAresta(Grafo* gr, int orig, int dest);

