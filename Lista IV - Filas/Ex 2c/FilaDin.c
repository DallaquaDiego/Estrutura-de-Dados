#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os Prot�tipos
//Defini��o do tipo Fila
struct elemento {

    struct aluno dados;
    struct elemento *prox;

}; typedef struct elemento Elem;

struct fila {

    struct elemento *inicio;
    struct elemento *final;
    int qtd;
    struct Fila *prox;

};


struct pilha {

    struct Fila *topo;

};

Fila* cria_Fila () {

    Fila* fi = ( Fila* ) malloc( sizeof( Fila ) );
    if(fi != NULL) {

        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;

    }

    return fi;

}


void libera_Fila(Fila* fi) {

    if(fi != NULL) {

        Elem* no;

        while(fi->inicio != NULL) {

            no = fi->inicio;
            fi->inicio = fi ->inicio -> prox;
            free(no);

        }
        
        free(fi);

    }
    
}

int consulta_Fila ( Fila* fi, struct aluno *al ) {

    if(fi == NULL) {

        return 0;

    }

    if(fi->inicio == NULL) {
        
        return 0;

    }

    *al = fi->inicio->dados;

    return 1;

}

int insere_Fila ( Fila* fi, struct aluno al ) {

    if(fi == NULL) {

        return 0;

    }

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL) {

        return 0;

    }

    no->dados = al;
    no->prox = NULL;

    if(fi->final == NULL) {

        fi->inicio = no;

    } else {

        fi->final->prox = no;

    }

    fi->final = no;
    fi->qtd++;

    return 1;

}

int remove_Fila ( Fila* fi ) {

    if(fi == NULL) {

        return 0;

    }
    if(fi->inicio == NULL) {

        return 0;

    }

    Elem *no = fi->inicio;

    fi->inicio = fi -> inicio -> prox;

    if(fi->inicio == NULL){

        fi->final = NULL;

    }

    free(no);
    fi->qtd--;

    return 1;

}

int tamanho_Fila ( Fila* fi ) {

    if(fi == NULL) {

        return 0;

    }

    return fi->qtd;

}

int Fila_vazia ( Fila* fi ) {

    if(fi == NULL) {

        return 1;

    }

    if(fi->inicio == NULL) {

        return 1;

    }

    return 0;

}

void imprime_Fila( Fila* fi ) {

    if( fi == NULL ) {

        return;

    }

    Elem* no = fi -> inicio;

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


// Função Cria Pilha
Pilha *cria_Pilha() {

    // Cria pi
    Pilha* pi = ( Pilha* ) malloc ( sizeof ( Pilha ) );

    // Caso pi exista, o topo da pilha aponta para nulo
    if ( pi != NULL ){

        pi -> topo = NULL;

    }

    return pi;

}

// Função Insere Pilha
int insere_Pilha ( Pilha *pi, Fila *fi ) {

    // Condicional de Segurança
    if ( pi == NULL || fi == NULL ) {

        return 0;

    }


    fi -> prox = pi -> topo;

    // O topo da pilha se torna o elemento inserido
    pi -> topo = fi;

    return 1;

}