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

    for(int i = 0; i < tam; i++){

        for(int j = 0; j < tam; j++){

            scanf("%d", &mat[i][j]);
        }
    }    
}

int evoluirReticulado(int **mat, int tam){

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){

            //Casos especiais

                //diagonal 1    
                if(mat[0][0] == 1){
                    
                    if((mat[0][1] == 0 && mat[1][0] == 0) || (mat[0][1] == 0 && mat[1][1] == 0) || 
                    (mat[1][0] == 0 && mat[1][1] == 0))
                        mat[0][0] = 0;
                }

                    //renascimento
                    else if(mat[0][0] == 0){

                        if(mat[0][1] == 1 && mat[1][1] == 1 && mat[1][0] == 1)
                            mat[0][0] = 1;
                    }

                //diagonal 2
                if(mat[0][tam] == 1){
                    
                    

                }

                    //renascimento
                    else if(mat[0][tam] == 0){
                        
                        if(mat[0][tam-1] == 1 && mat[1][tam-1] == 1 && mat[1][tam] == 1)
                            mat[0][tam] = 1;
                    }
                
                //diagonal 3
                if(mat[tam][0] == 1){

                }
                    //renascimento
                    else if(mat[tam][0] == 0){

                        if(mat[tam-1][0] == 1 && mat[tam-1][1] == 1 && mat[tam][1] == 1)
                            mat[tam][0] = 1;
                    }

                //diagonal 4    
                if(mat[tam][tam] == 1){


                }
                    //renascimento
                    else if(mat[tam][tam] == 0){

                        if(mat[tam][tam-1] == 1 && mat[tam-1][tam-1] == 1 && mat[tam][tam-1] == 1)
                            mat[tam][tam] = 1;
                    }

        }
    }

}

void imprimeReticulado(int **mat, int tam){

    for(int i = 0; i < tam; i++){

        for(int j = 0; j < tam; j++){

            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    
}

