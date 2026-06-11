#include <stdio.h>
#include <stdlib.h>

int main (){
  int n, *p;
  scanf("%d", &n); // tamnho do vetor

  int vet[n];
  p = vet;

  for(int i = 0; i < n; i++){ //leitura dos elemnetos 
    scanf("%d", &vet[i]); 
  }
  
  int q;
  scanf("%d", &q); // quantidade de operações

  for(int i = 0; i < q; i++){
    char operacao;
    scanf(" %c", &operacao);

    switch(operacao){
      case 'E':
        int x;
        scanf("%d", &x);
        p += x;
        break;
      
      case 'B':
        int y;
        scanf("%d", &y);
        p = (int*)((char*) p +y);
        break;

      case 'P':
        printf("%d\n", *p);
        break;

      case 'D':
        if((char*)p - (char*)vet < 0){
          printf("%td\n", (char*)vet - (char*)p);
        } else{
          printf("%td\n", (char*)p - (char*)vet);
        }
      break;
    }
  }
}