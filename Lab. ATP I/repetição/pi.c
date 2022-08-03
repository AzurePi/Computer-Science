#include <stdio.h>
#include <math.h>

int main()
{
  float pi, sum, termo, E, denom;
  int sinal;

  printf("Qual o menor decimal a ser usado?\n");
  scanf("%f", &E);

  sum = 0;
  denom = 1; // denominador inicial da sequência
  sinal = 1; // o primeiro termo será positivo

  while (fabs(termo) > E)
  {
    termo = sinal * 1 / denom;
    sum += termo;
    sinal *= -1; // garante que o próximo termo terá o sinal oposto
    denom += 2;  // define o próximo denominador como o próximo ímpar
  }

  pi = sum * 4;

  printf("A aproximação de pi é %2.10f\n", pi);

  return 0;
}