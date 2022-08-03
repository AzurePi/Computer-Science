#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
	
  int n, i;
  printf("Indique a quantidade de amostras: ");
  scanf("%d", &n);
  double amostras[n], desvPadr, soma = 0, media;

  for(i=0; i<n; i++){
    printf("Valor da amostra %d: ", i);
    scanf("%lf", &amostras[i]);
    soma += amostras[i];
  }
  media = soma / n;
  
  soma = 0;
  for(i=0; i<n-1; i++){
    soma+= (amostras[i] - media)*(amostras[i] - media);
  }
  desvPadr = sqrt(soma/(n-1));

  printf("\nMédia das amostras: %.3lf", media);
  printf("\nDesvio Padrão das amostras: %.3lf", desvPadr);
  return 0;
}
  
