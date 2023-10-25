/*  A leitura do tamanho do vetor é feita dentro da função main, em seguida, a função 'min_max' realiza a alocação
dinâmica do vetor, a leitura do primeiro elemento desse vetore iguala essa leitura aos valores de min e max. Dentro
de um loop, os restos dos elementos do vetor são lidos, e dentro desse loop, é feito um teste, para ver se o valor
digitado é menor do que a variável min, ou maior do que a variável max. Caso um desses casos ocorra, o valor digitado
substitui o valor da variável  */

#include <stdio.h>
#include <stdlib.h>


int min_max( int *vetor, int tam ) {

    int min, max;

    vetor = (int*) malloc ( tam * sizeof (int) );

    printf( "\nInsira um elemento do vetor: " );
    scanf( "%d", vetor );

    min = *vetor;
    max = *vetor;

    for ( int cont = 1; cont < tam; cont++ ) {

        printf( "\nInsira um elemento do vetor: " );
        scanf( "%d", vetor + cont );

        if ( min > *( vetor + cont ) ) {

            min = *( vetor + cont );

        }

        if ( max < *( vetor + cont ) ) {

            max = *( vetor + cont );

        }

    }

    printf( "\nO maior valor eh: %d ", max );
    printf( "\nO menor valor eh: %d ", min );

    vetor = (int*) realloc ( vetor, tam * sizeof (int) );

    free ( vetor );

    return 0;

}   


int main() {
    
    int *vetor, tam;

    printf( "\nInsira o tamanho do vetor: " );
    scanf( "%d", &tam );

    min_max ( vetor, tam );

    return 0;

}