#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.c"

int main () {

    int N = 8, dados[8] = { 50,100,30,20,40,45,35,37 };

    ArvBin* raiz = cria_ArvBin();
    ArvBin* raiz2 = cria_ArvBin();

    int i;

    for( i = 0; i < N; i++ ) {

        insere_ArvBin ( raiz, dados[i] );
        insere_ArvBin ( raiz2, dados[i] );

    }

    preOrdem_ArvBin ( raiz );
    preOrdem_ArvBin ( raiz2 );

    ArvBin_Iguais ( raiz, raiz2 );

    libera_ArvBin ( raiz );
    libera_ArvBin ( raiz2 );
    
    printf ( "\n\nFim!\n" );
    
    return 0;

}
