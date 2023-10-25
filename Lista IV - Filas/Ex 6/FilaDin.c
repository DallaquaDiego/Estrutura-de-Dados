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

// Função Fila Crescente
int FilaCrescente ( Fila *f1, Fila *f2, Fila *f3 ) {
    
    // Condicional de Segurança
    if ( f1 == NULL || f2 == NULL || Fila_vazia(f1) || Fila_vazia(f2) || !Fila_vazia(f3) ) {

        return 0;

    }

    // Cria os ponteiros auxiliares para percorrer as filas
    Elem *AuxF1 = f1 -> inicio;
    Elem *AuxF2 = f2 -> inicio;

    while ( AuxF1 != NULL || AuxF2 != NULL ) {
         
         // Primeiro caso de Teste, onde a Matrícula da primeira fila é menor que a da segunda
        if ( AuxF1 -> dados.matricula < AuxF2 -> dados.matricula ) {

            insere_Fila ( f3, AuxF1 -> dados );

            AuxF1 = AuxF1 -> prox;

        // Segundo caso de Teste, onde a Matrícula da segunda fila é menor que o da primeira
        } else if ( AuxF2 -> dados.matricula < AuxF1 -> dados.matricula ) { 

            insere_Fila ( f3, AuxF2 -> dados );

            AuxF2 = AuxF2 -> prox;

        // Terceiro caso de Teste, onde a Matrícula da segunda fila é igual a da primeira
        } else if ( AuxF2 -> dados.matricula == AuxF1 -> dados.matricula ) { 

            insere_Fila ( f3, AuxF1 -> dados );
            insere_Fila ( f3, AuxF2 -> dados );

            AuxF1 = AuxF1 -> prox;
            AuxF2 = AuxF2 -> prox;

        //  Quarto caso de teste, quando a primeira fila acaba mas a segunda não
        } else if ( AuxF1 == NULL && AuxF2 != NULL ) {

            insere_Fila ( f3, AuxF2 -> dados );

            AuxF2 = AuxF2 -> prox;

        // Quinto caso de teste, quando a segunda fila acaba mas a segunda não
        } else if ( AuxF2 == NULL && AuxF1 != NULL ) {

            insere_Fila ( f3, AuxF1 -> dados );

            AuxF1 = AuxF1 -> prox;

        } 

    }

    imprime_Fila ( f3 );
    
    return 1;

}