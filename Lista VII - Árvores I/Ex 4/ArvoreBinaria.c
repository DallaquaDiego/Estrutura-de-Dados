#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Prot�tipos

struct NO { 

    int info;
    struct NO *esq;
    struct NO *dir;

};


ArvBin* cria_ArvBin ( ) {

    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));

    if ( raiz != NULL ) {

        *raiz = NULL;

    }

    return raiz;

}


void libera_NO ( struct NO* no ) {

    if ( no == NULL ) {

        return 0;

    }

    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);

    no = NULL;

}


void libera_ArvBin(ArvBin* raiz) {

    if(raiz == NULL) {

        return 0;

    }

    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz

}


// Função de Inserir na Árvore
int insere_ArvBin ( ArvBin* raiz, int valor ) {
    
    // Verifica se a árvore que foi passada como parâmetro existe
    if ( raiz == NULL ) {

        return 0;

    }

    // Cria o novo nó e realiza a alocação do mesmo
    struct NO* novo;
    novo = ( struct NO* ) malloc ( sizeof ( struct NO ) );

    // Verifica se o novo nó realmente foi criado
    if ( novo == NULL ) {

        return 0;

    }

    // Coloca o valor passado como parâmetro no novo nó e faz com que os ponteiros que apontam para os filhos sejam nulos
    novo -> info = valor;
    novo -> dir = NULL;
    novo -> esq = NULL;

    // Caso o novo nó seja o primeiro elemento da árvore, o ponteiro raiz apontará para ele
    if ( *raiz == NULL ) {

        *raiz = novo;

    // Caso contrário, cria dois ponteiros auxiliares, o atual, que aponta para o mesmo lugar que a raiz e o ant, que inicialmente aponta para NULL
    } else {

        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        
        // Percorre toda a Árvore
        while ( atual != NULL ) {

            // Ant aponta para o atual para que ele possa "andar" sem perder a localização da posição anterior
            ant = atual;

            // Caso o elemento já exista, apaga o novo nó previamente criado
            if ( valor == atual -> info ) {

                free ( novo );
                return 0;

            }

            // Caso o valor digitado seja maior do que o número armazenado aonde o ponteiro atual aponta, o ponteiro atual "anda" para a direita
            if ( valor > atual -> info ) {

                atual = atual -> dir;

            // Caso contrário, o ponteiro atual "anda" para a esquerda
            } else {

                atual = atual -> esq;

            }
        }

        /* Após achar a posição do novo nó, verifica se o valor passado como parâmetro é maior do que o valor armazenado no elemento anterior,
        caso seja, faz com que o novo nó seja o filho ã direita daquele apontado pelo ponteiro anterior */
        if ( valor > ant -> info ) {

            ant -> dir = novo;

        // Caso não seja, faz com que o novo nó seja o filho ã esquerda daquele apontado pelo ponteiro anterior */
        } else {

            ant -> esq = novo;

        }
    }

    return 1;

}


// Função de Remover na Árvore
int remove_ArvBin ( ArvBin *raiz, int valor ) {

    // Verifica se a árvore que foi passada como parâmetro existe
    if ( raiz == NULL ){

        return 0;

    }

    // Cria dois ponteiros auxiliares, o atual, que aponta para o mesmo lugar que a raiz e o ant, que inicialmente aponta para NULL
    struct NO* ant = NULL;
    struct NO* atual = *raiz;

    // Percorre a Árvore
    while ( atual != NULL ) {

        // Verifica se o valor passado como parâmetro é igual ao armazenado no elemento apontado pelo ponteiro atual
        if ( valor == atual -> info ) {

            // Verifica se a Árvore possui apenas 1 elemento
            if ( atual == *raiz ) {
                
                // Caso possuir, remove aquele elemento e faz com que o ponteiro raiz aponte para NULL
                *raiz = remove_atual ( atual );

            // Caso possuir mais de 1 elemento
            } else {
                
                // Se o atual for o filho ã direita do elemento anterior, remove ele
                if ( ant -> dir == atual ) {

                    ant -> dir = remove_atual ( atual );

                // Caso contrário, remove o filho à esquerda
                } else {

                    ant -> esq = remove_atual ( atual );

                }
            }

            return 1;

        }

        // Caso o valor armazenado em atual não seja igual ao valor passado como parâmetro, faz com que ant aponte para o mesmo elemento de atual
        ant = atual;

        // Caso o valor passado como parâmetro seja maior do que o armazenado em atual, o ponteiro atual "anda" para a direita
        if ( valor > atual -> info ) {

            atual = atual -> dir;

        // Caso contrário, o ponteiro atual "anda" para a esquerda
        } else {

            atual = atual->esq;

        }
    }

    return 0;

}


int estaVazia_ArvBin ( ArvBin *raiz ) {

    if ( raiz == NULL || *raiz == NULL ) {

        return 1;

    }
}


struct NO* remove_atual ( struct NO* atual ) {

    struct NO *no1, *no2;

    if( atual -> esq == NULL ) {

        no2 = atual -> dir;
        free ( atual );

        return no2;

    }

    no1 = atual;
    no2 = atual -> esq;

    while ( no2 -> dir != NULL ) {

        no1 = no2;
        no2 = no2 -> dir;

    }

    // no2 � o n� anterior a r na ordem e-r-d
    // no1 � o pai de no2
    if ( no1 != atual ) {

        no1 -> dir = no2 -> esq;
        no2 -> esq = atual -> esq;

    }

    no2 -> dir = atual -> dir;

    free ( atual );

    return no2;

}


int altura_ArvBin ( ArvBin *raiz ) {

    if (raiz == NULL || *raiz == NULL ) {

        return 0;

    }

    int alt_esq = altura_ArvBin ( & ( ( *raiz ) -> esq ) );
    int alt_dir = altura_ArvBin ( & ( ( *raiz ) -> dir ) );

    if (alt_esq > alt_dir) {

        return ( alt_esq + 1 );

    } else {

        return ( alt_dir + 1 );

    }
}


void preOrdem_ArvBin ( ArvBin *raiz ) {
    if ( raiz == NULL ) {

        return 0;

    }

    if ( *raiz != NULL ) {

        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));

    }
}


int consulta_arvore_bin ( ArvBin *raiz, int valor ) {

    if ( raiz == NULL || *raiz == NULL ){

        return 0;

    }

    struct NO *atual = *raiz;

    while ( atual != NULL ) {

        if ( valor == atual -> info ) {

            printf ( "\n\nValor Encontrado !!!\n\n" );
            return 1;

        } else if ( valor > atual -> info ) {

            atual = atual -> dir;

        } else {

            atual = atual -> esq;

        }

    }

    return 0;
    
}

