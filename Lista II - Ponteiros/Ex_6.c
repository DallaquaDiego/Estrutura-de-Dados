/* O ponteiro 'inv' aponta para o último elemento da string, quando o loop é iniciado, o ponteiro imprime a última
posição da string, em seguida, ocorre o decréscimo do ponteiro, presente dentro do loop, e ele imprime a penúltima 
posição, etc... */

#include <stdio.h>
#include <stdlib.h>

int main () {

    char string[10] = "abcde";
    char *inv;

    int cont, tam = 10;

    inv = &string[tam - 1];

    for ( cont = 0; cont < tam; cont ++, inv-- ) {

        printf ( "%c", *inv);
        
    }
        
    return 0;

}