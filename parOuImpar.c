#include <stdio.h>

int main (){
  long long int a, b;
  scanf("%ld %ld", &a, &b);
  if( a % 2 == b % 2){
    if(a % 2 == 0 ){
      printf("O primeiro número é par \n");
      printf("O segundo número é par \n");
      printf("O resultado é %d, que é par", a * b);
    }
    else {
      printf("O primeiro número é impar \n");
      printf("O segundo número é impar \n");
      printf("O resultado é %d, que é impar", a * b);
    }
  }
  else{
    if(a % 2 == 0){
      printf("O primeiro número é par \n");
      printf("O segundo número é impar \n");
      printf("O resultado é %d, que é impar", a + b);
    }
    else{
      printf("O primeiro número é impar \n");
      printf("O segundo número é par \n");
      printf("O resultado é %d, que é impar", a + b);
    }
  }
}

/*
if(a % 2 == 0){
    printf("O primeiro número é par \n");
    if(b % 2 == 0){
      printf("O segundo número é par \n");
      printf("O resultado é %d, que é par", a * b);
    }
    else{
      printf("O segundo número é impar \n");
      printf("O resultado é %d, que é impar", a + b);
    }
  }
  else{
    printf("O primeiro número é impar \n");
    if(b % 2 == 0){
      printf("O segundo número é par \n");
      printf("O resultado é %d, que é impar", a + b);
    }
    else{
      printf("O segundo número é impar \n");
      printf("O resultado é %d, que é impar", a * b);
    }
  }*/