int remove_ArvAVL(ArvAVL *raiz, int valor){


    if(*raiz == NULL){  //a árvore estiver vazia, retorna 0
        printf("Valor não existe!!\n"); 
        return 0;
    }

    int res; //inicializa res   
    if(valor < (*raiz)->info){  //se o valor é menor que o valor do nó atual, a remoção vai ser feitana ana subárvore da esquerda
        
        if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1){
            
            if(fatorBalanceamento_NO(*raiz) >= 2){  //verifica se vai ser preciso fazer rotações pra balancear a árvore dps da remoção
                /
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir)) 
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
        }
    }

    if((*raiz)->info < valor){ //se o valor é maior que o valor do nó atual, a remoção vai ser feitana ana subárvore da direita

        if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){
           
            if(fatorBalanceamento_NO(*raiz) >= 2){ //verifica se vai ser preciso fazer rotações pra balancear a árvore dps da remoção 
                
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) ) //verifica ser via ser preciso fazer uma rotação LL ou LR dependendo do tam do valor
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
    }

    if((*raiz)->info == valor){ //se o valor é igual ao valor do nó atual, encontrou o nó a ser removido
       
        if((*raiz)->esq == NULL || (*raiz)->dir == NULL){//se o nó tem 1 filho ou nenhum, realiza a remoção direto
            
            struct NO *oldNode = (*raiz);
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(oldNode);
        }else {  //se o nó tem 2 filhos, encontra o menor nó na subárvore direita e o substitui
           
            struct NO* temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);

            if(fatorBalanceamento_NO(*raiz) >= 2){ //verifica se vai ser preciso fazer rotações pra balancear a árvore dps da remoção 

                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq)) //verifica ser via ser preciso fazer uma rotação LL ou LR dependendo do tam do valor
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
      
        if (*raiz != NULL)  //atualiza a altura do nó atual
            (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
        return 1;
    }

    (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1; //atualiza a altura do nó atual

    return res;
}
