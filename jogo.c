#include "main.c"
#include <stdio.h>
#include <stdlib.h>

char** aloca_tabuleiro(int linhas, int colunas){
  char **M = (char **) malloc(sizeof(char*) * linhas);
  if(M == NULL){
    return M;
  }
  for(int i = 0; i < linhas; i++){
    M[i] = (char *) malloc(sizeof(char) * (colunas + 1));
    if(M[i] == NULL){
      for(int j = 0; j < i; j++){
        free(M[j]);
      }
      free(M);
      M = NULL;
      return M;
    }
  }
  return M;
}

void le_tabuleiro(char **M, int lin, int col){
  for(int i = 0; i < lin; i++){
    scanf("%s", M[i]);
  }
}

void imprime_tabuleiro_jogado(char **M, int lin, int col){
  for(int i = 0; i < lin; i++){
    for(int j = 0; j < col; j++){
      if(M[i][j] == 'X'){
        printf("X");
        continue;
      }
      int vizinhos = 0;
      if(j != 0){
        if(M[i][j-1] == 'X'){
          vizinhos++;
        }
      } if(j != col - 1 && M[i][j+1] == 'X'){
        vizinhos++;
      }
      if(i != 0 && M[i-1][j] == 'X'){
        vizinhos++;
      } if(i != lin -1 && M[i+1][j] == 'X'){
        vizinhos++;
      }

      if(vizinhos % 2 == 0){
        printf("*");
      } else{
        printf(".");
      }
    }
    printf("\n");
  }
}

void libera_tabuleiro(char **M, int linhas){
  for(int i = 0; i < linhas; i++){
    free(M[i]);
    M[i] = NULL;
  }
  free(M);
  M = NULL;
}