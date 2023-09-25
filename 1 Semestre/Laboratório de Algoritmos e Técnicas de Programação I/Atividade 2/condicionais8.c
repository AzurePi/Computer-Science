#include <stdio.h>

int main()
{
  float valor, venda;

  // recebe o valor pago pelo produto
  printf("Qual o valor do produto? ");
  scanf("%f", &valor);

  // determina a margem de lucro do vendedor,
  // de acordo com o valor pago
  if (valor < 20)
  {
    venda = valor * 1.45;
  }
  else
  {
    venda = valor * 1.3;
  }

  // imprime o valor que deve ser cobrado
  printf("\nO valor final de venda deve ser de R$%.2f", venda);

  return 0;
}