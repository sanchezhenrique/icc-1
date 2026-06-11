#include <stdio.h>

void bubbleSort(int *p, int n);

int main (){
  int k;
  float mediana;
  scanf("%d", &k);

  int vet[k];

  for (int i = 0; i < k; i++){
    scanf("%d", &vet[i]);
  }

  bubbleSort(vet, k);

  if(k % 2 != 0){
    mediana = vet[k/2];
  } else{
    mediana = (float)(vet[k / 2] + vet[(k / 2) - 1]) / 2.0;
  }

  printf("%.1f", mediana);
}

void bubbleSort(int *p, int n){
  int temp, trocou;
  for(int i = 0; i < n; i++){
    trocou = 0;

    for(int j = 0; j < n - i - 1; j++){
      if(*(p + j) > *(p + j + 1)){
        temp = *(p +j);
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