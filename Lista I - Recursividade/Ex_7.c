/* O caso base da função recursiva é quando o número digitado for 0, onde a função retornará a variável 'cont'.
Caso contrário, a função testa se o resto da divisão do número digitado é igual ao dígito especificado, se for, 
a variável 'cont' é incrementada. Em seguida, a função retorna a si mesma, tendo como parâmetros o número digitado
dividido por 10, o dígito do usuário e o contador */

#include <stdio.h>

int contador ( int num, int digit, int cont ) {

    if ( num == 0 ) {

        return cont;
    
    } else {

        if ( num % 10 == digit ) {

            cont++;

        }

        return contador( num / 10, digit, cont );

    }
}

int main () {

    int num, digit;            

    printf( "\nInsira um numero: " );
    scanf( "%d", &num );

    printf( "\nInsira o valor de 'n': " );
    scanf( "%d", &digit );

    printf ( "\nO numero %d e repetido %d vezes no numero %d", digit, contador( num, digit, 0 ), num );

    return 0;
    
}