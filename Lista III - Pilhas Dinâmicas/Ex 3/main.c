#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.c"

int main() {
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};

    Pilha *pi = cria_Pilha();       // Cria a pilha 1
    Pilha *pi2 = cria_Pilha();      // Cria a pilha 2

    int i;
    
    for(i=0; i < 4; i++) {

        insere_Pilha ( pi, a[i] );      // Insere os elementos na Pilha 1

    }

    imprime_Pilha ( pi );               
    printf( "Tamanho da PI: %d\n\n\n\n",tamanho_Pilha ( pi ) );         

    pi2 = PilhaCopia( pi );             // Copia a pilha PI em PI2
    
    imprime_Pilha(pi2);
    printf( "Tamanho da PI2: %d\n\n\n\n",tamanho_Pilha ( pi2 ) );

    libera_Pilha(pi);                   // Libera a pilha PI
    libera_Pilha(pi2);                  // Libera a pilha PI2
    
    system("pause");
    
    return 0;

}

