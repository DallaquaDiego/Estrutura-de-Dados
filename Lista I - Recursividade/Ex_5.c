/* O caso base da função recursiva, é quando o contador 'start' for maior que o contador 'end', onde a função retorna
0. Enquanto a condição do caso base não for verdadeira, a função armazena o primeiro valor em uma variável auxiliar 
(aux), em seguida, ela substitui o valor dessa primeira posição, pelo valor da última posição. Após isso, a função
substitui o valor da ultima posição pelo valor da variável auxiliar. Em seguida, o processo se repete, com a variável
'start' tendo acréscimo de 1 unidade e a variável 'end' tendo decréscimo de 1 unidade */

#include <stdio.h>

int inverte( int v[], int start, int end ) {

    int aux;

    if ( start > end ) {

        return 0;
    
    } else {

        aux = v[start];
        v[start] = v[end];
        v[end] = aux;

        return inverte ( v, start + 1, end - 1 );

    }
}

int main() {

    int v[100], start = 0, end = 99, i = 0;

    for ( i = 0; i <= end; i++ ) {

        printf( "\nInsira um numero: ");
        scanf( "%d", &v[i] );

    }

    inverte ( v, start, end );

    for ( i = 0; i <= end; i++ ) {

        printf ( "%d\n", v[i] );

    }

    return 0;
    
}