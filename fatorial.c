#include <stdio.h>

int main(){
  int n;
  int i = 2;
  long double fatorial = 1;
  scanf("%d", &n);

  while(i <= n){
    fatorial *= i;
    i++;
  }
  printf("%1.Lf \n", fatorial);
}