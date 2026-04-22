#include <stdio.h>
#include <math.h>
int main (){
  int n, m, bN = 0, bM = 0, a, b, xor, and, or;
  //Entrada Parte 1
  scanf("%d %d", &n, &m);
  
  for (int i = n -1; i >= 0; i--){ //Conversao do numero N
    int digito;
    scanf("%d", &digito);
    if(digito == 1){
      bN += pow(2, i);
    }
  }

  for (int i = m -1; i >= 0; i--){ //Conversao do numero M
    int digito;
    scanf("%d", &digito);
    if(digito == 1){
      bM += pow(2, i);
    }
  }

  // Entrada Parte 2 
  scanf("%d %d", &a, &b);

  //Operacoes Parte 1
  xor = bN ^ bM;
  and = bN & bM;
  or= bN | bM;

  //Saida Parte 1
  printf("%d \n%d \n%d \n", or, and, xor);
  printf("\n"); // 4° linha vazia

  //Operacoes Parte 2
  xor = a ^ b;
  and = a & b;
  or = a | b;
  
  //Impressão BInaria OR
  int encontrou = 0;
  for(int i = 31; i >= 0; i--){
    int bit = (or >> i) & 1;

    if(bit == 1){
      encontrou = 1;
    }

    if(encontrou){
      printf("%d", bit);
    }
  }
  if(!encontrou){
    printf("0");
  }
  printf("\n");

  //Impressão BInaria AND
  encontrou = 0;
  for(int i = 31; i >= 0; i--){
    int bit = (and >> i) & 1;

    if(bit == 1){
      encontrou = 1;
    }

    if(encontrou){
      printf("%d", bit);
    }
  }
  if(!encontrou){
    printf("0");
  }  
  printf("\n");

  //Impressão BInaria XOR
  encontrou = 0;
  for(int i = 31; i >= 0; i--){
    int bit = (xor >> i) & 1;

    if(bit == 1){
      encontrou = 1;
    }

    if(encontrou){
      printf("%d", bit);
    }
  }
  if(!encontrou){
    printf("0");
  }
  printf("\n");
}