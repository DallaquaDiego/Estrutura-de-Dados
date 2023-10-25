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
    struct Fila *prox;

};

typedef struct fila FilaMestre;

struct fila_mestre {

    struct fila *inicio;
    struct fila *final;
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

// Função de Criação da Fila Mestre
FilaMestre* cria_FilaMestre() { 

    FilaMestre* fi = (Fila*) malloc(sizeof(FilaMestre));

    if ( fi != NULL ) {

        fi -> final = NULL;
        fi -> inicio = NULL;
        fi -> qtd = 0;

    }

    return fi;

}


// Cria a função que insere elementos na fila
int insere_FilaMestre ( FilaMestre* fi, Fila* item ) {

    // Condicional de segurança onde fi e o item devem existir
    if (fi == NULL && item == NULL) {

        return 0;

    }

    

    if ( fi -> final == NULL ) {

        // Faz com que o inicio aponte para o item inserido
        fi -> inicio = item; 
        
    } else {

        // Faz com que o próximo elemento depois do final seja o item inserido
        fi -> final -> prox = item; 

    }

    fi -> final = item;

    fi -> qtd++; 

    return 1;

}


// Cria a função que imprime a fila
void imprime_FilaMestre ( FilaMestre* fi ) {

    // Condicional de segurança
    if ( fi == NULL ) {

        return;

    }

    int n = 1;

    Elem* aux = fi -> inicio; 
    Elem* no = aux; 

    while( aux != NULL ) {

        // Detecta qual fila está sendo impressa
        printf("\nFila Mestre%d\n", n); 
        no = fi -> inicio;

        // Imprime os dados
        while( no != NULL ) {

            printf("Matricula: %d\n", no -> dados.matricula);
            printf("Nome: %s\n",no->dados.nome);
            printf("Notas: %f %f %f\n",no -> dados.n1,
                                        no -> dados.n2,
                                        no -> dados.n3);
            printf("-------------------------------\n");

            // Aponta para o próximo nó
            no = no -> prox;

        }

        // Aux aponta para a próxima fila da fila mestre
        aux = aux -> prox;

    }

}