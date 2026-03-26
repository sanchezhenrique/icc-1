#include <stdio.h>

int main(){
  unsigned int a,b,c;
  scanf("%d %d %d", &a, &b, &c);

  if(a + b > c && a + c > b && b + c > a){
    if(a == b && b == c){
      printf("Triangulo Equilatero");
    }
    else if(a == b || b == c || a == c){
      printf("Triangulo Isoceles");
    }
    else{
      printf("Triangulo Escaleno");
    }
  }
  else{
    printf("Triangulo Invalido");
  }
}