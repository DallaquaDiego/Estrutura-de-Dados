//Arquivo ListaDinEncadDupla.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

int inicializa_noDesc ( noDesc *no );
int enfileirar ( noDesc *n, int elem );
int desenfileirar (noDesc *n, int *elem);
