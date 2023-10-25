#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.c"

int main() {

    struct aluno al, a1[4] = {{1,"Bianca",9.7,6.7,8.4},
                            {3,"Andre",9.5,7.8,8.5}, 
                            {5,"Ana",5.7,6.1,7.4},
                            {7,"Ricardo",7.5,8.7,6.8}
    };

    struct aluno al2, a2[4] = {{2,"Bianca",9.7,6.7,8.4},
                            {4,"Andre",9.5,7.8,8.5}, 
                            {6,"Ana",5.7,6.1,7.4},
                            {8,"Ricardo",7.5,8.7,6.8}   
    };

    Fila* f1 = cria_Fila();
    Fila* f2 = cria_Fila();
    Fila* f3 = cria_Fila();
    
    int i;

    for ( i = 0; i < 4; i++ ) {

        insere_Fila( f1, a1[i] );

        if ( Fila_vazia( f1 ) ) {

            printf( "Erro!!!!!!\n" );

        }

    }

    for ( i = 0; i < 4; i++ ) {

        insere_Fila( f2, a2[i] );

        if ( Fila_vazia( f2 ) ) {

            printf( "Erro!!!!!!\n" );

        }

    }

    printf ( "\nFila 1:\n" );
    imprime_Fila ( f1 );

    printf ( "\n\n\nFila 2:\n" );
    imprime_Fila ( f2 );

    printf ( "\n\n\nFila 3:\n" );
    FilaCrescente ( f1, f2, f3 );
    
    libera_Fila( f1 );
    libera_Fila( f2 );
    libera_Fila ( f3 );

    return 0;

}


