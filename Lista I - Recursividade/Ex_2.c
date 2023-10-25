/* O caso base da função, é quando o contador 'tam' atinge o valor 0, nesse caso a função retorna 0. Senão, a função
retorna a soma do elemento do vetor em que a posição do número é igual a tam - 1 com o retorno da função soma 
novamente, dessa forma, o contador 'tam' será sempre decrementado até que ele atinja o valor 0 */

#include <stdio.h>
#include <stdlib.h>

int soma( int v[], int tam ) {

    if ( tam == 0 ) {

        return 0;

    } else {

        return v[ tam - 1 ] + soma( v, tam - 1 );

    }
}

int main() {

    int cont, tam, *v, resultado_soma;

    printf ( "\nInsira o tamanho do vetor: " );
    scanf ( "%d", &tam );

    v = (int*) malloc ( tam * sizeof (int) );

    for ( cont = 0; cont < tam; cont++ ) {

        printf ( "\nInsira um numero: " );
        scanf( "%d", &v[cont] );
        
    }

    resultado_soma = soma (v, tam);

    printf( "\nResultado: %d", resultado_soma );

    free(v);
    
    return 0;
    
}