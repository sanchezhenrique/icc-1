#include <stdio.h>

int main(){
  double a, b, area;
  scanf("%lf %lf", &a, &b);
  
  area = (b * b / a) / 2;

  printf("%lf", area);
}