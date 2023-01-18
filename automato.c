#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "automato.h"

int **alocarReticulado(int tam){

    int **mat;

    mat = malloc(tam * sizeof(int*));

    for(int i = 0; i < tam; i++)
        mat[i] = malloc(tam * sizeof(int));

    return mat;
        
}

void desalocarReticulado(int ***mat, int tam){

    for(int i = 0; i < tam; i++)
        free((*mat)[i]);
    
    free(*mat);
}

void LeituraReticulado(int **mat, int tam){

    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            scanf("%d", &mat[i][j]);   
}

void evoluirReticulado(int **mat1, int tam){

    int **mat2 = alocarReticulado(tam);
    
    mat2 = mat1;

    /* for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            mat2[i][j] = 0;
        }
    } */
    //Bordas
    
    int vivas = 0;

        //Borda de cima

        for(int j = 1; j < tam - 1; j++)
            if(mat1[1][j-1] == 1 && mat1[1][j] == 1 && mat1[1][j+1] == 1)
                mat2[0][j] = 1;

        //Borda esquerda

        for(int i = 1; i < tam - 1; i++)
            if(mat1[i-1][1] == 1 && mat1[i][1] == 1 && mat1[i+1][1] == 1)
                mat2[i][0] = 1;

        //Borda direita

        for(int i = 1; i < tam - 1; i++)
            if(mat1[i-1][tam-2] == 1 && mat1[i][tam-2] == 1 && mat1[i+1][tam-2] == 1)
                mat2[i][tam-1] = 1;

        //Borda de baixo

         for(int j = 1; j < tam - 1; j++)
            if(mat1[tam-2][j-1] == 1 && mat1[tam-2][j] == 1 && mat1[tam-2][j+1] == 1)
                mat2[tam-1][j] = 1;
    
     printf("Matriz 1: \n");
    imprimeReticulado(mat1, tam);

    printf("\n\nMatriz 2: \n");
    imprimeReticulado(mat2, tam);

    //Centro completo

        for(int i = 1; i < tam - 1; i++){
            for(int j = 1; j < tam - 1; j++){
                
                vivas = 0;
                //Contador de célular vivas em volta do automato atual

                    //Linha de cima

                    for(int col1 = j-1; col1 <= j+1; col1++)
                        if(mat1[i-1][col1] == 1)
                            vivas++;

                    //Lado esquerdo

                    if(mat1[i][j-1] == 1)
                        vivas++;

                    //Lado direito

                    if(mat1[i][j+1] == 1)
                        vivas++;
                    
                    //Linha de baixo

                    for(int col3 = j-1; col3 <= j+1; col3++)
                        if(mat1[i+1][col3] == 1)
                            vivas++;
                
                //Casos

                    //Sufocamento

                    if(vivas > 3)
                        mat2[i][j] = 0;
                    
                    //Solidao

                    if(vivas < 2)
                        mat2[i][j] = 0;

                    //Renascimento
                    
                    if(vivas == 3)
                        mat2[i][j] = 1;
            }
        } 

    printf("Matriz 1: \n");
    imprimeReticulado(mat1, tam);

    printf("\n\nMatriz 2: \n");
    imprimeReticulado(mat2, tam);


    mat1 = mat2;

    desalocarReticulado(&mat2, tam);
}

void imprimeReticulado(int **mat, int tam){

    printf("\n");
    for(int i = 0; i < tam; i++){

        for(int j = 0; j < tam; j++){

            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    
}

