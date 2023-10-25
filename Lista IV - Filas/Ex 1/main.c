#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.c"

int main() {

    struct aluno al,a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}
    };

    Fila* fi = cria_Fila();
    
    int i, n;

    for ( i = 0; i < 4; i++ ) {

        insere_Fila( fi, a[i] );

        if ( Fila_vazia( fi ) ) {

            printf( "Erro!!!!!!\n" );

        }

    }


    printf( "\n\n\nInsira o valor da matricula desejado: " );
    scanf( "%d", &n );

    Fila *fi2 = cria_Fila();
    
    printf("\nFila 1 de tamanho %d antes da alteracao: \n\n", tamanho_Fila( fi ) );   
    imprime_Fila( fi );
    
    printf( "\n\nProva de que funciona: " );
    separaFila ( fi, fi2, n );

    printf("\n\nFila 1 depois da alteracao: \n\n" );
    imprime_Fila( fi );
    
    printf( "\n\n" );

    printf("\nFila 2 depois da alteracao: \n\n" );
    imprime_Fila(fi2);
    
    libera_Fila(fi);
    libera_Fila(fi2);

    return 0;

}


