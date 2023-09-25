#include <stdio.h>

int main()
{
  signed int num, sum, quant = 0, med, max = 0, min = 10000000;

  while (num >= 0)
  {
    printf("Digite um número: ");
    scanf("%d", &num);
    if (num >= 0)
    {
      sum += num;
      quant++;
      if (num > max)
      {
        max = num;
      }
      if (num < min)
      {
        min = num;
      }
    }
  }

  med = sum / quant;
  printf("\n------------------\n");

  // a)
  printf("A soma dos números digitados é %d\n", sum);
  // b)
  printf("Foram digitados %d números\n", quant);
  // c)
  printf("A média dos números digitados é %d\n", med);
  // d)
  printf("O maior número digitado foi %d\n", max);
  // e)
  printf("O menor número digitado foi %d\n", min);

  return 0;
}