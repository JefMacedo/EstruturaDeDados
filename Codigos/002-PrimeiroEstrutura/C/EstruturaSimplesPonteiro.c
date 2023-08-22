#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h> // A biblioteca malloc estava falhando no MacOs, aparentemente não tem suporte ao OS, por esse motivo foi a biblioteca stdlib que contém a biblioteca malloc
#define alturaMaxima 225

typedef struct {
    int peso;
    int altura;
} PesoAltura;

int main() {
    PesoAltura* pessoa1 = (PesoAltura*) malloc(sizeof(PesoAltura));
    pessoa1->peso = 80;
    pessoa1->altura = 185;

    printf("Peso: %i, Altura: %i. ", pessoa1->peso, pessoa1->altura);

    if(pessoa1->peso > alturaMaxima) printf("Altura acima da máxima.\n");
    else printf("Altura abaixo da máxima.\n");
    
    return 0;
}