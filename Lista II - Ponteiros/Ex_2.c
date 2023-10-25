int main() {

    int y, *p, x;

    y = 0;          // Atribui o valor 0 à variável 'y'. y = 0.
    p = &y;         // O ponteiro P recebe o endereço de memória da variável 'y'. p = &y; y = 0.
    x = *p;         // A variável x recebe o valor apontado por 'p'. x = 0; y = 0; p = &y.
    x = 4;          // Atribui o valor 4 à variável 'x'. x = 4.
    (*p)++;         // Incrementa o valor apontado por 'p' em em 1. p = &y; y = 1.
    x--;            // Decrementa o valor de 'x' em 1. x = 3.
    (*p) += x;      // Incrementa o valor de 'x' à variável apontada por 'p'. y = 4.

    printf ("y = %d\n", y);

    return(0);

}