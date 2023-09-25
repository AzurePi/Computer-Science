#include <stdio.h>

int main()
{
  float P1, P2, P3, M;
  int faltas, aulas, pFalt;
  char nome[20];

  // recebe o nome do aluno
  printf("Qual o nome do aluno? ");
  scanf("%s[^\n]", &nome);

  // recebe o total de aulas
  printf("Quantas aulas foram ministradas? ");
  scanf(" %d", &aulas);

  // recebe o total de faltas
  printf("Quanta faltas o aluno teve? ");
  scanf(" %d", &faltas);

  // recebe as notas das provas
  printf("Qual foi a nota de %s na P1? ", nome);
  scanf(" %f", &P1);
  printf("Qual foi a nota de %s na P2? ", nome);
  scanf(" %f", &P2);
  printf("Qual foi a nota de %s na P3? ", nome);
  scanf(" %f", &P3);

  // cálculo da porcentagem de faltas
  pFalt = 100.0 * faltas / aulas;

  // cálculo da média
  M = (P1 + P2 + P3) / 3;

  printf("\n---------------\nSituação do Aluno:\n");

  // análise das condições de aprovação
  if (pFalt > 25.0)
  {
    printf("Reprovado por Falta\n");
  }
  else if (M < 5.0)
  {
    printf("Reprovado por Média\n");
  }
  else
  {
    printf("Aprovado\n");
  }

  return 0;
}
