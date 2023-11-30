#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.c"

int main () {

    int N = 8, dados[8] = { 30,100,30,30,40,45,35,37 };

    ArvBin* raiz = cria_ArvBin();

    int i;

    for( i = 0; i < N; i++ ) {

        insere_ArvBin ( raiz, dados[i] );

    }

    preOrdem_ArvBin ( raiz );

    conta_Valor ( raiz, 30 );

    libera_ArvBin ( raiz );
    printf ( "\n\nFim!\n" );
    
    return 0;

}
