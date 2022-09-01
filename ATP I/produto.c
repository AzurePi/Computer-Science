#include <stdio.h>

int main()
{
  char produto[10];
  int quantidade;
  float preço, valor;

  printf("Que produto foi comprado?\n");
  scanf("%s", &produto);
  printf("Qual o preço por unidade?\n");
  scanf("%f", &preço);
  printf("Quantas unidades foram compradas?\n");
  scanf("%d", &quantidade);

  if (quantidade <= 10)
    valor = preço * quantidade;
  else if (quantidade >= 11 && quantidade <= 20)
    valor = preço * quantidade * 0.9;
  else if (quantidade >= 21 && quantidade <= 50)
    valor = preço * quantidade * 0.8;
  else
    valor = preço * quantidade * 0.75;

  printf("O preço total de %s é %.2f\n", produto, valor);

  return 0;
}
