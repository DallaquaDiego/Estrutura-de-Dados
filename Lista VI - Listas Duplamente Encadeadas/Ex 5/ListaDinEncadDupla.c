#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h" //inclui os Prot�tipos

struct nodesc {

 struct fila *ini;
 struct fila *fim;

};

typedef struct nodesc noDesc;


struct fila {

 int info;
 struct fila *prox;
 struct fila *ant;

};

typedef struct fila Fila;

int inicializa_noDesc ( noDesc *no ) {


    no = ( noDesc* ) malloc( sizeof ( noDesc ) );

    if( !no ) {

        return 0;

    }

    else {
        
        no -> ini = NULL;
        no -> fim = NULL;

        return 1;

    }

}


int enfileirar ( noDesc *n, int elem ) {

    if( n == NULL ) {

        return 0;

    }

    Fila *fila = malloc (sizeof(Fila));

    fila -> info = elem;
    fila -> prox = NULL;
    fila -> ant = NULL;

    if( n -> ini == NULL ) {

        n -> ini = fila;
        n -> fim = fila;

    } else { 

        n -> fim -> prox = fila;
        fila -> ant = n -> fim;
        n -> fim = fila;

    }

    return 1;

}

int desenfileirar (noDesc *n, int *elem) {

    if(n->ini == NULL) {

        return 0;

    }

    Fila *aux = n -> ini;

    *elem = n -> ini -> info;
    n -> ini = n -> ini -> prox;

    if ( n -> ini == n -> fim ) {

        free(aux);
        
        n -> ini = NULL;
        n -> fim = NULL;

    }

    return 1;

}