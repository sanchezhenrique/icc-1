#include <stdio.h>

int main (){
  long long unsigned int tempo;
  int horas, dias, semanas;
  char s;
  scanf("%llu %c", &tempo, &s);

  semanas = tempo / 604800000000; // 7dias * 24horas *3600segundos * 10^s = 604800000000
  tempo %= 604800000000; // Tempo recebe o valor do resto da divisão 

  dias = tempo / 86400000000; // 24horas * 3600segundos * 10^s = 86400000000
  tempo %= 86400000000;

  horas = tempo / 3600000000;

  printf("Decomposição do setor %c", s);
  printf("\n%d Semana(s)", semanas);
  printf("\n%d Dia(s)", dias);
  printf("\n%d Hora(s)", horas);
}