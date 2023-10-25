/* O caso base da função é quando Y = 0, onde a função retorna o valor de X. Caso contrário, a função retornará
a sí mesma, tendo como parâmetros o valor de Y e o resto da divisão de X por Y. */

#include <stdio.h>

int mdc ( int x, int y ) {
    if ( y == 0 ) {

        return x;

    } else {

        return mdc ( y, x % y );

    }

}

int main () {

    int x, y; 

    printf( "\nInsira o valor de X: " );
    scanf( "%d", &x );

    printf( "\nInsira o valor de Y: " );
    scanf( "%d", &y );

    printf( "\nO resultado do MDC entre %d e %d e igual a %d!", x, y, mdc ( x, y ) );

    return 0;

}