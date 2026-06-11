#include <stdio.h>
#include <math.h>

double calculaHipotenusa(double a, double b);

int main (){
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  printf("%lf", calculaHipotenusa(c, calculaHipotenusa(a,b)));
}

double calculaHipotenusa(double a, double b){
  return(sqrt((a * a) + (b * b)));
}