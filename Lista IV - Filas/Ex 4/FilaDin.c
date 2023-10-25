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


void imprime_FilaCircular( Fila* fi ) {

    if(fi == NULL) {

        return;

    }

    Elem* no = fi->inicio;

    // Altera o while para não ficar imprimindo infinitamente
    do {

        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;

    } while( no != NULL && no != fi -> inicio );

}


int InsereCircular ( Fila *fi, struct aluno al ) {

    // Condicional de Segurança
    if ( fi == NULL ) {

        return 0;

    }

    // Cria o novo nó da fila
    Elem *no = ( Elem* ) malloc ( sizeof ( Elem ) );

    // Condicional que verifica se o novo nó foi criado
    if ( no == NULL ) {

        return 0;

    }

    // Passa os dados do aluno para o novo nó
    no -> dados = al;

    // Verifica se a fila está vazia
    if ( fi -> final == NULL ){

        fi -> final = no;
        fi -> inicio = no;

    } else {

        // Indica que o próximo elemento do novo nó, é o primeiro elemento da fila
        no -> prox = fi -> inicio;

        // Faz o ponteiro de inicio apontar para o novo elemento
        fi -> inicio = no;

    }

    // Faz com que o proximo elemento do último elemento da fila seja o novo elemento criado, fazendo com que ela seja circular, já que ela está no começo da fila
    fi -> final -> prox = no;

    // Incrementa a quantidade de elementos
    fi -> qtd++;

    return 1;

}