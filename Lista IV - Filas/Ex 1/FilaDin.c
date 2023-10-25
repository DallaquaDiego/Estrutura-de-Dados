#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os Prot�tipos
//Defini��o do tipo Fila
struct elemento {

    struct aluno dados;
    struct elemento *prox;

};
typedef struct elemento Elem;

//Defini��o do N� Descritor da Fila
struct fila {

    struct elemento *inicio;
    struct elemento *final;
    int qtd;

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
            fi->inicio = fi->inicio->prox;
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

    fi->inicio = fi->inicio->prox;

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

int Fila_cheia( Fila* fi ) { 

    return 0;

}

void imprime_Fila( Fila* fi ) {

    if(fi == NULL) {

        return;

    }

    Elem* no = fi->inicio;

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


int separaFila ( Fila *f1, Fila *f2, int n  ) {

    // Condicional de segurança 
    if ( f1 == NULL || f2 == NULL || Fila_vazia(f1) || !Fila_vazia (f2) ) { 
        
        return 0;

    }

    // Cria o auxiliar para percorrer a fila
    Elem *aux = f1 -> inicio;

    while ( aux != NULL && aux -> dados.matricula != n ) {
        
        // Aponta pro próximo para percorrer a fila inteira
        aux = aux -> prox;

    }

    if ( aux != NULL && aux != f1 -> final ) {

        // O final de f2 aponta para o final de f1
        f2 -> final = f1 -> final;

        // O início de f2 aponta para o próximo elemento onde o ponteiro aux parou
        f2 -> inicio = aux -> prox;

        // O final de f1 passa a ser o nó para onde aux aponta
        f1 -> final = aux;

        // O nó para onde aux aponta passa a ser o último elemento da pilha
        aux -> prox = NULL;

    } else {

        return 0;

    }

    return 1;

}