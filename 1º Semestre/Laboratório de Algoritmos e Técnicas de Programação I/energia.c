#include <stdio.h>
#define m 5
#define n 5

int main() {
  float C[m][n]={
  {7.03, 14.87, 26.41, 9.18, 27.05},
  {24.36, 21.14, 11.89, 22.74, 31.62},
  {22.4, 12, 29.8, 24.06, 27.23},
  {19, 16.04, 18.81, 9.62, 13.05},
  {24.66, 22.01, 26, 28.2, 28.56}
  };
  float soma[m];
  float termo[m];
  float poterm, somaPoterm=0;
  float somaTotal=0, somaTurb=0;
  int marc[m];
  
  //Imprimindo a matriz
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("[%.2f]\t",C[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  //Calculando o consumo total por cidade-B
  for(int i=0;i<m;i++)
  {
    soma[i]=0;
    for(int j=0;j<n;j++)
      {
        soma[i]=soma[i]+C[i][j];
      }
    if(soma[i]>110)
    {
      marc[i]=1;
      printf("A Termoelétrica da cidade %d foi ativada\n",i+1);
      poterm=soma[i]-110;
      printf("A potência fornecida pela termoelétrica para a cidade %d é: %.2fMW\n",i,poterm);
      somaPoterm=somaPoterm+poterm;
    }
  }

  printf("\n");
  
  //Item C
  for(int i=0;i<m;i++)
  {
    somaTotal=somaTotal+soma[i];
  }
  printf("A potência total consumida pelas cidades foi: %.2fMW\n", somaTotal);
  for(int i=0;i<m;i++)
  {
    if(marc[i]==1)
    {
      somaTurb+=110;
    }
    else
    {
      somaTurb+=soma[i]; 
    }
  }
  printf("A potência total fornecida pelas turbinas foi: %.2fMW\n", somaTurb);
  printf("A potência total fornecida pelas termoelétricas foi: %.2fMW\n", somaPoterm);

    return 0;
}
  