#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "automato.h"

int **alocarReticulado(int tamanho){

    int **matriz;
    matriz = malloc (tamanho * sizeof (int*));
    for(int i = 0; i < tamanho; i++)
        matriz[i] = malloc (tamanho * sizeof (int));
    return matriz;       
}

void desalocarReticulado(int ***matriz, int tamanho){

    for(int i = 0; i < tamanho; i++)
        free((*matriz)[i]);
    free(*matriz);
}

void LeituraReticulado(int **matriz, int tamanho){

    for(int i = 0; i < tamanho; i++)
        for(int j = 0; j < tamanho; j++)
            scanf("%d", &matriz[i][j]);   
}

int **copiaMatriz(int **matrizUm, int **matrizDois, int tamanho){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            matrizUm[i][j] = matrizDois[i][j];
        }    
    }
    return matrizUm;
}

int **evoluirReticulado(int **matrizBase, int tamanho){

    int **matrizEvoluida;
    matrizEvoluida = alocarReticulado(tamanho);
    matrizEvoluida = copiaMatriz(matrizEvoluida, matrizBase, tamanho);
 
    //Analisando a evolução nas bordas
    int vivas = 0;

    for(int i = 1; i < tamanho - 1; i++){
    //Borda de cima
        if(matrizBase[1][i-1] == 1 && matrizBase[1][i] == 1 && matrizBase[1][i+1] == 1)
            matrizEvoluida[0][i] = 1;
    //Borda esquerda
        if(matrizBase[i-1][1] == 1 && matrizBase[i][1] == 1 && matrizBase[i+1][1] == 1)
            matrizEvoluida[i][0] = 1;
    //Borda direita
        if(matrizBase[i-1][tamanho-2] == 1 && matrizBase[i][tamanho-2] == 1 && matrizBase[i+1][tamanho-2] == 1)
            matrizEvoluida[i][tamanho-1] = 1;
    //Borda de baixo
        if(matrizBase[tamanho-2][i-1] == 1 && matrizBase[tamanho-2][i] == 1 && matrizBase[tamanho-2][i+1] == 1)
            matrizEvoluida[tamanho-1][i] = 1;
    //Analisando as celulas vizinhas de cada celula do centro da matriz
            for(int j = 1; j < tamanho - 1; j++){
            
                vivas = 0;
                //Contador de células vivas em volta do automato atual

                //Linhas de cima e de baixo
                for(int coluna = j-1; coluna <= j+1; coluna++){
                    if(matrizBase[i-1][coluna] == 1)
                        vivas++;
                    if(matrizBase[i+1][coluna] == 1)
                        vivas++;
                }

                //Lado esquerdo
                if(matrizBase[i][j-1] == 1)
                    vivas++;

                //Lado direito
                if(matrizBase[i][j+1] == 1)
                    vivas++;
            
            //Casos

                //Sufocamento (mais que tres celulas vivas ao redor, a celula ira morrer)
                if(vivas > 3)
                    matrizEvoluida[i][j] = 0;
                
                //Solidao (menos que duas celulas vivas ao redor, a celula ira morrer)
                if(vivas < 2)
                    matrizEvoluida[i][j] = 0;

                //Renascimento (exatamente tres celulas vivas ao redor, ela ira renascer)
                if(vivas == 3)
                    matrizEvoluida[i][j] = 1;
                //se nenhum dos casos, a celula não se altera
            }
        }    
    matrizBase = copiaMatriz(matrizBase, matrizEvoluida, tamanho); 
    desalocarReticulado(&matrizEvoluida, tamanho);
    return matrizBase;
}

void imprimeReticulado(int **matriz, int tamanho){
   // printf("\n");
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

