#include <stdio.h>
#include "automato.h"

int main(){

    int Tamanho, **Matriz;

    scanf("%d", &Tamanho);
    Matriz = alocarReticulado(Tamanho);
    LeituraReticulado(Matriz, Tamanho);
    Matriz = evoluirReticulado(Matriz, Tamanho);
    imprimeReticulado(Matriz, Tamanho);
    desalocarReticulado(&Matriz, Tamanho);
    
    return 0;
}