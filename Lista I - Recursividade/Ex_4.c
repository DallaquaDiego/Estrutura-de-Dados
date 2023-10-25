/* Sempre que a função se repetir, o expoente será reduzido em 1 e o valor de k será multiplicado por ele mesmo, 
até que ele chegue em 0, quando a função retornará 1 de acordo com o caso base */

#include <stdio.h>

int poten ( int k, int n ) {

    if ( n == 0 ){

        return 1;

    }else {

        return k * poten(k, n - 1);

    }
}

int main () {

    int k, n, resultado;

    printf ( "\nInsira o numero: " );
    scanf ( "%d", &k );

    printf ( "\nInsira um expoente: ");
    scanf ( "%d", &n );

    resultado = poten(k, n);
    printf ( "\nResultado: %d", resultado);

    return 0;
    
}