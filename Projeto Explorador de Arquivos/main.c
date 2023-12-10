#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"ArvBin.c"

int main(){
    
    char comando[5], diretorio[20];

    AvVar *raiz = criaAvVar("C");
    AvVar *atual = NULL;

    readArqTXT ( "in.txt", raiz );

    menu();
    printf("\n");

    while ( strcmp ( comando, "exit" ) != 0 ) {

        scanf( "%s", comando);

        if ( strcmp ( comando, "help" ) == 0 ) {

            help();
            printf("\n");

        } else if ( strcmp ( comando, "cd" ) == 0) {

            scanf( "%s", diretorio);
           atual = cd ( raiz, diretorio );

            if ( atual == NULL ) {

                printf ( "Diretorio nao encontrado: %s\n", diretorio );

            }

            printf("\n");

        } else if ( strcmp ( comando, "mkdir"  ) == 0 ) {

            scanf( "%s", diretorio);
            mkdir ( atual, diretorio );
            printf("\n");

        } else if ( strcmp ( comando, "list" ) == 0) {

            if ( atual != NULL ) {

                AvVar *tes = atual; 

                listAvVar ( atual, tes );

            } else {

                printf ( "Realize o comando cd antes deste!!" );

            }

            printf("\n");

        } else if ( strcmp ( comando, "find" ) == 0 ) { 

            scanf( "%s", diretorio);
            findAvVar ( raiz, diretorio );

        } else if ( strcmp ( comando, "rm" ) == 0) {

            if ( atual != NULL ) {

                Herbicida ( atual );

            }else{ 

                printf ( "Realize o comando cd antes deste!!" );

            }

            printf("\n");

        } else if ( strcmp ( comando, "clear" ) == 0 ) {

            system ( "clear" );
            printf("\n");

        } else if ( strcmp ( comando, "exit" ) == 0 ) {

            Herbicida ( raiz );

            printf ( "Saindo." );
            break;

        }
    }

    return 0;
}
