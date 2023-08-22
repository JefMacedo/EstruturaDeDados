#include <stdio.h>
#define alturaMaxima 225 //definido uma constate em C

typedef struct {
    int peso;       //peso em quilogramas
    int altura;     //altura em centímetros
} PesoAltura;

int main() {
    PesoAltura pessoa1;
    pessoa1.peso = 80;
    pessoa1.altura = 185;

    printf("Peso: %i, Altura: %i. ", pessoa1.peso, pessoa1.altura);

    if(pessoa1.peso > alturaMaxima) printf("Altura acima da máxima.\n");
    else printf("Altura abaixo da máxima.\n");
    
    return 0;
}