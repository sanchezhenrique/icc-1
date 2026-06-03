/* Exercicio consiste em R = [(A × B) × (C × D)] × [(E × F) × (G × H)]
Utilizando alocação dinamica de memoria e modularização do codigo
*/

#include <stdio.h>
#include <stdlib.h>

int** alocarMatrizLinearmente(int linhas, int colunas);
void lerMatriz(int **ptr, int m, int n);
int** multiplicacaoMatriz(int **A, int mA, int nA, int **B, int mB, int nB);
void liberarMatriz(int **M);
void imprimirMatriz(int **M, int m, int n);
int processarMultiplicacao(
  int ***matrizes, int dimensoes[][2],
  int indiceA, int indiceB,
  int numeroResultado
  );

int main (){
  int **Matriz[8];
  int valoresMeN[8][2]; // [i] [0] = valor de M [i] [1] = valor de N

  //Leitura e alocação das Matrizes
  for(int i = 0; i < 8; i++){
    int m, n;
    scanf("%d %d", &m, &n);
    Matriz[i] = alocarMatrizLinearmente(m, n);
    if(Matriz[i] == NULL){
      printf("Erro ao alocar memoria!");
      exit(1);
    }
    lerMatriz(Matriz[i], m, n);
    valoresMeN[i][0] = m;
    valoresMeN[i][1] = n;
  }

//Primeira parte da Multiplicação AxB=[0] CxD =[2]...
  for(int i = 0; i < 8; i +=2){
    int retorno = processarMultiplicacao(Matriz, valoresMeN, i, i + 1, (i/2) +1);

    if(retorno == -1){
      for(int j = 0; j < 8; j++){
        liberarMatriz(Matriz[j]);
        Matriz[j] = NULL;
    }
      printf("Erro ao alocar memoria!");
      exit(1);
    }
  }

  // Segunda Parte da Multiplicação AxBxCxD=[0] ExFxGxH = [4]
  for(int i = 0; i < 8; i+=4){
    int retorno = processarMultiplicacao(Matriz, valoresMeN, i, i + 2, (i/4)+5);
    
    if(retorno == -1){
      for(int j = 0; j < 8; j++){
        liberarMatriz(Matriz[j]);
        Matriz[j] = NULL;
    }
      printf("Erro ao alocar memoria!");
      exit(1);
    }
  }

  //Ultima Parte
  int retorno = processarMultiplicacao(Matriz, valoresMeN, 0, 4, 7);
  if(retorno == -1){
    for(int j = 0; j < 8; j++){
        liberarMatriz(Matriz[j]);
        Matriz[j] = NULL;
    }
    printf("Erro ao alocar memoria!");
    exit(1);
  }

  if(Matriz[0] != NULL){
    liberarMatriz(Matriz[0]);
      Matriz[0] = NULL;
  }
  return 0;
}

int** alocarMatrizLinearmente(int linhas, int colunas){ //Velocidade
  int **M = (int **) malloc(linhas * sizeof(int*));
  if(M == NULL){
    return M;
  }
  int *N =(int *) malloc(linhas * colunas * sizeof(int));
  if(N == NULL){
    free(M);
    M = NULL;
    return M;
  }
  for(int i = 0; i < linhas; i++){
    M[i] = &N[i * colunas];
  }
  return M;
}


void lerMatriz(int **ptr, int m, int n){
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &ptr[i][j]);
    }
  }
}

int** multiplicacaoMatriz(int **A, int mA, int nA, int **B, int mB, int nB){

  int **resultado = alocarMatrizLinearmente(mA, nB);
  if(resultado == NULL){
    return NULL;
  }

  for(int i = 0; i < mA; i++){
    for(int j = 0; j < nB; j++){
      resultado[i][j] = 0;

      for(int k = 0; k < nA; k++){
        resultado[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return resultado;
}

void liberarMatriz(int **M){
  if(M == NULL)
    return;

  free(M[0]);
  free(M);
}

void imprimirMatriz(int **M, int m, int n){
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
}

int processarMultiplicacao(
  int ***matrizes, int dimensoes[][2],
  int indiceA, int indiceB,
  int numeroResultado
  )
{

  if(matrizes[indiceA] == NULL || matrizes[indiceB] == NULL){
    printf("Resultado %d:\n0\n", numeroResultado);
    if(matrizes[indiceB] != NULL){
      liberarMatriz(matrizes[indiceB]);
      matrizes[indiceB] = NULL;
    }

    if(matrizes[indiceA] != NULL){
      liberarMatriz(matrizes[indiceA]);
      matrizes[indiceA] = NULL;
    }

    return 0;
  }

  if(dimensoes[indiceA][1] != dimensoes[indiceB][0]){
    printf("Resultado %d:\n0\n", numeroResultado);
    liberarMatriz(matrizes[indiceA]);
    liberarMatriz(matrizes[indiceB]);

    matrizes[indiceA] = NULL;
    matrizes[indiceB] = NULL;
    return 0;
  }

  int **temp = multiplicacaoMatriz(
    matrizes[indiceA],
    dimensoes[indiceA][0],
    dimensoes[indiceA][1],
    matrizes[indiceB],
    dimensoes[indiceB][0],
    dimensoes[indiceB][1]
  );

  if(temp == NULL){
    return -1;
  }

  liberarMatriz(matrizes[indiceA]);
  liberarMatriz(matrizes[indiceB]);
  
  matrizes[indiceA] = temp;
  matrizes[indiceB] = NULL;

  dimensoes[indiceA][1]= dimensoes[indiceB][1];

  printf("Resultado %d:\n", numeroResultado);
  imprimirMatriz(
    matrizes[indiceA],
    dimensoes[indiceA][0],
    dimensoes[indiceA][1]
  );

  return 1;
}