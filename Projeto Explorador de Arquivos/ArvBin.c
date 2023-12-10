#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct aVar {
    char dados [255];
    struct aVar *pai;//Fala com o pai;
    struct aVar *filho;
    struct aVar *irmao;
};
typedef struct aVar AvVar;


AvVar* criaAvVar ( char* c ) {

    AvVar *a = (  AvVar * ) malloc ( sizeof ( AvVar ) );
    
    strcpy (a -> dados, c );
    a -> filho = NULL;
    a -> irmao = NULL;
    a -> pai  = NULL;

    return a;

}


AvVar *cd ( AvVar *raiz, const char* no ) {

    if ( raiz == NULL ) {

        return NULL;

    }

    if ( strcmp ( raiz -> dados, no ) == 0 ) {

        // Se encontrou o nó desejado, retorna o nó
        return raiz;

    }


    AvVar *resultFilho = cd ( raiz -> filho, no );

    if ( resultFilho != NULL ) {

        return resultFilho;

    }

    AvVar *resultIrmao = cd ( raiz -> irmao, no );

    if ( resultIrmao != NULL ) {

        return resultIrmao;

    }

    return NULL;

}


void findAvVar ( AvVar* raiz, const char* no) {

    if ( raiz == NULL ) {

        return;

    }

    if ( strcmp ( raiz -> dados, no ) == 0 ) {

        // Mostra o nó encontrado
        printf ( "%s/", raiz -> dados );

        // Mostra os pais
        AvVar *pai = raiz -> pai;

        while ( pai != NULL ) {

            printf ( "%s/", pai -> dados);
            pai = pai -> pai;

        }

        return;
    }

    // Procura recursivamente nos filhos e irmãos
    findAvVar ( raiz -> filho, no );
    findAvVar ( raiz -> irmao, no );
    
}


void menu() {

    printf ( "-----------------------------------------------------\n" );
    printf ( "-----------------------MENU--------------------------\n" );
    printf ( "cd     -  Entrar no Diretorio\n" );
    printf ( "find   -  Procurar um Arquivo\n" );
    printf ( "rm     -  Remover um Arquivo\n" );
    printf ( "list   -  Listar os Arquivos\n" );
    printf ( "mkdir  -  Criar Diretorio\n" );
    printf ( "clear  -  Limpar a Tela\n" );
    printf ( "help   -  Lista todos os Comandos\n" );
    printf ( "exit\n" );
    printf  ("-----------------------------------------------------\n" );

}

void help() {

    printf ( "-----------------------------------------------------\n" );
    printf ( "-----------------------HELP--------------------------\n" );
    printf ( "cd     -  Entrar no Diretorio\n" );
    printf ( "find   -  Procurar um Arquivo\n" );
    printf ( "rm     -  Remover um Arquivo\n" );
    printf ( "list   -  Listar os Arquivos\n" );
    printf ( "mkdir  -  Criar Diretorio\n" );
    printf ( "clear  -  Limpar a Tela\n" );
    printf ( "help   -  Lista todos os Comandos\n" );
    printf ( "exit\n" );
    printf  ("-----------------------------------------------------\n" );
    
}


int readAvVar ( char* linha, char* primeiro, char* segundo, char* terceiro ) {
    
    // Inicialize os vetores para garantir que eles estão vazios
    memset ( primeiro, 0, sizeof ( primeiro ) );
    memset ( segundo, 0, sizeof ( segundo ) );
    memset ( terceiro, 0, sizeof ( terceiro ) );
    
    // Use strtok para dividir a string em tokens
    char *token = strtok ( linha, "/" );
    strcpy ( primeiro, token );

    token = strtok ( NULL, "/" );
    strcpy ( segundo, token );

    // Continue a dividir até o final, para pegar o que está depois da última '/'
    while ( token != NULL ) {
        strcpy ( terceiro, token );
        token = strtok ( NULL, "/" );
    }

    // Imprima os resultados
    printf ( "Antes da barra: %s\n", primeiro );
    printf ( "Entre barras: %s\n", segundo );
    printf ( "Depois da última barra: %s\n", terceiro );
    printf ( "\n\n" );

    return 1;


}


int insereAvVar ( AvVar* raiz, char* primeiro, char* segundo, char* terceiro) {

    if (raiz == NULL) {

        return 0;

    }

    if ( raiz -> filho == NULL ) {

        AvVar *novo = criaAvVar ( primeiro );
        novo -> pai = raiz;
        raiz -> filho = novo;

        AvVar* aux = novo;

        if ( aux -> filho == NULL ) {

            AvVar *novo2 = criaAvVar ( segundo );
            novo2 -> pai = aux;
            aux -> filho = novo2;
            novo2 -> irmao = NULL;

        }

        if ( strcmp ( segundo, terceiro ) == 0 ) {

            printf ( "\n" );

        } // colocar como terceiro na primeira iteração

    } else {

        AvVar *aux1 = raiz -> filho;

        while ( aux1 != NULL ) {

            if ( strcmp ( primeiro, aux1 -> dados) == 0) {

                AvVar *aux2 = aux1 -> filho;

                while ( aux2 != NULL ) {

                    if ( strcmp ( segundo, aux2 -> dados ) == 0 ) {

                        AvVar *aux3 = aux2 -> filho;

                        while ( aux3 != NULL ) {

                            if ( strcmp ( terceiro, aux3 -> dados ) == 0) {

                                printf( " Elemento já adicionado " );
                                // return 0;
                            } else if ( aux3 -> irmao != NULL ) {

                                aux3 = aux3 -> irmao;

                            } else {

                                AvVar *novoTerceiro = criaAvVar ( terceiro );
                                aux3 -> irmao = novoTerceiro;
                                novoTerceiro -> pai = aux2;
                                novoTerceiro -> irmao = NULL;
                                novoTerceiro -> filho = NULL;
                                return 1;
                            }
                        }

                        if ( aux2 -> filho == NULL ) {

                            AvVar *novoTerceiro = criaAvVar ( terceiro );

                            novoTerceiro -> pai = aux2;
                            aux2 -> filho = novoTerceiro;
                            novoTerceiro -> irmao = NULL;
                            novoTerceiro -> filho = NULL;

                        }

                        if ( strcmp ( segundo, terceiro ) == 0 ) {

                            return 1;

                        }

                    } else if ( aux2 -> irmao != NULL ) {

                        aux2 = aux2 -> irmao;

                    } else {

                        AvVar *novoSegundo = criaAvVar ( segundo );

                        aux2 -> irmao = novoSegundo;
                        novoSegundo -> pai = aux1;
                        novoSegundo -> irmao = NULL;
                        novoSegundo -> filho = NULL;
                    }
                }

                if ( aux1 -> filho == NULL ) {

                    AvVar *novoSegundo = criaAvVar ( segundo );
                    novoSegundo -> pai = aux1;
                    aux1 -> filho = novoSegundo;
                    novoSegundo -> irmao = NULL;
                }

            } else if ( aux1 -> irmao != NULL ) {

                aux1 = aux1 -> irmao;

            } else {

                AvVar *novoPrimeiro = criaAvVar ( primeiro );

                aux1 -> irmao = novoPrimeiro;
                novoPrimeiro -> pai = raiz;
                novoPrimeiro -> irmao = NULL;

            }
        }
    }

    return 0; // Função terminou sem problemas

}


int readArqTXT ( char* arq, AvVar *raiz ) {

    FILE *file = fopen ( arq, "r" );


    if ( file == NULL ) {

        perror ( "Erro ao abrir o arquivo" );
        return 1;

    }

    // Ler a linha do arquivo
    char linha[200]; // Ajuste o tamanho conforme necessário

    char primeiro[200];
    char segundo[200];
    char terceiro[200];

    while ( !feof ( file ) ) {

        if ( fscanf ( file, "%[^\n]\n", linha ) ) {

            printf ( "%s\n", linha );
            readAvVar ( linha, primeiro, segundo, terceiro );
            insereAvVar ( raiz, primeiro, segundo, terceiro );

        }
    }

    fclose ( file );
    
}


int Herbicida ( AvVar *raiz ) {

    if ( raiz == NULL ) {

        return 0;

    }
    
    AvVar *aux = raiz -> filho;
    AvVar *ant = raiz;

    while ( aux != NULL ) {

        if ( aux -> filho != NULL ) {

            ant = aux;
            aux = aux -> filho;
                
        } else {

            if ( aux -> irmao != NULL ) {

                ant = aux;
                aux = aux -> irmao;

            } else {

                AvVar *rem = aux;

                if ( ant -> filho -> dados == aux -> dados ) {

                    ant -> filho = NULL;
                    aux = raiz -> filho;
                    ant = raiz;
                    free ( rem );

                } else {

                    aux = raiz -> filho;
                    ant -> irmao = NULL;
                    ant = raiz;
                    free ( rem );
                }
            }
        }
    }
    // free(ant);
    // free(aux);
    free ( raiz );
    return 1;

}


int listAvVar ( AvVar *aux, AvVar *xua ) {  

    if ( aux != NULL ) {

        printf ( "%s\n", aux -> dados );
        listAvVar ( ( aux -> filho ), xua );

        if ( aux -> dados == xua -> dados ) {

            return 0;

        }

        listAvVar ( ( aux -> irmao ), xua );

    }

    return 1;

}


int mkdir ( AvVar *raiz, const char* arg ) {

    if ( raiz == NULL ) {

        return 0;

    }

    // Alocar espaço dinamicamente para a string arg
    char* novoDir = ( char* ) malloc ( strlen ( arg ) + 1 );

    strcpy( novoDir, arg );

    if ( raiz -> filho != NULL ) {

        AvVar *aux = raiz -> filho;

        // Encontrar o último irmão
        while ( aux -> irmao != NULL ) {

            aux = aux -> irmao;

        }

        AvVar *novo = criaAvVar ( novoDir );

        aux -> irmao = novo;
        novo -> pai = raiz;
        novo -> irmao = NULL;
        novo -> filho = NULL;

    } else {

        // Se raiz não tiver filhos, criar o primeiro filho
        AvVar *novo = criaAvVar ( novoDir );

        raiz -> filho = novo;
        novo -> pai = raiz;
        novo -> irmao = NULL;
        novo -> filho = NULL;

    }

    // Liberar a memória alocada dinamicamente
    free ( novoDir );

    return 1;

}


int rm ( AvVar *raiz ) {

    if( raiz == NULL ) {

        return 0;

    }

    AvVar *aux = raiz -> pai;

    aux = aux -> filho;

    if( aux -> filho != raiz ) {

        while ( aux -> irmao != raiz ) {

        aux = aux->irmao;

        }

        aux -> irmao = raiz -> irmao;

    } else {

        raiz -> pai -> filho = aux -> irmao;

    }

    Herbicida ( raiz );

}
