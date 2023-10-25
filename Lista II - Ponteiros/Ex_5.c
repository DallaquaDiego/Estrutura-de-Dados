/* Após a alocação dinâmica dos ponteiros, e a leitura dos valores do vetor A, é criada uma variável 'maior' na 
função 'inverte_vetor' que recebe o valor da primeira posição aonde o ponteiro aponta, em seguida, dentro de um loop,
ocorre um caso de teste onde o valor da variável 'maior' é comparado com o p´roximo elemento para onde o vetor aponta,
caso o próximo elemento seja maior que o valor da variável, ele o substitui. Em seguida, é feita a inversão da ordem
dos elementos do vetor A e a gravação do vetor B, onde um elemento do começo do vetor A é gravado no final do vetor B*/

#include <stdio.h>
#include <stdlib.h>

int inverte_vetor ( int *vetor_a, int *vetor_b, int tam ) {
    
    int i, maior = *vetor_a;

    for ( i = 0; i < tam; i ++ ) {

        if ( *(vetor_a + i) > maior ) {

            maior = *(vetor_a + i);

        }

        *(vetor_b + (tam - i - 1)) = *(vetor_a + i);

    }

    return maior;

}


int main () { 

    int *vetor_a, *vetor_b, tam, cont;

    printf( "\nInsira o tamanho dos vetores: " );
    scanf( "%d", &tam );

    vetor_a = (int*) malloc ( tam * sizeof (int));
    vetor_b = (int*) malloc ( tam * sizeof (int));

    for ( cont = 0; cont < tam; cont ++ ) {

        printf ( "\nInsira o elemento %d do vetor A: ", cont );
        scanf ( "%d", (vetor_a + cont) );

    }

    printf ( "\nO maior valor do vetor A eh: %d", inverte_vetor ( vetor_a, vetor_b, tam ) );


    printf ( "\nVetor A: " );
    for ( cont = 0; cont < tam; cont ++ ) {

        printf ( "%d ", *(vetor_a + cont) );
        
    }

    printf ( "\nVetor B: " );
    for ( cont = 0; cont < tam; cont ++ ) {

        printf ( "%d ", *(vetor_b + cont) );
        
    }

    free (vetor_a); 
    free (vetor_b);

    return 0;

}