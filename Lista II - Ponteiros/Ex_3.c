#include <stdio.h>

int main() {

    int x, *p, **q;

    p = &x;
    q = &p;
    x = 10;

    printf("\n%d\n", **q);          /* Ao trocar o '&' por '**', o valor impresso deixa de ser o endereço para onde 
o ponteiro aponta e passa a ser o valor armazenado naquele endereço */

    return(0);
    
}