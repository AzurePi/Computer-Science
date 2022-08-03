#include <stdio.h>

#define n 20

int main(void) {
  typedef struct cliente {
    char nome[100];
    char sex;
  } cliente;

  typedef struct conta {
    cliente cli;       // dados pessoais
    int nConta;        // número da conta
    int dia, mes, ano; // data de abertura da conta
    float saldo;
    float especial;
  } conta;

  conta C[n];                         // vetor de clientes
  float salMedMul = 0, salMedHom = 0; // saldos médios
  int M, H;                           // quantidade de mulheres e homens
  float menSal, maiorSal;             // menor e maior saldos
  int maisAnt, maiorEsp;  //índices do mais antigo e maior limite especial
  int negs[n], negsI = 0; //índices onde há saldos negativos
  int cresc[n]; // ordem dos índices de C de acordo com o saldo crescente

  // leitura dos dados
  for (int i = 0; i < n; i++) {
    printf("Nome: ");
    scanf(" %[^\n]s", C[i].cli.nome);

    printf("Sexo (M/F): ");
    scanf(" %c", &C[i].cli.sex);
    if (C[i].cli.sex == 'M') {
      M++;
    } else {
      H++;
    }

    printf("Número da conta: ");
    scanf("%d", &C[i].nConta);

    printf("Data de abertura da conta (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &C[i].dia, &C[i].mes, &C[i].ano);

    printf("Saldo em conta: ");
    scanf("%f", &C[i].saldo);
    if (C[i].saldo < 0) { // se o saldo for negativo
      negs[negsI] = i;
      negsI++;
    }
    if (C[i].cli.sex == 'M') {
      salMedMul += C[i].saldo;
    } else {
      salMedHom += C[i].saldo;
    }

    printf("Limite do cheque especial: ");
    scanf("%f", &C[i].especial);

    printf("\n");
  }

  // cálculo dos saldos médios
  salMedMul /= M;
  salMedHom /= H;

  // verificação do mais antigo, menor saldo, maior especial
  for (int i = 0; i < n; i++) {
    if (i == 0) { // na primeira iteração
      menSal = C[i].saldo;
      maiorSal = C[i].saldo;
      maisAnt = i;
      maiorEsp = i;
    } else {
      // menor saldo
      if (C[i].saldo < menSal) {
        menSal = C[i].saldo;
      }
      // maior saldo
      if (C[i].saldo > maiorSal) {
        maiorSal = C[i].saldo;
      }
      // mais antigo
      if (C[i].ano < C[maisAnt].ano && C[i].mes < C[maisAnt].mes &&
          C[i].dia < C[maisAnt].dia) {
        maisAnt = i;
      }
      // maior especial
      if (C[i].especial > C[maiorEsp].especial) {
        maiorEsp = i;
      }
    }
  }

  return 0;
}