#include <stdio.h>
#include <stdlib.h>
#include "matrizDin.c"

void main () {

    struct dados valor;

    int contLinha, contColuna, tamanho, coluna, linha, num, menu = 0;

    Matriz *mat = criaMatriz();

    printf ( "\n\n\nInsira o tamanho da matriz: " );
    scanf ( "%d", &tamanho );

    for( contLinha = 0 ; contLinha < tamanho; contLinha ++ ) {

        for ( contColuna = 0; contColuna < tamanho; contColuna++ ) {

            ponteiroTop ( mat, contLinha, contColuna, tamanho );
            ponteiroBot ( mat, contLinha, contColuna, tamanho );

        }

    }

    do {
        
        printf( "\n\nMENU DE ACOES " );

        printf( "\n1 - Inserir Elementos da Matriz" );
        printf( "\n2 - Imprimir a Matriz" );
        printf( "\n3 - Imprimir os vizinhos de um Elemento" );
        printf( "\n4 - Imprimir um elemento pelo seu indice" );
        printf( "\n5 - Procurar um Elemento na Matriz" );
        printf( "\n6 - DELETE PERMANENTLY C:\\Windows\\System32\n" );

        printf( "\n\nChoose your fighter: " );
        scanf( "%d", &menu );
        
        switch ( menu ) {

            case 1:

                for ( contLinha = 0; contLinha < tamanho; contLinha++ ) {

                    for ( contColuna = 0; contColuna < tamanho; contColuna++ ) {

                        valor.coluna = contColuna;
                        valor.linha = contLinha;

                        printf ( "Insira o elemento que vai estar na posicao (%i)(%i): ", contLinha, contColuna );
                        scanf ( "%d", &num );

                        valor.conteudo = num;
                        insereMatriz ( mat, valor );

                    }
        
                }

            break;
            

            case 2:

                imprimeMatriz ( mat, tamanho );

            break;
            
            
            case 3:

                imprimeMatriz ( mat, tamanho );

                printf ( "Digite a linha: " );
                scanf ( "%d", &linha );
                printf ( "Digite a coluna: " );
                scanf ( "%d", &coluna );

                imprimeVizinho ( mat, linha, coluna, tamanho );

            break;
            
            case 4:

                printf ( "\Digite a linha: " );
                scanf ( " %d", &linha);

                printf ( "Digite a coluna: " );
                scanf ( " %d", &coluna );

                imprimeMatriz ( mat, tamanho );
                imprimeElemento ( mat, linha, coluna, tamanho );

            break;
            
            case 5:

                imprimeMatriz ( mat, tamanho );
                
                printf ( "Digite um numero: " );
                scanf ( "%d", &num );

                procuraElemento ( mat, num, tamanho );

            break;

            case 6: 

                apagaMatriz ( mat );

            break;
            
        }

    } while ( menu != 6 );
    
}