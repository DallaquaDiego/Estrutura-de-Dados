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

// Criação da PilhaPopDouble e passagem do parâmetro ponteiro tipo pilha "pi"
int PilhaPopDouble (Pilha *pi ) {       

    // Caso o endereço para onde pi aponta seja Nulo ou não haja nada naquele endereço, retorna 0
    if ( pi == NULL || *pi == NULL ) {      

        return 0;

    }
    
    // Criação do ponteiro auxiliar, que possui o mesmo valor apontado por pi
    Elem *aux = *pi;

    // O ponteiro pi aponta para o próximo nó
    *pi = (*pi) -> prox;

    // Libera a memória do  ponteiro auxiliar
    free (aux);

    // Caso a pilha estiver vazia, retorna 1
    if ( Pilha_vazia( pi ) ) {

        return 1;

    }

    // Atribui o valor apontado por pi ao ponteiro auxiliar
    aux = *pi;

    // O ponteiro pi aponta para o próximo nó
    *pi = (*pi) -> prox;

    // Libera a memória do  ponteiro auxiliar
    free (aux);

    return 1;

}

// Criação da PilhaPushDouble e passagem do parâmetro ponteiro "pi" tipo pilha, e dos ponteiros a1 e a2 do tipo alino
int PilhaPushDouble ( Pilha *pi, struct aluno *a1, struct aluno *a2 ) {

    // Caso o endereço para onde pi aponta seja Nulo ou não haja nada naquele endereço, retorna 0
    if ( pi == NULL ) {

        return 0;

    }

    // Alocação do nó no1
    Elem *no1 = ( Elem*) malloc ( sizeof ( Elem ) );

    // Caso o endereço apontado por no1 for nulo, retorna 0
    if ( no1 == NULL ) {

        return 0;

    }

    // no1 recebe os dados armazenados em no endereço apontado por a1
    no1 -> dados = *a1;

    // no1 aponta para o nó anterior
    no1 -> prox = (*pi);

    // pi passa a apontar para no1, que é a cabeça da pilha
    *pi = no1;

    // Alocação do nó no2
    Elem *no2 = ( Elem* ) malloc ( sizeof ( Elem ) );

    // Caso o endereço apontado por no2 for nulo, retorna 0
    if ( no2 == NULL ) {
        
        return 0;

    }

    // no2 recebe os dados armazenados em no endereço apontado por a2
    no2 -> dados = *a2;

    // no2 aponta para o nó anterior
    no2 -> prox = (*pi);

    // pi passa a apontar para no2, que passa a ser a cabeça da pilha
    *pi = no2;

    return 1;

}
