#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h" //inclui os Prot�tipos

//Defini��o do tipo lista
struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere in�cio
        no->ant = NULL;
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    if(*li != NULL)//lista n�o vazia: apontar para o anterior!
        (*li)->ant = no;
    *li = no;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    while(no->prox != NULL)
        no = no->prox;

    if(no->ant == NULL)//remover o primeiro e �nico
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
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


int insere_lista_ordenada (Lista *li, struct aluno al) {

    // Caso li não exista, retorna erro crítico
    if ( li == NULL ) {

        printf ( "\n\nCRITICAL ERROR\n\n" );
        return 0;

    }

    // Cria o novo nó e coloca os dados dele
    Elem *no = (Elem *) malloc ( sizeof ( Elem ) );

    no -> dados = al;

    // Caso a lista esteja vazia, tanto o prox quanto ant serão nulos, pois só existe 1 elemento, e li apontará para ele
    if ((*li) == NULL) {

        no -> ant = NULL;
        no -> prox = NULL;
        *li = no;

        return 1;

    // Caso a lista não esteja vazia
    } else {

        Elem *aux = *li;
        Elem *ant = *li;

        // Percorre caso o novo dado seja menor do atual
        while ( aux != NULL && aux -> dados.matricula < al.matricula ) {

            ant = aux;
            aux = aux -> prox;

        }
        // Caso for inserir no primeiro elemento da lista
        if (aux == *li) {
            
            /* faz com que o novo nó seja inserido antes de li, fazendo com que o ant de aux aponte para nó, 
            o ant de nó seja null, pois ele é o primeiro elemento e o prox de nó seja o elemento para onde li 
            aponta, em seguida, li aponta para nó */
            aux -> ant = no;
            no -> ant = NULL;
            no -> prox = *li;
            *li = no;

        } else {
            
            /* Faz com que nó prox seja igual ao auxiliar e que o nó ant seja igual a ant, fazendo com que
            nó seja inserido entre os dois elementos, após isso, ant prox aponta para nó, pois ele é o próximo
            elemento da lista e por último, caso nó não for o último elemento da lista, aux ant aponta para o nó */
            no -> prox = aux;
            no -> ant = ant;
            ant -> prox = no;

            if( aux != NULL ) {

                aux -> ant = no;

            }
        }

        return 1;

    }
}

