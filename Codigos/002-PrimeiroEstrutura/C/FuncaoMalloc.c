#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h> // A biblioteca malloc estava falhando no MacOs, aparentemente não tem suporte ao OS, por esse motivo foi a biblioteca stdlib que contém a biblioteca malloc

int main() {
    int* y = (int*) malloc(sizeof(int));
    *y = 20;
    int z = sizeof(int);

    printf("*y = %i z = %i\n", *y, z);
    return 0;
}