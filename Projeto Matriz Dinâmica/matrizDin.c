#include <stdio.h>
#include <stdlib.h>
#include "matrizDin.h"

struct matriz {

    struct elemento *top;
    struct elemento *bot;
    struct elemento *prox;
    struct elemento *ant;
    struct dados numero;

}; typedef struct matriz Elem;

Matriz *criaMatriz() {

    Matriz *mat = ( Matriz* ) malloc ( sizeof ( Matriz ) );

    if ( mat != NULL ) {

        *mat = NULL;

    }

    return mat;

}


Matriz *insereMatriz ( Matriz *mat, struct dados valor ) {

    // Condicional de segurança pro caso da matriz não existir
   if ( mat == NULL ) {
    
        return 0;

    }

    // Criação e alocação do auxiliar dinâmicamente, em seguida, outra condicional de segurança é executada para garantir que o auxiliar foi alocado
    Elem *aux;
    aux = ( Elem* ) malloc ( sizeof ( Elem ) );

    if ( aux == NULL ) {

        return 0;

    }

    // O número digitado pelo usuário é armazenado aonde o auxiliar aponta e o ponteiro PROX de auxiliar aponta para NULL, pois ainda não existe um próximo elemento
    aux -> numero = valor;
    aux -> prox = NULL;

    // Caso o elemento inserido for o primeiro elemento da matriz, o ponteiro ANT do auxiliar aponta para NULL e o conteúdo da cabeça da matriz, passa a ser o endereço de aux
    if ( ( *mat ) == NULL ) {

        aux -> ant = NULL;
        *mat = aux;

    // Caso não for o primeiro elemento, cria um segundo auxiliar e faz com que o auxiliar aponte para a cabeça da matriz
    } else {

        Elem *aux2;

        aux2 = *mat;

        // Enquanto o próximo elemento de Aux2 for diferente de NULL, aux2 aponta para o próximo
        while ( aux2 -> prox != NULL ) {

            aux2 = aux2 -> prox;

        }

        // O ponteiro PROX de aux2 aponta para aux, e o ponteiro ANT de aux aponta para aux2, logo, o nó aux vem depois do nó aux2
        aux2 -> prox = aux;
        aux -> ant = aux2;

    }

    return 1;

}


int imprimeElemento ( Matriz *mat, int linha, int coluna, int tamanho ) {

    // Condicional de Segurança
    if ( linha < 0 || linha > tamanho || coluna < 0 || coluna > tamanho ) {

        printf( "\nValores Invalidos\n\n\n" );

        return 0;

    }

    // Cria o ponteiro auxiliar para percorrer a matriz
    Elem *aux = *mat;

    while ( aux != NULL ) {

        // Quando a linha e a coluna do nó para onde o uxiliar aponta forem iguais as digitadas pelo usuário, imprime o conteúdo do nó
        if ( aux -> numero.linha == linha && aux -> numero.coluna == coluna ) {

            printf ( "\nElemento (%d)x(%d) = %d\n", linha, coluna, aux -> numero.conteudo );

            return 1;

        }

        // Caso contrário, aponta para o próximo nó
        aux = aux -> prox;
        
    }

    return 0;

}


int procuraElemento ( Matriz *mat, int num, int tamanho ) {

    // Cria o ponteiro auxiliar e os contadores
    Elem *aux = *mat;
    

    // Percorre toda a matriz
    while ( aux != NULL ) {
            
        // Compara o conteúdo do nó e o número digitado
        if ( aux -> numero.conteudo == num ) {

            printf ( "\nLinha: %d\n",aux -> numero.linha );
            printf ( "Coluna: %d\n",aux -> numero.coluna );

            return 1;

        } 
                
        // Caso não for igual, aponta para o próximo nó
        aux = aux -> prox;

    }

    printf ( "Número Inválido, Tente Novamente" );

    return 0;
    
}

int ponteiroTop ( Matriz *mat, int linha, int coluna, int tamanho ) {

    Elem *aux = *mat; 
    int i = 0;

    // Calcula a posição do elemento com base nas coordenadas de linha e coluna.
    int contador = (linha * tamanho) + coluna; 

    // Enquanto não chegarmos ao final da matriz ou não encontrarmos o elemento desejado    
    while ( aux != NULL && i != contador ) { 

        i++; 

        // Move o ponteiro aux para o próximo elemento da matriz.
        aux = aux->prox; 

    }

    Elem *aux2 = *mat;

    while ( aux2 != NULL ) {
        
        // Se o elemento apontado por aux2 está diretamente acima do elemento apontado por aux
        if ( aux2->numero.linha == aux->numero.linha - 1 && aux2->numero.coluna == aux->numero.coluna ) {
            
            // Configura o ponteiro 'top' do elemento atual para apontar para o elemento acima
            aux->top = aux2; 

            return 1; 

        }

        // Move o ponteiro aux2 para o próximo elemento da matriz.
        aux2 = aux2->prox; 

    }

    // Se chegarmos até aqui, significa que não foi encontrado um elemento diretamente acima do elemento atual.
    // Nesse caso, o ponteiro 'top' permanece configurado como NULL (não aponta para nenhum elemento).

    return 0;

}


int ponteiroBot( Matriz *mat, int linha, int coluna, int tamanho ) {

    Elem *aux = *mat; 

    int i = 0; 

    // Calcula a posição do elemento com base nas coordenadas de linha e coluna.
    int contador = (linha * tamanho) + coluna; 

    // Enquanto não chegarmos ao final da matriz ou não encontrarmos o elemento desejado...
    while ( aux != NULL && i != contador ) { 

        i++;

        // Move o ponteiro aux para o próximo elemento da matriz.
        aux = aux->prox;

    }

    Elem *aux2 = *mat; 

    while (aux2 != NULL) { 
        
        // Se o elemento apontado por aux2 está diretamente abaixo do elemento apontado por aux
        if ( aux2->numero.linha == aux->numero.linha + 1 && aux2->numero.coluna == aux->numero.coluna ) {
            
            // Configura o ponteiro 'bot' do elemento atual para apontar para o elemento abaixo
            aux->bot = aux2; 

            return 1; 

        }

        // Move o ponteiro aux2 para o próximo elemento da matriz.    
        aux2 = aux2->prox; 

    }

    // Se chegarmos até aqui, significa que não foi encontrado um elemento diretamente abaixo do elemento atual.
    // Nesse caso, o ponteiro 'bot' permanece configurado como NULL (não aponta para nenhum elemento).

    return 1;

}


int imprimeVizinho ( Matriz *mat, int linha, int coluna, int tamanho ) {

    if ( linha < 0 || linha > tamanho || coluna < 0 || coluna > tamanho || linha * coluna > ( tamanho * tamanho ) ) {

        printf("\nValores Invalidos\n\n\n");
        return 0;

    }

    int posTop = tamanho, posBot = tamanho;

    Elem *aux = *mat;
    Elem *aux2, *top, *bot;

    while ( aux != NULL ) {

        if ( aux -> numero.linha == linha && aux -> numero.coluna == coluna ) {

            printf ( "\n\nPosicao (%d)x(%d) = %d\n", linha, coluna, aux -> numero.conteudo );

            aux2 = aux -> ant;

            if ( aux2 != NULL && aux2 -> numero.linha == aux -> numero.linha ) {

                printf ( "Left = %d\n", aux2 -> numero );

            } else {

                printf ( "Left = NULL\n" );

            }

            top = aux;

            while ( top -> ant != NULL && posTop > 0 ) {

                top = top -> ant;
                posTop--;

            }

            if ( top == aux ) {

                top = NULL;

            }

            if ( top != NULL && top -> numero.coluna == aux -> numero.coluna ) {

                printf( "Top = %d\n", top -> numero );

            } else {

                printf( "Top = NULL\n" );

            }

            aux2 = aux -> prox;

            if ( aux2 != NULL && aux2 -> numero.linha == aux -> numero.linha ) {

                printf ( "Right = %d\n", aux2 -> numero );

            } else {

                printf ( "Right = NULL\n" );

            }

            bot = aux;

            while ( bot -> prox != NULL && posBot > 0 ) {

                bot = bot -> prox;
                posBot--;

            }

            if ( bot == aux ) {

                bot = NULL;

            }

            if ( bot != NULL && bot -> numero.coluna == aux -> numero.coluna ) {

                printf ( "Bot = %d\n", bot -> numero );

            } else {

                printf ( "Bot = NULL\n" );

            }

            return 1;
        }

        aux = aux -> prox;

    }

}


void apagaMatriz ( Matriz* mat ) {

    // Condicional de segurança
    if ( mat == NULL ) {

        return;

    }

    // Cria os auxiliares que vão percorrer a matriz
    Elem *aux = *mat, *aux2;

    while ( aux != NULL ) {

        // O segundo auxiliar aponta para o próximo elemento após o primeiro auxiliar
        aux2 = aux -> prox;

        // Libera o primeiro auxiliar
        free ( aux );

        // O primeiro auxiliar aponta para o mesmo lugar que o segundo aponta
        aux = aux2;

    }

    // Após isso tudo, libera a matriz
    free ( mat );

    printf ( "\nSua matriz foi jogar no Vasco!\n\n" );
    
}


void imprimeMatriz ( Matriz *mat, int tamanho ) {

    int cont = 0, contAux = 1, linha, coluna;

    // Condicional de segurança pro caso da matriz não existir
    if ( mat == NULL ) {

        return 0;

    }
    
    // Cria o auxiliar e faz com que ele aponte para onde a cabeça aponta
    Elem *aux = *mat;

    printf ( "\n" );

    // Enquanto o auxiliar não apontar para NULL, imprime o número armazenado aonde o auxiliar aponta
    while ( aux != NULL ) {

        printf( "\t" );
        printf( "|%d|", aux -> numero.conteudo );

        // O auxiliar aponta para o próximo elemento
        aux = aux -> prox;
        cont++;

        // Faz com que ocorra uma quebra de linha quando necessário
        if ( cont == tamanho || cont == tamanho * contAux ){

            printf ( "\n\n" );
            contAux++;

        }

    }

}