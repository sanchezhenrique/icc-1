#include <stdio.h>

void leituraVetoreOrdena(int *p, int n);

int main (){
  int vet [3], n = 3;
  leituraVetoreOrdena(vet, n);
  for(int i = 0; i < n; i++){
    printf("%d ", vet[i]);
  }
}

void leituraVetoreOrdena(int *p, int n){
  for(int i = 0; i < n; i++){
    scanf("%d", p + i);
  }
  for(int i = 0; i < n; i++){
    int trocou = 0, temp;

    for(int j = 0; j < n - i - 1; j++){
      if(*(p + j) > *(p + j +1)){
        temp = *(p + j);
        *(p + j) = *(p + j + 1);
        *(p + j + 1) = temp;

        trocou = 1;
      }
    }
    if(trocou == 0){
      break;
    }
  }
}  