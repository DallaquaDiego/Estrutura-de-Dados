#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h" //inclui os Prot�tipos

typedef struct {

    Lista** vet;
    int nos; 

} Grafo;

typedef struct elemento {

    int dest;
    float peso;
    struct elemento* prox;

} Lista;



Grafo* cria_Grafo ( int nos ) {

    // Aloca memória para a estrutura do grafo
    Grafo *gr = ( Grafo* ) malloc ( sizeof ( Grafo ) );

    // Verifica se a alocação foi bem-sucedida
    if (gr != NULL) {

        // Define o número de nós no grafo
        gr -> nos = nos;

        // Aloca memória para o vetor de listas de adjacência
        gr -> vet = ( Lista** ) malloc ( nos * sizeof ( Lista* ) );

        // Inicializa cada lista como vazia
        for ( int i = 0; i < nos; i++ ) {

            gr -> vet[i] = NULL;

        }
    }

    // Retorna o ponteiro para o grafo criado
    return gr;

}

void libera_Grafo ( Grafo* gr ) {

    // Verifica se o ponteiro para o grafo é válido
    if ( gr != NULL ) {

        // Libera a memória de cada lista de adjacência
        for ( int i = 0; i < gr -> nos; i++ ) {

            Lista* atual = gr -> vet[i];

            while ( atual != NULL ) {

                Lista *prox = atual -> prox;
                free ( atual );
                atual = prox;

            }
        }

        // Libera o vetor de listas de adjacência
        free ( gr -> vet );

        // Libera a estrutura do grafo
        free ( gr  );
    }
}


int insereAresta ( Grafo* gr, int orig, int dest, float peso ) {

    // Verifica se o grafo e os nós são válidos
    if ( gr == NULL || orig < 0 || orig >= gr->nos || dest < 0 || dest >= gr -> nos ) {

        return 0;

    }

    // Aloca memória para o novo nó na lista de adjacência de orig
    Lista* novo = ( Lista* ) malloc ( sizeof ( Lista ) );

    // Verifica se a alocação foi bem-sucedida
    if ( novo == NULL ) {

        return 0; 

    }

    // Preenche os dados do novo nó
    novo -> dest = dest;
    novo -> peso = peso;

    // Insere o novo nó no início da lista de adjacência de orig
    novo -> prox = gr -> vet[orig];
    gr -> vet[orig] = novo;

    // Retorna 1 indicando sucesso na inserção
    return 1;

}


int removeAresta ( Grafo* gr, int orig, int dest ) {

    // Verifica se o grafo e os nós são válidos
    if ( gr == NULL || orig < 0 || orig >= gr->nos || dest < 0 || dest >= gr->nos ) {

        return 0;

    }

    // Inicializa ponteiros para percorrer a lista de adjacência
    Lista *atual = gr -> vet[orig];
    Lista *anterior = NULL;

    // Procura o nó de destino na lista de adjacência de orig
    while ( atual != NULL && atual->dest != dest ) {

        anterior = atual;
        atual = atual -> prox;

    }

    // Se o nó não foi encontrado, retorna 0
    if ( atual == NULL ) {

        return 0;

    }

    // Remove o nó da lista de adjacência
    if ( anterior == NULL ) {   

        // Remove do início
        gr -> vet[orig] = atual -> prox;

    } else {

        // Remove do meio ou final
        anterior -> prox = atual -> prox; 

    }

    // Libera a memória do nó removido
    free ( atual );

    // Retorna 1 indicando sucesso na remoção
    return 1;
    
}