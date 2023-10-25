/* O caso base é quando o número digitado é 0, nesse caso o programa retorna 0. Quando isso não ocorre, a 
função pega o resto da divisão do número digitado por 10, obtendo o ultimo algarismo desse número, em seguida
ela imprime esse número obtido e chama a função novamente, tendo como parâmatro o número que o úsuário digitou
dividido por 10, como o tipo da variável é inteiro, os algarismos após a vírgula serão ignorados */

#include <stdio.h>

int inverter ( int num ) {

    if ( num == 0 ) {

        return 0;

    } else {

        printf( "%d", num % 10 );

        return inverter( num / 10 );

    }
}

int main () {

    int num;

    printf( "\nInsira um numero: " );
    scanf( "%d", &num );

    inverter ( num );

    return 0;

}