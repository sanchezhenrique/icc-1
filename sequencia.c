#include <stdio.h>

int main (){
  long double x, res, numerador, denominador;
  unsigned int n;

  scanf("%Lf %u", &x, &n);
  res = 0;

  for(int i = 0; i < n; i++){
    numerador = x;
    for(int j = 1; j < i*2; j++){
      numerador *= x;
    }
    denominador = 1;
    for(int j = 2; j <= (i*2) + 1; j++){
      denominador *= j;
    }
    if(i % 2 == 0){
      res += numerador/denominador;
    }
    else{
      res -= numerador/denominador;
    }
  }
  printf("%.10Lf", res);
}