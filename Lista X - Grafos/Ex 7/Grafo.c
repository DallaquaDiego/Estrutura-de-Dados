#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "Grafo.h" //inclui os Prot�tipos

//Defini��o do tipo Grafo
struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){

    // Aloca memória para a estrutura Grafo
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));

    // Verifica se a alocação foi bem-sucedida
    if(gr != NULL){
        int i;

        // Inicializa os atributos básicos da estrutura Grafo
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;

        // Aloca memória para o vetor de graus (grau)
        gr->grau = (int*) calloc(nro_vertices,sizeof(int));

        // Aloca memória para a matriz de adjacência (arestas)
        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));

        // Se o grafo for ponderado, aloca memória para a matriz de pesos (pesos)
        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
        }

    }

    // Retorna o ponteiro para o grafo devidamente inicializado
    return gr;
}

void libera_Grafo(Grafo* gr) {

    // Verifica se o ponteiro para o grafo é válido
    if (gr != NULL) {
        int i;

        // Libera a memória alocada para a matriz de adjacência (arestas)
        for (i = 0; i < gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        // Se o grafo for ponderado, libera a memória alocada para a matriz de pesos (pesos)
        if (gr->eh_ponderado) {
            for (i = 0; i < gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }

        // Libera a memória alocada para o vetor de graus (grau)
        free(gr->grau);

        // Libera a memória alocada para a estrutura Grafo
        free(gr);

    }
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso) {

    // Verifica se o ponteiro para o grafo é válido
    if (gr == NULL)
        return 0;

    // Verifica se os vértices origem e destino são válidos
    if (orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if (dest < 0 || dest >= gr->nro_vertices)
        return 0;

    // Insere a aresta na matriz de adjacência
    gr->arestas[orig][gr->grau[orig]] = dest;

    // Se o grafo for ponderado, atribui o peso à aresta na matriz de pesos
    if (gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;

    // Incrementa o grau do vértice origem
    gr->grau[orig]++;

    // Se o grafo não for direcionado, chama a função recursivamente para inserir a aresta inversa
    if (eh_digrafo == 0)
        insereAresta(gr, dest, orig, 1, peso);

    return 1;
    
}


int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo) {
    
    // Verifica se o ponteiro para o grafo é válido
    if (gr == NULL)
        return 0;

    // Verifica se os vértices origem e destino são válidos
    if (orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if (dest < 0 || dest >= gr->nro_vertices)
        return 0;

    int i = 0;

    // Procura a aresta na lista de adjacência do vértice origem
    while (i < gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;

    // Se a aresta não for encontrada, retorna 0 indicando falha na remoção
    if (i == gr->grau[orig])
        return 0;

    // Decrementa o grau do vértice origem
    gr->grau[orig]--;

    // Substitui a aresta a ser removida pela última aresta no array de arestas
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];

    // Se o grafo for ponderado, realiza a mesma operação na matriz de pesos
    if (gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];

    // Se o grafo não for direcionado, chama a função recursivamente para remover a aresta inversa
    if (eh_digrafo == 0)
        removeAresta(gr, dest, orig, 1);

    return 1; // Retorna 1 indicando sucesso na remoção
}

void imprime_Grafo(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;
    for(i=0; i < gr->nro_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->eh_ponderado)
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n");
    }
}


int encontraNo ( Grafo *gr, int noDesejado ) {

    // Verifica se o ponteiro para o grafo é válido
    if ( gr == NULL ) {

        return 0;

    }

    // Verifica se o nó desejado está dentro dos limites do grafo
    if ( noDesejado < 0 || noDesejado >= gr -> nro_vertices ) {

        return 0;

    }

    // Percorre a lista de adjacência do nó desejado
    printf ( "Arestas conectadas ao no %d: ", noDesejado );

    for ( int i = 0; i < gr -> grau[noDesejado]; i++ ) {

        printf ( "%d ", gr -> arestas[noDesejado][i] );

    }

    printf("\n");

    return 1;

}


int encontraArestaMenorPeso ( Grafo *gr, int *menorOrigem, int *menorDestino, float *menorPeso ) {

    // Verifica se o ponteiro para o grafo é válido
    if ( gr == NULL ) {

        return 0; 

    }

    *menorPeso = FLT_MAX; // Inicializa com um peso máximo possível
    *menorOrigem = -1;
    *menorDestino = -1;

    // Percorre todas as arestas do grafo
    for ( int i = 0; i < gr -> nro_vertices; i++ ) {

        for ( int j = 0; j < gr -> grau[i]; j++ ) {

            // Se encontrarmos uma aresta com peso menor, atualizamos as variáveis
            if ( gr -> eh_ponderado && gr -> pesos[i][j] < *menorPeso ) {

                *menorOrigem = i;
                *menorDestino = gr -> arestas[i][j];
                *menorPeso = gr -> pesos[i][j];

            }
        }
    }

    // Verifica se foi encontrada uma aresta de menor peso
    if ( *menorOrigem != NULL && *menorDestino != NULL ) {

        printf ( "Aresta de menor peso: %d, %d \n", *menorOrigem, *menorDestino );

    } else {

        printf ( "Nenhuma aresta encontrada.\n" );
    }

    free ( menorPeso );

    return 1; 

}


// Função para obter os nós adjacentes a um nó específico
void obtemVizinhos ( Grafo* gr, int no ) {

    if ( gr == NULL || no < 0 || no >= gr->nro_vertices ) {

        printf ( "No inválido.\n" );
        return;

    }

    printf ( "Nos vizinhos de %d: ", no );

    for ( int i = 0; i < gr -> nro_vertices; i++ ) {

        // Verifica se há uma aresta entre o nó atual e o nó especificado
        if ( gr -> arestas[no][i] == 1 ) {

            printf("%d ", i);

        }
    }

    printf("\n");
    
}


