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
    if( pi != NULL )
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


// Criação da função calcula, que realizará as operações
float Calcula ( float resultado, char operador, float numero ) {

    switch (operador) {

        // Caso for operador de soma, acrescenta um número a outro
        case '+':

            resultado += numero;

        break;

        // Caso for operador de subtração, subtrai um número do outro
        case '-':

            resultado -= numero;

        break;

        // Caso for operador de multiplicação, multiplica um pelo outro
        case '*':

            resultado *= numero;

        break;

        // Caso for operador de divisão, divide um número pelo outro
        case '/':

            resultado /= numero;

        break;
        
    }

    return resultado;

}

Pilha *invertePilha ( Pilha *pi ) {

    Elem *aux;
    int tamanho = tamanho_Pilha(pi);

    struct aluno *vet = ( struct aluno* ) malloc ( tamanho * sizeof ( struct aluno ) );

    // Loop de inversão
    for ( int i = 0; i < tamanho; i++ ) {

        aux = *pi;

        vet[ tamanho - i - 1 ] = (*pi) -> dados;

        *pi = (*pi) -> prox;

        free (aux);

    }

    Pilha *pi2 = cria_Pilha();

    for ( int i = 0; i < tamanho; i++ ) { 

        insere_Pilha( pi2, vet[ tamanho - i - 1 ] );

    }

    free (vet);

    return pi2;

}


// Criação da Função Calculadora
float Calculadora (  Pilha *pi, int tamanho ) {
    
    // Verifica se a pilha foi criada e se ela termina com um número
    if ( tamanho % 2 == 0 || pi == NULL ) {

        return 0;

    }

    // Cria a estrutura
    struct aluno calc;

    // Loop para preenchimento da pilha
    for ( int i = 1; i <= tamanho; i++ ) {

        // Verifica se o elemento digitado será um número ou um operador
        if ( i % 2 != 0 ) {

            printf ( "\nInsira um numero: " );
            scanf ( "%f", &calc.n1 );

        } else {

            printf ( "\nInsira um operador: " );
            scanf ( " %c", &calc.nome[0] );

        }

        // Insere o elemento na pilha
        insere_Pilha ( pi, calc );

    }

    // Cria a variável que armazena o resultado das operações 
    float resultado = 0;
    
    int i = 1;

    // Cria a variável que armazena o operador auxiliar
    char operAux;

    // Cria o auxiliar que aponta para o topo da pilha
    Elem *aux = *pi;
    
    invertePilha( pi );

    // Loop de calculo
    while ( aux != NULL ) {

        // Quando for nó par, onde existe um operador, esse operador é armazenado na variável operAux
        if ( i % 2 == 0 ) {

            operAux = aux -> dados.nome[0];

        } else {

            // Quando for o primeiro número da operação, o resultado vai ser igual a ele mesmo
            if ( i == 1 ) {

                resultado = aux -> dados.n1;

            } else { // Caso contrário, chama a função que realizará a operação

                resultado = Calcula ( resultado, operAux, aux -> dados.n1 );

            }

        }

        i++;

        // Aponta para o próximo nó
        aux = aux -> prox;

    }

    return resultado;

}