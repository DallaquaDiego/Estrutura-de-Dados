#include <stdio.h>
#include <stdlib.h>
#include "Grafo.c"

int main(){

    int eh_digrafo = 1, menorOrigem, menorDestino;
    float menorPeso;

    Grafo* gr = cria_Grafo(5, 5, 0);

    insereAresta(gr, 0, 1, eh_digrafo, 0);
    insereAresta(gr, 1, 3, eh_digrafo, 0);
    insereAresta(gr, 1, 2, eh_digrafo, 0);
    insereAresta(gr, 2, 4, eh_digrafo, 0);
    insereAresta(gr, 3, 0, eh_digrafo, 0);
    insereAresta(gr, 3, 4, eh_digrafo, 0);
    insereAresta(gr, 4, 1, eh_digrafo, 0);

    imprime_Grafo(gr);
    printf("\nBusca \n");

    encontraNo ( gr, 2 );

    obtemVizinhos( gr, 4 );

    encontraArestaMenorPeso( gr, &menorOrigem, &menorDestino, &menorPeso );

    libera_Grafo ( gr );

    

    return 0;
}
