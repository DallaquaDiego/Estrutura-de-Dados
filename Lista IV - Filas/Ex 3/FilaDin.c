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


int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}


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

// Função Inverte Fila
int inverteFila ( Fila *fi, Pilha *pi ) {

    // Condicional de Segurança
    if ( fi == NULL || Fila_vazia(fi) || pi == NULL || !Pilha_vazia(pi) ) {

        return 0;

    }

    // Cria um ponteiro auxiliar para percorrer a fila
    Elem *auxF = fi -> inicio;

    // Loop para percorrer a fila
    while ( auxF != NULL ) {
        
        // Coloca os elementos da fila na pilha
        insere_Pilha ( pi, auxF -> dados );

        // O auxiliar aponta para o próximo elemento
        auxF = auxF -> prox;

        // Remove os elementos da fila para depois colocar na ordem inversa
        remove_Fila(fi);

    }

    // Cria o ponteiro auxiliar da pilha
    Elem *auxP = *pi;

    // Loop para percorrer a pilha
    while ( auxP != NULL ) {

        // Insere os elementos na pilha de volta na fila, que estão na ordem inversa por causa da propriedade First In Last Out
        insere_Fila ( fi, auxP -> dados );

        // O auxiliar aponta para o próximo elemento
        auxP = auxP -> prox;

        // Remove o elemento da pilha para deixar ela vazia
        remove_Pilha (pi);

    }
    
   return 0;

}