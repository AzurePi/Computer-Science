#include <stdio.h>
#include <math.h>


// funções
float deriv(float c[], int n, float x){
  int i, soma = 0;

  for(i=0; i<=n; i++){
    soma += i*c[i]*pow(x, i-1);
  }

  return soma;
}

int main() {
  int n=3, i;
  float c[n+1], x;
  
  for(i=0; i<n; i++){
    printf("Digite o coeficiente %d: ", i);
    scanf("%f", &c[i]);
  }

  printf("\nEscolha um valor para x: ");
  scanf("%f", &x);
  printf("A derivada de P(%.2f) é %f", x, deriv(c, n, x));
  
  return 0;
}
  