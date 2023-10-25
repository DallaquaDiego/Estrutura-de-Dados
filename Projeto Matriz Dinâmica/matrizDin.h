struct dados {

    int conteudo;
    int linha;
    int coluna;

};

typedef struct matriz* Matriz;

Matriz* criaMatriz();
Matriz* insereMatriz ( Matriz* mat, struct dados valor );

int imprimeElemento ( Matriz *mat, int linha, int coluna, int tamanho );
int procuraElemento ( Matriz *mat, int num, int tamanho );
int ponteiroTop ( Matriz *mat, int linha, int coluna, int tamanho );
int ponteiroBot ( Matriz *mat, int linha, int coluna, int tamanho );
int imprimeVizinho ( Matriz *mat, int linha, int coluna, int tamanho );

void apagaMatriz ( Matriz* mat );
void imprimeMatriz ( Matriz* mat, int tamanho );