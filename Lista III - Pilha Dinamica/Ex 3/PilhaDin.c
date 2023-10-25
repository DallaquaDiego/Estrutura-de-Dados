#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h" //inclui os Protótipos

//Definição do tipo Pilha
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;


Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}


void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}


int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}


int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}


int remove_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}


int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}


int Pilha_cheia(Pilha* pi){
    return 0;
}


int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}


void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}


// Criação da função PilhaPopN
struct aluno *PilhaPopN ( Pilha *pi, int tam ) {

    /* Caso o endereço para onde pi aponta for nulo ou estiver vazio, retorna 0.
       Se a função tamanho_Pilha retornar um valor menor do que n também retorna 0. */
    if ( pi == NULL || *pi == NULL || tamanho_Pilha (pi) < tam ) {

        return 0;

    }

    struct aluno *al = malloc ( tam * sizeof ( struct aluno ) );
    
    // Criação do ponteiro auxiliar,
    Elem *aux;

    // Loop para desempilhar N vezes
    for ( int i = 0; i < tam; i++ ) {

        // O ponteiro auxiliar possui o mesmo valor apontado por pi
        aux = *pi;

        // Armazena os dados no vetor antes de dar o free
        al[i] = (*pi) -> dados;

        // O ponteiro pi aponta para o próximo nó
        *pi = (*pi) -> prox;

        // Libera a memória do  ponteiro auxiliar
        free (aux);

    }  

    return al;

}


// Criação da função PilhaCopia
Pilha *PilhaCopia (Pilha *pi) {

    // Caso o endereço para onde pi aponta for nulo ou estiver vazio, retorna 0.
    if ( pi == NULL || *pi == NULL ) {

        return 0;

    }

    // Obtém o tamanho da pilha
    int tam = tamanho_Pilha (pi);

    // Pega o vetor de alunos da PilhaPopN
    struct aluno *a1 = PilhaPopN( pi, tam );

    // Cria outra cabeça
    Pilha *pi2 = cria_Pilha();

    for ( int i = 0; i < tam; i++ ) { 

        // Reconstrói as pilhas
        insere_Pilha( pi, a1[ tam - i - 1 ] );

        insere_Pilha( pi2, a1[ tam - i - 1 ] );

    }

    free ( a1 );

    return pi2;

}