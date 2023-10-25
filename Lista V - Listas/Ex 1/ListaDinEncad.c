#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os Prot�tipos

//Defini��o do tipo lista
struct elemento {

    struct aluno dados;
    struct elemento *prox;

}; typedef struct elemento Elemento;


Lista* cria_lista() {

    Lista* li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL) {

        *li = NULL;

    }

    return li;

}


void libera_lista(Lista* li) {

    if(li != NULL) {

        Elemento* no;

        while((*li) != NULL) {

            no = *li;
            *li = (*li)->prox;

            free(no);

        }

        free(li);

    }

}


int insere_lista_final(Lista* li, struct aluno al) {

    if(li == NULL) {

        return 0;

    }

    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL) {

        return 0;

    }

    no->dados = al;
    no->prox = NULL;

    if((*li) == NULL) {//lista vazia: insere in�cio

        *li = no;

    } else {

        Elemento *aux;
        aux = *li;

        while(aux->prox != NULL) {

            aux = aux->prox;

        }

        aux->prox = no;

    }

    return 1;

}


int insere_lista_inicio(Lista* li, struct aluno al) {

    if(li == NULL) {

        return 0;

    }

    Elemento* no;
    no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL) {

        return 0;

    }

    no->dados = al;
    no->prox = (*li);
    *li = no;

    return 1;

}

int insere_lista_ordenada(Lista* li, struct aluno al) {

    if(li == NULL) {

        return 0;

    }

    Elemento *no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL) {

        return 0;
    
    }

    no->dados = al;

    if((*li) == NULL) {//lista vazia: insere in�cio

        no->prox = NULL;
        *li = no;

        return 1;

    } else {

        Elemento *ant, *atual = *li;

        while(atual != NULL && atual->dados.matricula < al.matricula) {

            ant = atual;
            atual = atual->prox;

        }

        if(atual == *li) {//insere in�cio

            no->prox = (*li);
            *li = no;

        } else {

            no->prox = atual;
            ant->prox = no;

        }

        return 1;

    }

}


int remove_lista(Lista* li, int mat) {

    if(li == NULL) {

        return 0;

    }

    if((*li) == NULL) {//lista vazia
        
        return 0;

    }

    Elemento *ant, *no = *li;

    while(no != NULL && no->dados.matricula != mat) {

        ant = no;
        no = no->prox;

    }

    if(no == NULL){//n�o encontrado

        return 0;

    }

    if(no == *li) {//remover o primeiro?

        *li = no->prox;

    } else {

        ant->prox = no->prox;

    }

    free(no);

    return 1;

}


int remove_lista_inicio(Lista* li) {

    if(li == NULL) {

        return 0;

    }

    if((*li) == NULL) {//lista vazia

        return 0;

    }

    Elemento *no = *li;
    *li = no->prox;

    free(no);

    return 1;

}


int remove_lista_final(Lista* li) {

    if(li == NULL) {

        return 0;

    }

    if((*li) == NULL) {//lista vazia

        return 0;

    }

    Elemento *ant, *no = *li;

    while(no->prox != NULL) {

        ant = no;
        no = no->prox;

    }

    if(no == (*li) ) {//remover o primeiro?

        *li = no->prox;

    } else {

        ant->prox = no->prox;

    }

    free(no);

    return 1;

}


int tamanho_lista(Lista* li) {

    if(li == NULL) {

        return 0;

    }

    int cont = 0;

    Elemento* no = *li;

    while(no != NULL) {

        cont++;
        no = no->prox;

    }

    return cont;

}


int lista_cheia(Lista* li) {

    return 0;

}


int lista_vazia(Lista* li) {

    if(li == NULL) {

        return 1;

    }

    if(*li == NULL) {

        return 1;

    }

    return 0;

}


void imprime_lista(Lista* li) {

    if(li == NULL) {

        return 0;

    }

    Elemento* no = *li;

    while(no != NULL) {
        
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;

    }

}


// Criação da função Consulta Lista Matrícula, que recebe um número de matrícula e retorna o nome do respectivo aluno
int consultaListaMatricula ( Lista *li, int matricula, struct aluno *al ) {

    // Condicional de segurança para caso a lista esteja vazia ou não exista
    if ( li == NULL || lista_vazia(li) ) {

        return 0;

    }

    // Cria o ponteiro auxiliar para percorrer a lista e faz ele apontar para o primeiro elemento da lista
    Elemento *aux = *li;

    /* Enquanto aux não apontar para NULL e o número da matrícula do aluno armazenado em aux for diferente da matrícula digitada, 
    o ponteiro aux vai para o próximo elemento */
    while ( aux != NULL && aux -> dados.matricula != matricula ) {

        aux = aux -> prox;

    }

    // Caso ao final do loop, aux apontar para NULL, é sinal que o aluno não existe
    if ( aux == NULL ) {

        printf ( "\nO aluno nao existe" );
        return 0;

    // Caso contrário, imprime o nome do aluno armazenado na posição apontada por aux
    } else {

        printf ( "\nO nome do aluno com o número de matrícula %d eh: %s ", matricula, aux -> dados.nome );

    }

    return 1;

}


// Criação da função Consulta Lista Matrícula, que recebe um índice do aluno e retorna o nome do respectivo aluno
int consultaListaIndice ( Lista *li, int pos ) {

    // Condicional de segurança para caso a lista esteja vazia, não exista, o tamanho da lista seja menor que o indice digitado ou o indice digitado seja negativo
    if ( li == NULL || lista_vazia(li) || tamanho_lista(li) < pos || pos <= 0) {

        return 0;

    }

    // Cria o ponteiro auxiliar para percorrer a lista e faz ele apontar para o primeiro elemento da lista
    Elemento *aux = *li;

    // Contador para peercorrer a lista
    int cont = 1;

    /* Enquanto aux não apontar para NULL e o número do elemento para onde aux aponta for diferente do número digitado, 
    o ponteiro aux vai para o próximo elemento e incrementa o contador cont*/
    while ( aux != NULL && cont < pos ) {

        aux = aux -> prox;
        cont++;

    }

    // Ao sair do loop, printa o nome do aluno armazenado no elemento para onde aux aponta
    printf ( "\nO nome do aluno na posicao %d da lista eh: %s ", pos, aux -> dados.nome );

    return 1;

}
