/* O Caso Base ocorre caso o número digitado seja 0. Caso contrário, a função soma o número digitado com o número
que a antecede ao número que foi digitado pelo usuário */

#include <stdio.h>

int soma ( int num ) {

    if ( num == 0 ){

        return 0;

    } else {

        return num + soma(num - 1);

    }
}

int main () {

    int num, resultado;

    printf ( "\nInsira o numero:" );
    scanf ( "%d", &num );

    resultado = soma(num);

    printf ( "\nResultado: %d", resultado);

    return 0;
    
}