#include <stdio.h>

int main()
{
  int tempo[7][7] = {{0, 2, 11, 6, 15, 11, 1}, {2, 0, 7, 12, 4, 2, 15}, {11, 7, 0, 11, 8, 3, 13}, {6, 12, 11, 0, 10, 2, 1}, {14, 5, 8, 10, 0, 5, 13}, {11, 2, 3, 2, 5, 0, 14}, {1, 15, 13, 1, 13, 14, 0}};

  // 14.3
  int orig, dest, aux, temp = 0;

  do
  {
    printf("Cidade de origem (0 a 6): ");
    scanf("%d", &orig);
  } while (orig < 0 || orig > 6); // validação das entradas

  aux = orig; // atribui a cidade de destino a uma variável auxiliar

  do
  {
    do
    {
      printf("\nCidade de destino: ");
      scanf("%d", &dest);
    } while (dest < 0 || dest > 6); // validação das entradas

    printf("Distância parcial: %d", tempo[aux][dest]); // aqui, aux age como a cidade de origem

    temp = temp + tempo[aux][dest]; // adiciona ao tempo total

    aux = dest; // atribui o valor da cidade de destino à variável auxiliar
  } while (orig != dest);

  printf("\nDistância total: %d\n", temp);

  return 0;
}