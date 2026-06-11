#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void entradaDados(int *n, int *m, double *entrada);
void entradaMatriz(int m, int n, double matriz[n][m]);
void imprimirMatriz(int n, int m, double matriz[n][m]);
double somaMatriz(int n, int m, double matriz[n][m], double entrada);

int main (){
  int n, m;
  double entrada, soma;
  entradaDados(&n, &m, &entrada);
  double matriz[n][m];
  entradaMatriz(n, m, matriz);
  soma = somaMatriz(n, m, matriz, entrada);

  printf("%lf", soma);
}

void entradaDados(int *n, int *m, double *entrada){
  scanf("%d %d %lf", n, m, entrada);
}

void entradaMatriz(int n, int m, double matriz[n][m]){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%lf", &matriz[i][j]);
    }
  }
}

void imprimirMatriz(int n, int m, double matriz[n][m]){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      printf("%lf ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

double somaMatriz(int n, int m, double matriz[n][m], double entrada){
  double soma = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(matriz[i][j] > entrada){
      soma += matriz[i][j];
     }
    }
  }
  
  return soma;
}