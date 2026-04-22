#include <stdio.h>

int main (){
  long int n, somaPa;

  scanf("%ld", &n);
  somaPa = (1 + n) * n / 2;

  for(long int i = 0; i < n-1; i++){
    long int aI;
    scanf("%ld", &aI);
    somaPa -= aI; // resultara no numero faltante
  }

  printf("%ld", somaPa);
}