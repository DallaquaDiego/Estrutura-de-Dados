int insere_ArvAVL(ArvAVL *raiz, int valor){
    int res;
   
    if(*raiz == NULL){ //verifica se a árvore tá vazia ou se chegou a uma folha
       
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO)); // aloca um novo nó
        if(novo == NULL) //se o nó novo for nulo, retorna 0
            return 0;

       
        novo->info = valor; //inicializa o novo nó com o valor passado
        novo->altura = 0; //deixa a altura desse novo nó em 0
        novo->esq = NULL;//atualiza a raiz para apontar pro novo nó
        novo->dir = NULL;
        
        *raiz = novo; //faz o ponteiro raiz apontar para o nó novo
        return 1;
    }
    
struct NO *atual = *raiz; //se a árvore não estiver vazia vai realiza a inserção
    if(valor < atual->info){
        
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1){    //insere na subárvore da esquerda
            
            if(fatorBalanceamento_NO(atual) >= 2){  //verifica se vai ser preciso fazer rotações pra balancear a árvore

                if(valor < (*raiz)->esq->info ){ //verifica ser via ser preciso fazer uma rotação LL ou LR dependendo do tam do valor 
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else{
        if(valor > atual->info){ 
            
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1){   //insere na subárvore direita
            
                if(fatorBalanceamento_NO(atual) >= 2){ //verifica se vai ser preciso fazer rotações pra balancear a árvore

                    if((*raiz)->dir->info < valor){ //verifica ser via ser preciso fazer uma rotação RR ou RL dependendo do tam do valor 
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            //caso contrário, vai imprimir isso caso o valor seja duplicado
            printf("Valor duplicado!!\n");
            return 0;
        }
    }
    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;  //atualiza a altura do nó atual

    return res;
}
