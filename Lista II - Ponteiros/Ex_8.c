/* A função main lê o qual será o tamanho do vetor, e em seguida aloca dinamicamente um vetor de estruturas do
tipo 'Produto', em seguida um loop é executado para realizar as leituras dos nomes e preços dos produtos. O programa
pede para que o usuário digite um código, em seguida um loop testa o código lido com os códigos do produto até 
encontrar o que seja igual, e imprime o valor do produto */

#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int cod;
    char nome[100];
    float preco;

} Produto;

int main () {

    int tam, consulta, cont;
    Produto *lista;

    printf( "\nInsira o tamanho da lista de produtos: " );
    scanf ( "%d", &tam );

    lista = ( Produto* ) malloc ( tam * sizeof (Produto) );

    for ( cont = 0; cont < tam; cont ++ ) {

        lista[cont].cod = cont + 1;
        printf( "\nCodigo %d", lista[cont].cod );

        printf( "\nInsira o nome do produto: " );
        scanf( " %[^\n]", lista[cont].nome );

        printf( "\nInsira o preco do produto: " );
        scanf( "%f", &lista[cont].preco );
        
    }

    printf ( "\nInsira o codigo de consulta: " );
    scanf( "%d", &consulta );

    for ( cont = 0; cont < tam; cont++ ) {

        if ( consulta == lista[cont].cod ) {

            printf ( "\nValor do Produto Consultado: %.2f ", lista[cont].preco );

        }

    }

    free ( lista );

    return 0;

}