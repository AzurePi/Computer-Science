#include <stdio.h>

int main()
{
  int N, sum;

  sum = 0;
  printf("Até que número somar?\n");
  scanf("%d", &N);

  for (int i = 1; i <= N; i++)
  {
    sum += i;
  }

  printf("A soma dos %d primeiros números é %d\n", N, sum);

  return 0;
}