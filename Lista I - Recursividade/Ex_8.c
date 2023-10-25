/* Após o usuário digitar um número par, a função recursiva imprime esse número, e após isso, a função recursiva
sempre imprimirá esse número com um decréscimo de 2 unidades, mostrando o próximo número par em ordem decrescente
até chegar em 0 */

#include <stdio.h>

int par ( int num ) {

    if (num == 0) {
        return 0;
    } else {
        printf( "%d ", num );

        return par ( num - 2 );
    }

}

int main () {

    int num;

    do {

        printf( "\nInsira um numero par: " );
        scanf( "%d", &num );

    } while ( num % 2 != 0 );

    printf( "%d", par( num ) );
   
    return 0;
}