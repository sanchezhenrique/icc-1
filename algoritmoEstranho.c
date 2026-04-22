#include <stdio.h>

int main (){
  long int n, i = 1 ;
  scanf("%ld", &n);
  printf("%ld ", n );
  while(n != 1 ){
    if(n % 2 == 0 ){
      n /= 2;
    } else{
      n = (n * 3) + 1;
    }
    i++;
    printf("%ld ", n);
  } 
  printf("\n%ld", i);
}