#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
  /*
  int vet[10], pares = 0;

  for(int i = 0; i < 10; i++){
    scanf("%d", &vet[i]);
  }

  for(int i = 0; i < 10; i++){
    if(vet[i] % 2 == 0 && vet[i] > 10){
      pares++;
    }
  }
  printf("\n %d", pares);
  */
/*
  int n;
  scanf("%d", &n);
  int vet[n];

  for(int i = 0; i < n; i++){
    scanf("%d", &vet[i]);
  }

  int maior = vet[0];

  for(int i = 0; i < n; i++){
    if(vet[i] > maior){
      maior = vet[i];
    }
  }

  printf("%d", maior);
  */

  /*
  int n[15], iMaior, iMenor;
  srand(time(NULL));
  for(int i = 0; i < 15; i++){
    n[i] = rand() % 100 + 1;
  }

  for(int i = 0; i < 15; i++){
    printf("%d ", n[i]);
  }
  
  printf("\n");

  for(int i = 0; i < 15; i++){
    if(i == 0){
      iMaior = i;
      iMenor = i;
      continue;
    }

    if(n[i] > n[iMaior]){
      iMaior = i;
    }

    if(n[i] < n[iMenor]){
      iMenor = i;
    }
  }

  int temp;
  temp = n[iMaior];
  n[iMaior] = n[iMenor];
  n[iMenor] = temp;

  for(int i = 0; i < 15; i++){
    printf("%d ", n[i]);
  }
  */

  int n[15];
  randomVet(n, 15);

  
  
}

void randomVet(int *p, int n){
  srand(time(NULL));
  for(int i = 0; i < n; i++){
    *p = rand() % 100 + 1;
    p++;
  }
}

int encontraMaiorMenor(int *p, int n){
  int iMaior;
  int iMenor;
  for(int i = 0; i < 15; i++){
    if(i == 0){
      iMaior = i;
      iMenor = i;
      continue;
    }

    if(*p > p[iMaior]){
      iMaior = i;
    }

    if(*p < p[iMenor]){
      iMenor = i;
    }
  }

  int temp;
  temp = n[iMaior];
  n[iMaior] = n[iMenor];
  n[iMenor] = temp;
}