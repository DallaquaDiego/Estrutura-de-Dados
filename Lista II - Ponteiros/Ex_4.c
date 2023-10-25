/* Inicialmente, o programa lê qual será o tamanho do vetor, em seguida, é realizada a alocação dinâmica do ponteiro
de acordo com o tamanho digitado pelo usuário. Por último, o programa realiza a liberação da memória posteriormente
alocada com a função 'free()'. */

#include <stdio.h>
#include <stdlib.h> 

int main () { 

    int *vetor, tamanho;

    printf( "Insira o tamanho do vetor");
    scanf ( "%d", &tamanho );

    vetor = (int*) malloc ( tamanho * sizeof (int) );

    free ( vetor );

    return 0;

}