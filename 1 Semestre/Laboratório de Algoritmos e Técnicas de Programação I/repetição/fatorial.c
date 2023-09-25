#include <stdio.h>

int main()
{
  int fact, N;

  printf("Qual o número?\n");
  scanf("%d", &N);

  fact = 1;

  for (int i = 1; i <= N; i++)
  {
    fact *= i;
  }

  printf("O fatorial desse número é %d\n", fact);

  return 0;
}