/* O programa lê a quantidade de linhas e colunas da matriz, realiza a alocação dinâmica e faz a leitura dos elementos. 
Em seguida, ele  imprime os elementos da matriz e libera a memória alocada */

#include <stdio.h>
#include <stdlib.h>

int main () {

    int **matriz, linha, coluna, l, c;

    printf( "\nInsira a quantidade de linhas da matriz: " );
    scanf( "%d", &linha );

    printf( "\nInsira a quantidade de colunas da matriz: " );
    scanf( "%d", &coluna );

    matriz = (int**) malloc ( linha * sizeof (int *) );

    for ( l = 0; l < linha; l++ ) {

        matriz[l] = (int*) malloc ( coluna * sizeof (int) );

        for ( c = 0; c < coluna; c++ ) {

            printf( "\nInsira um elemento da matriz: " );
            scanf( "%d", &matriz[l][c] );

        }

    }

    for ( l = 0; l < linha; l++ ) {

        for ( c = 0; c < coluna; c++ ) {

            printf( "%d ", matriz[l][c] );
           
        }

        printf ( "/n" );

    }

    for (l = 0; l < linha; l++) {

        free(matriz[l]);

    }

    free (matriz);

    return 0;

}