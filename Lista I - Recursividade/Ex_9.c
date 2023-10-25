/* A função recursiva pega o número ímpar digitado pelo usuário, e o multiplica por ele mesmo com um decréscimo de 
2 unidades, esse processo se repete até que o número lido chegue em 0, onde a função retorna 1 */

#include <stdio.h>

int fat_duplo( int num ) {
    if ( num <= 0 ) {

        return 1;

    } else {

        return num * fat_duplo ( num - 2 );

    }
}

int main () {

    int num, resposta;

    do {

        printf( "\nInsira um numero Impar: " );
        scanf( "%d", &num );

    } while ( num % 2 != 1 );

    resposta = fat_duplo( num );

    printf ( "\nA resposta e: %d", resposta );

    return 0;

}