#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.c"

int main() {

    struct aluno al, a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};

    Lista* li = cria_lista();

    int i, matricula, posicao;

    for(i=0; i < 4; i++) {

        insere_lista_ordenada(li,a[i]);

    }

    imprime_lista(li);

    printf ( "\nInsira um numero de matricula para consulta: " );
    scanf( "%d", &matricula );
    consultaListaMatricula( li, matricula, a );
    
    printf ( "\nInsira um indice para consulta: " );
    scanf( "%d", &posicao );
    consultaListaIndice ( li, posicao );

    libera_lista(li);

    return 0;

}