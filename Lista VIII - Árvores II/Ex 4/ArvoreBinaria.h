typedef struct NO* ArvBin;

ArvBin* cria_ArvBin ( );

struct NO* remove_atual ( struct NO* atual );

void libera_ArvBin ( ArvBin *raiz );
void preOrdem_ArvBin ( ArvBin *raiz );

int estaVazia_ArvBin ( ArvBin *raiz );
int altura_ArvBin ( ArvBin *raiz );
int totalNO_ArvBin ( ArvBin *raiz );
int consulta_ArvBin ( ArvBin *raiz, int valor );
int insere_ArvBin ( ArvBin* raiz, int valor );
int remove_ArvBin ( ArvBin *raiz, int valor );
int imprime_folhas_decrescente ( ArvBin *raiz );