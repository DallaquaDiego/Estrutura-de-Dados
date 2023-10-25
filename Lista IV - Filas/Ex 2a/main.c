#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.c"

int main() {

    struct aluno al,a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}
    };

    // Cria a fila mestre
    FilaMestre *fm = cria_FilaMestre();

    // Cria a fila fi e a fila fi2
    Fila* fi = cria_Fila();
    Fila *fi2 = cria_Fila();

    int i;

    // Preenche e imprime fi
    for ( i = 0; i < 4; i++ ) {

        insere_Fila( fi, a[i] );

        if ( Fila_vazia( fi ) ) {

            printf( "Erro!!!!!!\n" );

        }

    }

    imprime_Fila(fi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
     
    // Preenche e imprime fi2
    for ( i = 0; i < 4; i++ ) {

        insere_Fila( fi2, a[i] );

        if ( Fila_vazia( fi2 ) ) {

            printf( "Erro!!!!!!\n" );

        }

    }

    imprime_Fila( fi2 );
    printf( "Tamanho: %d\n\n\n\n",tamanho_Fila(fi2) );

    insere_FilaMestre(fm, fi);
    insere_FilaMestre(fm, fi2);

    imprime_FilaMestre(fm);
    
    libera_Fila(fi);

    return 0;

}


