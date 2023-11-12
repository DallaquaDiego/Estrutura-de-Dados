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


int Pilha_cheia(Pilha *pi) {
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

// Criação da Função MenorMaior
int MM ( Pilha *pi ) {

    // Teste de Segurança
    if ( pi == NULL || Pilha_vazia( pi ) ) {

        return 0;

    }

    // Crianção do Ponteiro Auxiliar que aponta para onde pi aponta
    Elem *aux = *pi;

    // Definições das variáveis manor, menor e média
    float maior = aux -> dados.n1;
    float menor = aux -> dados.n1;
    float media = 0;

    // Loop para percorrer toda a pilha
    while ( aux != NULL ) {

        // Teste do Maior Valor
        if ( aux -> dados.n1 > maior ) {

            maior = aux -> dados.n1;

        }

        // Teste do Menor Valor
        if ( aux -> dados.n1 < menor ) {

            menor = aux -> dados.n1;

        }

        // Soma o valor na variável média
        media += aux -> dados.n1;

        // Aponta pro próximo ponteiro
        aux = aux -> prox;

    }

    // Cálculo da Média
    media /= tamanho_Pilha( pi ); 

    // Printa o Resultado
    printf ( "\nMaior: %.2f\nMenor: %.2f\nMedia: %.3f\n", maior, menor, media );

    return 1;

}