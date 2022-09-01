#include <stdio.h>

// Lista 4 ex 12
int main()
{
  float alt, altF, medF, alt_maxM, alt_maxF, dif;
  int M = 0, F = 0, i = 0;
  char sex;

  altF = 0;
  alt_maxM = 0;
  alt_maxF = 0;

  while (i < 15)
  {
    printf("\nQual o sexo da pessoa? <M/F> ");
    scanf(" %c", &sex);
    printf("Qual a altura da pessoa? ");
    scanf(" %f", &alt);

    switch (sex)
    {
    case 'M':
      M++;
      if (alt > alt_maxM)
      {
        alt_maxM = alt;
      }
      i++;
      break;
      ;
    case 'F':
      F++;
      altF += alt;
      if (alt > alt_maxF)
      {
        alt_maxF = alt;
      }
      i++;
      break;
      ;
    default:
      printf("\nEsse não é um sexo válido. Repita a operação\n");
      break;
      ;
    }
  }

  printf("\n-------------------\n");

  // a)
  printf("O homem mais alto tem %.2fm e a mulher mais alta tem %.2fm\n", alt_maxM, alt_maxF);

  // b)
  medF = altF / F;
  printf("A altura média das mulheres é %.2fm\n", medF);

  // c)
  dif = M * 100.0 / F;
  printf("Há um total de %d homens, o que equivale a %.2f por cento do total de mulheres\n\n", M, dif);

  return 0;
}