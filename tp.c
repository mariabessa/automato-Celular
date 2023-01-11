#include <stdio.h>
#include "automato.h"

int main(){

    int tam, **mat;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tam);
    mat = alocarReticulado(tam);
    LeituraReticulado(mat, tam);
    imprimeReticulado(mat, tam);
    evoluirReticulado(mat, tam);
    desalocarReticulado(&mat, tam);

    return 0;
}