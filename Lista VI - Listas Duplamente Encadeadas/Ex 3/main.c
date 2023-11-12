#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.c"

int main() {

    struct aluno al, a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",7.5,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};

    Lista* li = cria_lista();
  
    int i;

    for ( i=0; i < 4; i++ ) {

        insere_lista_inicio( li, a[i] );

    }

    imprime_lista ( li );

    contaNota ( li, 7.5 );

    libera_lista ( li );
   
    return 0;

}

