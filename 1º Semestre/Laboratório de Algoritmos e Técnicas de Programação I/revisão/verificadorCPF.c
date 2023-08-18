#include <stdio.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  char CharPF[12], c;
  int CPF[11], i, flag = 0, soma = 0, resto;

  printf("Digite um CPF (sem traços ou pontos): ");
  scanf("%s", CharPF);
  
  for(i=0; i<11; i++){
    c = CharPF[i];
    CPF[i] = c - '0'; //força o C a converter um char em um int
  }

  for(i=0; i<11; i++){
    if(CPF[i] != CPF[i+1]){
      /*vários "ou" entre negações, equivalente a vários
      "e" (Lei de deMorgan); analisa se todos os dígitos
      são iguais*/
      flag = 1; //sinaliza que o if foi adentrado
    }
  }

  if(flag != 1){
    printf("\nCPF inválido: todos os dígitos são iguais");
    return 0;
  }else{
    //verifica o primeiro dígito verificador
    for(i=0; i<9; i++){
      soma += CPF[i]*(10-i);
    }
    resto = (10*soma) % 11;
    if(resto == 10){
      resto = 0; //se o resto é 10, o dígito verificador tem que ser 0
    }
    if(resto != CPF[9]){
      printf("\nCPF inválido\n");
      return 0;
    }
    //verifica o segundo dígito verificador
    soma = 0;
    for(i=0; i<10; i++){
      soma += CPF[i]*(11-i);
    }
    resto = (10*soma) % 11;
    if(resto == 10){
      resto = 0; //se o resto é 10, o dígito verificador tem que ser 0
    }
    if (resto != CPF[10]){
      printf("\nCPF inválido\n");
      return 0;
    }
  }
  //só acontece se não adentra o if anterior
  printf("\nCPF válido\n");
  return 0;
}
  
