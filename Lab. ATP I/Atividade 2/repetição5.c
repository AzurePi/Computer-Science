#include <stdio.h>

int main()
{
  int N, i;

  printf("Escreva um inteiro positivo: ");
  scanf("%d", &N);

  for (i = 1; i <= 10; i++)
  {
    printf("\n%d * %d = %d", N, i, N * i);
  }

  return 0;
}
