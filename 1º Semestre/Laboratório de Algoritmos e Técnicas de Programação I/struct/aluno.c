#include <stdio.h>

// Criação da struct
struct aluno {
  char nome[101];
  int matricula;
  float cr;
};

int main() {
  struct aluno aluno1;

  // Preenchendo a variável aluno1
  printf("Digite um nome: ");
  gets(aluno1.nome);
  printf("Digite um número de matrícula: ");
  scanf("%d", &aluno1.matricula);
  printf("Digite o coeficiente de rendimento: ");
  scanf("%f", &aluno1.cr);

  // Impressão da variável aluno
  printf("Nome: %s\n", aluno1.nome);
  printf("Matrícula: %d\n", aluno1.matricula);
  printf("Coeficiente de rendimento: %f\n", aluno1.cr);
    
  return 0;
}
  
